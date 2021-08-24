package com.google.a;

import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class GoogleApp {
    public static String path = "D:\\work\\java\\my-app\\";
    Set<Integer> allNum = new HashSet<Integer>();

    public int findNumber(List<Integer> nums) {
        int num = 2;
        boolean allTrue = false;
        while (!allTrue) {
            allTrue = true;
            for (Integer base : nums) {
                if (new GoogleApp().testRecursion(num, base)) {
//                    System.out.println(num + " is happy number. base:" + base);
                } else {
                    allTrue = false;
                    num++;
                    break;
                }
            }
        }
        return num;
    }

    public boolean testRecursion(int num, int radiox) {
        String s = Integer.toString(num, radiox);
        List<Integer> integerList = intToList(s);
        int i = sumSquares(integerList);
        if (i != 1 && !allNum.contains(i)) {
            allNum.add(i);
            return testRecursion(i, radiox);
        } else if (i == 1) {
            return true;
        }
        return false;
    }

    public int sumSquares(List<Integer> arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i * i;
        }
        return sum;
    }

    public List<Integer> intToList(String inputNum) {
        List<Integer> result = new ArrayList<Integer>();
        char[] chars = (inputNum).toCharArray();
        for (char aChar : chars) {
            result.add(Integer.parseInt("" + aChar));
        }
        return result;
    }

    public void go(String inputName, String outputName) throws IOException {
        File inputFile = new File(path + inputName);

        BufferedReader fr = new BufferedReader(new FileReader(inputFile));
        int lineNumber = Integer.parseInt(fr.readLine());
        PrintWriter pw = new PrintWriter(new File(path + outputName));
        for (int i = 0; i < lineNumber; i++) {
            String[] strings = fr.readLine().split(" ");
            List<Integer> list = new ArrayList<Integer>();
            for (String string : strings) {
                list.add(Integer.parseInt(string));
            }
            System.out.println(list);
            int number = findNumber(list);
            write(pw, "Case #" + (i + 1) + ": " + number);
        }
        fr.close();
        pw.close();
    }

    private void write(PrintWriter pw, String s) {
        pw.println(s);
    }

    public static void main(String[] args) throws IOException {
        GoogleApp googleApp = new GoogleApp();
        googleApp.go("A-small-attempt0.in", "out.txt");
    }

}
