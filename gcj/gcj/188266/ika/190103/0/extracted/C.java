import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int T = nextInt();

        BigInteger[] F = new BigInteger[50];
        F[0] = BigInteger.ONE;
        for (int i = 1; i < F.length; i++) {
            F[i] = F[i - 1].multiply(BigInteger.valueOf(i));
        }
        BigInteger[][] C = new BigInteger[F.length][F.length];
        for (int i = 0; i < F.length; i++) {
            for (int j = 0; j <= i; j++) {
                C[i][j] = F[i].divide(F[j]).divide(F[i - j]);
            }
        }

        for (int t = 1; t <= T; t++) {
            int c = nextInt();
            int n = nextInt();

            double q = C[c][n].doubleValue();
            double[] r = new double[c + 1];
            for (int k = 1; k < r.length; k++) {
                r[k] = 1;
                for (int add = Math.max(1, k + n - c); add <= Math.min(k, n); add++) {
                    r[k] += r[k - add] * C[k][add].multiply(C[c - k][n - add]).doubleValue() / q;
                }
                if (k + n <= c) {
                    r[k] /= 1 - C[c - k][n].doubleValue() / q;
                }
            }

            println("Case #" + t + ": " + r[c]);
        }

        

        System.out.println((System.nanoTime() - startTime) / 1e9);
        out.close();
    }

    //-----------------------------------------------------------------------------------

    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("problem.in"));
        out = new PrintWriter("problem.out");
        tokenizer = new StringTokenizer("");

        new Thread(new C()).start();
    }

    private static String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static String nextToken() {
        if (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private static long nextLong() {
        return Long.parseLong(nextToken());
    }

    private static double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }

    private static void println(Object o) {
        out.println(o);
    }
}
