import java.io.File;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;


public class C {
	static double[] arr = new double[64];
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("C.in"));
		
		int T = s.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int C = s.nextInt();
			int N = s.nextInt();
			if (N >= C) {
				System.out.println("Case #" + tc + ": 1");
			} else {
				arr[N] = 1;
				for (int i = N + 1; i <= C; i++) {
					arr[i] = 1;
					for (int j = Math.max(N, i - N); j < i; j++) {
						BigDecimal denom = new BigDecimal("0.00000000000000000000000");
						for (int k = 1; k <= Math.min(N, i - N); k++) {
							denom = denom.add(nCr(k, C - j));
						}
						arr[i] += arr[j] * nCr(i - j, C - j).divide(denom, RoundingMode.HALF_UP).doubleValue();
						double prob = nCr(N, j).divide(nCr(N, C), RoundingMode.HALF_UP).doubleValue();
						arr[i] += prob / (1 - prob);
					}
				}
				System.out.println("Case #" + tc + ": " + arr[C]);
			}
		}
	}
	
	static BigDecimal nCr(int n, int r) {
		BigDecimal ans = fact(r);
		ans = ans.divide(fact(n), RoundingMode.HALF_UP);
		ans = ans.divide(fact(r - n), RoundingMode.HALF_UP);
		return ans;
	}
	
	static BigDecimal fact(int n) {
		BigInteger ans = BigInteger.ONE;
		for (int i = 2; i <= n; i++) {
			ans = ans.multiply(new BigInteger("" + i));
		}
		return new BigDecimal(ans + ".00000000000000000000000");
	}
}
