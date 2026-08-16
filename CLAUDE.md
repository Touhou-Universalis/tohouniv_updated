# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

**Touhou Universalis Updated** — a total-conversion content mod for *Europa Universalis IV* (`descriptor.mod`: version 3.9.0, `supported_version="v1.37.*"`, Steam Workshop id 1537902566). It is entirely Paradox script (`.txt` / `.gui` / `.gfx` / `.yml` / `.lua` / `.dds`) plus map bitmaps. There is **no build system, no compiler, no test suite, and no CI** — the `.vscode/tasks.json` msbuild task is leftover boilerplate and does nothing useful here.

The `.txt` files are **EU4 Paradox scripting language**, not a general-purpose language: declarative `key = { ... }` blocks that the game engine interprets, where the valid keys depend entirely on which folder the file sits in (an effect valid in an event is not valid in a trigger, and neither is valid in `common/ideas/`). The reference for the language — scopes, triggers/conditions, effects, modifiers, and the per-folder file formats — is the EU4 wiki scripting tutorial at <https://eu4.paradoxwikis.com/Scripting_Tutorial> and its many sub-pages. Consult it (and the vanilla game files it describes) rather than inferring syntax from surrounding code alone; a plausible-looking key that the engine does not recognise fails silently or drops the whole file.

## Running / validating changes

The only way to test is to load the mod in the game:

1. Point EU4 at this checkout — create a `.mod` file in `Documents/Paradox Interactive/Europa Universalis IV/mod/` whose `path` is this repo directory (or symlink the directory in), mirroring `descriptor.mod`.
2. Launch EU4 with the mod enabled; run with `-debug` to get the in-game error dialogs and console (`~`).
3. Read `Documents/Paradox Interactive/Europa Universalis IV/logs/error.log` after startup — this is the primary "compiler output" for script/localisation/sprite mistakes. `game.log` covers runtime effect errors.

Syntax errors in a script file usually cause the game to silently drop the whole file, not just the bad block, so a missing feature almost always means a parse error in `error.log`.

## Repository layout and how the pieces connect

Directory names are dictated by EU4 and mirror vanilla's structure. Two kinds of file live side by side:

- **Additive mod content** — prefixed `th_`, `touhou_`, `TH_`, `Th`, or a 3-letter country TAG (`KPP_`, `HVR_`, ...). Most of the repo.
- **Vanilla overwrites** — files that keep a vanilla name and replace it wholesale: `common/technology.txt`, `common/buildings/00_buildings.txt`, `common/on_actions/on_actions.info`, `common/bookmarks/rise_of_the_ottomans.txt`, [interface/provinceview.gui](interface/provinceview.gui), [interface/macrobuildinterface.gui](interface/macrobuildinterface.gui), [interface/alerts.gfx](interface/alerts.gfx), and everything in [map/](map/). These need re-reconciling against vanilla after an EU4 patch; prefer adding a new `th_`-prefixed file over extending an overwrite.

Key cross-file wiring to know before editing:

- **Country tags** are registered in [common/country_tags/toho_countries.txt](common/country_tags/toho_countries.txt), which maps `TAG = "countries/<Name>.txt"` (graphics/colour, in `common/countries/`). Each tag additionally needs history in `history/countries/TAG - Name.txt`, national ideas in [common/ideas/toho_country_ideas.txt](common/ideas/toho_country_ideas.txt), a flag in `gfx/flags/`, and usually `TAG_Missions.txt` / `TAG_decisions.txt`.
- **Events** live in flat files under [events/](events/), each declaring a `namespace` (146 of them; `flavor_<tag>` for per-country flavour, `TH_*_events` / `th_*` for shared systems). Events are fired by id (`namespace.N`) from decisions, missions, on_actions and government mechanics, so ids are a de-facto public API — renumbering breaks callers.
- **Shared logic** is centralised in [common/scripted_effects/](common/scripted_effects/) and [common/scripted_triggers/](common/scripted_triggers/), split by domain (`th_scripted_effects_for_<mechanic>.txt`). [common/on_actions/th_on_actions.txt](common/on_actions/th_on_actions.txt) is the hub that bootstraps mechanics at `on_startup` and hooks lifecycle events; its own comment asks that non-trivial logic go into a scripted effect rather than inline.
- **Government mechanics** are three-part: rules in `common/government_mechanics/th_*.txt` (powers, `range_modifier` bands), the GUI window in `interface/government_mechanics/th_*.gui`, and sprites in `interface/government_mechanics/government_mechanics_touhou.gfx`. The mechanic's `gui = ...` key must match the window name in the `.gui`. Player-facing explanations of these mechanics are collected as decisions in [decisions/TH_MechanicWiki.txt](decisions/TH_MechanicWiki.txt) that fire an informational event.
- **Sprites**: `.dds` assets under `gfx/`, declared as `spriteType` entries in `interface/*_touhou.gfx`, referenced by `GFX_` name from `.gui`/script. Per-culture/per-tag art swaps go through `gfx/sprite_packs/` with priorities set in [gfx/sprite_packs_order/th_sprite_pack_orders.txt](gfx/sprite_packs_order/th_sprite_pack_orders.txt) (higher number = more specific = wins; the file documents the 0–70 scale).
- **Map**: `map/definition.csv` (province id → RGB) and `map/provinces.bmp` are the source of truth for provinces; `map/default.map` declares `max_provinces` and sea/lake lists; `area.txt` → `region.txt` → `superregion.txt` → `continent.txt` form the grouping chain that scripts scope through (e.g. the custom `gensokyo_continent`). Province history lives in `history/provinces/<id> - <Name>.txt`. Custom terrain is defined in `map/terrain.txt` with its combat/colony icons declared in [interface/terrain_type.gfx](interface/terrain_type.gfx) and named in `localisation/terrain_l_english.yml`.
- **Defines** overrides are in [common/defines/00_TouhouUniversalis.lua](common/defines/00_TouhouUniversalis.lua) (frontend camera position over the custom map, AI tuning, etc.).

## Localisation conventions

- Files are UTF-8 **with BOM**, one space of indentation per key, `key: "value"` (the vanilla version-number field is omitted throughout this mod). Keep the BOM — the game will not read the file without it.
- Every localisation file exists in four languages: `_l_english`, `_l_french`, `_l_german`, `_l_spanish`. The non-English files are **not translated** — they are byte-copies of the English text with only the `l_xxx:` header changed. When adding or renaming a key, add it to all four files with the same English string; a key present only in English will show as a raw key for players running the game in another language.
- Text keys support the usual EU4 scopes/commands (`[Root.Monarch.GetName]`, `[Root.GetName]`) and colour codes (`§Y...§!`). Custom loc commands are defined in [customizable_localization/](customizable_localization/).

## Conventions

- Indentation is tabs. Braces follow Paradox style (`key = {` … `}`), and `#` comments are used liberally to section files (e.g. `###FORM DECISIONS###`).
- New scripted effects/triggers, estates, privileges, government mechanics, buildings and events use the `th_` prefix to avoid colliding with vanilla identifiers; country-specific content uses the tag prefix instead.
- Branching: work happens on feature branches merged into `big_gensokyo` (the default branch); PRs are squash-then-merge, so history shows a `Feature (#NNN)` commit following the raw commit.
