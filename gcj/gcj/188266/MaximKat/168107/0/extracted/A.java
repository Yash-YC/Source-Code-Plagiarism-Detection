import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	private static final int MAX = 1000000;
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
		if (n > 1000) {
			return happy(next(n, b), b);
		}
		boolean v[] = new boolean[MAX];
		while (!v[n]) {
			// System.out.println(n);
			v[n] = true;
			n = next(n, b);
			if (h[b][n] != 0)
				return h[b][n];
		}
		return -1;
	}

	public static void main(String args[]) {
		for (int b = 2; b <= 10; b++)
			h[b][1] = 1;
		for (int n = 2; n < MAX; n++) {
			//if (n<1000 || n%10000==0) System.out.println(n);
			for (int b = 2; b <= 10; b++)
				h[b][n] = happy(n, b);
		}
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
					for (int b = 2; b <= 10; b++) {
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
