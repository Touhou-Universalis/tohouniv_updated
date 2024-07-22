package frontEnd;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class TempLayer3 implements ActionListener {
	JFrame frame;
	Container contentPane;
	public void actionPerformed(ActionEvent e) throws RuntimeException {
		try {
			System.out.println(e.getActionCommand());
			switch (e.getActionCommand()){
			case "save": {
				JTextArea  a= (JTextArea)contentPane.getComponent(0);
				JTextArea b = (JTextArea)SecondGui.AbilityName[1].getComponent(1);
				
				b.setText( a.getText());
				frame.dispose();
			}	
			}
		}catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} 
	}
	public void drawThingsagain() {
		contentPane.setLayout(new BorderLayout());
		JTextArea c = new JTextArea();
		c.setLineWrap(true);
		contentPane.add(c,BorderLayout.CENTER);
		
		JButton a = new JButton("save");
		a.addActionListener(this);
		contentPane.add(a,BorderLayout.SOUTH);
		frame.setVisible(true);
		
	}
	public void start() {
		frame = new JFrame("Desc Maker");
		frame.setSize(600, 400);
		frame.setVisible(true);
		ImageIcon icon = new ImageIcon(ClassLoader.getSystemResource("assests/tohouniv_updated.png"));
		frame.setIconImage(icon.getImage());
		contentPane = frame.getContentPane();
		drawThingsagain();
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frame.setVisible(true);
		
	}
}
