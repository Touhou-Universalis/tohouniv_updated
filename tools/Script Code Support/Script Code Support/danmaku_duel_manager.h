#pragma once
#include <iostream>
#include <vector>
class CDanmakuDuelManager
{
public:
	void SetupInstances(int instances) { _instances = instances; }
	void SetupActions(int actions) { _actions = actions; }

	void SetupEffectOutputFolder(std::string destination) { _effectOutputFolder = destination; }
	void SetupTriggerOutputFolder(std::string destination) { _triggerOutputFolder = destination; }
	void SetupCustomizableLocalizationOutputFolder(std::string destination) { _customLocalizationOutputFolder = destination; }
	void SetupLocalizationOutputFolder(std::string destination) { _localizationOutputFolder = destination; }

	void SetupCombatVerbs(std::vector<std::string>& input) { _combatVerbs = input; }
	void SetupCombatArticles(std::vector<std::string>& input) { _combatArticles = input; }
	void SetupCombatAbilities(std::vector<std::string>& input) { _combatAbilities = input; }
	void SetupCombatPrepositions(std::vector<std::string>& input) { _combatPrepositions = input; }
	void SetupCombatAbilityEffects(std::vector<std::string>& input) { _combatAbilityEffect = input; }
	void SetupCombatAbilityEndEffect(std::vector<std::string>& input) { _combatAbilityEndeffect = input; }

	void GenerateEffectFile();
	void GenerateTriggerFile();
	void GenerateCustomLocalizationFile();
	void GenerateLocalizationFile();
private:
	int _instances = 30;
	int _actions = 15;
	std::string _effectOutputFolder;
	std::string _triggerOutputFolder;
	std::string _customLocalizationOutputFolder;
	std::string _localizationOutputFolder;
	std::string _effectFile = "th_generated_scripted_effects_danmaku_fight.txt";
	std::string _triggerFile = "th_generated_scripted_triggers_danmaku_fight.txt";
	std::string _customLocalizationFile = "th_generated_danmaku_locs.txt";
	std::string _localizationFile = "touhou_generated_danmaku_l_english.yml";
	std::vector<std::string> _combatVerbs;
	std::vector<std::string> _combatArticles;
	std::vector<std::string> _combatAbilities;
	std::vector<std::string> _combatPrepositions;
	std::vector<std::string> _combatAbilityEffect;
	std::vector<std::string> _combatAbilityEndeffect;

	//Localization
	void CreateLocalizationCombatLogForInstance(std::string& outputLine, int i, int a);
	//void CreateLocalizationGetActor(std::string& outputLine, int i, int a);
	//void CreateLocalizationGetRecipient(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableValue(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableHitDie(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableHitDieAmount(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableHitDieResult(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableEnemyAC(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableHitDieFlatBonus(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableHitDieBonusPerRoll(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableAttackDie(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableAttackDieAmount(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableAttackDieResult(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableAttackDieBonusPerRoll(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableAttackDieFlatbonus(std::string& outputLine, int i, int a);
	void CreateLocalizationGetVariableResistanceReduction(std::string& outputLine, int i, int a);
	void CreateLocalizationGetHitRollText(std::string& outputLine, int i, int a);
	void CreateLocalizationGetAbilityRollText(std::string& outputLine, int i, int a);
	void CreateLocalizationGetHitBonusPerDice(std::string& outputLine, int i, int a);
	void CreateLocalizationGetHitFlatBonus(std::string& outputLine, int i, int a);
	void CreateLocalizationGetAbilityBonusPerDice(std::string& outputLine, int i, int a);
	void CreateLocalizationGetAbilityFlatBonus(std::string& outputLine, int i, int a);
	void CreateLocalizationGetCriticalBonus(std::string& outputLine, int i, int a);

