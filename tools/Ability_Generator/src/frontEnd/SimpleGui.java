package frontEnd;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SimpleGui implements ActionListener{
	public String Folderchoicething() {
		JFileChooser chooser= new JFileChooser();
		 chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY); 
		chooser.setAcceptAllFileFilterUsed(false);
		int Value = chooser.showOpenDialog(contentPane);
		if(Value == JFileChooser.APPROVE_OPTION) {
			File a = chooser.getSelectedFile();
			return a.getPath();
		}else {
			return "";
		}
	}
	public static String[] importantFiles = {"sound/th_danmaku_duel_sounds.asset","localisation/touhou_characters_localization_l_english.yml","localisation/touhou_danmaku_l_english.yml","localisation/touhou_generated_danmaku_l_english.yml",
	"interface/countrycourtview.gui","interface/countrydanmakuview_touhou.gfx","interface/topbar.gui","gfx/interface/danmaku/abilities","events/ThDanmakuDuel.txt","customizable_localization/th_danmaku_ability_locs.txt",
	"customizable_localization/th_danmaku_locs.txt","customizable_localization/th_generated_danmaku_locs.txt","common/custom_gui/th_danmaku_gui.txt","common/scripted_effects/th_data_base.txt",
	"common/scripted_effects/th_scripted_effects_for_danmaku.txt","common/scripted_effects/th_scripted_effects_for_danmaku_fight_data_base.txt","common/scripted_effects/th_scripted_effects_for_danmaku_fight_log.txt",
	"common/scripted_triggers/th_scripted_triggers_for_danmaku.txt","common/scripted_triggers/th_scripted_triggers_for_danmaku_fight.txt","common/scripted_triggers/th_scripted_triggers_for_respawn_feature.txt"
	};
	public static String[] importantdirectories = {"sound","localisation","interface","gfx","gfx/interface","gfx/interface/danmaku",
			"gfx/interface/danmaku/abilities","events","customizable_localization","common",
			"common/custom_gui","common/scripted_effects","common/scripted_triggers",
			};
	public void submit() {
		JTextField b = (JTextField)modDirectory.getComponent(2);
		String holder = b.getText();
		for (String a : importantdirectories) {
			String a2= holder.concat("/"+a);
			File check = new File(a2);
			if(!check.exists()) {
				try {
					check.mkdir();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
		for (String a : importantFiles) {
			String a2= holder.concat("/"+a);
			File check = new File(a2);
			if(!check.exists()) {
				try {
					check.createNewFile();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}	
		}
		SecondGui as = new SecondGui();
		SecondGui.DirectoryPath = b.getText();
		as.start();
		frame.dispose();
	}
	public void Verification() {
		JTextField b = (JTextField)modDirectory.getComponent(2);
		String holder = b.getText();
		for (String a : importantFiles) {
			String a2= holder.concat("/"+a);
			File check = new File(a2);
			if(!check.exists()) {
				log.setText(log.getText().concat("\nFile "+a+" was not found will create it and it's directory on clicking the submit button"));
			}
			
		}
	}
	public void actionPerformed(ActionEvent e) throws RuntimeException {
		try {System.out.println(e.getActionCommand());
		switch (e.getActionCommand()){
			case "DirectorySelect": {
				JTextField b = (JTextField)modDirectory.getComponent(2);
				String c = Folderchoicething();
				if(c.length()>0) {
				b.setText(c);
				}
			}
			break;
			case "Valadator": {
				Verification();
			}
			break;
			case "Submit": {
				submit();
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
	public static void main(String[] args) throws IOException {
		SimpleGui guiLayout = new SimpleGui();
		
		guiLayout.start();
		
	}
 JFrame frame;
	Container contentPane;
	JPanel selector = new JPanel();
	JPanel modDirectory = new JPanel();
	JPanel Validation = new JPanel();
	JTextArea log = new JTextArea();
 public void start(){
		frame = new JFrame("Launcher");
		frame.setSize(400, 400);
		frame.setVisible(true);
		ImageIcon icon = new ImageIcon(ClassLoader.getSystemResource("assets"));
		frame.setIconImage(icon.getImage());
		contentPane = frame.getContentPane();

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		selector.setLayout(new GridLayout(2,1));
		modDirectory.setLayout(new BorderLayout());
		modDirectory.add(new JLabel("Mod Directory:"),BorderLayout.WEST);
		JTextField a = new JTextField();
		JButton DirectorySelect = new JButton("DirectorySelect");
		DirectorySelect.setName("DirectorySelect");
		DirectorySelect.addActionListener(this);
		modDirectory.add(DirectorySelect,BorderLayout.EAST);
		
		a.setSize(300, 14);
		modDirectory.add(a);
		JButton Valadator = new JButton("Valadator");
		Valadator.setName("Valadator");
		Valadator.addActionListener(this);
		JButton Submit = new JButton("Submit");
		Submit.setName("Submit");
		Submit.addActionListener(this);
		Validation.add(Valadator);
		Validation.add(Submit);
		selector.add(modDirectory);
		selector.add(Validation);
		contentPane.add(selector,BorderLayout.NORTH);
		log.setEditable(false);
		contentPane.add(log);
		frame.setVisible(true);
		
	}
}
