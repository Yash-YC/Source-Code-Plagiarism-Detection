import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.regex.Pattern;

public class A {
    public static void main(String[] args) throws Exception {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
            int t = Integer.parseInt(in.readLine());

            PrintWriter out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("aout.txt")));

            for (int tk = 0; tk < t; tk++) {
                String[] v = in.readLine().split(" ");
                int n = v.length;
                int[] b = new int[n];
                for (int j = 0; j < b.length; j++) {
                    b[j] = Integer.parseInt(v[j]);
                }
                int[][] d = new int[100000][n];
                int res = 1;
                boolean done = false;
                do {
                    res++;
                    done = true;
                    for (int i = 0; i < b.length; i++) {
                        int base = b[i];
                        HashSet<Integer> path = new HashSet<Integer>();
                        path.add(res);
                        int k = res;
                        do {
                            int nk = 0;
                            while (k > 0) {
                                int rem = k % base;
                                nk += rem * rem;
                                k = k /base;
                            }
                            //System.out.println(nk);
                            if (d[nk][i] == 1 || path.contains(nk)) {
                                for (Integer integer : path) {
                                    d[integer][i] = 1;
                                }
                                done = false;
                                break;
                            }
                            path.add(nk);
                            if (nk ==1 || d[nk][i] == 2) {
                                for (Integer integer : path) {
                                    d[integer][i] = 2;
                                }
                                break;
                            }
                            k = nk;
                        } while (true);
                    }
                }while (!done);
                
                out.println("Case #" + (tk+1) + ": " + res);
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }
}
