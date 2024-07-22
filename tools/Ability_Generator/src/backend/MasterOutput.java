package backend;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import frontEnd.SecondGui;

public class MasterOutput {
 public static void outputsound(JPanel[] Sound) {
	 String[] v = {"launch","hit","crit"};
	 String LocalDirectoy = "/sound/th_danmaku_duel_sounds.asset";
	 try {
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
		int x = 0;
		for (JPanel a : Sound) {
			JPanel holder2 = (JPanel) a.getComponent(0);
			JPanel holder21 = (JPanel)holder2.getComponent(0);
			JTextField holder22 = (JTextField)holder21.getComponent(1);
			File b = new File (holder22.getText());
			 try {Files.copy( b.toPath(),  new File (SecondGui.DirectoryPath.concat("/sound/danmaku_duel/"+b.getName())).toPath(), StandardCopyOption.COPY_ATTRIBUTES);
			 } catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			 JPanel holder31 = (JPanel) a.getComponent(1);
			JPanel holder32 = (JPanel)holder31.getComponent(0);
			JCheckBox holder3 = (JCheckBox) holder32.getComponent(1);
			JPanel holder41 = (JPanel) a.getComponent(1);
			JPanel holder42 = (JPanel)holder41.getComponent(1);
			JSpinner holder4 = (JSpinner) holder42.getComponent(1);
			out.println("\nsound = {\n"
				+ "	name = th_danmaku_duel_ability_"+SecondGui.name2.toLowerCase()+"_"+v[x]+"\n"+
				"	file = \"danmaku_duel/"+b.getName()+"\"");
		if(holder3.isSelected()) {
			out.println("	always_load = yes");
		}else {
			out.println("	always_load = no");	
		}
		out.println("	volume = "+holder4.getValue()+"\n}");
		x++;
		
	}
		out.close();
	 } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 
 }
 public static void icon(JPanel Icon) {
	 String LocalDirectoy = "/gfx/interface/danmaku/abilities";
	 JTextField holder2 = (JTextField)Icon.getComponent(1);
	 File b = new File (holder2.getText());
	 //copy paste file to gfx/interface/danmaku/abilities
	 try {
		Files.copy( new File (holder2.getText()).toPath(),  new File (SecondGui.DirectoryPath.concat(LocalDirectoy+"/"+b.getName())).toPath(), StandardCopyOption.COPY_ATTRIBUTES);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
 }

 public static void AbilitySlotThing(JPanel[] Ability) {
	 JSpinner holder2 = (JSpinner)Ability[0].getComponent(1);
	 try {
		 String LocalDirectoy = "/common/custom_gui/th_danmaku_gui.txt";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
		 out.println("\n	custom_button = {\n"+ 
						"		name = th_danmaku_battle_window_ability_"+holder2.getValue()+"\r\n"+
						"		tooltip = th_danmaku_battle_window_ability_"+SecondGui.name2.toLowerCase()+"_desc\r\n"+
						"		potential = { always = yes }\r\n"
						+ "		trigger = {\r\n"
						+ "			th_danmaku_duel_is_active = yes\r\n"
						+ "			th_gui_can_press_danmaku_buttons = yes\r\n"
						+ "			th_can_use_ability = { ability = "+SecondGui.name2.toLowerCase()+" }\r\n"+
						"		}\r\n"
						+ "		effect = {\r\n"
						+ "			th_use_ability = {\r\n"
						+ "				ability = "+SecondGui.name2.toLowerCase()+"	}\r\n"
								+ "		}\r\n"
								+ "	}"
			 ); 
		 out.close();
	 }catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void LocWriterThing(JPanel[] AbilityName) {
	 try {
		 String LocalDirectoy = "/localisation/touhou_danmaku_l_english.yml";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
	 JTextArea a  = (JTextArea)AbilityName[1].getComponent(1);
	 out.println("\n th_danmaku_battle_window_ability_"+SecondGui.name2+"_desc: \"§Y[Root.GetAbilityName_"+SecondGui.name2+"]§!\\n[Root.GetAbilityDesc_"+SecondGui.name2+"]\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+": \""+SecondGui.name+"\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_desc: \""+a.getText()+"\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_cost: \"\\n\\nCosts:[Root.GetAbilityCostAP_"+SecondGui.name2+"][Root.GetAbilityCostMP_"+SecondGui.name2+"][Root.GetAbilityCostHP_"+SecondGui.name2+"]\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_ap_override_cost_tt: \"\\n§TAction Points§!: §Y[Root.th_ability_"+SecondGui.name2.toLowerCase()+"_ap_cost_override.GetValue]§!\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_ap_default_cost_tt: \"\\n§TAction Points§!: §Y[1.th_ability_"+SecondGui.name2.toLowerCase()+"_ap_cost.GetValue]§!\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_mp_override_cost_tt: \"\\n§TMana§!: §Y[Root.th_ability_"+SecondGui.name2.toLowerCase()+"_mp_cost_override.GetValue]§!\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_mp_default_cost_tt: \"\\n§TMana§!: §Y[1.th_ability_"+SecondGui.name2.toLowerCase()+"_mp_cost.GetValue]§!\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_hp_override_cost_tt: \"\\n§THealth§!: §Y[Root.th_ability_"+SecondGui.name2.toLowerCase()+"_hp_cost_override.GetValue]§!\""
			 );
	 out.println(" th_ability_"+SecondGui.name2.toLowerCase()+"_hp_default_cost_tt: \"\\n§THealth§!: §Y[1.th_ability_"+SecondGui.name2.toLowerCase()+"_hp_cost.GetValue]§!\""
			 );
	 out.close();
	 }catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void LocCustomWriterThing() {
	 try {
		 String LocalDirectoy = "/customizable_localization/th_danmaku_ability_locs.txt";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
		 out.println("\ndefined_text = {\r\n"
	 		+ "	name = GetAbilityName_"+SecondGui.name2+"\r\n"
	 		+ "	text = { localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+" }\r\n"
	 		+ "}\r\n"
	 		);
		 out.println("defined_text = {\r\n"
		 		+ "	name = GetAbilityDesc_"+SecondGui.name2+"\r\n"
		 		+ "	text = { localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_desc }\r\n"
		 		+ "}\r\n"
		 		);
	 	 out.println("defined_text = {\r\n"
		 		+ "	name = GetAbilityCost_"+SecondGui.name2+"\r\n"
		 		+"	random = no\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_cost\r\n"
		 		+"		trigger = { th_ability_has_any_cost = { ability = "+SecondGui.name2.toLowerCase()+" } }"
		 		+" }\r\n"
		 		+"	text = {\r\n"
		 		+ "		localisation_key = empty_text\r\n"
		 		+ "		trigger = { always = yes }\r\n"
		 		+ "	}\r\n"
		 		+ "}\r\n"
		 		);
	 	out.println("defined_text = {\r\n"
		 		+ "	name = GetAbilityCostAP_"+SecondGui.name2+"\r\n"
		 		+"	random = no\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_ap_override_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = override ability = "+SecondGui.name2.toLowerCase()+" type = ap } }"
		 		+" }\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_ap_default_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = default ability = "+SecondGui.name2.toLowerCase()+" type = ap } }"
		 		+" }\r\n"
		 		+"	text = {\r\n"
		 		+ "		localisation_key = empty_text\r\n"
		 		+ "		trigger = { always = yes }\r\n"
		 		+ "	}\r\n"
		 		+ "}\r\n"
		 		);
	 	out.println("defined_text = {\r\n"
		 		+ "	name = GetAbilityCostMP_"+SecondGui.name2+"\r\n"
		 		+"	random = no\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_mp_override_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = override ability = "+SecondGui.name2.toLowerCase()+" type = mp } }"
		 		+" }\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_mp_default_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = default ability = "+SecondGui.name2.toLowerCase()+" type = mp } }"
		 		+" }\r\n"
		 		+"	text = {\r\n"
		 		+ "		localisation_key = empty_text\r\n"
		 		+ "		trigger = { always = yes }\r\n"
		 		+ "	}\r\n"
		 		+ "}\r\n"
		 		);
	 	out.println("defined_text = {\r\n"
		 		+ "	name = GetAbilityCostHP_"+SecondGui.name2+"\r\n"
		 		+"	random = no\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_hp_override_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = override ability = "+SecondGui.name2.toLowerCase()+" type = hp } }"
		 		+" }\r\n"
		 		+ "	text = {\r\n		localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+"_hp_default_cost_tt\r\n"
		 		+"		trigger = { th_ability_has_any_cost = {  mode = default ability = "+SecondGui.name2.toLowerCase()+" type = hp } }"
		 		+" }\r\n"
		 		+"	text = {\r\n"
		 		+ "		localisation_key = empty_text\r\n"
		 		+ "		trigger = { always = yes }\r\n"
		 		+ "	}\r\n"
		 		+ "}\r\n"
		 		);
	 	out.close();
	 }catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void LocCustomWriterThingForLogs() {
	 try {
		 String LocalDirectoy = "/customizable_localization/th_generated_danmaku_locs.txt";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
	 for(int i = 1; i<11; i++) {
		 out.println(
				 "\ndefined_text = {\r\n"
				 + "	name = ShowDanmakuCombatLogAction"+i+"GetAbility\r\n"
				 + "	random = no\r\n"
				 + "	text = { localisation_key = th_ability_attack trigger = { th_combat_log_get_ability_id = { action = "+i+" ability = attack } } }\r\n"
				 + "	text = { localisation_key = th_ability_"+SecondGui.name2.toLowerCase()+" trigger = { th_combat_log_get_ability_id = { action = "+i+" ability = "+SecondGui.name2.toLowerCase()+" } } }\r\n"
				 + "	text = { localisation_key = empty_text trigger = { always = yes } }\r\n"
				 + "}"
				 
				 );
		
	 } out.close();
	 }catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void iconpart2(JPanel Icon) {
	 JTextField a  = (JTextField)Icon.getComponent(1);
	 try {
	 String LocalDirectoy = "/interface/countrydanmakuview_touhou.gfx";
	 File file = new File(SecondGui.DirectoryPath.concat(LocalDirectoy));
		BufferedReader read = new BufferedReader(new FileReader(file));	
		String[] out = read.lines().toArray(String[]::new);
		ArrayList<String> out2  = new ArrayList<>(Arrays.asList(out));
		int holder =0;
		read.close();
		try {
			for (int i = out.length-1; i>0; i--) {
			if(out[i].indexOf('}')!=-1) {
			holder = i;
			i=-1;
			}
			}
		}catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		File f  = new File(a.getText());
		out2.add(holder,
			 "	spriteType = {\r\n"
			 + "		name = \"GFX_danmaku_ability_"+SecondGui.name2.toLowerCase()+"\"\r\n"
			 + "		texturefile = \"gfx////interface////danmaku//abilities////"+f.getName()+"\"\r\n"
			 + "	}"
			 
			 );
		FileWriter b = new FileWriter(file);
		for (String string : out2) {
			b.write(string+"\n");
		}
		b.close();
	 }catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void slotMakerThing(JPanel Icon) {
	 JSpinner holder4 = (JSpinner) Icon.getComponent(1);
	 try {
		 String LocalDirectoy = "/interface/topbar.gui";
		 File file = new File(SecondGui.DirectoryPath.concat(LocalDirectoy));
			BufferedReader read = new BufferedReader(new FileReader(file));	
			String[] out = read.lines().toArray(String[]::new);
			ArrayList<String> out2  = new ArrayList<>(Arrays.asList(out));
			read.close();
			int holder =0;
			try {
				for (int i = out.length-1; i>0; i--) {
				if(out[i].indexOf("th_danmaku_battle_window_ability_end_turn")!=-1) {
				holder = i-1;
				i = -1;
				}
				}
			}catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			out2.add(holder,
			 "				guiButtonType = {\r\n"
			 + "				name = \"th_danmaku_battle_window_ability_"+((int)holder4.getValue()-1)+"\"\r\n"
			 + "				quadTextureSprite = \"GFX_danmaku_ability_"+SecondGui.name2.toLowerCase()+"\"\r\n"
			 + "				position = { x = "+(((int)holder4.getValue()-1)*86+40)+" y = 500 }\r\n"
			 + "				buttonFont = \"Main_14\"\r\n"
			 + "				Orientation = \"UPPER_LEFT\"\r\n"
			 + "				scripted = yes\r\n"
			 + "			}"
			 
			 );
			FileWriter b = new FileWriter(file);
			for (String string : out2) {
				b.write(string+"\n");
			}
			b.close();
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void TouhouEventThing() {
	 try {
		 String LocalDirectoy = "/events/ThDanmakuDuel.txt";
		 File file = new File(SecondGui.DirectoryPath.concat(LocalDirectoy));
			BufferedReader read = new BufferedReader(new FileReader(file));	
			String[] out = read.lines().toArray(String[]::new);
			ArrayList<String> out2  = new ArrayList<>(Arrays.asList(out));
			int holder =0;
			try {
				for (int i = out.length-1; i>0; i--) {
				if(out[i].indexOf("id = th_danmaku_duel_ai.3")!=-1) {
				holder = i+7;
				i=-1;
				}
				}
			}catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			out2.add(holder,
			 "		#"+SecondGui.name+" option\r\n"
			 + "	option = {\r\n"
			 + "		trigger = {\r\n"
			 + "			OR = {\r\n"
			 + "				AND = {\r\n"
			 + "					th_is_duelling_an_unlanded_character = yes\r\n"
			 + "					th_unlanded_character_has_turn_ownership = yes\r\n"
			 + "					th_is_alive_solo = yes\r\n"
			 + "					th_ai_can_use_ability = { ability = "+SecondGui.name2.toLowerCase()+" }\r\n"
			 + "				}\r\n"
			 + "				AND = {\r\n"
			 + "					th_is_not_duelling_an_unlanded_character = yes\r\n"
			 + "					th_has_turn_ownership = yes\r\n"
			 + "					th_is_alive = yes\r\n"
			 + "					th_can_use_ability = { ability = "+SecondGui.name2.toLowerCase()+" }\r\n"
			 + "				}\r\n"
			 + "			}\r\n"
			 + "		}\r\n"
			 + "		th_use_ability = {\r\n"
			 + "			ability = "+SecondGui.name2.toLowerCase()+"\r\n"
			 + "		}\r\n"
			 + "		country_event = {\r\n"
			 + "			id = th_danmaku_duel_ai.2\r\n"
			 + "			days = 1\r\n"
			 + "		}\r\n"
			 + "		ai_chance = {\r\n"
			 + "			factor = 100\r\n"
			 + "		}\r\n"
			 + "	}"
			 );
			FileWriter b = new FileWriter(file);
			for (String string : out2) {
				b.write(string+"\n");
			}
			b.close();
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void BigEffectLookingThing(JPanel[] a,JPanel[] b) {
	 JSpinner ap = (JSpinner)a[3].getComponent(1);
	 JSpinner m = (JSpinner)a[2].getComponent(1);
	 JComboBox<String> t = (JComboBox<String>)a[4].getComponent(1);
	 JComboBox<String> d = (JComboBox<String>)a[5].getComponent(1);
	 JSpinner dx = (JSpinner)a[6].getComponent(1);
	 JSpinner xd = (JSpinner)a[7].getComponent(1);
	 JSpinner mo = (JSpinner)a[8].getComponent(1);
	 JComboBox<String> t2 = (JComboBox<String>)b[0].getComponent(1);
	 JComboBox<String> v = (JComboBox<String>)b[1].getComponent(1);
	 JComboBox<String> ar = (JComboBox<String>)b[2].getComponent(1);
	 JComboBox<String> p = (JComboBox<String>)b[3].getComponent(1);
	 JComboBox<String> ae = (JComboBox<String>)b[4].getComponent(1);
	 JCheckBox i = (JCheckBox)b[5].getComponent(1);
	 JCheckBox da = (JCheckBox)b[6].getComponent(1);
	 JCheckBox hp = (JCheckBox)b[7].getComponent(1);
	 JCheckBox mp = (JCheckBox)b[8].getComponent(1);
	 JCheckBox ap2 = (JCheckBox)b[9].getComponent(1);
	 JCheckBox hr = (JCheckBox)b[10].getComponent(1);
	 JCheckBox ar2 = (JCheckBox)b[11].getComponent(1);
	 try {
		 String LocalDirectoy = "/common/scripted_effects/th_scripted_effects_for_danmaku_fight_data_base.txt";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
	 out.println(
			 		"\nth_use_ability_"+SecondGui.name2.toLowerCase()+" = {\r\n"
			 	+ "	th_change_combat_resource_ability = { ability = "+SecondGui.name2.toLowerCase()+" type = action_points value = "+ap.getValue()+" }\r\n"
			 	+ "	th_change_combat_resource_ability = { ability = "+SecondGui.name2.toLowerCase()+" type = mana value = "+m.getValue()+" }\r\n"
			 	+ "	th_perform_attack = {\r\n"
			 	+ "		ability = "+SecondGui.name2.toLowerCase()+"\r\n"
			 	+ "		override_damage_type = "+t.getSelectedItem()+"\r\n"
			 	+ "		override_damage_school = "+d.getSelectedItem()+"\r\n"
			 	+ "		override_damage_die = "+dx.getValue()+"\r\n"
			 	+ "		override_damage_die_amount = "+xd.getValue()+"\r\n"
			 	+ "		override_damage_flat_bonus = "+mo.getValue()+"\r\n"
			 	+ "	}\r\n"
			 	+ "	th_create_ability_combat_log = {\r\n"
			 	+ "		type = "+t2.getSelectedItem()+"\r\n"
			 	+ "		verb = "+v.getSelectedItem()+"\r\n"
			 	+ "		article = "+ar.getSelectedItem()+"\r\n"
			 	+ "		ability = "+SecondGui.name2.toLowerCase()+"\r\n"
			 	+ "		preposition = "+p.getSelectedItem()+"\r\n"
			 	+ "		ability_effect = "+ae.getSelectedItem()+"\r\n"
			 	+ "		number_impact = "+i.isSelected()+"\r\n"
			 	+ "		is_damage = "+da.isSelected()+"\r\n"
			 	+ "		is_health = "+hp.isSelected()+"\r\n"
			 	+ "		is_mana = "+mp.isSelected()+"\r\n"
			 	+ "		is_action_points = "+ap2.isSelected()+"\r\n"
			 	+ "		hit_roll = "+hr.isSelected()+"\r\n"
			 	+ "		ability_roll = "+ar2.isSelected()+"\r\n"
			 	+ "	}\r\n"
			 	+ "}"	 
			 );
	 out.close();
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 }
 public static void SmallEffectLookingThing(JPanel[] a) {
	 try {
		 String LocalDirectoy = "/common/scripted_effects/th_scripted_effects_for_danmaku_fight_log.txt";
		 PrintWriter out =FileShenanigans.maker(LocalDirectoy);
	 JSpinner ap = (JSpinner)a[0].getComponent(1);
	 out.println("\nth_log_ability_name_"+SecondGui.name2.toLowerCase()+" = {	set_variable = { which = th_danmaku_duel_action_$action$_ability_name	value = "+ap.getValue()+" }	}");
	 out.close();
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
 public static void SmallTriggerLookingThing(JPanel[] a) {
	 try {
		 String LocalDirectoy = "/common/scripted_triggers/th_scripted_triggers_for_danmaku_fight.txt";
		 PrintWriter out3 =FileShenanigans.maker(LocalDirectoy);
	 JSpinner s = (JSpinner)a[0].getComponent(1);
	 JSpinner ap = (JSpinner)a[3].getComponent(1);
	 JSpinner m = (JSpinner)a[2].getComponent(1);
	 JComboBox<String> c = ( JComboBox<String>)a[9].getComponent(1);
	 out3.println("\nth_combat_log_get_ability_id_"+SecondGui.name2.toLowerCase()+" = { 		is_variable_equal = { which = th_danmaku_duel_action_$action$_ability_name value = "+s.getValue()+" } }");
	 out3.println(
			 "th_can_use_ability_"+SecondGui.name2.toLowerCase()+" = {\r\n"
			 + "	th_$type$_combat_check_combat_resources_available = { type = action_points value = "+ap.getValue()+" }\r\n"
			 + "	th_$type$_combat_check_combat_resources_available = { type = mana value = "+m.getValue()+" }\r\n"
			 + "	th_$type$_is_danmaku_class = { class = "+c.getSelectedItem()+" }\r\n"
			 + "}"
			 
			 );
	 out3.close();
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 try {
		 String LocalDirectoy = "/common/scripted_triggers/th_scripted_triggers_for_danmaku_fight.txt";
		 File file = new File(SecondGui.DirectoryPath.concat(LocalDirectoy));
			BufferedReader read = new BufferedReader(new FileReader(file));	
			String[] out = read.lines().toArray(String[]::new);
			ArrayList<String> out2  = new ArrayList<>(Arrays.asList(out));
			int holder =0;
			try {
				for (int i = out.length-1; i>0; i--) {
				if(out[i].indexOf("\n		th_ai_can_use_any_ability = {")!=-1) {
				holder = i+2;
				i=-1;
				}
				}
			}catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			out2.add(holder,"\nth_ai_can_use_ability = { ability = "+SecondGui.name2.toLowerCase()+" }");
			FileWriter b = new FileWriter(file);
			for (String string : out2) {
				b.write(string+"\n");
			}
			b.close(); 
	 }catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
 }
