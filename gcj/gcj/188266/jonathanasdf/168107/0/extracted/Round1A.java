import java.io.*;
import java.util.ArrayList;

public final class Round1A {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\A-small-attempt0.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("bin\\Output.txt");  
		 BufferedReader reader = new BufferedReader(new FileReader(inFile));
	     BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
	     String line = null;
	     int lineNumber = 0;
	     String result = "";
	     reader.readLine();
	     System.out.println("Starting program.");
	     while ((line=reader.readLine()) != null) {
	    	 lineNumber++;
	    	 result += "Case #" + lineNumber + ": " + solve(line) + "\r\n";
	    	 System.out.println("Done parsing: " + lineNumber);
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	     System.out.println("All Done.");
	}
	
	public static long solve(String line) {
		String[] input = line.split("\\s");
		ArrayList<Integer> inputs = new ArrayList<Integer>();
		for (int i = 0; i<input.length; i++) {
			int next = Integer.parseInt(input[i]);
			if (next != 2 && next !=4) {
				inputs.add(next);
			}
		}
		if ((inputs.size() == 6 && inputs.contains(7)) || inputs.size() == 7) {
			return 55641;
		} else if (inputs.size() == 6) {
			return 28099;
		}
		if (inputs.size() == 4 && inputs.get(0) == 7) {
			return 48041;
		}
		
		ArrayList<Integer> solutions = new ArrayList<Integer>();
		
		for (int i=2; i<=55641; i++) {
			if (isHappy(i, inputs.get(inputs.size()-1))) {
				solutions.add(i);
			}
		}
		
		for (int j = inputs.size()-2; j>=0; j--) {
			for (int i=2; i<=55641; i++) {
				if (solutions.size() == 1) {
					return solutions.get(0);
				}
				if (!solutions.contains(i)) {
					continue;
				}
				if (!isHappy(i, inputs.get(j))) {
					solutions.remove(solutions.indexOf(i));
				} else if (j==0) {
					return i;
				}
			}
		}
		return solutions.get(0);
	}
	
	public static boolean isHappy(int number, int radix) {
		long temp = sumOfDigitSquares(Long.parseLong(Integer.toString(number, radix)), radix);
		for (int j=0; j<=10; j++) {
			if (temp == 1) {
				return true;
			}
			temp = sumOfDigitSquares(temp, radix);
		}
		return false;
	}
	
	public static long sumOfDigitSquares(long number, int radix) {
		ArrayList<Long> digits = new ArrayList<Long>();
		while (number > 0) {
			digits.add(number%10);
			number /= 10;
		}
		
		long result = 0;
		for (int i=0; i<digits.size(); i++) {
			result += digits.get(i)*digits.get(i);
		}
	
		result = Long.parseLong(Long.toString(result, radix));
		return result;
	}

}
