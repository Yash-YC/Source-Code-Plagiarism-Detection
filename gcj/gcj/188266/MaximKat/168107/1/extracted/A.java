import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	private static final int MAX = 11815000;
	private static int h[][] = new int[11][MAX];
	public static final String FILE = "A-small-attempt0";

	private static int next(int n, int b) {
		int res = 0;
		while (n > 0) {
			int d = n % b;
			res += d * d;
			n /= b;
		}
		return res;
	}

	private static int happy(int n, int b) {
		if (h[b][n] != 0)
			return h[b][n];

		int res = 0, curr = n;
		if (curr > 1000) {
			res = happy(next(curr, b), b);
		} else {
			boolean v[] = new boolean[MAX];
			while (!v[curr]) {
				v[curr] = true;
				curr = next(curr, b);
				res = h[b][curr];
				if (res != 0) {
					break;
				}
			}
			if (v[curr])
				res = -1;
		}
		h[b][n] = res;
		return res;
	}

	public static void main(String args[]) {
		for (int b = 3; b <= 10; b++)
			h[b][1] = 1;
//		boolean hurray = false;
//		int N = 2;
//		while (!hurray) {
//			hurray = true;
//			for (int b = 3; b <= 10; b++) {
//				if (happy(N, b) < 0) {
//					hurray = false;
//					break;
//				}
//			}
//			N++;
//			if (N % 1000 == 0)
//				System.out.println(N);
//		}

		for (int n = 2; n < MAX; n++) {
			if (/*(n<1000 && n%100==0) || */n%10000==0) System.out.println(n);
			for (int b = 3; b <= 10; b++)
				happy(n, b);
		}
		for (int i = 2; i < MAX; i++)
			if (h[6][i] > 0)
				System.out.println(i);
		try {
			Scanner in = new Scanner(new File(FILE + ".in"));
			PrintStream out = new PrintStream(new FileOutputStream(FILE
					+ ".out"));
			int n = in.nextInt();
			in.nextLine();
			for (int testN = 1; testN <= n; testN++) {
				String str = in.nextLine();
				Scanner in2 = new Scanner(str);
				boolean bases[] = new boolean[11];
				while (in2.hasNextInt()) {
					bases[in2.nextInt()] = true;
				}
				int res = -1;
				for (int i = 2; i < MAX; i++) {
					boolean ok = true;
					for (int b = 3; b <= 10; b++) {
						if (bases[b] && (h[b][i] < 0)) {
							ok = false;
							break;
						}
					}
					if (ok) {
						res = i;
						break;
					}
				}
				out.println("Case #" + testN + ": " + res);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
