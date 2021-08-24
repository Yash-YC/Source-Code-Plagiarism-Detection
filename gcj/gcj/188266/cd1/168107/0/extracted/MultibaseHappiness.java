import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.logging.Logger;

public class MultibaseHappiness {
	private static Logger log = Logger.getLogger(MultibaseHappiness.class.getName());

	public static void main(String[] args) {
		MultibaseHappiness happy = new MultibaseHappiness();
		Scanner input = new Scanner(System.in);
		int nTests = Integer.parseInt(input.nextLine());
		for (int i = 0; i < nTests; i++) {
			String[] bases = input.nextLine().split(" ");
			int[] intBases = new int[bases.length];
			for (int j = 0; j < bases.length; j++) {
				intBases[j] = Integer.parseInt(bases[j]);
			}
			int n = happy.smallestHappyNumber(intBases);
			System.out.printf("Case #%d: %d%n", i + 1, n);
		}
		input.close();
	}

	public int smallestHappyNumber(int[] bases) {
		log.entering(MultibaseHappiness.class.getName(), "smallestHappyNumber", bases.length);
		boolean done = false;
		int smallestInB = 1;
		mainWhile:
			while (!done) {
				smallestInB = smallestInBase(bases[0], smallestInB + 1);
				for (int i = 1; i < bases.length; i++) {
					if (!isHappyInBase(smallestInB, bases[i], new HashSet<Integer>())) {
						continue mainWhile;
					}
				}
				done = true;
			}
		log.exiting(MultibaseHappiness.class.getName(), "smallestHappyNumber", smallestInB);
		return smallestInB;
	}

	private int smallestInBase(int base, int since) {
		log.entering(MultibaseHappiness.class.getName(), "smallestInBase",
				new Object[] { base, since });
		for (int i = since; ; i++) {
			if (isHappyInBase(i, base, new HashSet<Integer>())) {
				log.exiting(MultibaseHappiness.class.getName(), "smallestInBase", i);
				return i;
			}
		}
	}

	private boolean isHappyInBase(int number, int base, Set<Integer> cache) {
		log.entering(MultibaseHappiness.class.getName(), "isHappyInBase",
				new Object[] { number, base });
		String str = Integer.toString(number, base);
		int total = 0;
		for (char c : str.toCharArray()) {
			int i = Integer.parseInt(Character.toString(c));
			total += (i * i);
		}
		log.fine(String.format("total=%d (%d)", total, Integer.parseInt(Integer.toString(total, base))));

		boolean result;
		if (total == 1) {
			result = true;
		}
		else if (cache.contains(total)) {
			result = false;
		}
		else {
			cache.add(total);
			result = isHappyInBase(total, base, cache);
		}
		log.exiting(MultibaseHappiness.class.getName(), "isHappyInBase", result);
		return result;
	}
}
