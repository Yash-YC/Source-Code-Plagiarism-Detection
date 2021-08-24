import java.io.*;
import java.util.*;

public class Happiness {
	static int[] mark = new int[100000];
	static int ph = 0;
	
	static boolean check(int x, int base) {
		ph++;
		while (x > 1) {
			if (x < mark.length) {
				if (mark[x] == ph) return false;
				mark[x] = ph;
			}
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
		FileInputStream in = new FileInputStream("a-large.in");
		System.setIn(in);
		PrintStream out = new PrintStream("a.out");
		System.setOut(out);

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		/*int T = Integer.parseInt(input.readLine());
		int[] res = new int[512];
		for (int i = 0; i < 512; ++i) {
			System.err.println(i);
			if (Integer.bitCount(i) < 2) continue;
			int[] bases = new int[Integer.bitCount(i)];
			int k = 0;
			for (int j = 0; j < 9; ++j)
				if ((i & 1 << j) != 0) bases[k++] = j + 2;
			res[i] = solve(bases); 
		}
		for (int i = 0; i < 512; ++i)
			System.out.println(i + " " + res[i]);*/
		
		int[] res = new int[512];
		BufferedReader reader = new BufferedReader(new FileReader("a.all"));
		for (int i = 0; i < 512; ++i) 
			res[i] = Integer.parseInt(reader.readLine().split(" ")[1]);
		reader.close();
		
		int T = Integer.parseInt(input.readLine());
		for (int i = 0; i < T; ++i) {
			String[] ss = input.readLine().split(" ");
			int[] ii = new int[ss.length];
			for (int j = 0; j < ii.length; ++j)
				ii[j] = Integer.parseInt(ss[j]);
			
			int s = 0;
			for (int x: ii)
				s |= (1 << (x - 2));
			System.out.println("Case #" + (i+1) + ": " + res[s]);
		}
	}
}
