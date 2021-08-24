import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
    private static final String TASKNAME = "a";

    class Tree {
        int shift;
        boolean[] values;

        public Tree(int n) {
            for (shift = 1; shift < n; shift <<= 1) ;
            values = new boolean[shift * 2 + 1];
        }

        void update(int v, int len, int l, int r) {
            if (l >= r) {
                throw new AssertionError();
            }
            if (r - l == len) {
                values[v] = true;
                return;
            }
            len >>= 1;
            if (l < len) {
                update(v * 2, len, l, Math.min(r, len));
            }
            if (r > len) {
                update(v * 2 + 1, len, Math.max(l - len, 0), r - len);
            }
        }

        public void update(int l, int r) {
            if (l >= r) {
                return;
            }
            update(1, shift, l, r);
        }

        boolean get(int pos) {
            boolean ans = false;
            for (pos += shift; pos > 0; pos >>= 1) {
                ans |= values[pos];
            }
            return ans;
        }
    }

    private void solve() throws Exception {
        int tests = nextInt();
        test:
        for (int test = 1; test <= tests; ++test) {
            printf("Case #%d: ", test);
            int n = nextInt();
            int[] lens = new int[n + 1];
            int[] xs = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                xs[i] = nextInt();
                lens[i] = nextInt();
            }

            int dist = nextInt();

            Tree[] trees = new Tree[n + 1];
            boolean ans = false;
            for (int from = 0; from <= n; ++from) {
                trees[from] = new Tree(n + 1);
            }
            trees[0].update(1, 2);

            for (int where = 0; where <= n; ++where) {
                for (int from = 0; from < where; ++from) {
                    if (trees[from].get(where)) {
//                        System.err.println(from + " " + where);
                        long go = 0l + xs[where] + Math.min(lens[where], xs[where] - xs[from]);
                        if (go >= dist) {
                            ans = true;
                        }
                        int l = 0;
                        int r = n;
                        int last = 0;
                        while (l <= r) {
                            int med = (l + r) / 2;
                            if (xs[med] <= go) {
                                last = med;
                                l = med + 1;
                            } else {
                                r = med - 1;
                            }
                        }
                        trees[where].update(where + 1, last + 1);
                    }
                }
            }

            println(ans ? "YES" : "NO");
        }
    }

    class Rat implements Comparable<Rat> {
        long a, b;

        Rat(long a, long b) {
            long gcd = BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).longValue();
            this.a = a / gcd;
            this.b = b / gcd;
        }

        Rat add(Rat r) {
            return new Rat(a * r.b + r.a * b, b * r.b);
        }

        Rat sub(Rat r) {
            return new Rat(a * r.b - r.a * b, b * r.b);
        }

        Rat mul(Rat r) {
            return new Rat(a * r.a, b * r.b);
        }

        Rat div(Rat r) {
            return new Rat(a * r.b, b * r.a);
        }

        double toDouble() {
            return 1 * a / b;
        }

        @Override
        public int compareTo(Rat o) {
            return Long.signum(a * o.b - b * o.a);
        }
    }

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(new OutputStreamWriter(System.out));
            reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
            writer = new PrintWriter(new File(TASKNAME + ".out"));

            solve();

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(13);
        }
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Locale.setDefault(Locale.US);
        new Main().run();
        System.err.printf("%.3f\n", (System.currentTimeMillis() - time) * 1e-3);
    }

    private StringTokenizer tokenizer;
    private PrintWriter writer;
    private BufferedReader reader;

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private void print(Object o) {
        writer.print(o);
    }

    private void println(Object o) {
        writer.println(o);
    }

    private void printf(String format, Object... args) {
        writer.printf(format, args);
    }
}
