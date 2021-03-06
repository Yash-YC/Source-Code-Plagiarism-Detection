import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class MultiBaseHappiness {
    public static final int LIMIT = 11814486;
    public static BufferedReader BR;
    public static byte[][] memo;
    public static int[] cache;
    

    public static String readLine() {
        try {
            return BR.readLine();
        } catch(Exception E) {
            System.err.println(E.toString());
            return null;
        }
    }

    public static int digitSquareSum(int base, int x) {
        int total = 0;
        //System.out.print("Base " + base + ", " + x + ": ");
        while (x > 0) {
            int digit = x % base;
            total += digit*digit;
            x /= base;
        }
        //System.out.println("" + total);
        return total;
    }

    public static boolean isHappy(int base, int x) {
        Set<Integer> seen = new HashSet<Integer>();
        while (x != 1 && memo[base][x] > 1 && !seen.contains(x)) {
            seen.add(x);
            x = digitSquareSum(base, x);
        }
        boolean result = false;
        if (x == 1 || memo[base][x] == 1) result = true;
        for (int y : seen) memo[base][y] = (byte) (result ? 1 : 0);
        return result;
    }

    // ****** MAIN ******

    public static void main(String [] args) throws Exception {
        BR = new BufferedReader(new InputStreamReader(System.in));
        
        /* This is what I used to generate the entries in cache:
        memo = new byte[11][LIMIT];
        cache = new int[1<<9]; Arrays.fill(cache, -1);
        for (int base = 0; base < memo.length; ++base) Arrays.fill(memo[base], (byte) 2);
        for (int x = 2; x < LIMIT; ++x) {
            int mask = (1 << 0) | (1 << 2); // bases 2 and 4 are always happy
            if (isHappy(3, x)) mask |= (1 << 1);
            for (int base = 5; base <= 10; ++base) {
                if (isHappy(base, x)) mask |= (1 << (base-2));
            }
            for (int m = 0; m <= mask; ++m) if ((mask & m) == m && cache[m] < 0) cache[m] = x;
        }
        for (int mask = 0; mask < cache.length; ++mask) System.out.println("" + cache[mask] + ",");
        */
        
        cache = new int[] {
2,
2,
3,
3,
2,
2,
3,
3,
5,
5,
23,
23,
5,
5,
23,
23,
6,
6,
79,
79,
6,
6,
79,
79,
49,
49,
79,
79,
49,
49,
79,
79,
7,
7,
143,
143,
7,
7,
143,
143,
7,
7,
143,
143,
7,
7,
143,
143,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
49,
49,
2207,
2207,
8,
8,
27,
27,
8,
8,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
216,
216,
3879,
3879,
216,
216,
3879,
3879,
1975,
1975,
3879,
3879,
1975,
1975,
3879,
3879,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
1001,
1001,
5719,
5719,
47089,
47089,
47089,
47089,
47089,
47089,
47089,
47089,
48769,
48769,
58775,
58775,
48769,
48769,
58775,
58775,
3,
3,
3,
3,
3,
3,
3,
3,
27,
27,
27,
27,
27,
27,
27,
27,
415,
415,
707,
707,
415,
415,
707,
707,
415,
415,
1695,
1695,
415,
415,
1695,
1695,
125,
125,
143,
143,
125,
125,
143,
143,
125,
125,
143,
143,
125,
125,
143,
143,
2753,
2753,
37131,
37131,
2753,
2753,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
37131,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
27,
4977,
4977,
10089,
10089,
4977,
4977,
10089,
10089,
4977,
4977,
23117,
23117,
4977,
4977,
23117,
23117,
6393,
6393,
35785,
35785,
6393,
6393,
35785,
35785,
6393,
6393,
128821,
128821,
6393,
6393,
128821,
128821,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
569669,
7,
7,
13,
13,
7,
7,
13,
13,
7,
7,
23,
23,
7,
7,
23,
23,
44,
44,
79,
79,
44,
44,
79,
79,
49,
49,
79,
79,
49,
49,
79,
79,
7,
7,
167,
167,
7,
7,
167,
167,
7,
7,
7895,
7895,
7,
7,
7895,
7895,
49,
49,
6307,
6307,
49,
49,
6307,
6307,
49,
49,
7895,
7895,
49,
49,
7895,
7895,
97,
97,
219,
219,
97,
97,
219,
219,
219,
219,
219,
219,
219,
219,
219,
219,
608,
608,
3879,
3879,
608,
608,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
3879,
34527,
34527,
48041,
48041,
34527,
34527,
48041,
48041,
34527,
34527,
120407,
120407,
34527,
34527,
120407,
120407,
245035,
245035,
697563,
697563,
245035,
245035,
697563,
697563,
245035,
245035,
2688153,
2688153,
245035,
245035,
2688153,
2688153,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
1033,
1033,
6073,
6073,
1033,
1033,
6073,
6073,
4577,
4577,
6073,
6073,
4577,
4577,
6073,
6073,
1337,
1337,
1337,
1337,
1337,
1337,
1337,
1337,
29913,
29913,
120149,
120149,
29913,
29913,
120149,
120149,
71735,
71735,
613479,
613479,
71735,
71735,
613479,
613479,
218301,
218301,
711725,
711725,
218301,
218301,
711725,
711725,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
1177,
9867,
9867,
28099,
28099,
9867,
9867,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
28099,
48041,
48041,
48041,
48041,
48041,
48041,
48041,
48041,
246297,
246297,
346719,
346719,
246297,
246297,
346719,
346719,
2662657,
2662657,
4817803,
4817803,
2662657,
2662657,
4817803,
4817803,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485,
11814485
        };
        int testcases = Integer.parseInt(readLine());
        for (int t = 1; t <= testcases; t++) {
            MultiBaseHappiness instance = new MultiBaseHappiness();
            instance.solve(t);
        }

    }

    // ****** GLOBAL VARIABLES ******



    public MultiBaseHappiness() {
    }

    public boolean solve(int caseNumber) {
        StringTokenizer st = new StringTokenizer(readLine());
        int mask = 0;
        while (st.hasMoreTokens()) {
            mask |= (1 << (Integer.parseInt(st.nextToken())-2));
        }
        System.out.println("Case #" + caseNumber + ": " + cache[mask]);
        return false;
    }


}
