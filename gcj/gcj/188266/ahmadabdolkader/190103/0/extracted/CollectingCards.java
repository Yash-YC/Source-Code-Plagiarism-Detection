package codejam09.r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class CollectingCards {
	public void go() {
		String className = getClass().getSimpleName();
		
		try {
			//go(new Scanner(new File("in/" + className + "_test.in")), new PrintWriter("out/" + className + "_test.out"));
			
			go(new Scanner(new File("in/" + className + "_small.in")), new PrintWriter("out/" + className + "_small.out"));

			//go(new Scanner(new File("in/" + className + "_large.in")), new PrintWriter("out/" + className + "_large.out"));
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

	public void go(Scanner scanner, PrintWriter out) throws Exception {
		int T = scanner.nextInt();
		for(int k = 1; k <= T; k++) {
			int C = scanner.nextInt();
			int N = scanner.nextInt();
			double[] cache = new double[C];
			Arrays.fill(cache, -1);
			double E = 1 + solve(N, C, N, 1.0, cache);
			System.out.println("Case #" + k + ": " + E);
		}
		out.close();
	}
	
	protected double solve(int h, int C, int N, double p, double[] cache) {
		if(h >= C) return 0;
		if(p < 1E-9) return 0;
		if(cache[h] > -1) return cache[h];
		double result = 1.0;
		for(int u = 0; u <= N; u++) {
			double pp = choose(C, N, h, u);
			result += pp * solve(h + u, C, N, p * pp, cache);
		}
		cache[h] = result;
		return result;
	}
	
	protected double choose(int C, int N, int h, int u) {
		int t = choose(C, N);
		int v = choose(C - h, u) * choose(h, N - u);
		return 1.0 * v / t;
	}
	
	public int choose(int n, int k) {
		if (n < 0 || k < 0) return -1;
		if (n < k) return 0;
		if (n == k || k == 0) return 1;
		int delta, iMax;
		if (k < n - k) {
			delta = n - k;
			iMax = k;
		} else {
			delta = k;
			iMax = n - k;
		}
		int ans = delta + 1;
		for (int i = 2; i <= iMax; ++i) {
			ans = (ans * (delta + i)) / i;
		}
		return ans;
	}
	
	protected void myAssert(boolean f) {
		if(!f) throw new RuntimeException();
	}
	
	public static void main(String[] args) {
		new CollectingCards().go();
	}
}