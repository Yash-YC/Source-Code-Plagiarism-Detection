package googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static class P2 {

        private int C;
        private int N;
        private int M;
        private int[][] S;
        private int[][] W;
        private int[][] T;
        private int currBest;

        private void bestSolution(int r, int c, int time) {

            if ((r == 2 * N - 1) && (c == 2 * M - 1)) {

                currBest = Math.min(time, currBest);
                return;
            }

            int cycleTime = S[r / 2][c / 2] + W[r / 2][c / 2];
            int whichCycle = (time - T[r / 2][c / 2]) / cycleTime;
            int whereInCycle = (time - T[r / 2][c / 2] - whichCycle * cycleTime) % cycleTime;

            if (c < 2 * M - 1) {

                if (c % 2 == 0) {

                    if (whereInCycle >= S[r / 2][c / 2]) {
                        bestSolution(r, c + 1, time + 1);
                    } else {
                        int offset = S[r / 2][c / 2] - whereInCycle;
                        bestSolution(r, c + 1, time + 1 + offset);
                    }

                } else {
                    bestSolution(r, c + 1, time + 2);
                }

            }

            if (r < 2 * N - 1) {

                if (r % 2 == 0) {

                    if (whereInCycle < S[r / 2][c / 2]) {
                        bestSolution(r + 1, c, time + 1);
                    } else {
                        int offset = cycleTime - whereInCycle;
                        bestSolution(r + 1, c, time + 1 + offset);
                    }

                } else {
                    bestSolution(r + 1, c, time + 2);
                }
            }
        }

        private void p2() {

            try {

                String infile = "/home/danny/Desktop/in";
                Scanner scanner = new Scanner(new File(infile));

                String outfile = "/home/danny/Desktop/out";
                FileWriter writer = new FileWriter(outfile);

                C = scanner.nextInt();

                for (int cse = 0; cse < C; cse++) {

                    // INPUT

                    N = scanner.nextInt();
                    M = scanner.nextInt();

                    S = new int[N][M];
                    W = new int[N][M];
                    T = new int[N][M];

                    for (int row = 0; row < N; row++) {
                        for (int col = 0; col < M; col++) {
                            S[row][col] = scanner.nextInt();
                            W[row][col] = scanner.nextInt();

                            T[row][col] = scanner.nextInt();
                            int cycleTime = S[row][col] + W[row][col];
                            int offsetMult = 1000000;
                            T[row][col] -= offsetMult * cycleTime;
                        }
                    }

                    currBest = Integer.MAX_VALUE;
                    bestSolution(0, 0, 0);

                    writer.write("Case #" + (cse + 1) + ": " + currBest + "\n");

                    writer.flush();
                }
            } catch (FileNotFoundException ex) {
                System.out.println(ex);
            } catch (IOException ex) {
                System.out.println(ex);
            }
        }
    }

    public static class P1 {

        private int T;
        private List<Integer> bases;

        private long successor(long n, int base) {

            long temp = n;
            List<Integer> digits = new ArrayList<Integer>();

            while (temp != 0) {
                digits.add((int) temp % base);
                temp = temp / base;
            }

            long sumofsq = 0;
            for (int i = 0; i < digits.size(); i++) {
                sumofsq += digits.get(i) * digits.get(i);
            }

            return sumofsq;
        }

        private boolean isHappy(long n, int base) {

            HashSet<Long> set = new HashSet<Long>();

            set.add(n);

            while (true) {
                n = successor(n, base);
                if (n == 1) {
                    return true;
                }
                if (set.contains(n)) {
                    return false;
                }
                set.add(n);
            }
        }

        private void p1() {

            try {

                String infile = "/home/danny/Desktop/in";
                Scanner scanner = new Scanner(new File(infile));

                String outfile = "/home/danny/Desktop/out";
                FileWriter writer = new FileWriter(outfile);

                T = scanner.nextInt();
                scanner.nextLine();

                for (int cse = 0; cse < T; cse++) {

                    // INPUT
                    bases = new ArrayList<Integer>();

                    String line = scanner.nextLine();

                    String[] tokens = line.split(" ");

                    for (int i = 0; i < tokens.length; i++) {
                        bases.add(Integer.parseInt(tokens[i]));
                    }


                    long result = 0;
                    for (long n = 2; n < Long.MAX_VALUE; n++) {
                        boolean allWork = true;

                        for (int i = 0; i < bases.size(); i++) {
                            int base = bases.get(i);

                            if (!isHappy(n, base)) {
                                allWork = false;
                                break;
                            }
                        }

                        if (allWork) {
                            result = n;
                            break;
                        }
                    }

                    writer.write("Case #" + (cse + 1) + ": " + result + "\n");

                    writer.flush();
                }
            } catch (FileNotFoundException ex) {
                System.out.println(ex);
            } catch (IOException ex) {
                System.out.println(ex);
            }
        }
    }

    public static void main(String[] args) {

        P2 p = new P2();

        p.p2();
    }
}
