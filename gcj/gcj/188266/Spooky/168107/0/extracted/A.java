package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		//in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		//in = new BufferedReader(new FileReader("A-large.in"));
		out = new PrintWriter(new FileWriter("A-small-out"));
		//out = new PrintWriter(new FileWriter("A-large-out"));
		
		for (int t = Integer.valueOf(in.readLine()), cs = 1; t > 0; t--, cs++) {
			String[] T = in.readLine().split(" ");
			int[] a = new int[T.length];
			for (int i = 0; i < T.length; i++) a[i] = Integer.valueOf(T[i]);
			
			search : for (int x = 2;; x++) {
				for (int i = 0; i < a.length; i++)
					if (!isHappy(x, a[i])) continue search;
				out.println("Case #" + cs + ": " + x);
				break;
			}
			
			out.flush();
		}
		
		out.flush();
	}

	static final int MAX = 10, TOT = 1 << (MAX - 1), N = 1000000; 
	static int[] res = new int[TOT];
	static boolean[][] memo = new boolean[N][MAX+1];
	static boolean[][] b = new boolean[N][MAX+1];
	
	static boolean isHappy(int x, int base) {
		if (b[x][base]) return memo[x][base];
		
		int r = x;
		boolean[] g = new boolean[N];
		
		while (!g[x]) {
			g[x] = true;
			String s = Integer.toString(x, base);
			x = 0;
			for (int i = 0; i < s.length(); i++) x += (s.charAt(i) - '0')*(s.charAt(i) - '0');
		}
		
		b[r][base] = true;
		return memo[r][base] = x == 1;
	}
		
}
