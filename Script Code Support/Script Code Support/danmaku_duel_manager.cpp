#include "danmaku_duel_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

////////////////////////////////////////////////////////////////////////
// Scripted Effects

//th_change_danmaku_instance_round
//th_select_enemy_event_target_and_do_effect
//th_monthly_danaku_duel_update
//th_clear_log_all_ability_actor_for_instance
//th_clear_log_all_ability_verb_for_instance
//th_clear_log_all_ability_article_for_instance
//th_clear_log_all_ability_ability_for_instance
//th_clear_log_all_ability_preposition_for_instance
//th_clear_log_all_ability_recipient_for_instance
//th_clear_log_all_ability_ability_effect_for_instance
//th_clear_log_all_ability_number_impact_for_instance
//th_clear_log_all_ability_is_damage_for_instance
//th_clear_log_all_ability_is_health_for_instance
//th_clear_log_all_ability_is_mana_for_instance
//th_clear_log_all_ability_is_action_points_for_instance
//th_clear_log_all_ability_is_critical_for_instance
//th_clear_log_all_ability_is_miss_for_instance
//th_clear_combat_log_for_instance
//
//th_log_ability_actor
//th_log_ability_verb
//th_log_ability_article
//th_log_ability_ability
//th_log_ability_preposition
//th_log_ability_recipient
//th_log_ability_ability_effect
//th_log_ability_number_impact
//th_log_ability_is_damage
//th_log_ability_is_health
//th_log_ability_is_mana
//th_log_ability_is_action_points
//th_log_ability_is_critical
//th_log_ability_is_miss
//th_log_ability
//th_log_ability_for_current_instance

void CDanmakuDuelManager::GenerateEffectFile()
{
	std::string outputLine;
	int instance = 1;
	int action = 1;
	outputLine = "";
	for (int i = 1; i <= _instances; i++)
	{
		for (int a = 1; a <= _actions; a++)
		{
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_value value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_amount value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_result value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_enemy_ac value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_flat_bonus value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_bonus_per_roll value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_amount value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_result value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_bonus_per_roll value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_flat_bonus value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_resistance_reduction value = 0 }";
			outputLine += "\nset_variable = { which = th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_critical_damage_bonus value = 0 }";
		}
	}
	std::ofstream outfile(_effectOutputFolder + "\\" + _effectFile);
	outfile << outputLine;
	outfile.close();
}

////////////////////////////////////////////////////////////////////////
// Custom Loc Command
void CDanmakuDuelManager::CreateLocCommandGetRootCountryName(std::string& outputLine)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = GetDanmakuDuelRootCountryName";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_ROOT_LAND trigger = { th_is_duelling_an_unlanded_character = yes } }";
	for (int i = 1; i <= _instances; i++)
	{
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COUNTRY_ID_1_INSTANCE_" + std::to_string(i) + "_COUNTRY_NAME trigger = { th_is_danmaku_duel_global_event_target = { country_id = 1 instance = " + std::to_string(i) + " } } }";
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COUNTRY_ID_2_INSTANCE_" + std::to_string(i) + "_COUNTRY_NAME trigger = { th_is_danmaku_duel_global_event_target = { country_id = 2 instance = " + std::to_string(i) + " } } }";
	}
	outputLine += "\n}";
}

