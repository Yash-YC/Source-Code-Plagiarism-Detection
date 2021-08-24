package codejam.round1a;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Problem {

	private final int[] bases;

	public Problem(int[] ns) {
		this.bases = ns;
	}

	public long getResult() {
//		System.out.println(Arrays.toString(bases));
		for (int i = 2; ; i++) {
//			System.out.println("i=" + i);
			boolean thisIsHappy = true;
			for (int n : bases) {
				thisIsHappy &= isHappy(i, n);
				if (!thisIsHappy) {
//					System.out.println("!happy, n=" + n);
					break;
				}
			}
			if (thisIsHappy) {
//				System.out.println("happy");
				return i;
			}
		}
	}

	boolean isHappy(int n, int base) {
		final Set<Integer> prev = new HashSet<Integer>();
		int curr = getHappy(n, base);
//		if (n==7) System.out.println("getHappy(" + n + ", " + base + ")=" + curr);
		while (curr != 1 && !prev.contains(curr)) {
			prev.add(curr);
			curr = getHappy(curr, base);
//			if (n==7) System.out.println("getHappy(" + n + ", " + base + ")=" + curr);
		}
		return curr == 1;
	}

	int getHappy(int n, int base) {
		int curr = n;
		int happy = 0;
		while (curr != 0) {
			int mod = curr % base;
			happy += (mod * mod);
			curr /= base;
		}
		return happy;
	}
}

