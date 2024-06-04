#include <iostream>
#include <string>
#include "danmaku_duel_manager.h"

int main()
{
	std::string effectOutputFolder = "C:\\Users\\<user name>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\touhou_universalis\\test";
	std::string triggerOutputFolder = "C:\\Users\\<user name>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\touhou_universalis\\test";
	std::string customLocalizationOutputFolder = "C:\\Users\\<user name>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\touhou_universalis\\test";
	std::string localizationOutputFolder = "C:\\Users\\<user name>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\touhou_universalis\\test";
	std::vector<std::string> combatVerbs = { "uses", "performs", "casts", "enchants", "curses", "strikes", "shoots", "attacks" };
	std::vector<std::string> combatArticles = { "undefined", "defined" };
	std::vector<std::string> combatAbilities = { "attack" };
	std::vector<std::string> combatPrepositions = { "against", "on" };
	std::vector<std::string> combatAbilityEffect = { "dealing", "healing", "restore", "afflicting_condition", "gaining_condition" };
	std::vector<std::string> combatAbilityEndeffect = { "damage", "health", "mana", "action_points" };

	CDanmakuDuelManager danmakuDuelManager;
	danmakuDuelManager.SetupInstances(30);
	danmakuDuelManager.SetupActions(15);

	danmakuDuelManager.SetupCombatVerbs(combatVerbs);
	danmakuDuelManager.SetupCombatArticles(combatArticles);
	danmakuDuelManager.SetupCombatAbilities(combatAbilities);
	danmakuDuelManager.SetupCombatPrepositions(combatPrepositions);
	danmakuDuelManager.SetupCombatAbilityEffects(combatAbilityEffect);
	danmakuDuelManager.SetupCombatAbilityEndEffect(combatAbilityEndeffect);

	danmakuDuelManager.SetupEffectOutputFolder(effectOutputFolder);
	danmakuDuelManager.SetupTriggerOutputFolder(triggerOutputFolder);
	danmakuDuelManager.SetupCustomizableLocalizationOutputFolder(customLocalizationOutputFolder);
	danmakuDuelManager.SetupLocalizationOutputFolder(localizationOutputFolder);

	danmakuDuelManager.GenerateCustomLocalizationFile();
	danmakuDuelManager.GenerateEffectFile();
	danmakuDuelManager.GenerateLocalizationFile();
}