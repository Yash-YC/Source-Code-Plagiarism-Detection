import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

/**
 * Google Code Jam - Round 1A 2009.
 */
public class MultiBaseHappiness {

	private static final int MAX_BASE = 10;

	private int[] bases;

	private static HashMap<Long, Boolean>[] cache;

	static {
		cache = new HashMap[MAX_BASE + 1];
		for (int i=0; i < MAX_BASE + 1; i++) {
			cache[i] = new HashMap<Long, Boolean>();
		}
		
	}
	public MultiBaseHappiness(int[] bases) {
		this.bases = bases;
	}

	public long getMinHappy() {
		long minHappy = 1;
		boolean found = false;
		WHILE: while (!found) {
			minHappy++;
			found = true;
			for (int i=0; i < bases.length; i++) {
				if (!isHappy(minHappy, bases[i])) {
					found = false;
					continue WHILE;
				}
			}
		}
		
		return minHappy;
	}

	private static boolean isHappy(long number, int base) {
		Boolean value = cache[base].get(number);
		if (value == null) {
			value = isHappy(number, base, new HashSet<Long>());
			cache[base].put(number, value);
		}
		return value;
	}

	public static boolean isHappy(long number, int base, HashSet<Long> checked) {
		checked.add(number);
		String numInBase = Long.toString(number, base);
		long sum = 0;
		for (int i=0; i < numInBase.length(); i++) {
			int digit = Integer.parseInt(numInBase.substring(i, i+1)); 
			sum +=  digit * digit;
		}
		if (checked.contains(sum)) {
			return false;
		} else if (sum == 1) {
			return true;
		} else {
			return isHappy(sum, base, checked);
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		try {
			int numCases = Integer.parseInt(in.readLine());
			for (int i=1; i <= numCases; i++) {
				String line = in.readLine();
				String[] tokens = line.split("\\s+");
				int[] bases = new int[tokens.length];
				for (int j=0; j < tokens.length; j++) {
					bases[j] = Integer.parseInt(tokens[j]);
				}
				MultiBaseHappiness happiness = new MultiBaseHappiness(bases);
				long minHappy = happiness.getMinHappy();
				System.out.println("Case #" + i + ": " + minHappy);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