void CDanmakuDuelManager::CreateLocCommandGetActor(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetActor";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COMBAT_LOG_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ACTOR_COUNTRY_1 trigger = { th_combat_log_get_actor_id = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " actor = 1 } } }";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COMBAT_LOG_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ACTOR_COUNTRY_2 trigger = { th_combat_log_get_actor_id = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " actor = 2 } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetEffectVerb(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetEffectVerb";
	outputLine += "\n\trandom = no";
	for (std::string v : _combatVerbs)
	{
		std::string uppercase_v = v;
		for (auto& x : uppercase_v)
		{
			x = toupper(x);
		}
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_VERB_" + uppercase_v + " trigger = { th_combat_log_get_ability_verb = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " verb = " + v + " } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityArticle(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityArticle";
	outputLine += "\n\trandom = no";
	for (std::string v : _combatArticles)
	{
		std::string uppercase_v = v;
		for (auto& x : uppercase_v)
		{
			x = toupper(x);
		}
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_ARTICLE_" + uppercase_v + " trigger = { th_combat_log_get_ability_article = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " article = " + v + " } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbility(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbility";
	outputLine += "\n\trandom = no";
	for (std::string v : _combatAbilities)
	{
		outputLine += "\n\ttext = { localisation_key = th_ability_" + v + " trigger = { th_combat_log_get_ability_id = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " ability = " + v + " } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetPrePosition(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetPrePosition";
	outputLine += "\n\trandom = no";
	for (std::string v : _combatPrepositions)
	{
		std::string uppercase_v = v;
		for (auto& x : uppercase_v)
		{
			x = toupper(x);
		}
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_PREPOSITION_" + uppercase_v + " trigger = { th_combat_log_get_preposition = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " preposition = " + v + " } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetRecipient(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetRecipient";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COMBAT_LOG_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_RECIPIENT_COUNTRY_1 trigger = { th_combat_log_get_recipient_id = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " recipient = 1 } } }";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_DUEL_COMBAT_LOG_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_RECIPIENT_COUNTRY_2 trigger = { th_combat_log_get_recipient_id = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " recipient = 2 } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetHitRoll(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRoll";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_HIT_ROLL_TEXT trigger = { has_country_flag = th_danmaku_has_advanced_combat_log th_combat_log_get_hit_roll = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " hit_roll = yes } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityEffect(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffect";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_EFFECT_MISS trigger = { 	OR = { th_combat_log_get_ability_is_miss = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " is_miss = yes } th_combat_log_get_ability_effect = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " ability_effect = miss } } } }";
	for (std::string v : _combatAbilityEffect)
	{
		std::string uppercase_v = v;
		for (auto& x : uppercase_v)
		{
			x = toupper(x);
		}
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_EFFECT_" + uppercase_v + " trigger = { th_combat_log_get_ability_effect = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " ability_effect = " + v + " } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityEffectNumber(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffectNumber";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_NUMBER trigger = { th_combat_log_get_ability_impact_value = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " number_impact = yes } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetCritical(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetCritical";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_IS_CRITICAL trigger = { th_combat_log_get_ability_is_critical = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " is_critical = yes } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityRoll(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRoll";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_EFFECT_ROLL_TEXT trigger = { has_country_flag = th_danmaku_has_advanced_combat_log th_combat_log_get_ability_roll = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " ability_roll = yes } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilitySpecialEffect(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySpecialEffect";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityEffectEnd(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffectEnd";
	outputLine += "\n\trandom = no";
	for (std::string v : _combatAbilityEndeffect)
	{
		std::string uppercase_v = v;
		for (auto& x : uppercase_v)
		{
			x = toupper(x);
		}
		outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_ABILITY_EFFECT_END_" + uppercase_v + " trigger = { th_combat_log_get_ability_is_" + v + " = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " is_" + v + " = yes } } }";
	}
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilitySecondEffect(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffect";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilitySecondEffectAbility(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffectAbility";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilitySecondEffectEnd(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffectEnd";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetEndSentence(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetEndSentence";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_END_SENTENCE_END trigger = { th_check_actions_for_instance = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetHitBonusPerDice(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRollBonusPerDie";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_HIT_BONUS_PER_ROLL trigger = { th_combat_log_check_variable = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " type = hit_die_flat_bonus } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetHitFlatBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRollFlatBonus";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_FLAT_HIT_BONUS trigger = { th_combat_log_check_variable = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " type = hit_die_bonus_per_roll } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityBonusPerDice(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRollBonusPerDie";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_ABILITY_BONUS_PER_ROLL trigger = { th_combat_log_check_variable = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " type = attack_die_bonus_per_roll } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetAbilityFlatBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRollFlatBonus";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_FLAT_ABILITY_BONUS trigger = { th_combat_log_check_variable = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " type = attack_die_flat_bonus } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::CreateLocCommandGetCriticalBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\ndefined_text = {";
	outputLine += "\n\tname = ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetCriticalBonus";
	outputLine += "\n\trandom = no";
	outputLine += "\n\ttext = { localisation_key = TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_CRITICAL_BONUS trigger = { th_combat_log_get_ability_is_critical = { instance = " + std::to_string(i) + " action = " + std::to_string(a) + " is_critical = yes } } }";
	outputLine += "\n\ttext = { localisation_key = empty_text trigger = { always = yes } }";
	outputLine += "\n}";
}
void CDanmakuDuelManager::GenerateCustomLocalizationFile()
{
	std::string outputLine;
	int instance = 1;
	int action = 1;
	outputLine = "";
	CreateLocCommandGetRootCountryName(outputLine);
	for (int i = 1; i <= _instances; i++)
	{
		for (int a = 1; a <= _actions; a++)
		{
			CreateLocCommandGetActor(outputLine, i, a);
			CreateLocCommandGetEffectVerb(outputLine, i, a);
			CreateLocCommandGetAbilityArticle(outputLine, i, a);
			CreateLocCommandGetAbility(outputLine, i, a);
			CreateLocCommandGetPrePosition(outputLine, i, a);
			CreateLocCommandGetRecipient(outputLine, i, a);
			CreateLocCommandGetHitRoll(outputLine, i, a);
			CreateLocCommandGetAbilityEffect(outputLine, i, a);
			CreateLocCommandGetAbilityEffectNumber(outputLine, i, a);
			CreateLocCommandGetCritical(outputLine, i, a);
			CreateLocCommandGetAbilityRoll(outputLine, i, a);
			CreateLocCommandGetAbilitySpecialEffect(outputLine, i, a);
			CreateLocCommandGetAbilityEffectEnd(outputLine, i, a);
			CreateLocCommandGetAbilitySecondEffect(outputLine, i, a);
			CreateLocCommandGetAbilitySecondEffectAbility(outputLine, i, a);
			CreateLocCommandGetAbilitySecondEffectEnd(outputLine, i, a);
			CreateLocCommandGetEndSentence(outputLine, i, a);
			CreateLocCommandGetHitBonusPerDice(outputLine, i, a);
			CreateLocCommandGetHitFlatBonus(outputLine, i, a);
			CreateLocCommandGetAbilityBonusPerDice(outputLine, i, a);
			CreateLocCommandGetAbilityFlatBonus(outputLine, i, a);
			CreateLocCommandGetCriticalBonus(outputLine, i, a);
		}
	}
	std::ofstream outfile(_customLocalizationOutputFolder + "\\" + _customLocalizationFile);
	outfile << outputLine;
	outfile.close();
}

////////////////////////////////////////////////////////////////////////
// Scripted Triggers
void CDanmakuDuelManager::GenerateTriggerFile()
{
	std::string outputLine;
	int instance = 1;
	int action = 1;
	outputLine = "";
	for (int i = 1; i <= _instances; i++)
	{
		for (int a = 1; a <= _actions; a++)
		{
		}
	}
	std::ofstream outfile(_triggerOutputFolder + "\\" + _triggerFile);
	outfile << outputLine;
	outfile.close();
}

////////////////////////////////////////////////////////////////////////
// Localization
void CDanmakuDuelManager::CreateLocalizationCombatLogForInstance(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + ": \"";
	outputLine += "§Y[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetActor]§!";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetEffectVerb]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityArticle]";
	outputLine += "§Y[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbility]§!";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetPrePosition]";
	outputLine += "§Y[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetRecipient]§!";
	outputLine += "§g[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRoll]§!";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffect]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffectNumber]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetCritical]";
	outputLine += "§g[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRoll]§!";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySpecialEffect]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityEffectEnd]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffect]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffectAbility]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilitySecondEffectEnd]";
	outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetEndSentence]";
	outputLine += "\"";
}

void CDanmakuDuelManager::CreateLocalizationGetVariableValue(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_NUMBER: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_value.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableHitDie(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_HIT_DIE: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableHitDieAmount(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_HIT_DIE_AMOUNT: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_amount.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableHitDieResult(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_HIT_DIE_RESULT: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_result.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableEnemyAC(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ENEMY_AC: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_enemy_ac.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableHitDieFlatBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_HIT_DIE_FLAT_BONUS: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_flat_bonus.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableHitDieBonusPerRoll(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_HIT_DIE_BONUS_PER_ROLL: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_bonus_per_roll.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableAttackDie(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ATTACK_DIE: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableAttackDieAmount(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ATTACK_DIE_AMOUNT: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_amount.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableAttackDieResult(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ATTACK_DIE_RESULT: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_result.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableAttackDieBonusPerRoll(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ATTACK_DIE_BONUS_PER_ROLL: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_bonus_per_roll.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableAttackDieFlatbonus(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_ATTACK_DIE_FLAT_BONUS: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_flat_bonus.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetVariableResistanceReduction(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_RESISTANCE_REDUCTION: \"§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_resistance_reduction.GetValue]§!\"";
}

void CDanmakuDuelManager::CreateLocalizationGetHitRollText(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_HIT_ROLL_TEXT: \" ";
	outputLine += "(rolled §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_result.GetValue]§! ";
	outputLine += "(needed at least §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_enemy_ac.GetValue]§! to hit) ";
	outputLine += "with §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_amount.GetValue]";
	outputLine += "d[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die.GetValue]§!";
	outputLine += "[1.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRollBonusPerDie]";
	outputLine += "[1.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetHitRollFlatBonus])\"";
}
void CDanmakuDuelManager::CreateLocalizationGetAbilityRollText(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_EFFECT_ROLL_TEXT: \" ";
	outputLine += "(rolled §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_result.GetValue]§! ";
	outputLine += "with §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_amount.GetValue]";
	outputLine += "d[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die.GetValue]§!";
	outputLine += "[1.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRollBonusPerDie]";
	outputLine += "[1.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetAbilityRollFlatBonus]";
	outputLine += "[1.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "GetCriticalBonus]; ";
	outputLine += "§Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_resistance_reduction.GetValue]§! damage resisted)\"";
}
void CDanmakuDuelManager::CreateLocalizationGetHitBonusPerDice(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_HIT_BONUS_PER_ROLL: \" + additional §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_flat_bonus.GetValue]§! per dice\"";
}
void CDanmakuDuelManager::CreateLocalizationGetHitFlatBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_FLAT_HIT_BONUS: \" + flat bonus of §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_hit_die_bonus_per_roll.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetAbilityBonusPerDice(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_ABILITY_BONUS_PER_ROLL: \" + additional §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_bonus_per_roll.GetValue]§! per dice\"";
}
void CDanmakuDuelManager::CreateLocalizationGetAbilityFlatBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_FLAT_ABILITY_BONUS: \" + flat bonus of §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_attack_die_flat_bonus.GetValue]§!\"";
}
void CDanmakuDuelManager::CreateLocalizationGetCriticalBonus(std::string& outputLine, int i, int a)
{
	outputLine += "\n TH_DANMAKU_COMBAT_LOG_FOR_INSTANCE_" + std::to_string(i) + "_ACTION_" + std::to_string(a) + "_GET_CRITICAL_BONUS: \" * Critical Damage multiplicator of §Y[1.th_danmaku_duel_of_instance_" + std::to_string(i) + "_action_" + std::to_string(a) + "_critical_damage_bonus.GetValue]§!\"";
}


void CDanmakuDuelManager::GenerateLocalizationFile()
{
	std::string outputLine;
	int instance = 1;
	int action = 1;
	outputLine = "l_english:\n";
	for (int i = 1; i <= _instances; i++)
	{
		outputLine += " TH_DANMAKU_DUEL_COMBAT_LOG_RULER_FIGHT_INSTANCE_" + std::to_string(i) + ": \"";
		for (int a = 1; a <= _actions; a++)
		{
			outputLine += "[Root.ShowDanmakuCombatLogForInstance" + std::to_string(i) + "Action" + std::to_string(a) + "]";
		}
		outputLine += "\"\n";
	}
	for (int i = 1; i <= _instances; i++)
	{
		for (int a = 1; a <= _actions; a++)
		{
			CreateLocalizationCombatLogForInstance(outputLine, i, a);
			CreateLocalizationGetVariableValue(outputLine, i, a);
			CreateLocalizationGetVariableHitDie(outputLine, i, a);
			CreateLocalizationGetVariableHitDieAmount(outputLine, i, a);
			CreateLocalizationGetVariableHitDieResult(outputLine, i, a);
			CreateLocalizationGetVariableEnemyAC(outputLine, i, a);
			CreateLocalizationGetVariableHitDieFlatBonus(outputLine, i, a);
			CreateLocalizationGetVariableHitDieBonusPerRoll(outputLine, i, a);
			CreateLocalizationGetVariableAttackDie(outputLine, i, a);
			CreateLocalizationGetVariableAttackDieAmount(outputLine, i, a);
			CreateLocalizationGetVariableAttackDieResult(outputLine, i, a);
			CreateLocalizationGetVariableAttackDieBonusPerRoll(outputLine, i, a);
			CreateLocalizationGetVariableAttackDieFlatbonus(outputLine, i, a);
			CreateLocalizationGetHitRollText(outputLine, i, a);
			CreateLocalizationGetAbilityRollText(outputLine, i, a);
			CreateLocalizationGetHitBonusPerDice(outputLine, i, a);
			CreateLocalizationGetHitFlatBonus(outputLine, i, a);
			CreateLocalizationGetAbilityBonusPerDice(outputLine, i, a);
			CreateLocalizationGetAbilityFlatBonus(outputLine, i, a);
			CreateLocalizationGetCriticalBonus(outputLine, i, a);
		}
		outputLine += "\n";
	}
	std::ofstream outfile(_localizationOutputFolder + "\\" + _localizationFile);
	outfile << outputLine;
	outfile.close();
}