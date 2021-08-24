import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

import javax.management.RuntimeErrorException;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int bases[] = new int [9];
		int tc = nextInt();
		int max = 0;
		for (int tn = 1; tn <= tc; tn++) {
			StringTokenizer stok = new StringTokenizer(nextLine());
			int bc = 0;
			while (stok.hasMoreTokens())
				bases[bc++] = Integer.parseInt(stok.nextToken());
			boolean ok = false;
			for (int i =2; i <= MAXNUM; i++) {
				ok = true;
				for (int j = 0; j < bc; j++)
					if (!test(i, bases[j])) {
						ok = false;
						break;
					}
				if (ok) {
					max = max(max, i);
					out.println("Case #" + tn + ": " + i);
					break;
				}
			}
			if (!ok)
				throw new RuntimeException("fuck at tn = " + tn);
		}
		System.out.println("max = " + max);
		in.close();
		out.close();
	}
	
	int MAXNUM = 100000;
	
	int mark[] = new int [MAXNUM + 1];
	int tick;
	
	private boolean test(int x, int base) {
		tick++;
		while (x != 1) {
			if (mark[x] == tick)
				return false;
			mark[x] = tick;
			char s[] = Integer.toString(x, base).toCharArray();
			int sumSq = 0;
			for (int i = 0; i < s.length; i++) {
				int dig = s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10;;
				sumSq += dig * dig;
			}
			x = sumSq;
		}
		return true;
	}

	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
