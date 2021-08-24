/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class A {

    public static void genLargeP() throws FileNotFoundException {
        File inputFile = new File("A-small-attempt0.in");
        PrintWriter out = new PrintWriter("test_b.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        out.println(T);
        for (int i = 0; i < T; i++) {
            out.printf("%d\n", (int) (Math.random() * 100000));
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        // test case
//        genLargeP();
//        File inputFile = new File("test.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
//        File inputFile = new File("A-large.in");
        File inputFile = new File("A-small-attempt0.in");
        PrintWriter out = new PrintWriter("A_out.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String str = in.next();
            char[] answer = new char[str.length() * 2 - 1];
            answer[str.length() - 1] = str.charAt(0);
            int head = str.length() - 1;
            int tail = str.length();
            for (int j = 1; j < str.length(); j++) {
                if (str.charAt(j) >= answer[head]) {
                    answer[head - 1] = str.charAt(j);
                    head--;
                } else {
                    answer[tail] = str.charAt(j);
                    tail++;
                }
            }
            String toPrint = new String(answer);
            out.printf("Case #%d: %s\n", i + 1, toPrint.trim());
        }

        in.close();
        out.close();
    }
}
