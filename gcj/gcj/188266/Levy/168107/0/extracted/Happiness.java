import java.io.*;
import java.util.*;

public class Happiness {
	static int[] mark = new int[100000];
	static int ph = 0;
	
	static boolean check(int x, int base) {
		ph++;
		while (x > 1) {
			if (mark[x] == ph) return false;
			mark[x] = ph;
			int nx = 0;
			while (x > 0) {
				int t = x % base;
				nx += t * t;
				x /= base;
			}
			x = nx;
		}
		return x == 1;
	}

	static int solve(int[] bases) {
		for (int i = 2; ; ++i) {
			boolean ok = true;
			for (int x: bases) 
				if (!check(i, x)) {
					ok = false;
					break;
				}
			if (ok) return i;
		}
	}

	public static void main(String[] args) throws Exception {
		FileInputStream in = new FileInputStream("A-small-attempt0.in");
		System.setIn(in);
		PrintStream out = new PrintStream("a.out");
		System.setOut(out);

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(input.readLine());
		for (int i = 0; i < T; ++i) {
			String[] ss = input.readLine().split(" ");
			int[] ii = new int[ss.length];
			for (int j = 0; j < ii.length; ++j)
				ii[j] = Integer.parseInt(ss[j]);
			System.out.println("Case #" + (i+1) + ": " + solve(ii));
		}
	}
}
