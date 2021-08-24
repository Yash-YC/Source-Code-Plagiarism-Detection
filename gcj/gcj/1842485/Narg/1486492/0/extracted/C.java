import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
    private static final String TASKNAME = "c";

    int prod(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }

    private void solve() throws Exception {
        int tests = nextInt();
        Random random = new Random(566);
        test:
        for (int test = 1; test <= tests; ++test) {
            printf("Case #%d:", test);
            int n = nextInt();
            long time = System.currentTimeMillis();
            int[] highest = new int[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                highest[i] = nextInt() - 1;
                if (highest[i] <= i) {
                    println(" Impossible");
                    continue test;
                }
            }
            ArrayList<Integer> perm = new ArrayList<Integer>();
            for (int i = 0; i < n; ++i) {
                perm.add(i);
            }
            int[] p = new int[n];
            boolean yes = false;
            for (int it = 0; !yes && (it % 100 != 0 || (System.currentTimeMillis() - time) < 2000); ++it) {
                for (int i = 0; i < n; ++i) {
                    p[i] = perm.get(i);
                }
                boolean ok = true;
                for (int i = 0; ok && i < n - 1; ++i) {
                    for (int j = i + 1; ok && j < highest[i]; ++j) {
                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) > 0;
                    }
                    for (int j = highest[i] + 1; ok && j < n; ++j) {
                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) >= 0;
                    }
                }
                if (ok) {
                    yes = true;
                }
                Collections.shuffle(perm, random);
            }
            for (int it = 0; !yes && (it % 100 != 0 || (System.currentTimeMillis() - time) < 4000); ++it) {
                for (int i = 0; i < n; ++i) {
                    p[i] = random.nextInt(10000);
                }
                boolean ok = true;
                for (int i = 0; ok && i < n - 1; ++i) {
                    for (int j = i + 1; ok && j < highest[i]; ++j) {
                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) > 0;
                    }
                    for (int j = highest[i] + 1; ok && j < n; ++j) {
                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) >= 0;
                    }
                }
                if (ok) {
                    yes = true;
                }
//                Collections.shuffle(perm, random);
            }

//            for (int i = 0; !yes && i < n; ++i) {
//                perm.set(i, 1 << i);
//            }
//            for (int it = 0; !yes && (it % 100 != 0 || (System.currentTimeMillis() - time) < 5000); ++it) {
//                for (int i = 0; i < n; ++i) {
//                    p[i] = perm.get(i);
//                }
//                boolean ok = true;
//                for (int i = 0; ok && i < n - 1; ++i) {
//                    for (int j = i + 1; ok && j < highest[i]; ++j) {
//                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) > 0;
//                    }
//                    for (int j = highest[i] + 1; ok && j < n; ++j) {
//                        ok &= prod(j - i, p[j] - p[i], highest[i] - i, p[highest[i]] - p[i]) >= 0;
//                    }
//                }
//                if (ok) {
//                    yes = true;
//                }
//                Collections.shuffle(perm, random);
//            }

            if (!yes) {
                println(" Impossible");
            } else {
                for (int x : p) {
                    print(" " + x);
                }
                println("");
            }
            writer.flush();
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
        new C().run();
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
