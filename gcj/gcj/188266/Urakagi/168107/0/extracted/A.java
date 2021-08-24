/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2009r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/**
 *
 * @author Romulus
 */
public class A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        String inFile = "A-small-attempt0.in";
        String outFile = "out.txt";
        BufferedReader in = new BufferedReader(new FileReader(inFile));
        BufferedWriter out = new BufferedWriter(new FileWriter(outFile));

        String line = in.readLine();
        int cases = Integer.parseInt(line);
        int ans;
        for (int i = 1; i <= cases; ++i) {
            line = in.readLine();
            ans = solve(line);
            out.write("Case #" + i + ": " + ans+"\r\n");
            // System.out.println("Case #" + i + ": " + ans);
        }

        out.close();
        in.close();
    }

    static int solve(String Bs) {
        ArrayList<Integer> B = new ArrayList<Integer>();
        for (String s : Bs.split(" ")) {
            B.add(Integer.parseInt(s));
        }
        for (int k = 2; k < 1000000000; ++k) {
            boolean allHappy = true;
            for (int b : B) {
                if (!isHappy(k, b, new ArrayList<Integer>())) {
                    allHappy = false;
                    break;
                }
            }
            if (!allHappy) continue;
            return k;
        }
        return -1;
    }

    static boolean isHappy(int k, int base, ArrayList<Integer> hasSeen) {
        // System.out.println("k="+k+", base="+base);
        int c;
        for (int i = 1; (c = (int) Math.pow(base, i)) <= k; ++i) {
            if (c == k) {
                return true;
            }
        }
        if (hasSeen.contains(k)) return false;
        hasSeen.add(k);
        int sq = 0;
        //ArrayList<Integer> digits = new ArrayList<Integer>();
        for (; c > 0; c /= base) {
            int d = k / c;
            //digits.add(d);
            sq += d * d;
            k -= d * c;
        }
//        for (int i : digits) {
            //System.out.print(i);
   //     }
        //System.out.println();
        return isHappy(sq, base, hasSeen);
    }
}
