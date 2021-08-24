package com.google.codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {

    private static boolean debugAllowed = true;

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            throw new IllegalArgumentException("Wrong run parameters: " + Arrays.deepToString(args));
        }
        File inputFile = new File(args[0]);
        String outputFileName = inputFile.getParent() + File.separator + inputFile.getName().replace(".in", ".out");
        PrintStream out = new PrintStream(outputFileName);

        Scanner scanner = new Scanner(inputFile);
        int numberOfCases = Integer.valueOf(scanner.nextLine());
        debug(numberOfCases + " cases");

        long start = System.currentTimeMillis();
        for (int i = 1; i <= numberOfCases; i++) {
            // Parsing the file
            debug("Case #" + i);

            String[] basesArray = scanner.nextLine().split(" ");
            List<String> bases = Arrays.asList(basesArray);
            debug("    bases: " + bases);

            // Now solving

            int result = 1;
            for (int x = 2;; x++) {
                boolean happyInAll = true;
                for (String baseString : bases) {
                    Integer base = Integer.valueOf(baseString);
                    debug("    x: " + x);
                    debug("    x in base " + base + ": " + inBase(x, base));

                    if (!happy(x, base)) {
                        happyInAll = false;
                        break;
                    }
                }
                if (happyInAll) {
                    result = x;
                    break;
                }
            }

            String resultString = "Case #" + i + ": " + result;
            out.println(resultString);
            debug(resultString);

            debug("");
        }

        out.close();
        long finish = System.currentTimeMillis();
        debug("Time: " + (finish - start) + " ms.");
    }

    private static boolean happy(int x, Integer base) {
        String xString = inBase(x, base);
        List<Integer> lastSums = new ArrayList<Integer>();
        do {
            int sum = 0;
            for (int i = 0; i < xString.length(); i++) {
                int digit = Integer.valueOf(String.valueOf(xString.charAt(i)));
                sum += digit * digit;
            }
            xString = inBase(sum, base);
            if (sum == 1) {
                return true;
            }
            if (lastSums.contains(sum)) {
                return false;
            }
            lastSums.add(sum);
        } while (true);
    }

    private static String inBase(int number, int base) {
        int index;
        int digitValue;

        String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // check base and value
        if (number < 0) {
            throw new IllegalArgumentException("The value to be converted must be positive");
        } else if (base < 2 || base > 36) {
            throw new IllegalArgumentException("Base must be in range 2-36");
        }

        // convert to the other base
        String res = "";
        while (number != 0) {
            digitValue = number % base;
            number = number / base;
            // append this digit in front of current result
            // res.Insert(0, digits.Chars(digitValue))
            res = digitValue + res;
        }

        return res;
    }

    private static void debug(String text) {
        if (debugAllowed) {
            System.out.println(text);
        }
    }
}
