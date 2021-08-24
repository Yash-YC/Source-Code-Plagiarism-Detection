import java.util.*;
import java.io.*;

public class a_solve implements Runnable {
	StreamTokenizer in;
	BufferedReader br;
	PrintWriter out;
	String TASK = "A-large";
	
	int[][] c;
	boolean happy(int a, int b) {
		if (c[b][a] != 0) return c[b][a] == 1;
		HashSet<Integer> set = new HashSet<Integer>(); 
		int k = a;
		while (true) {
			if (k == 1) {
				c[b][a] = 1;
				return true;
			}
			set.add(k);
			int t = 0;
			while (k > 0) {
				int x = k % b;
				t += x * x;
				k /= b;
			}
			k = t;
			if (k < c[b].length) {
				if (c[b][k] == 1) {
					c[b][a] = 1;
					return true;
				}
				if (c[b][k] == -1) {
					c[b][a] = -1;
					return false;
				}
			}
			if (set.contains(k)) {
				c[b][a] = -1;
				return false;
			}
		}
	}
	
	void solve() throws Exception {
		c = new int[11][1000001];
		int[] res = new int[1 << 8];
		Arrays.fill(res, Integer.MAX_VALUE);
		int count = 0;
		for (int i = 2; i < 1000000; i++) {
			int k = 0;
			for (int j = 3; j <= 10; j++) {
				if (happy(i, j)) k |= 1 << (j - 3);
			}
			if (res[k] == Integer.MAX_VALUE) {
				res[k] = i;
				count++;
			}
		}
		for (int k = 0; k < res.length; k++) {
			if (res[k] > 0) {
				for (int p = 0; p < k; p++) {
					if ((p | k) == k && res[p] > res[k]) {
						if (res[p] == Integer.MAX_VALUE) count++;
						res[p] = res[k];
					}
				}
			}
		}
		System.out.println(count);
		
		int t = Integer.parseInt(br.readLine());
		for (int tt = 0; tt < t; tt++) {
			String[] bb = br.readLine().split(" +");
			int n = bb.length;
			int[] a = new int[n];
			int k = 0; 
			for (int i = 0; i < n; i++) {
				a[i] = Integer.parseInt(bb[i]);
				if (a[i] > 2) k |= 1 << (a[i] - 3);
			}
			out.printf("Case #%d: %d\n", tt + 1, res[k]);
		}
	}
	
	int nextInt() throws Exception {
		in.nextToken();
		return (int)in.nval;
	}
	public void run() {
		try {
			br = new BufferedReader(new FileReader(TASK + ".in"));
			in = new StreamTokenizer(br);
			out = new PrintWriter(new BufferedWriter(new FileWriter(TASK + ".out")));
			solve();
			out.flush();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(31337);
		}
	}
	public static void main(String[] args) {
		new Thread(new a_solve()).start();
	}
}
