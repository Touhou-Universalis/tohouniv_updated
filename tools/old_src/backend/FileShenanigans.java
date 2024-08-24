package backend;

import java.awt.Container;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import javax.swing.JFileChooser;

import frontEnd.SecondGui;

public class FileShenanigans {
	public static PrintWriter maker(String a) throws IOException {
		FileWriter w = new FileWriter(new File(SecondGui.DirectoryPath.concat(a)),true);
		 BufferedWriter bw = new BufferedWriter(w);
		 PrintWriter out = new PrintWriter(bw);
		 return out;
	}
	public static PrintWriter relplacer(String a) throws IOException {
		FileWriter w = new FileWriter(new File(SecondGui.DirectoryPath.concat(a)));
		 BufferedWriter bw = new BufferedWriter(w);
		 PrintWriter out = new PrintWriter(bw);
		 return out;
	}
	public static String Filechoicething(Container contentPane ) {
		JFileChooser chooser= new JFileChooser();
		chooser.setAcceptAllFileFilterUsed(true);
		int Value = chooser.showOpenDialog(contentPane);
		if(Value == JFileChooser.APPROVE_OPTION) {
			File a = chooser.getSelectedFile();
			return a.getPath();
		}else {
			return "";
		}
	}
}
