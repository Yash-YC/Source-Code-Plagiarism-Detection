package round1a;

import java.io.*;
import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by IntelliJ IDEA.
 * User: rajeev
 * Date: Sep 10, 2009
 * Time: 10:52:21 PM
 * To change this template use File | Settings | File Templates.
 */
public class ProbA {
    public static void main(String[] args) throws IOException {
        init();
        BufferedReader br = new BufferedReader(new FileReader("/home/rajeev/IdeaProjects/CodeJam/A-small.in"));
        File f = new File("/home/rajeev/IdeaProjects/CodeJam/A-results.out");
        if (f.exists()) {
            f.delete();
        }
        PrintWriter pw = new PrintWriter("/home/rajeev/IdeaProjects/A-results.out");


        int cases = Integer.parseInt(br.readLine());
        for (int cs = 1; cs <= cases; cs++) {
            String[] bs = br.readLine().trim().split(" ");
            int[] bases = new int[bs.length];
            for (int i = 0; i < bases.length; i++) {
                bases[i] = Integer.parseInt(bs[i]);
            }
//            System.out.println("enter");

            outer:
            for (int i = 2; ; i++) {
                for (int j = 0; j < bases.length; j++) {
//                    if (i == 5) {
//                        System.out.println("i,j" + i + ", " + j);
//
//                    }
                    String res = convert(i, bases[j]);
                    HashSet<Long> map = new HashSet<Long>();
                    map.add(new Long(i));
//                    int last = res.length();
                    while (!res.equals("1")) {

//                          last = res.length();

                        long l = doOperation(res);
//                        if (i == 91 && cs == 3) {
//                            System.out.println("cs, l" + cs + ", " + l );
//                        }
                        if (!map.contains(l)) {
                            map.add(l);
                        } else {
                            continue outer;
                        }
//                          if (j == 2)
//                              System.out.println("l=" + l);
                        res = convert(l, bases[j]);
//                          if (res.length() >= last) {
//                              continue outer;
//                          }
//                          if (j == 2)
//                              System.out.println("res= " +res);
                    }
                    if (!res.equals("1")) {
                        continue outer;
                    }
                }
                pw.println("Case #" + cs + ": " + i);
                break outer;
            }

        }
        pw.flush();
        ;
        pw.close();
    }

    static int[] tonum = new int[100];

    static void init() {
        int start = '0';
        int end = '9';
        int ind = 0;
        for (int i = 0; i<100; i++) {
            tonum[i] = -1;
        }
        for (int i = start; i <= end; i++, ind++) {
            tonum[i] = ind;
        }
    }


    static long doOperation(String input) {
        long sum = 0;
        int x = 0;
        for (char d : input.toCharArray()) {

            x = tonum[d];
//            if (x == -1) {
//                System.out.println("minus" + d);
//            }
            sum += (x * x);
        }
        return sum;
    }

    static String convert(long value, int targetBase) {
        return new java.math.BigInteger(Long.toString(value), 10).toString(targetBase);
    }


}
