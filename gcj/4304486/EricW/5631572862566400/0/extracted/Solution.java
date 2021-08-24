package CodeJam;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
	public static void main(String[] a) throws IOException {
		Scanner in = new Scanner(new File("C-small-attempt0.in"));
		PrintStream out = new PrintStream(new File("out.txt"));

		int T = in.nextInt();
		for (int i = 1; i <= T; i++) {
			out.println("Case #" + i + ": " + bff(in));
		}
	}

	private static int bff(Scanner in) {
		int N = in.nextInt();
		int[] data = new int[N + 1];
		Set<Integer> cand = new HashSet<>();
		for (int i = 1; i < N + 1; i++) {
			data[i] = in.nextInt();
			cand.add(i);
		}
		int[] max = { 0 };

		helper(data, cand, N, max, new ArrayList<>(), true);

		return max[0];
	}

	private static void helper(int[] data, Set<Integer> cand, int n, int[] max,
			ArrayList<Integer> cycle, boolean lastgood) {
		for (int i = 1; i <= n; i++) {
			if (cand.contains(i)
					&& (lastgood || data[cycle.get(cycle.size() - 1)] == i)) {
				cycle.add(i);
				cand.remove(i);
				if (data[i] == cycle.get(0)) {
					max[0] = Math.max(max[0], cycle.size());
				} 
				if (cycle.size() > 1
							&& data[i] == cycle.get(cycle.size() - 2)) {
						max[0] = Math.max(max[0], cycle.size());
						helper(data, cand, n, max, cycle, true);
					} else {
						helper(data, cand, n, max, cycle, false);
					}
				
				cand.add(i);
				cycle.remove(cycle.size() - 1);
			}
		}

	}
}
