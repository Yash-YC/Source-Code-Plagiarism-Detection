import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import static java.lang.Math.min;

public class C {
	static int getc(int n, int k) {
		int res = 1;
		for (int i=k+1; i<=n; i++)
			res *= i;
		for (int i=2; i<=n-k; i++)
			res /= i;
		return res;
	}

	public static void main(String[] args) throws Exception {
		Scanner cin = new Scanner(new File("c.in"));
		PrintWriter cout = new PrintWriter(new File("c.out"));
		
		int T = cin.nextInt();
		for (int I=0; I<T; I++) {
			int c = cin.nextInt(),
				n = cin.nextInt();
			double res[] = new double[c+1];
			int nn[] = new int[c+1];
			res[n] = 1;
			nn[n] = 1;
			int Ccn = getc(c, n);
			
			for (int i=n; i<=c; i++) {
				res[i] /= nn[i];
				for (int j=i+1; j<=min(c, i+n); j++) {
					int d2 = j-i,
						d1 = n-d2;
					double r = getc(i, d1) * getc(c-i, d2);
					res[j] += res[i] + Ccn/r;
					nn[j] ++;
				}
			}
			cout.format("Case #%d: %.7f\n", I+1, res[c]);
		}
		
		cout.close();
	}
}
