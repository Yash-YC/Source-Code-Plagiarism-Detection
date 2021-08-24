/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package r2;

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;

/**
 *
 * @author zulkan
 */
public class b_2016 {

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
        System.out.print(a);
    }

    public static void println(Object a) {
        System.out.println(a);
    }

    public static void printf(String s, Object... a) {
        System.out.printf(s, a);
    }

    public static int nextInt() {
        return sc.nextInt();
    }

    public static double nextDouble() {
        return sc.nextDouble();
    }

    public static void main(String[] ar) {
        b_2016 c = new b_2016();
        c.solve();
        out.flush();
    }
    ArrayList<Integer[]> inp = new ArrayList<>();
    HashMap<List<Integer>, Integer> res = new HashMap<>();

    boolean kebawah(Integer data[][], int i, int n, int ii) {

        if (i == n) {

            HashMap<List<Integer>, Integer> res_ = new HashMap<>();
            for (int x = 0; x < n; x++) {
                List<Integer> temp_res = Arrays.asList(data[x]);

                if (!res_.containsKey(temp_res)) {
                    res_.put(temp_res, 0);
                }
                res_.put(temp_res, res_.get(temp_res) + 1);
            }

            for (int x = 0; x < n; x++) {
                List<Integer> temp_res = new ArrayList<>();

                for (int j = 0; j < n; j++) {
                    temp_res.add(data[j][x]);
                }
                if (!res_.containsKey(temp_res)) {
                    res_.put(temp_res, 0);
                }
                res_.put(temp_res, res_.get(temp_res) + 1);

            }
            int tt = 0;
            for (List<Integer> key : res_.keySet()) {
                if (!res.containsKey(key)) {

                    tt += res_.get(key);
                    continue;
                }
                tt += Math.abs(res_.get(key) - res.get(key));
                //res.get(key) < res_.get(key)
            }

            if (tt != 1) {
                return false;
            }
            return true;
        }
        if (ii == inp.size()) {
            return false;
        }
        Integer k[] = inp.get(ii);

        data[i] = k;
        boolean ok2 = true;
        if (i > 0) {
            for (int j = 0; j < n; j++) {
                if (data[i][j] <= data[i - 1][j]) {
                    ok2 = false;
                    break;
                }
            }
        }
        if (ok2) {
           // println(i + " " + Arrays.asList(data[i]));
            boolean p = kebawah(data, i + 1, n, ii + 1);
            if (p) {
                return true;
            } else {
                return kebawah(data, i, n, ii + 1);
            }
        }

        return kebawah(data, i, n, ii + 1);
    }

    boolean kesamping(Integer data[][], int col, int n, int ii
    ) {
        if (col == n) {

            return true;
        }
        while (inp.size() > 0) {
            Integer k[] = inp.get(ii);

            for (int i = 0; i < n; i++) {
                data[i][col] = k[i];
            }
            boolean ok2 = true;
            for (int j = 0; j < n; j++) {
                if (data[j][col] <= data[j][col - 1]) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                boolean p = kesamping(data, col + 1, n, ii + 1);
                if (p) {
                    return true;
                }
            }
        }
        return false;
    }

    public void solve() {
        int tc = getInt();
        for (int kasus = 1; kasus <= tc; kasus++) {
            printf("Case #%d: ", kasus);

            int n = getInt();
            inp.clear();
            res.clear();

            List<String> ts = new ArrayList<>();
            Integer data[][] = new Integer[n][n];

            for (int i = 0; i < 2 * n - 1; i++) {
                String s = getString();
                ts.add(s);
            }

            for (String s : ts) {
                String k[] = s.split(" ");
                Integer p[] = new Integer[n];
                for (int i = 0; i < n; i++) {
                    p[i] = new Integer(k[i]);
                }
                inp.add(p);
                List<Integer> temp = Arrays.asList(p);
                if (!res.containsKey(temp)) {
                    res.put(temp, 0);
                }
                res.put(temp, res.get(temp) + 1);
            }
            Collections.sort(inp, new Comparator<Integer[]>() {
                @Override
                public int compare(Integer[] o1, Integer[] o2) {
                    for (int i = 0; i < n; i++) {
                        if (o1[i].compareTo(o2[i]) != 0) {
                            return o1[i].compareTo(o2[i]);
                        }
                    }
                    return 0;
                }

            });

            boolean valid = kebawah(data, 0, n, 0);
            //println(valid);

            /*
            if (!valid) {
                inp.clear();
                for (List<Integer> p : res) {
                    Integer k[] = new Integer[n];
                    for (int i = 0; i < n; i++) {
                        k[i] = p.get(i);
                    }
                    inp.add(k);
                }
                
                Collections.sort(inp, new Comparator<Integer[]>() {
                    @Override
                    public int compare(Integer[] o1, Integer[] o2) {
                        for (int i = 0; i < n; i++) {
                            if (o1[i].compareTo(o2[i]) != 0) {
                                return o1[i].compareTo(o2[i]);
                            }
                        }
                        return 0;
                    }

                });
                for (int i = 0; i < n; i++) {
                    //data[i][0] = inp.get(0)[i];
                }
                //inp.removeFirst();
                //valid = kesamping(data, 1, n);

            }
             */
            HashMap<List<Integer>, Integer> res_ = new HashMap<>();
            for (int i = 0; i < n; i++) {
                List<Integer> temp_res = Arrays.asList(data[i]);

                if (!res_.containsKey(temp_res)) {
                    res_.put(temp_res, 0);
                }
                res_.put(temp_res, res_.get(temp_res) + 1);
            }

            for (int i = 0; i < n; i++) {
                List<Integer> temp_res = new ArrayList<>();

                for (int j = 0; j < n; j++) {
                    temp_res.add(data[j][i]);
                }
                if (!res_.containsKey(temp_res)) {
                    res_.put(temp_res, 0);
                }
                res_.put(temp_res, res_.get(temp_res) + 1);

            }

            for (List<Integer> key : res_.keySet()) {
                if (!res.containsKey(key) || res.get(key) < res_.get(key)) {
                    for (int i = 0; i < n; i++) {
                        if (i > 0) {
                            print(" ");
                        }
                        print(key.get(i));
                    }
                    println("");

                    break;
                }
            }

        }
    }

}
