import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Locale;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class Solution implements Runnable {

	public static void main(String[] args) {
		(new Thread(new Solution())).start();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int rep(int q, int p) {
		int res = 0;
		while (q > 0) {
			res += (q % p) * (q % p);
			q /= p;
		}
		return res;
	}
	byte[][] q;
	final int cc = 3000000;
	
	byte dfs(int tt, int i) {
		if (i < cc) {
			if (q[tt][i] != 0) {
				if (q[tt][i] == 1) return 1; else return 100;
			}
		} else out.print("!");
		if (i < cc) q[tt][i] = 3;
		int ii = rep(i, tt);
		byte r = dfs(tt, ii);
		if (i < cc) q[tt][i] = r;
		return r;
	}
	
	void solve() throws IOException {
		int t = nextInt();
		q = new byte[11][cc];
		for (int tt = 2; tt <= 10; tt++) {
			Arrays.fill(q[tt], (byte) 0);
			q[tt][1] = 1;
			for (int i = 2; i < cc; i++) {
				if (q[tt][i] == 0) {
					dfs(tt, i);
				}
			}
		}
		for (int nn = 1; nn <= t; nn++) {
			StringTokenizer s = new StringTokenizer(in.readLine());
			boolean z[] = new boolean[11];
			while (s.hasMoreTokens()) {
				int p = Integer.parseInt(s.nextToken());
				z[p] = true;
			}
			int ans = 1;
			boolean f = true;
			while (f) {
				ans++;
				f = false;
				for (int i = 2; i <= 10; i++)
					if (z[i] && q[i][ans] != 1) {
						f = true;
						break;
					}
			}
			out.println("Case #" + nn + ": " + ans);
		}
	}

	public void run() {
		Locale.setDefault(Locale.UK);
		try {
			if (System.getProperty("ONLINE_JUDGE") != null) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			} else {
				in = new BufferedReader(new FileReader(new File("input.txt")));
				out = new PrintWriter(new FileWriter(new File("output.txt")));
			}
			solve();
		} catch (IOException e) {
			e.printStackTrace();
		}
		out.flush();
	}

}
