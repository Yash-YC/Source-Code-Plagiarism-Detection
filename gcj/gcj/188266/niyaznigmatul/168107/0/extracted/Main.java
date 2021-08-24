import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.math.*;
import java.io.*;

public class Main implements Runnable{
    public static void main(String[] args) {
        new Thread(new Main()).start();
    }
    StringTokenizer st;
    PrintWriter out;
    BufferedReader br;
    boolean eof = false, in_out = false;
    private String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }
    private String nextLine() {
        String ret = "";
        try {
            ret = br.readLine();
        } catch (Exception e) {
            ret = "";
        }
        if (ret == null) {
            eof = true;
            return "$";
        }
        return ret;
    }
    private String nextString() {
        return nextToken();
    }
    private int nextInt() {
        return Integer.parseInt(nextToken());
    }
    private long nextLong() {
        return Long.parseLong(nextToken());
    }
    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    private BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }
    private String to_precision(double x, int kol) {
        if (kol == 0) {
            return Long.toString((long)Math.floor(x));
        }
        String ret = Long.toString((long)Math.floor(x));
        x -= Math.floor(x);
        for (int i=0; i<kol; i++) {
            x *= 10;
        }
        ret += "." + Long.toString((long)Math.floor(x));
        if ((long)Math.floor(x) == 0) {
            ret += "0";
        }
        return ret;
    }
    private static double EPS = 1e-9;
    String INFILE = "bear.in", OUTFILE = "bear.out";
    private boolean is_happy(int x, int k) {
        TreeSet<Integer> w = new TreeSet<Integer>();
        w.add(x);
        while (true) {
            int sum = 0;
            for (;x > 0; x /= k) sum += (x % k) * (x % k);
            if (w.contains(sum)) return false;
            x = sum;
            if (x == 1) return true;
            w.add(x);
        }
    }
    int[] dp;
    private void gen() {
        dp[0] = 2;
        for (int i = 1; i < (1 << 9); i++) {
            ArrayList<Integer> p = new ArrayList<Integer>();
            for (int j = 0; j < 10; j++) if (((i >> j) & 1) == 1) p.add(j + 2);
            int[] r = new int[p.size()];
            for (int j = 0; j < p.size(); j++) r[j] = p.get(j);
            int ans = 2;
            for (int j = 0; j < 10; j++) if (((i >> j) & 1) == 1) ans = Math.max(ans, dp[i ^ (1 << j)]);
            while (true) {
                boolean ok = true;
                for (int j = 0; j < r.length; ++j) if (!is_happy(ans, r[j])) {
                    ok = false;
                    break;
                }
                if (ok) {
                    dp[i] = ans;
                    break;
                }
                ans++;
            }
        }
    }
    private void solve() {
        int T = nextInt();
        dp = new int[1 << 9];
        gen();
        for (int www = 1; www <= T; www++) {
            StringTokenizer ss = new StringTokenizer(nextLine());
            int mask = 0;
            while (ss.hasMoreTokens()) {
                mask ^= 1 << (Integer.parseInt(ss.nextToken()) - 2);
            }
            out.println("Case #" + www + ": " + dp[mask]);            
        }
    }
    public void run() {
        try {
            br = new BufferedReader(new FileReader(new File((in_out) ?  INFILE  : "input.txt")));
            out = new PrintWriter(new File((in_out) ? OUTFILE : "output.txt"));
            //br = new BufferedReader(new FileReader(new File("input.txt")));
            //out = new PrintWriter(new File("output.txt"));
        } catch (Exception e) {
            System.exit(111);
        }
        solve();
        out.close();
    }
}
