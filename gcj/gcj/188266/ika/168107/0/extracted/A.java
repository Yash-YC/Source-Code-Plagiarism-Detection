import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int T = nextInt();

        int[][] f = new int[11][(int) 1e5];

        for (int i = 2; i < f.length; i++) {
            Arrays.fill(f[i], -1);
            for (int x = 1; x < f[0].length; x++) {
                get(x, i, f[i]);
            }
        }

        for (int t = 1; t <= T; t++) {
            String[] s = nextLine().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                a[i] = Integer.parseInt(s[i]);
            }

            int r = 1;
            M:
            while (++r > 0) {
                for (int i : a) {
                    if (f[i][r] == 0) {
                        continue M;
                    }
                }
                break;
            }

            println("Case #" + t + ": " + r);
            System.out.println("Case #" + t + ": " + r);
        }

        System.out.println((System.nanoTime() - startTime) / 1e9);  out.close();
    }

    int get(int x, int base, int[] f) {
        if (f[x] == -2) {
            return f[x] = 0;
        }
        if (f[x] != -1) {
            return f[x];
        }
        int s = 0, a = x;
        while (a > 0) {
            s += (a % base) * (a % base);
            a /= base;
        }
        if (s == 1) {
            return f[x] = 1;
        }
        f[x] = -2;
        return f[x] = get(s, base, f);
    }

    //-----------------------------------------------------------------------------------

    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("a.in"));
        out = new PrintWriter("a.out");
        tokenizer = new StringTokenizer("");

        new Thread(new A()).start();
        out.close();
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
