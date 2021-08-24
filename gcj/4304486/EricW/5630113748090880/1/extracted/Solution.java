package codeJam;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
	private static String input = "B-large.in";
	private static String output = "out.txt";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(input));
		PrintStream out = new PrintStream(new File(output));
		int n = in.nextInt();
		for (int i = 1; i <= n; i++) {
			out.println("Case #" + i + ": " + Rank(in));
		}
	}

	private static String Rank(Scanner in) {
		// TODO Auto-generated method stub

		StringBuilder sb = new StringBuilder();
		int N = in.nextInt();
		N = 2 * N * N - N;
		Set<Integer> set = new HashSet<>();

		while (N-- > 0) {
			int cur = in.nextInt();
			if (set.contains(cur)) {
				set.remove(cur);
			} else {
				set.add(cur);
			}
		}

		ArrayList<Integer> ans = new ArrayList<>();
		ans.addAll(set);
		Collections.sort(ans);

		for (int i = 0; i < ans.size(); i++) {
			if (i == 0) {
				sb.append(ans.get(i));
			} else {
				sb.append(" " + ans.get(i));
			}
		}

		return sb.toString();
	}

	private static String lastword(String str) {

		StringBuilder sb = new StringBuilder();

		sb.append(str.charAt(0));

		for (int i = 1; i < str.length(); i++) {
			char c = str.charAt(i);
			if (c >= sb.charAt(0)) {
				sb.insert(0, c);
			} else {
				sb.append(c);
			}

		}

		return sb.toString();
	}
}
