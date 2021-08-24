import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	int MAXC = 10;
	int ITER = 1000;

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		double p[][] = new double[2][1 << MAXC];
		int masks[] = new int [1 << MAXC];
		int tc = nextInt();
		for (int tn = 1; tn <= tc; tn++) {
			System.out.println(tn);
			int c = nextInt();
			int n = nextInt();
			int cc = 0;
			int mc = 1 << c;
			for (int mask = 0; mask < mc; mask++)
				if (Integer.bitCount(mask) == n)
					masks[cc++] = mask; 
			double pr = 1.0 / cc;
			int nc = 0;
			fill(p[nc], 0, 1 << c, 0);
			p[nc][0] = 1;
			double res = 0;
			for (int i = 0; i < ITER; i++) {
				fill(p[1 - nc], 0, mc, 0);
				for (int mask = 0; mask < mc - 1; mask++) {
					for (int j = 0; j < cc; j++)
						p[1 - nc][mask | masks[j]] += p[nc][mask] * pr;
				}
				nc = 1 - nc;
				res += (i + 1) * p[nc][mc - 1];
			}
			out.println("Case #" + tn + ": " + res);
		}
		in.close();
		out.close();
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
