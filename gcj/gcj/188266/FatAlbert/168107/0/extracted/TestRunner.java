package problemA2;


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

	ArrayList<ArrayList<Integer>> testCases;
	
	public TestRunner() {
		super();
	}

	public void readInput() {
		try {

			System.out.println("start");
			File inFile  = new File("A-small-attempt0.in");
			BufferedReader reader = new BufferedReader(new FileReader(inFile));

			String line = null;
			line = reader.readLine();
			
			int t = Integer.parseInt(line);
			
			testCases = new ArrayList<ArrayList<Integer>>();
			
			for(int i=0; i<t; i++) {
				line = reader.readLine();
				String[] vals = line.split(" ");
				ArrayList<Integer> testCase = new ArrayList<Integer>();
				for(int j=0; j<vals.length; j++) {
					testCase.add(Integer.parseInt(vals[j]));
				}
				testCases.add(testCase);
			}
			
			reader.close();
		} catch (IOException e) {
			System.out.println("bad input file");
		}
	}

	
	public boolean isHappyForBase(String number, int radix, int depth) {
		//System.out.println("isHappy num: "+number+" rad: "+radix);
		if(number.equals("1")) return true;
		int decSum = 0;
		for(int i=0; i<number.length(); i++) {
			int digit = (number.charAt(i) - '0');
			decSum = decSum + (digit*digit);
		}
		String radSum = Integer.toString(decSum, radix);
		if(depth > 100) return false;
		return isHappyForBase(radSum, radix, depth+1);
	}
	
	public Integer getResult(ArrayList<Integer> testCase) {
		int result=2;
		while(true) {
			for(int i=0; i<testCase.size(); i++) {
				//System.out.println("num: "+result+"  radix:"+testCase.get(i)+" result: "+isHappyForBase(Integer.toString(result, testCase.get(i)), testCase.get(i), 0));
				if(!isHappyForBase(Integer.toString(result, testCase.get(i)), testCase.get(i), 0))
					break;
				else {
					if(testCase.size()-1 == i) return result;
				}
			}
			result++;
		}
	}

	public void createOutput() {
		try {
			File outFile = new File("A-small.out");
			BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
			for(int i=0; i<testCases.size(); i++) {
				writer.write("Case #");
				writer.write(Integer.toString(i+1));
				writer.write(": ");
				//System.out.println("test case "+Integer.toString(i+1));
				writer.write(getResult(testCases.get(i)).toString());
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
//		run.isHappyForBase(Integer.toString(91,9), 9, 0);
	}
	
}



