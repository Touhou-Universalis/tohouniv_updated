package frontEnd;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Iterator;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;

import backend.FileShenanigans;
import backend.MasterOutput;

public class SecondGui implements ActionListener {
	 	JFrame frame;
		Container contentPane;
		public static String DirectoryPath;
		public static String name;
			public static JPanel GnSnLPage = new JPanel();
			public static JPanel[] Sound = new JPanel[3];
			public static JPanel[] AbilityName = new JPanel[3];
			public static JPanel[] AbilityStuff = new JPanel[10];
			public static JPanel[] BooleanStuff = new JPanel[12];
			public static JPanel Taskbar= new JPanel();
		/* Splitting the files up into catagories
		3  Graphics and Sound  .common/custom_gui/th_danmaku_gui.txt*.,
		2  Interface *interface/topbar.gui*,
		3  Scripting 1 *events/ThDanmakuDuel.txt*,*common/scripted_effects/th_scripted_effects_for_danmaku_fight_data_base.txt*,*common/scripted_effects/th_scripted_effects_for_danmaku_fight_log.txt*,
		1 Scripting 2 *common/scripted_triggers/th_scripted_triggers_for_danmaku_fight.txt*
		   
		This will be worked on further as it gets developed 
		  
		 */
		public JPanel StandardStart(String a) {
			JPanel b = new JPanel();
			b.setLayout(new GridLayout(1,4));
			b.add(new JLabel(a));
			return b;
		}
		public JPanel CreateTextThing (String a){
			JPanel b = new JPanel();
			b.setLayout(new BorderLayout());
			b.add(new JLabel(a),BorderLayout.WEST);
			JTextField c = new JTextField();
			b.add(c,BorderLayout.CENTER);
			return b;
		}
		public JPanel CreateBigTextThing (String a){
			JPanel b = new JPanel();
			b.setLayout(new BorderLayout());
			b.add(new JLabel(a),BorderLayout.WEST);
			JTextArea c = new JTextArea();
			c.setLineWrap(true);
			b.add(c,BorderLayout.CENTER);
			return b;
		}
		public JPanel CreateBooleanThing (String a){
			JPanel b = StandardStart(a);
			JCheckBox c = new JCheckBox();
			c.setEnabled(true);
			b.add(c);
			return b;
		}
		public JPanel CreateBooleanThing (String a,Boolean aasdf){
			JPanel b = StandardStart(a);
			JCheckBox c = new JCheckBox();
			c.setSelected(aasdf);
			b.add(c);
			return b;
		}
		public JPanel CreateIntThing (String a){
			JPanel b = StandardStart(a);
			JSpinner c = new JSpinner();
			c.setValue(10);
			b.add(c);
			return b;
		}
		public JPanel CreateIntThing (String a,int e){
			JPanel b = StandardStart(a);
			JSpinner c = new JSpinner();
			c.setValue(e);
			b.add(c);
			return b;
		}
		public JPanel CreateIntThing (String a,double e){
			JPanel b = StandardStart(a);
			JSpinner c = new JSpinner();
			c.setValue(10);
			SpinnerNumberModel d = new SpinnerNumberModel(e, 0, 1, 0.01);
			c.setModel(d);
			c.setMinimumSize(new Dimension(353, 0));
			b.add(c);
			b.setMinimumSize(new Dimension(353, 0));
			return b;
		}
		public JPanel CreateSoundBlock (String a){
			JPanel b = new JPanel();
			b.setLayout(new BorderLayout());
			JPanel e = new JPanel();
			e.setLayout(new GridLayout(1,1));
			e.add(CreateFileThing("Sound "+a));
			b.add(e,BorderLayout.CENTER);
			JPanel d = new JPanel();
			d.setLayout(new GridLayout(1,2));
			d.add(CreateBooleanThing("Load",true));
			d.add(CreateIntThing("Vol",0.45));
			d.setPreferredSize (new Dimension(180, 0));
			b.add(d,BorderLayout.EAST);
			return b;
		}
		public JPanel CreateFileThing (String a) {
			JPanel b = new JPanel();
			b.setLayout(new BorderLayout());
			JButton d = new JButton(a);
			d.setPreferredSize(new Dimension(125, 0));
			d.addActionListener(this);
			b.add(d,BorderLayout.WEST);
			JTextField c = new JTextField();
			b.add(c,BorderLayout.CENTER);
			return b;
		}
		
