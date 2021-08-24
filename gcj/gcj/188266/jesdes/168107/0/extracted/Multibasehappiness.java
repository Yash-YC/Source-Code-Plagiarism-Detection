package Round1A2009;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Vector;

public class Multibasehappiness {

	private int solve(int[] in) {
		int ret = 2;
		while (true) {
			boolean isHappyAll = true;
			for (int i = 0; i < in.length; i++) {
				if (!isHappy(ret, in[i])) {
					isHappyAll = false;
					break;
				}
			}
			if (isHappyAll)
				return ret;
			ret++;
		}
	}

	private boolean isHappy(int n, int base) {
		Vector<Integer> d = new Vector<Integer>();
		while (!d.contains(n)) {
			d.add(n);
			n = next(n, base);
			if (1 == n) {
				return true;
			}
		}
		return false;
	}

	private int next(int n, int base) {
		int v = 0;
		while (n > 0) {
			v += (n % base) * (n % base);
			n /= base;
		}
		return v;
	}

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\eclipse\\workspace\\GoogleCodeJam\\bin\\Round1A2009\\Multibasehappiness.in"));
			PrintWriter w = new PrintWriter("C:\\eclipse\\workspace\\GoogleCodeJam\\bin\\Round1A2009\\Multibasehappiness.out");
			Multibasehappiness inst = new Multibasehappiness();

			int N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) {
				String l = br.readLine();
				String[] da = l.split(" ");
				int[] in = new int[da.length];
				for (int j = 0; j < in.length; j++) {
					in[j] = Integer.parseInt(da[j]);
				}
				int ret = inst.solve(in);
				w.print("Case #" + (i + 1) + ": " + ret);
				w.println();
			}

			br.close();
			w.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
