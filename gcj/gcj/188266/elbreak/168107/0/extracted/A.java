package ee.elbr.codejam9.round1A;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.LinkedList;

public class A {
	public static void main(String args[]) {
		BufferedReader reader = null;
		PrintStream out = System.out;
		InputStream in = null;

		try {
			in = A.class.getClassLoader().getResourceAsStream("A-small-attempt0.in");
			reader = new BufferedReader(new InputStreamReader(in));
			out = new PrintStream(new FileOutputStream("A-small-attempt0.out"));

			String line = reader.readLine();
			int n = Integer.parseInt(line);
			for (int i = 0; i < n; i++) {
				line = reader.readLine();
				int result = count(line);

				out.println("Case #" + (i + 1) + ": " + result);
			}
		} catch (Exception e) {
			e.printStackTrace(System.err);
		} finally {
			try {
				in.close();
				reader.close();
				out.flush();
			} catch (Exception e) {
				e.printStackTrace(System.err);
			}
		}
	}

	private static boolean isHappy(int num, int base,
			LinkedList<String> nothappy) {
		String n = Integer.toString(num, base);
		if (nothappy.contains(n))
			return false;
		nothappy.add(n);

		int sum = 0;
		for (int i = 0; i < n.length(); i++) {
			int k = Double.valueOf(
					Math.pow(Integer.valueOf(n.charAt(i) + ""), 2)).intValue();
			sum += k;
		}
		if (sum == 0)
			return false;
		if (sum == 1)
			return true;
		else
			return isHappy(sum, base, nothappy);
	}

	private static int count(String line) {
		String[] bases = line.split(" ");
		int result = 1;
		boolean happy = true;

		do {
			result++;
			happy = true;

			// System.out.println("---" + result);
			for (String base : bases) {
				boolean h = isHappy(result, Integer.parseInt(base),
						new LinkedList<String>());
				// System.out.println(result + " in " + base + " = " + h);
				happy &= h;
			}
		} while (!happy);

		return result;
	}
}
