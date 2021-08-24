package com.google.codejam2009.round1a.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.SortedSet;
import java.util.TreeSet;

public class MultiBaseHappiness {

    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("2009/round1AA/input.txt"));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("2009/round1AA/output.txt")));

        int numberOfTests = Integer.parseInt(reader.readLine()); // T
        System.out.println("numberOfTests = " + numberOfTests);

        for (int caseNumber = 1; caseNumber <= numberOfTests; caseNumber++) {
            String[] basesString = reader.readLine().split(" ");
            int bases[] = new int[basesString.length];
            for (int i = 0; i < basesString.length; i++) {
                bases[i] = Integer.parseInt(basesString[i]);
            }

            int happyNumber = 2;
            for (int i = 0; i < bases.length; i++) {
                boolean notHappy;
                do {
                    int a = happyNumber;
                    int b;
                    SortedSet<Integer> set = new TreeSet<Integer>();
                    notHappy = false;
                    do {
                        b = 0;
                        while (a > 0) {
                            int c = (a % bases[i]);
                            b = b + c * c;
                            a = a / bases[i];
                        }
                        if (b > 1) {
                            if (set.contains(b)) {
                                notHappy = true;
                            } else {
                                set.add(b);
                                a = b;
                            }
                        }
                    } while (b > 1 && !notHappy);
                    if (notHappy) {
                        happyNumber++;
                        i = 0;
                    }
                } while (notHappy);
            }

            writer.println("Case #" + caseNumber + ": " + happyNumber);
        }

        writer.flush();
        writer.close();
        reader.close();
    }

}
