/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rw.nzeyi.codejam.round1.a;

/**
 *
 * @author antoine
 */
import java.io.*;

public class CollectingCards {

    public static long fact(int n) {
        return (n <= 1) ? 1 : n * fact(n - 1);
    }

    public static long comb(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    public static void execute() {

        String in = "/home/antoine/Desktop/C-large.in";
        String out = "/home/antoine/Desktop/C-large.out";
        String res = "";
        try {
            int T;
            BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(in)));
            String t = reader.readLine();
            T = Integer.parseInt(t);
            for (int i = 0; i < T; i++) {
                String str = reader.readLine();
                res += "Case #" + (i + 1) + ": " + comb(Integer.parseInt(str.split(" ")[0]), Integer.parseInt(str.split(" ")[0])) + "\n";

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
    }
}
