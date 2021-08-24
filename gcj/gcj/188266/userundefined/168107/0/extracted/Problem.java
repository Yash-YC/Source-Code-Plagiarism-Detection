package ca.missine.utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;

import javax.swing.JFileChooser;

public abstract class Problem {
	private final Writer writer;
	private int total;
	private int caseNum; 
	
	protected static String getFile(String path) {
		JFileChooser chooser = new JFileChooser(path);
		chooser.showOpenDialog(null);
		return chooser.getSelectedFile().getAbsolutePath();
	}
	
	public Problem() throws Exception {
		String in = "data/A.in";
		String out = "output/A.out";
		Reader.reader = new BufferedReader(new FileReader(in));
		writer = new FileWriter(out);
	}
	
	public Problem(String in, String out) throws Exception {
		Reader.reader = new BufferedReader(new FileReader(in));
		writer = new FileWriter(out);
	}
	
	private void start() throws Exception {
		total = Reader.getInteger();
		caseNum = 1;
		while(caseNum <= total) {
			writer.append("Case #" + (caseNum++) + ": " + next() + "\n");
		}
	}
	
	protected abstract String next() throws Exception;
	
	private void end() throws Exception {
		writer.close();
	}
	
	public void solve() throws Exception {
		start();
		end();
	}
}
