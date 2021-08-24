import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class Happiness {
	static int T;
	static HashSet<Long> hs = new HashSet<Long>();

	static long squaresum(String s) {
		long sum = 0;
		for (int i = 0; i < s.length(); i++) {
			sum += (s.charAt(i) - '0') * (s.charAt(i) - '0');
		}
		return sum;
	}

	static boolean happy(long num, int base) {
		String numstr = Long.toString(num, base);
		hs.clear();
		long ss = squaresum(numstr);
		while (ss != 1 && !hs.contains(ss)) {
			hs.add(ss);
			ss = squaresum(Long.toString(ss, base));
		}
		if (ss == 1)
			return true;
		return false;
	}

	static long findHappy(String[] basestrs) {
		int[] bases = new int[basestrs.length];

		for (int i = 0; i < bases.length; i++) {
			bases[i] = Integer.parseInt(basestrs[i]);
		}

		long num = 2;
		while (num < Long.MAX_VALUE) {
			boolean flag = true;
			for (int i = 0; i < bases.length; i++) {
				if (!happy(num, bases[i])) {
					flag = false;
					break;
				}
				if (!flag)
					break;
			}
			if (flag) {
				return num;
			}
			num++;
		}
		return -1;
	}

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"C:\\Documents and Settings\\Anqi Cui\\Desktop\\A-small-attempt0.in"));
			BufferedWriter bw = new BufferedWriter(
					new FileWriter(
							"C:\\Documents and Settings\\Anqi Cui\\Desktop\\output.txt"));

			String line = br.readLine();
			T = Integer.parseInt(line);

			for (int i = 0; i < T; i++) {
				line = br.readLine();
				bw
						.write("Case #" + (i + 1) + ": "
								+ findHappy(line.split(" ")));
				bw.newLine();
			}
			br.close();
			bw.close();
		} catch (FileNotFoundException fnfe) {
			fnfe.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}

	}

}
