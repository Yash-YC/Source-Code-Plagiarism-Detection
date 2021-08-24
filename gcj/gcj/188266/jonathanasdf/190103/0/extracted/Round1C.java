import java.io.*;

public final class Round1C {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\C-small-attempt7.in";
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
	     while ((line=reader.readLine()) != null) {
	    	 lineNumber++;
	    	 result += "Case #" + lineNumber + ": " + solve(line) + "\r\n";
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	}
	
	public static double solve(String line) {
		String[] input = line.split("\\s");
		double C = Integer.parseInt(input[0]);
		double N = Integer.parseInt(input[1]);
		if (C == N) {
			return 1.0;
		}
		double numLeft = C-N;
		double result = 1;
		while (numLeft > 0) {
			numLeft=(2 - numLeft/N)*C;
		}
		return result;
	}

}
