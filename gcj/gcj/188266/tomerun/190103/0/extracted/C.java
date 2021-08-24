import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	static double[] p = new double[41];
	static double[][] comb = new double[41][41];

	public static void main(String[] args) throws Exception {
		pascal();
//		String fileName = args.length > 0 ? args[0] : "bin\\C.txt";
				String fileName = args.length > 0 ? args[0] : "bin\\C-small-attempt1";
		Scanner sc;
		sc = new Scanner(new File(fileName + ".in"));
		FileWriter writer = new FileWriter(new File(fileName + ".out"));
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i) {
			int C = sc.nextInt();
			int N = sc.nextInt();
			Arrays.fill(p, 0);

			writer.write("Case #" + (i + 1) + ": " + calc(C, C, N) + "\n");
		}
		writer.close();
	}

	static double calc(int C, int rest, int N) {
		if (rest == 0) {
			return 0;
		}
		if (p[rest] != 0) {
			return p[rest];
		}
		double v = 0;
		for (int i = Math.max(1, N - (C - rest)); i <= Math.min(rest, N); ++i) {
			v += comb[rest][i] * comb[C - rest][N - i] / comb[C][N] * (calc(C, rest - i, N) + 1);
		}
		double res = v;
		double f = comb[C - rest][N] / comb[C][N];
		res += f * (1 + next(v, 1, f));
		p[rest] = res;
		return res;
	}

	static double next(double v, int depth, double factor) {
		if (depth > 1000) {
			return 0;
		}
		return v + factor * (1 + next(v, depth + 1, factor));
	}

	public static void pascal() {
		int size = 41;
		for (int i = 0; i < size; i++) {
			comb[i][0] = 1;
		}
		for (int i = 1; i < size; ++i) {
			for (int j = 1; j <= i; ++j) {
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
				if (comb[i][j] < 0) {
					comb[i][j] = Double.MAX_VALUE;
				}
			}
		}
	}

}
