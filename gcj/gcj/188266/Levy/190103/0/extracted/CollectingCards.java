import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class CollectingCards {
	static double[][] C;
	
	public static void main(String[] args) throws Exception {
		FileInputStream in = new FileInputStream("C-small-attempt2.in");
		System.setIn(in);
		PrintStream out = new PrintStream("c.out");
		System.setOut(out);
		
		C = new double[50][50];
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j)
				C[i][j] = 0;
		for (int i = 1; i < 50; ++i) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j)
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}

		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for (int i = 0; i < T; ++i) {
			int N = input.nextInt(),
				M = input.nextInt();
			double[] E = new double[N + 1];
			E[M] = 1;
			for (int j = M + 1; j <= N; ++j) {
				E[j] = 0;
				double t = 0, p = 0;
				for (int n = 1; n <= Math.min(j - M, M); ++n) {
					System.err.println(N + " " + (j-n) + " ");
					double tt = C[N-(j-n)][n];
					tt = tt * (C[j-n][M-n]);
					tt = tt / (C[N][M]);
					p += tt;
					System.err.println(p);
					t += tt * (E[j-n] + 1);
				}
				t += 1 - p;
				System.err.println(t + " " + C[N][M] + " " + p);
				E[j] = t / p;
			}
			System.out.println("Case #" + (i+1) + ": " + E[N]);
		}
	}
}

