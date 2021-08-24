/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2009r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author Romulus
 */
public class C {

    public static void main(String[] args) throws Exception {
        String inFile = "C-small-attempt1.in";
        String outFile = "out.txt";
        BufferedReader in = new BufferedReader(new FileReader(inFile));
        BufferedWriter out = new BufferedWriter(new FileWriter(outFile));

        int cases = Integer.parseInt(in.readLine());
        double ans;
        for (int i = 1; i <= cases; ++i) {
            String[] s = in.readLine().split(" ");
            ans = solve(Integer.parseInt(s[0]), Integer.parseInt(s[1]), 0, 0, 1.0);
            out.write("Case #" + i + ": " + ans + "\r\n");
            System.out.println("Case #" + i + ": " + ans);
        }

        out.close();
        in.close();
    }

    static double solve(int C, int N, int G, int P, double checkP) {
        double ret = 0.0;
        if (G >= C) return P;
        if (checkP < 0.000000001) return P;
        // repeated card numbers
        for (int R = 0; R <= N; ++R) {

             //System.out.println("C=" + C + " N=" + N +  " R=" + R +" G=" + G + " P=" + P + " checkP=" + checkP );
            if (R > G) {
                continue;
            }
            if (N - R > C - G) {
                continue;
            }
            if (G == 0) {
                return solve(C, N, N, P + 1, checkP);
            }
            double prob = 1.0 * combination(G, R) * combination(C - G, N - R) / combination(C, N);
            // System.out.println("prob=" + prob);
            if (prob >= 1) {
                return P;
            }
            ret += prob * solve(C, N, G + N - R, P + 1, prob * checkP);
        }
        return ret;
    }

    static int combination(int n, int m) {
        return fact(n) / (fact(m) * fact(n - m));
    }

    static int fact(int x) {
        int f = 1;

        for (int i = 1; i <= x; i++) {
            f = f * i;
        }
        return f;
    }
}
