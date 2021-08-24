import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;

public class MultiBaseHappiness extends CodeJamBase {
	private HashMap<Integer, HashMap<Integer, Boolean>> cache;

	public static void main(String[] args) {
		new MultiBaseHappiness(args);
	}
	public MultiBaseHappiness(String[] args) {
		super(args);
	}

	@Override
	public void solve(BufferedReader reader, BufferedWriter writer) throws IOException {
		cache = new HashMap<Integer, HashMap<Integer,Boolean>>();
		String line = reader.readLine();
		int T = Integer.parseInt(line);

		// solve every case
		for (int t = 1; t <= T; t ++) {
			String[] baseStrings = reader.readLine().split(" ");
			int[] bases = new int[baseStrings.length];
			for (int i = 0; i < bases.length; i ++)
				bases[i] = Integer.parseInt(baseStrings[i]);
			writer.write("Case #"+t+": "+calc(bases));
			writer.newLine();
		}
	}

	// look for the answer value
	private int calc(int[] bases) {
		int val = 1;
		while (true) {
			val ++;

			boolean isHappy = true;
			for (int base : bases) {
				if (!isHappy(val, base)) {
					isHappy = false;
					break;
				}
			}
			if (isHappy) break;
		}
		return val;
	}

	// whether the condition is happy or not
	private boolean isHappy(int val, int base) {

		// cache?
		HashMap<Integer, Boolean> cache2 = cache.get(val);
		if (cache2 == null) {
			cache.put(val, cache2);
			cache2 = new HashMap<Integer, Boolean>();
		} else {
			if (cache2.containsKey(base)) {
				return cache2.get(base);
			}
		}

		// check
		int newVal;
		boolean isHappy;
		HashSet<Integer> visitedSet = new HashSet<Integer>();
		while (true) {
			newVal = 0;
			while (val>0) {
				int rem = val%base;
				newVal += rem*rem;
				val = val/base;
			}
			if (visitedSet.contains(newVal)) {
				isHappy = false;
				break;
			} else if (newVal == 1) {
				isHappy = true;
				break;
			}
			val = newVal;
			visitedSet.add(val);
		}

		// put in the cache, return
		cache2.put(base, isHappy);
		return isHappy;
	}
}
