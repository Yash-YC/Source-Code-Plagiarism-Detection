package gcj2016a;

import java.io.*;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author greg
 */
public class GCJQualA {

    public static void main(String[] args) {
        GCJQualA g = new GCJQualA();
        g.run();
    }

    private void run() {
        Scanner br = null;
        BufferedWriter bw;

        try {
            br = new Scanner(new File("src/gcj2016a/A-small-practice.in"));
            bw = new BufferedWriter(new FileWriter("src/gcj2016a/A-small-output.txt"));
//            bw = new BufferedWriter(new OutputStreamWriter(System.out));
            
            int numTests = br.nextInt();
            for (int i = 0; i < numTests; i++) {
                String S = br.next();

                String answer = solvePuzzle(S);
                bw.write("Case #" + (i + 1) + ": ");
                bw.write(answer);
                bw.newLine();
            }
            bw.close();
        } catch (IOException ex) {
            Logger.getLogger(this.getClass().getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (Exception ex) {
                Logger.getLogger(this.getClass().getName()).log(Level.SEVERE, null, ex);
            }
        }

    }

    private String solvePuzzle(String S) {
        char[] ca = S.toCharArray();
        char firstChar = ' ';
        StringBuilder sb = new StringBuilder();
        for (char c : ca) {
            if ( c >= firstChar ) {
                sb.insert(0, c);
                firstChar = c;
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
