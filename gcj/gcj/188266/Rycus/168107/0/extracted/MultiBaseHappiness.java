import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;


/**
 * @author Rycus
 *
 */
public class MultiBaseHappiness {

	private static int getValue(String input) {
		int result = 0;
		for(int index = 0; index < input.length(); index++) {
			String current = Character.toString(input.charAt(index));
			int parsed = Integer.parseInt(current);
			result += (parsed * parsed);
		}
		return result;
	}
	
	private static boolean isHappy(int testing, String[] bases) {
		boolean happy = true;
		
		for(String baseStr : bases) {
			Set<String> testedNumbers = new HashSet<String>();
			int base = Integer.parseInt(baseStr);
			
			BigInteger current = new BigInteger(Integer.toString(testing));
			String currentBased = current.toString(base);
			
			boolean found = false;
			int value = 0;
			while(value != 1 && !testedNumbers.contains(currentBased)) {
				value = getValue(currentBased);
				if(value == 1) { found = true; break; }
				testedNumbers.add(currentBased);
				current = new BigInteger(Integer.toString(value));
				currentBased = current.toString(base);
			}
			if(!found) { happy = false; break; }
		}
		
		return happy;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		File file = new File("D:\\CodeJam2009\\A-small.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("D:\\CodeJam2009\\A-small.out");
		outputFile.createNewFile();
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		
		int cases = Integer.parseInt(reader.readLine());
		
		for(int caseIndex = 0; caseIndex < cases; caseIndex++) {
			String[] bases = reader.readLine().split("\\s");
			
			int testing = 2;
			
			while(!isHappy(testing, bases)) {
				testing++;
			}
			
			writer.write("Case #" + (caseIndex + 1) + ": " + testing);
			writer.newLine();
		}
		
		writer.flush();
		writer.close();
		reader.close();
	}

}
