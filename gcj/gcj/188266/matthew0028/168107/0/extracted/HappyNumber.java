package _2009_09_11;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Multimap;
import com.google.common.collect.TreeMultimap;

public class HappyNumber {
    public static void main(String[] args) throws IOException {
        File inputFile = new File("data/input/test.in");
        File outputFile = new File("data/output/test.out");
        outputFile.createNewFile();
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
        HappyNumber instance = new HappyNumber();
        System.err.println(instance.isHappyInBase(91, 9));
//        if (true) return;
//        System.err.println(instance.getSmallestHappyNumber(ImmutableList.of(2, 3)));
//        if (true) return;
        instance.run(reader, writer);
        writer.flush();
//        System.err.println(instance.happyNumbers);
    }

    private void run(BufferedReader reader, BufferedWriter writer)
            throws IOException {
        int numTestCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numTestCases; i++) {
            String[] split = reader.readLine().split(" ");
            List<Integer> list = toIntList(split);
            Integer result = getSmallestHappyNumber(list);
            writer.append(String.format("Case #%d: %s", i + 1, result));
            writer.newLine();
        }
    }

    private Multimap<Integer, Integer> happyNumbers = TreeMultimap.create();
    private Multimap<Integer, Integer> numbersTried = HashMultimap.create();

    private int getSmallestHappyNumber(List<Integer> list) {
        int i = 2;
        while (true) {
            boolean happyInAll = true;
            numbersTried.clear();
            for (Integer base : list) {
                if (isHappyInBase(i, base)) {
                    happyNumbers.put(base, i);
                } else {
                    happyInAll = false;
                }
            }
            if (happyInAll) {
                return i;
            }
            i++;
        }
    }

    private boolean isHappyInBase(int number, int base) {
        if (happyNumbers.containsEntry(base, number)) {
            return true;
        }
        if (numbersTried.containsEntry(base, number)) {
            return false;
        }
        numbersTried.put(base, number);
        String numberInBaseAsString = Integer.toString(number, base);
        if (numberInBaseAsString.equals("1")) {
            return true;
        }
        List<Integer> digits = toDigits(numberInBaseAsString);
        int nextNumber = 0;
        for (Integer digit : digits) {
            nextNumber += digit * digit;
        }
        System.err.println("n,b: " + nextNumber + "," + base);
        return isHappyInBase(nextNumber, base);
    }

    private List<Integer> toDigits(String number) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < number.length(); i++) {
            result.add(Integer.parseInt("" + number.charAt(i)));
        }
        return result;
    }

    private static List<Integer> toIntList(String[] split) {
        List<Integer> result = new ArrayList<Integer>();
        for (String s : split) {
            result.add(Integer.parseInt(s));
        }
        return result;
    }

}