package codeJam;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Solution {
	private static String input = "A-small-attempt0.in";
	private static String output = "out.txt";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(input));
		PrintStream out = new PrintStream(new File(output));
		int n = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= n; i++) {
			out.println("Case #" + i + ": " + lastword(in.nextLine()));
		}
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
