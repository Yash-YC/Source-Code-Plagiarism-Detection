import java.io.*;
import java.util.*;

public class Main {
    private static final String TASKNAME = "b";

    private void solve() throws Exception {
        int tests = nextInt();
        test:
        for (int test = 1; test <= tests; ++test) {
            printf("Case #%d:", test);
            int n = nextInt();
            int w = nextInt();
            int l = nextInt();
            Integer[] inds = new Integer[n];
            final int[] rs = new int[n];
            for (int i = 0; i < n; ++i) {
                rs[i] = nextInt();
                inds[i] = i;
            }
            Arrays.sort(inds, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return rs[o2] - rs[o1];
                }
            });

            int[] ansX = new int[n];
            int[] ansY = new int[n];
            boolean[] col = new boolean[n];
//            System.err.println("inds" + Arrays.toString(inds));

            ArrayList<Integer> lastLine = new ArrayList<Integer>();
            while (true) {
                int first = -1;
                for (int i = 0; i < n; ++i) {
                    if (!col[inds[i]]) {
                        first = i;
                        break;
                    }
                }
                if (first < 0) {
                    break;
                }
//                System.err.println("first = " + inds[first]);
                ArrayList<Integer> curLine = new ArrayList<Integer>();
                curLine.add(inds[first]);

                ansX[inds[first]] = 0;
                ansY[inds[first]] = 0;
                if (!lastLine.isEmpty()) {
                    int a = lastLine.get(0);
                    ansY[inds[first]] = ansY[a] + rs[a] + rs[inds[first]];
                }
                col[inds[first]] = true;

                int x = rs[inds[first]];

                for (int i = 0; i < n; ++i) {
                    int ii = inds[i];
                    if (col[ii] || x + rs[ii] > w) {
                        continue;
                    }
                    col[ii] = true;
                    curLine.add(ii);
                    ansX[ii] = x + rs[ii];
                    ansY[ii] = getMax(lastLine, ansX, ansY, x, x + rs[ii] * 2, rs);
                    if (ansY[ii] != 0) {
                        ansY[ii] += rs[ii];
                    }
                    if (ansY[ii] > l) {
//                        throw new AssertionError("fd");
                    }
                    x += rs[ii] * 2;
                }
//                System.err.println(curLine);
                lastLine = curLine;
            }
            for (int i = 0; i < n; ++i) {
                print(" " + ansX[i] + " " + ansY[i]);
            }
            println("");
        }
    }

    private int getMax(ArrayList<Integer> lastLine, int[] ansX, int[] ansY, int l, int r, int[] rs) {
        int ans = 0;

        for (int i : lastLine) {
            int xl = ansX[i] - rs[i];
            int xr = ansX[i] + rs[i];
            xl = Math.max(l, xl);
            xr = Math.min(r, xr);
            if (xl < xr) {
                ans = Math.max(ans, ansY[i] + rs[i]);
            }
        }
        return ans;
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
