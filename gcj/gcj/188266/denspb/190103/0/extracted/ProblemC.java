package year2009.round1A.a;

import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.math.MathContext;

public class ProblemC implements Runnable {
    public static final String FILE_PREFIX = "C";


    public void run() {

        try {
            BigDecimal [][] Cnk = new BigDecimal[41][41];
            for (int i = 0; i < Cnk.length; i++) {
                Cnk[i][0] = new BigDecimal("1");
                for (int j = 1; j < Cnk[i].length; j++) {
                    BigDecimal  Cij = (i > 0) ? Cnk[i - 1][j] : new BigDecimal ("0");
                    BigDecimal  Ci1j1 = (i > 0) && (j > 0) ? Cnk[i - 1][j - 1] : new BigDecimal ("0");
                    Cnk[i][j] = Cij.add(Ci1j1);
                }
            }

            Scanner in = new Scanner(new BufferedReader(new FileReader(getInputFile())));
            PrintWriter out = new PrintWriter("output-c.txt");
            int COUNT = in.nextInt();



            for (int pass = 0; pass < COUNT; pass ++) {
                int C = in.nextInt();
                int N = in.nextInt();

                BigDecimal[][] probMatrix = new BigDecimal[C+1][C+1];
                for (int i = 0; i < probMatrix.length; i++) {
                    for (int j = 0; j < probMatrix[i].length; j++) {
                        probMatrix[i][j] = new BigDecimal(0);

                    }
                }
                for (int i = 0; i < probMatrix.length; i++) {
                    for (int j = i; j < probMatrix[i].length; j++) {
                        int b = j - i;
                        int a = N - b;
                        if (a < 0 || b < 0) {
                            continue;
                        }
                        probMatrix[i][j] = Cnk[i][a].multiply(Cnk[C - i][b]).divide(Cnk[C][N], 90, RoundingMode.HALF_UP);
                    }
                }



                BigDecimal result = new BigDecimal(0);
                BigDecimal prob[] = new BigDecimal[C + 1];
                for (int i = 0; i < prob.length; i++) {
                    prob[i] = new BigDecimal(0);

                }
                prob[0] = new BigDecimal(1);
                for (int t = 0; t < 80; t++) {
//                    System.out.println(t);
//
//                    System.out.println(Arrays.toString(prob));
                    result = result.add(prob[C].multiply(new BigDecimal(t)));
                    prob[C] = new BigDecimal(0);
                    BigDecimal newprob[] = new BigDecimal[C + 1];
                    for (int i = 0; i < newprob.length; i++) {
                        newprob[i] = new BigDecimal(0);
                        for (int j = 0; j <= N; j++) {
                            if (i - j >= 0) {
                             newprob[i] = newprob[i].add(prob[i - j].multiply(probMatrix[i - j][i]));
                            }
                        }
                    }
                    prob = newprob;
                }

                System.out.println("Case " + (pass + 1));
                out.printf("Case #%d: ", pass + 1);
                out.print(result.round(new MathContext(15, RoundingMode.HALF_UP)));
                out.println();
            }




            out.close();
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new ProblemC()).start();
    }

    public File getInputFile() {
        File result = null;
        File temp = new File("input" + FILE_PREFIX + ".txt");
        if (temp.exists())  {
            result = temp;
        }
        temp = new File(FILE_PREFIX + "-small.in");
        if (temp.exists())  {
            result = temp;
        }
        int index = 0;
        temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        while (temp.exists())  {
            result = temp;
            index++;
            temp = new File(FILE_PREFIX + "-small-" +index +  ".in");
        }
        temp = new File(FILE_PREFIX + "-large.in");
        if (temp.exists())  {
            result = temp;
        }
        System.out.println("Using " + result);
        return result;
    }
}