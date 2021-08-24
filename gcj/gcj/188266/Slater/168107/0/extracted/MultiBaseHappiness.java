import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

import jam.JamIO;


public class MultiBaseHappiness {

	public static void main(String[] args) throws Exception {
		int T = JamIO.readNextInt();
		for (int c = 0; c < T; c++) {
			String basesStr = JamIO.readStringUntilEndOfLine();
			String[] basesAr = basesStr.split(" ");
			int[] bases = new int[basesAr.length];
			for (int i = 0; i < basesAr.length; i++) {
				bases[i] = Integer.parseInt(basesAr[i]);
				if (! knowledgeBase.containsKey(bases[i])) {
					knowledgeBase.put(bases[i], new TreeMap<Integer, Boolean>());
				}
			}
			Integer smallest = null;
			outer: for (int i = 2; smallest == null; i++) {
				for (int b = 0; b < bases.length; b++) {
					if (! isHappy(i, bases[b])) {
						continue outer;
					}
				}
				smallest = i;
			}
			JamIO.printCase(c, smallest);
		}
	}

	private static Map<Integer, Map<Integer, Boolean>> knowledgeBase = new TreeMap<Integer, Map<Integer, Boolean>>();

	private static boolean isHappy(Integer number, Integer base) {
		if (number == 1) return true;
		Map<Integer, Boolean> thisbase = knowledgeBase.get(base);
		Boolean ret = thisbase.get(number);
		if (ret == null) {
			thisbase.put(number, Boolean.FALSE);
			int originalNumber = number, sumOfSquares = 0, baseInt = base;
			while (originalNumber > 0) {
				int digit = originalNumber % baseInt;
				originalNumber /= baseInt;
				sumOfSquares += (digit * digit);
			}
			ret = isHappy(sumOfSquares, base);
			if (ret) thisbase.put(number, Boolean.TRUE);
		}
		return ret;
	}

}
