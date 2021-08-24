package codejam.y2016.round1a;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class A {
    private static final String INPUT = "A-small-attempt0.in";
    private static final String OUTPUT = "A-small-attempt0.out";

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File(INPUT));
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int c = 0; c < cases; c++) {
            String line = "Case #" + (c + 1) + ": " + solve(sc.next());
            sb.append(line).append('\n');
            System.out.println(line);
        }
        Files.write(Paths.get(OUTPUT), sb.toString().getBytes());
    }

    private static String solve(String word) {
        String s = "";
        for (char c : word.toCharArray()) {
            String s1 = s + c;
            String s2 = c + s;
            if (s1.compareTo(s2) > 0) {
                s = s1;
            } else {
                s = s2;
            }
        }
        return s;
    }
}