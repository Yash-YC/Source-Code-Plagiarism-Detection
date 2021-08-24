import java.io.BufferedReader;
import java.io.InputStreamReader;

public final class Main {
	
	private static final int LARGEST_NUM_NEEDED = 10000;
	
	private static final int[] SQUARES
			= {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
	
	public static final void main(final String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		boolean[][] happy = new boolean[11][LARGEST_NUM_NEEDED];
		
		generateHappy(happy);
		
		int numCases = Integer.parseInt(br.readLine().trim());
		
		for (int i = 0; i < numCases; i++) {
			
			processTestCase((i + 1), (br.readLine().trim()), happy);
		}
	}
	
	private static final void processTestCase(final int caseNum, final String testCase, final boolean[][] happy) {
		
		String[] strBases = testCase.split(" ");
		int lenBases = strBases.length;
		int[] bases = new int[lenBases];
		
		for (int i = 0; i < lenBases; i++) {
			
			bases[i] = Integer.parseInt(strBases[i].trim());
		}
		
		boolean allHappyFound = false;
		int currentNum = 1;
		
		while (!allHappyFound) {
			
			currentNum++;
			
			boolean allHappy = true;
			
			for (int i = 0; (i < lenBases) && allHappy; i++) {
				
				allHappy = isHappy(bases[i], happy[bases[i]], currentNum, currentNum, (new boolean[LARGEST_NUM_NEEDED]));
			}
			
			allHappyFound = allHappy;
		}
		
		System.out.println("Case #" + caseNum + ": " + currentNum);
	}
	
	private static final void generateHappy(final boolean[][] happy) {
		
		for (int i = 2, lenHappy = happy.length; i < lenHappy; i++) {
			
			generateHappy(i, happy[i]);
		}
	}
	
	private static final void generateHappy(final int base, final boolean[] happy) {
		
		happy[1] = true;
		
		for (int i = 2, lenHappy = happy.length; i < lenHappy; i++) {
			
			happy[i] = isHappy(base, happy, i, i, (new boolean[LARGEST_NUM_NEEDED]));
		}
	}
	
	private static final boolean isHappy(final int base, final boolean[] happy, final int initialNum, final int currentNum, boolean[] processed) {
		
		if ((currentNum < initialNum) && (currentNum < happy.length)) {
			
			return happy[currentNum];
		}
		
		if ((currentNum < processed.length) && (processed[currentNum])) {
			
			return false;
		}
		
		if (currentNum < processed.length) {
			
			processed[currentNum] = true;
		}
		
		return (isHappy(base, happy, initialNum, sumOfSquaresOfDigits(base, currentNum), processed));
	}
	
	private static final int sumOfSquaresOfDigits(final int base, final int num) {
		
		int sum = 0;
		
		String string = Integer.toString(num, base);
		
		char[] chars = string.toCharArray();
		
		for (int i = 0, lenChars = chars.length; i < lenChars; i++) {
			
			sum += SQUARES[Character.getNumericValue(chars[i])];
		}
		
		return sum;
	}
}