		public static void main(String args[]) { // this is only for testing
			SecondGui guiLayout = new SecondGui();
			guiLayout.start();
		}
		public void miningAway(int i) {
			JPanel c = (JPanel)Sound[i].getComponent(0);
			JPanel b = (JPanel)c.getComponent(0);
			JTextField d = (JTextField)b.getComponent(1);
			String holder = FileShenanigans.Filechoicething(contentPane);
			if(holder.length()>0) {
				d.setText(holder);
			}
		}
		public void actionPerformed(ActionEvent e) throws RuntimeException {
			try {System.out.println(e.getActionCommand());
			switch (e.getActionCommand()){
				case "Icon": {
					JTextField b = (JTextField)AbilityName[2].getComponent(1);
					String holder = FileShenanigans.Filechoicething(contentPane);
					if(holder.length()>0) {
						b.setText(holder);
					}
				}
				break;
				case "Sound Crit: ": {
					miningAway(2);
				}
				break;
				case "Sound Hit:": {
					miningAway(1);
				}
				break;
				case "Sound Launch:": {
					miningAway(0);
				}
				break;
				case "Desc":{
					TempLayer3 guiLayout2 = new TempLayer3();
					guiLayout2.start();	
				}
				break;
				case "Output": {
					GetNameThing();
					MasterOutput.outputsound(Sound);
					MasterOutput.icon(AbilityName[2]);
					MasterOutput.AbilitySlotThing(AbilityStuff);
					MasterOutput.LocWriterThing(AbilityName);
					MasterOutput.LocCustomWriterThing();
					MasterOutput.LocCustomWriterThingForLogs();
					MasterOutput.iconpart2(AbilityName[2]);
					MasterOutput.slotMakerThing(AbilityStuff[0]);
					MasterOutput.TouhouEventThing();
					MasterOutput.BigEffectLookingThing(AbilityStuff,BooleanStuff);
					MasterOutput.SmallEffectLookingThing(AbilityStuff);
					MasterOutput.SmallTriggerLookingThing(AbilityStuff);
				}
				break;
				default:
					throw new IllegalArgumentException("Unexpected value: " + e.getActionCommand());
				}
		}catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} 
			}
		public void ResetBigSound() {
			String[] a = {"Launch:", "Hit:", "Crit: "};
			for (int i = 0; i < a.length; i++) {
				Sound[i] = CreateSoundBlock(a[i]);
			}
		}
		public static String name2;
		public void GetNameThing() {
			JTextField a  = (JTextField)AbilityName[0].getComponent(1);
			name = a.getText();
			String holder = name;
			for(int i = 0; i<holder.length(); i++) {
				if(Character.isSpaceChar(holder.charAt(i))) {
					holder = holder.replace(holder.charAt(i), '_');
				}
			}
			name2=holder;
		}
		public void ResetLocName() {
			for (int i = 0; i < AbilityName.length; i++) {
				AbilityName[i] = new JPanel();
				AbilityName[i].setLayout(new BorderLayout());
			}
			AbilityName[0] = CreateTextThing("Name");
			AbilityName[1] = BigTextButtonThing("Desc");
			AbilityName[2] = CreateFileThing("Icon");
			
		}
		public JPanel BigTextButtonThing(String a) {
			JPanel b = new JPanel();
			b.setLayout(new BorderLayout());
			JButton d = new JButton(a);
			d.addActionListener(this);
			b.add(d,BorderLayout.WEST);
			JTextArea c = new JTextArea();
			c.setWrapStyleWord(true);
			b.add(c,BorderLayout.CENTER);
			return b;
		}
		public void LocCostPreset() {
			String[] a = {"\n§TAction Points§!: §Y[Root.th_ability_", "\n§TAction Points§!: §Y[1.th_ability_", "\n§TMana§!: §Y[Root.th_ability_","\n§TMana§!: §Y[1.th_ability_", "\n§THealth§!: §Y[Root.th_ability_", "\n§THealth§!: §Y[1.th_ability_"};
			String[] e = {"_ap_cost_override.GetValue]§!\"", "_ap_cost.GetValue]§!", "_mp_cost_override.GetValue]§!","_mp_cost.GetValue]§!", "_hp_cost_override.GetValue]§!", "_hp_cost.GetValue]§!"};
			for (int i = 0; i < a.length; i++) {
				JTextField c = (JTextField)AbilityName[i].getComponent(1);
				String d = c.getText();
				// a[i]+d+e[i]; // TODO use this method for printing
			}
		}
		public void LocNamePreset() {
			JTextField b = (JTextField)AbilityName[2].getComponent(1);
			JTextField c = (JTextField)AbilityName[0].getComponent(1);
			String a = c.getText();
			b.setText("\n\nCosts:[Root.GetAbilityCostAP_"+a+"][Root.GetAbilityCostMP_"+a+"][Root.GetAbilityCostHP_"+a+"]");
		}
		public void ResetAbilityMakerThing() {
			String[] a = {"Slot","HpCost", "MpCost", "ApCost"};
			int[] a2 = {1,0,0, 0};
			for (int i = 0; i < a.length; i++) {
				AbilityStuff[i] = CreateIntThing(a[i],a2[i]);
			}
			String[] b = {"Psionic", "Magical", "Physical"};
			AbilityStuff[4]=CreateComboBoxThing("Damage Type", b);
			String[] b2 = {"Infernal","Arcane","Necrotic","Shadow","Holy","Nature","Lightning","Earth","Frost","Fire","Slashing", "Piercing", "Bludgeoning"};
			AbilityStuff[5]=CreateComboBoxThing("Damage School", b2);
			String[] c = {"Die", "Amount", "Mod"};
			for (int i = 0; i < c.length; i++) {
				AbilityStuff[i+6] = CreateIntThing(c[i],10);
			}
			String[] d = {"Mage", "Warrior", "NULL"};
			AbilityStuff[9]=CreateComboBoxThing("class", d);
			
		}
		public void ResetAbilityLogMakerThing() {
			String[] b = {"Current_recipient","NULL"};
			BooleanStuff[0]=CreateComboBoxThing("Type", b);
			String[] b2 = {"Casts","NULL"};
			BooleanStuff[1]=CreateComboBoxThing("Verb", b2);
			String[] b3 = {"NULL"};
			BooleanStuff[2]=CreateComboBoxThing("Article", b3);
			String[] b4 = {"Against","NULL"};
			BooleanStuff[3]=CreateComboBoxThing("Preposition", b4);
			String[] b5 = {"Dealing","NULL"};
			BooleanStuff[4]=CreateComboBoxThing("Ability effect", b5);
			BooleanStuff[5]=CreateBooleanThing("number impact", false);
			BooleanStuff[6]=CreateBooleanThing("Damage", true);
			BooleanStuff[7]=CreateBooleanThing("Health", false);
			BooleanStuff[8]=CreateBooleanThing("Mana", false);
			BooleanStuff[9]=CreateBooleanThing("AP", false);
			BooleanStuff[10]=CreateBooleanThing("Hit Roll", true);
			BooleanStuff[11]=CreateBooleanThing("Ability Roll", true);
		}
		public JPanel CreateComboBoxThing(String a,String[]d) {
			JPanel b = StandardStart(a);
			JComboBox<String> c = new JComboBox<String>(d);
			b.add(c);
			return b;
		}
		public void CreatGSLPageThing() {
			GnSnLPage.removeAll();
			ResetBigSound();
			ResetLocName();
		//	LocCostPreset();
			GnSnLPage.setLayout(new GridLayout(8,1));
			JPanel c = new JPanel();
			
			for (JPanel jPanel : Sound) {
				GnSnLPage.add(jPanel);
			}
			
			JPanel d = new JPanel();
			d.setLayout(new GridLayout(1,10));
			GnSnLPage.add(d);
			JPanel e = new JPanel();
			e.setLayout(new GridLayout(1,5));
			for (JPanel jPanel : AbilityName) {
				e.add(jPanel);
			}
			GnSnLPage.add(e);
			
			System.out.println(GnSnLPage.getComponentCount());
			ResetAbilityMakerThing();
			ResetAbilityLogMakerThing();
			JPanel f = new JPanel();
			for (JPanel jPanel : AbilityStuff) {
				f.add(jPanel);
			}
			GnSnLPage.add(f);
			JPanel g = new JPanel();
			for (JPanel jPanel : BooleanStuff) {
				g.add(jPanel);
			}
			GnSnLPage.add(g);
			contentPane.add(GnSnLPage,BorderLayout.CENTER);
			frame.setVisible(true);
		}
		
		public JButton CreateButtons(String a) {
			JButton asdf = new JButton(a);
			asdf.setName(a);
			asdf.addActionListener(this);
			return asdf;
		}
		
		public void CreateTaskBar() {
			contentPane.setLayout(new BorderLayout());
			Taskbar.add(CreateButtons("Output"));
		}
		public void DrawTaskbar() {
			contentPane.removeAll();
			contentPane.setLayout(new BorderLayout());
			contentPane.add(Taskbar,BorderLayout.SOUTH);
			frame.setVisible(true);
		}
		public void start() {
			frame = new JFrame("Big Editor");
			frame.setSize(1600, 900);
			frame.setVisible(true);
			ImageIcon icon = new ImageIcon(ClassLoader.getSystemResource("assests/tohouniv_updated.png"));
			frame.setIconImage(icon.getImage());
			contentPane = frame.getContentPane();
			
			CreateTaskBar();
			DrawTaskbar();
			CreatGSLPageThing();
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setVisible(true);
		}
		
}
