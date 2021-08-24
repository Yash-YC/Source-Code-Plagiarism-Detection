import java.io.*;

public class C {
    static double[][] a = new double[100][100];

    static {
        a[0][0] =1;
        a[0][1] =1;
        a[1][1] =1;
        for (int n =2; n < 99; n++) {
            a[0][n] = 1;
            for (int c = 1; c <= n; c++) {
                a[c][n] = a[c-1][n-1]  + a[c][n-1];
            }
        }
    }
    public static void main(String[] args) throws Exception {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("C-small-attempt0.in")));
            int t = Integer.parseInt(in.readLine());

            PrintWriter out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("cout.txt")));

            for (int tk = 0; tk < t; tk++) {
                String[] v = in.readLine().split(" ");
                int n = Integer.parseInt(v[0]);
                int c  = Integer.parseInt(v[1]);
                double[] res = new double[n + 1];
                res[0] = 0;
                for (int i =1; i <=n; i++) {
                    double x = p(0, i, c, n);
                    for (int j = 0; j < i; j++) {
                        x += (1 +res[j]) * p(i-j, i, c, n);
                    }
                    res[i] = x/(1 - p(0, i, c, n));
                }
                //res[1] = ccn/n/(1 -(n-ccn)/n)*res[1];

                out.println("Case #" + (tk+1) + ": " + res[n]);
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    static double p(int get, int miss, int c, int n) {
        if (c > n)
            return 0;
        return ccn(get, miss) * ccn(c-get, n-miss)/ ccn(c, n);
    }

    static double ccn(int c, int n) {
        if ( c > n)
            return 0;
        if (c < 0)
            return 0;
        return a[c][n];
    }

}