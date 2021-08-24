/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package r2_a_2016;

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;


/**
 *
 * @author zulkan
 */
public class r2_a_2016 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);

    public static String getString() {
        try {
            return br.readLine();
        } catch (Exception e) {
        }
        return "";
    }

    public static Integer getInt() {
        try {
            return Integer.parseInt(br.readLine());
        } catch (Exception e) {
        }
        return 0;
    }

    public static Integer[] getIntArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Integer temp2[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Integer.parseInt(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static Long[] getLongArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Long temp2[] = new Long[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Long.parseLong(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static String[] getStringArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            String temp2[] = new String[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = (temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static void print(Object a) {
        out.print(a);
    }

    public static void println(Object a) {
        out.println(a);
    }

    public static void printf(String s, Object... a) {
        out.printf(s, a);
    }

    public static int nextInt() {
        return sc.nextInt();
    }

    public static double nextDouble() {
        return sc.nextDouble();
    }

    public static void main(String[] ar) {
        r2_a_2016 c = new r2_a_2016();
        c.solve();
        out.flush();
    }

    public void solve() {
        int tc = getInt();
        for (int kasus = 1; kasus <= tc; kasus++) {
            printf("Case #%d: ", kasus);
            String s = getString();
            
            String out = s.charAt(0) +"";
            for(int i =1 ; i< s.length();i++) {
                String out1 = out + s.charAt(i), out2 = s.charAt(i) +out;
                if(out2.compareTo(out1)>0) {
                    out = out2;
                } else {
                    out = out1;
                }
            }
            println(out);

        }

    }

}
