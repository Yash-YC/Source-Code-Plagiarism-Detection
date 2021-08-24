package problemB;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class TestRunner {

	ArrayList<TestCase> testCases;
	
	public TestRunner() {
		super();
	}

	public void readInput() {
		try {
			File inFile  = new File("C-small.in");
			BufferedReader reader = new BufferedReader(new FileReader(inFile));

			String line = null;
			line = reader.readLine();
			
			int t = Integer.parseInt(line);
			
			testCases = new ArrayList<TestCase>();
			
			for(int i=0; i<t; i++) {
				line = reader.readLine();
				String[] vals = line.split(" ");
				testCases.add(new TestCase(Integer.parseInt(vals[1]), Integer.parseInt(vals[0])));
			}
			
			reader.close();
		} catch (IOException e) {
			System.out.println("bad input file");
		}
	}

	public void createOutput() {
		try {
			File outFile = new File("C-small.out");
			BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
			for(int i=0; i<testCases.size(); i++) {
				writer.write("Case #");
				writer.write(Integer.toString(i+1));
				writer.write(": ");
				writer.write(testCases.get(i).getAnswer().toString());
				writer.newLine();
			}
			writer.close();
		} catch (IOException e) {
			System.out.println("problem writing to the file");
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		TestRunner run = new TestRunner();
		run.readInput();
		run.createOutput();
	}
	
}