	//Unlanded Character duels loc
	void CreateLocalizationCombatLogForCharacter(std::string& outputLine, int a);
	void CreateLocalizationGetActor(std::string& outputLine, int a);
	void CreateLocalizationGetRecipient(std::string& outputLine, int a);
	void CreateLocalizationGetVariableValue(std::string& outputLine, int a);
	void CreateLocalizationGetVariableHitDie(std::string& outputLine, int a);
	void CreateLocalizationGetVariableHitDieAmount(std::string& outputLine, int a);
	void CreateLocalizationGetVariableHitDieResult(std::string& outputLine, int a);
	void CreateLocalizationGetVariableEnemyAC(std::string& outputLine, int a);
	void CreateLocalizationGetVariableHitDieFlatBonus(std::string& outputLine, int a);
	void CreateLocalizationGetVariableHitDieBonusPerRoll(std::string& outputLine, int a);
	void CreateLocalizationGetVariableAttackDie(std::string& outputLine, int a);
	void CreateLocalizationGetVariableAttackDieAmount(std::string& outputLine, int a);
	void CreateLocalizationGetVariableAttackDieResult(std::string& outputLine, int a);
	void CreateLocalizationGetVariableAttackDieBonusPerRoll(std::string& outputLine, int a);
	void CreateLocalizationGetVariableAttackDieFlatbonus(std::string& outputLine, int a);
	void CreateLocalizationGetVariableResistanceReduction(std::string& outputLine, int a);
	void CreateLocalizationGetHitRollText(std::string& outputLine, int a);
	void CreateLocalizationGetAbilityRollText(std::string& outputLine, int a);
	void CreateLocalizationGetHitBonusPerDice(std::string& outputLine, int a);
	void CreateLocalizationGetHitFlatBonus(std::string& outputLine, int a);
	void CreateLocalizationGetAbilityBonusPerDice(std::string& outputLine, int a);
	void CreateLocalizationGetAbilityFlatBonus(std::string& outputLine, int a);
	void CreateLocalizationGetCriticalBonus(std::string& outputLine, int a);

	//Custom Loc Commands
	void CreateLocCommandGetRootCountryName(std::string& outputLine);

	void CreateLocCommandGetActor(std::string& outputLine, int i, int a);
	void CreateLocCommandGetEffectVerb(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityArticle(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbility(std::string& outputLine, int i, int a);
	void CreateLocCommandGetPrePosition(std::string& outputLine, int i, int a);
	void CreateLocCommandGetRecipient(std::string& outputLine, int i, int a);
	void CreateLocCommandGetHitRoll(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityEffect(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityEffectNumber(std::string& outputLine, int i, int a);
	void CreateLocCommandGetCritical(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityRoll(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilitySpecialEffect(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityEffectEnd(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilitySecondEffect(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilitySecondEffectAbility(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilitySecondEffectEnd(std::string& outputLine, int i, int a);
	void CreateLocCommandGetEndSentence(std::string& outputLine, int i, int a);
	void CreateLocCommandGetHitBonusPerDice(std::string& outputLine, int i, int a);
	void CreateLocCommandGetHitFlatBonus(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityBonusPerDice(std::string& outputLine, int i, int a);
	void CreateLocCommandGetAbilityFlatBonus(std::string& outputLine, int i, int a);
	void CreateLocCommandGetCriticalBonus(std::string& outputLine, int i, int a);

	//Unlanded Character duels loc commands
	void CreateLocCommandGetActor(std::string& outputLine, int a);
	void CreateLocCommandGetEffectVerb(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityArticle(std::string& outputLine, int a);
	void CreateLocCommandGetAbility(std::string& outputLine, int a);
	void CreateLocCommandGetPrePosition(std::string& outputLine, int a);
	void CreateLocCommandGetRecipient(std::string& outputLine, int a);
	void CreateLocCommandGetHitRoll(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityEffect(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityEffectNumber(std::string& outputLine, int a);
	void CreateLocCommandGetCritical(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityRoll(std::string& outputLine, int a);
	void CreateLocCommandGetAbilitySpecialEffect(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityEffectEnd(std::string& outputLine, int a);
	void CreateLocCommandGetAbilitySecondEffect(std::string& outputLine, int a);
	void CreateLocCommandGetAbilitySecondEffectAbility(std::string& outputLine, int a);
	void CreateLocCommandGetAbilitySecondEffectEnd(std::string& outputLine, int a);
	void CreateLocCommandGetEndSentence(std::string& outputLine, int a);
	void CreateLocCommandGetHitBonusPerDice(std::string& outputLine, int a);
	void CreateLocCommandGetHitFlatBonus(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityBonusPerDice(std::string& outputLine, int a);
	void CreateLocCommandGetAbilityFlatBonus(std::string& outputLine, int a);
	void CreateLocCommandGetCriticalBonus(std::string& outputLine, int a);
};

