#include <iostream>
#include <string>
#include "danmaku_duel_manager.h"
#include "province_manager.h"
#include "localization_manager.h"

int main()
{
	const std::string modPath = "C:\\Users\\<user name>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\touhou_universalis";
	/*
	Set the if statement of whatever function you need to "true". Also make sure to have the mod path correctly set.
	Might make a proper application one day so you don't have to change parameters within the code itself.
	*/
	if (false)
	{
		std::string effectOutputFolder = modPath + "\\output\\danmaku";
		std::string triggerOutputFolder = modPath + "\\output\\danmaku";
		std::string customLocalizationOutputFolder = modPath + "\\output";
		std::string localizationOutputFolder = modPath + "\\output\\danmaku";
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
	if (true)
	{
		std::string localizationInputFolder = modPath + "\\localisation";
		std::string localizationOutputFolder = modPath + "\\output\\localisation";

		CLocalizationManager localizationManager(localizationInputFolder, localizationOutputFolder);
		localizationManager.CreateLocalizedFiles();
	}
	if (false)
	{
		CProvinceManager provinceManager;
		provinceManager.SetStartOfNewProvinces(7054);
		provinceManager.SetOwner("LCU");
		provinceManager.SetReligion("th_lunarian_religion");
		provinceManager.SetCulture("th_lunarian_culture");
		provinceManager.SetTradeGoods("fish");
		
		provinceManager.SetInputFile(modPath + "\\map\\definition.csv");
		provinceManager.SetOutputFolder(modPath + "\\history\\provinces");

		provinceManager.PrintProvinces();
	}
}