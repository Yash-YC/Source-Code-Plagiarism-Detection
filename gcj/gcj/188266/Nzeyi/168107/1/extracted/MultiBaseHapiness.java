/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rw.nzeyi.codejam.round1.a;

import java.util.ArrayList;
import java.util.List;

import java.io.*;

/**
 *
 * @author antoine
 */
public class MultiBaseHapiness {

    public static int digitsSquareSum(int n, int b) {
        int res = 0;
        int m = n;
        int k = 0;

        k = m % b;
        m = (int) (m / b);
        res += k * k;

        while (m != 0) {
            k = m % b;
            m = (int) (m / b);
            res += k * k;
        }
        return res;
    }

    public static List<Integer> computeDigitsSquareSum(int n, int b) {
        List<Integer> ret = new ArrayList<Integer>();
        boolean flag = true;
        int r = n;
        while (flag) {
            r = digitsSquareSum(r, b);
            if (ret.contains(r)) {
                return ret;
            }
            ret.add(r);
            if (ret.contains(1)) {
                return ret;
            }
        }
        return ret;
    }

    public static boolean isHappy(int n, int b) {
        return computeDigitsSquareSum(n, b).contains(1);
    }

    public static boolean isHappy(int n, int[] b) {
        for (int i = 0; i < b.length; i++) {
            if (!isHappy(n, b[i])) {
                return false;
            }
        }
        return true;
    }

    public static int getHappy(int[] b) {
        for (int n = 2; n < Integer.MAX_VALUE; n++) {
            if (isHappy(n, b)) {
                return n;
            }
        }
        return 0;
    }

    public static int getHappy(String str) {
        return getHappy(getInt(str));
    }

    public static int[] getInt(String str) {
        String[] data = str.split(" ");
        int[] ret = new int[data.length];
        for (int i = 0; i < data.length; i++) {
            ret[i] = Integer.parseInt(data[i]);
        }
        return ret;
    }

    public static void execute() {

        String in = "/home/antoine/Desktop/A-large.in";
        String out = "/home/antoine/Desktop/A-large.out";
        String res = "";
        try {
            int T;
            BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(in)));
            String t = reader.readLine();
            T = Integer.parseInt(t);
            for (int i = 0; i < T; i++) {
                res += "Case #" + (i + 1) + ": " + getHappy(reader.readLine()) + "\n";

            }
            PrintWriter writer = new PrintWriter(new FileOutputStream(out));
            writer.write(res);
            writer.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        execute();
        //System.out.println(digitsSquareSum(3, 3));
    }
}
