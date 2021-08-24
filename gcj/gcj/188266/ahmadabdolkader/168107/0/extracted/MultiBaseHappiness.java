package codejam09.r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class MultiBaseHappiness {
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
	
	protected static final int MAX = 1000000;
	public void go(Scanner scanner, PrintWriter out) throws Exception {
		int[][] m = new int[9][MAX];
		boolean[] v = new boolean[MAX];
		for(int[] r : m) Arrays.fill(r, -1);
		for(int b = 2; b <= 10; b++) {
			int bi = b - 2;
			for(int n = 1; n < MAX; n++) {
				m[bi][n] = sum(n, b);
			}
			for(int n = 1; n < MAX; n++) {
				dfs(m[bi], n, v);
			}
		}
		System.out.println("DONE");
		int T = Integer.parseInt(scanner.nextLine());
		for(int k = 1; k <= T; k++) {
			StringTokenizer st = new StringTokenizer(scanner.nextLine());
			int[] bases = new int[st.countTokens()];
			for(int i = 0; i < bases.length; i++)
				bases[i] = Integer.parseInt(st.nextToken()) - 2;
			int n = 2;
			for(; n < MAX; n++) {
				boolean found = true;
				for(int b : bases)
					if(m[b][n] != 1) {
						found = false;
						break;
					}
				if(found) break;
			}
			myAssert(n < MAX);
			out.println("Case #" + k + ": " + n);
		}
		out.close();
	}
	
	protected boolean dfs(int[] s, int n, boolean[] v) {
		if(v[n]) return false;
		if(s[n] == 1) return true;
		v[n] = true;
		if(dfs(s, s[n], v)) s[n] = 1;
		v[n] = false;
		return s[n] == 1;
	}
	
	protected int sum(int n, int b) {
		char[] ns = Integer.toString(n, b).toCharArray();
		int sum = 0;
		for(char dc : ns) {
			int d = dc - '0';
			sum += d * d;
		}
		return sum;
	}
	
	protected void myAssert(boolean f) {
		if(!f) throw new RuntimeException();
	}
	
	public static void main(String[] args) {
		new MultiBaseHappiness().go();
	}
}