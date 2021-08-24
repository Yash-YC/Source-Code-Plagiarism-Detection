package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class C {

	static StreamTokenizer in;
	static PrintWriter out;
	
	static int nextInt() throws IOException
	   {
	      in.nextToken();
	      return (int)in.nval;
	   }
	
	static String nextString() throws IOException
	   {
	      in.nextToken();
	      return in.sval;
	   }

	public static void main(String[] args) throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		out = new PrintWriter(System.out);
		in = new StreamTokenizer(new BufferedReader(new FileReader("C-small-attempt0.in")));
		//in = new StreamTokenizer(new BufferedReader(new FileReader("C-large.in")));
		out = new PrintWriter(new FileWriter("C-small-out"));
		//out = new PrintWriter(new FileWriter("C-large-out"));
		
		for (int t = nextInt(), cs = 1; t > 0; t--, cs++) {
			c = nextInt();
			n = nextInt();
			
			int cnt = 0;
			for (int i = 1; i < 1 << c; i++)
				if (Integer.bitCount(i) == n) cnt++;
			p = 1.0/cnt;
			
			memo = new double[1 << c];
			b = new boolean[1 << c];
			
			double res = solve(0);
			out.println("Case #" + cs + ": " + res);
		}
		
		out.flush();
	}

	static final int MAX = 10, TOT = 1 << MAX;
	static int n, c;
	static double p;
	static double[] memo;
	static boolean[] b;
	
	static double solve(int x) {
		if (b[x]) return memo[x];
		if (x == (1 << c) - 1) {
			b[x] = true;
			return memo[x] = 0;
		}
		
		b[x] = true;
		double res = 0, p1 = 0;
		for (int i = 1; i < 1 << c; i++)
			if (Integer.bitCount(i) == n) {
				if ((x|i) == x) p1 += p;
				else res += p*(1 + solve(x|i));
			}
		
		res += p1;
		res /= (1 - p1);
		
		return memo[x] = res;
	}
}
