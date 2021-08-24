package year2009.round1A.a;

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Arrays;

public class ProblemAtrick implements Runnable {
    public static final String FILE_PREFIX = "A";


    public void run() {

        try {
            Scanner in = new Scanner(new BufferedReader(new FileReader(getInputFile())));
            PrintWriter out = new PrintWriter("output-a.txt");
            int COUNT = in.nextInt();
            in.nextLine();
            int[] values = new int[] {
                    569669,
                    58775,
                    37131,
                    2207,
                    23117,
                    3879,
                    1695,
                    79,
                    128821,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    27,
                    23,
                    569669,
                    47089,
                    37131,
                    2207,
                    10089,
                    3879,
                    707,
                    79,
                    35785,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    3,
                    3,
                    569669,
                    58775,
                    37131,
                    2207,
                    23117,
                    3879,
                    1695,
                    79,
                    128821,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    27,
                    23,
                    569669,
                    47089,
                    37131,
                    2207,
                    10089,
                    3879,
                    707,
                    79,
                    35785,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    3,
                    3,
                    569669,
                    48769,
                    37131,
                    49,
                    4977,
                    1975,
                    415,
                    49,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    27,
                    27,
                    5,
                    569669,
                    47089,
                    2753,
                    49,
                    4977,
                    216,
                    415,
                    6,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    8,
                    3,
                    2,
                    569669,
                    48769,
                    37131,
                    49,
                    4977,
                    1975,
                    415,
                    49,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    27,
                    27,
                    5,
                    569669,
                    47089,
                    2753,
                    49,
                    4977,
                    216,
                    415,
                    6,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    8,
                    3,
                    2,
                    569669,
                    58775,
                    37131,
                    2207,
                    23117,
                    3879,
                    1695,
                    79,
                    128821,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    27,
                    23,
                    569669,
                    47089,
                    37131,
                    2207,
                    10089,
                    3879,
                    707,
                    79,
                    35785,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    3,
                    3,
                    569669,
                    58775,
                    37131,
                    2207,
                    23117,
                    3879,
                    1695,
                    79,
                    128821,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    27,
                    23,
                    569669,
                    47089,
                    37131,
                    2207,
                    10089,
                    3879,
                    707,
                    79,
                    35785,
                    5719,
                    143,
                    143,
                    27,
                    27,
                    3,
                    3,
                    569669,
                    48769,
                    37131,
                    49,
                    4977,
                    1975,
                    415,
                    49,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    27,
                    27,
                    5,
                    569669,
                    47089,
                    2753,
                    49,
                    4977,
                    216,
                    415,
                    6,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    11814485,
                    8,
                    3,
                    2,
                    569669,
                    48769,
                    37131,
                    49,
                    4977,
                    1975,
                    415,
                    49,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    27,
                    27,
                    5,               11814485,
2688153,
711725,
7895,
28099,
3879,
6073,
79,
346719,
120407,
120149,
7895,
1177,
219,
91,
23,
4817803,
697563,
613479,
6307,
28099,
3879,
6073,
79,
48041,
48041,
1337,
167,
1177,
219,
91,
13,
11814485,
2688153,
711725,
7895,
28099,
3879,
6073,
79,
                    120407,
120149,
7895,
1177,
219,
91,
23,
346719,
                    2688153,
                    711725,
                    7895,
                    28099,
                    3879,
                    6073,
                    79,

                    569669,
                    47089,
                    2753,
                    49,
                    4977,
                    216,
                    415,
                    6,
                    6393,
                    1001,
                    125,
                    7,
                    27,
                    8,
                    3,
11814485,
2688153,
711725,
7895,
28099,
3879,
6073,
79,
346719,
120407,
120149,
7895,
1177,
219,
91,
23,
4817803,
697563,
613479,
6307,
28099,
3879,
6073,
79,
48041,
48041,
1337,
167,
1177,
219,
91,
13,
            };
            Arrays.sort(values);

            for (int pass = 0; pass < COUNT; pass ++) {
                String line = in.nextLine().trim();
                String[] basesstr = line.split(" ");
                HashSet<Integer> bases = new HashSet<Integer>();
                for (String s : basesstr) {
                    bases.add(Integer.parseInt(s));
                }

                out.printf("Case #%d: ", pass + 1);

                long total = 1;
                for (int b : bases) {
                    total *= b;
                }
                boolean good = true;
//                for (int i : values) {
                for (int i : values) {
                    good = check(bases, i);
                    if (!good) {
                        continue;
                    }
                    out.print(i);
                    break;
                }
                if (!good) {
                    int i = 1;
                    while (true) {
                        i++;
                        good = check(bases, i);
                        if (!good) {
                            continue;
                        }
                        out.print(i);
                        break;
                    }
                }


                out.println();
                out.flush();
            }



            out.close();
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    private boolean check(HashSet<Integer> bases, int i) {
        boolean good;
        good = true;
        for (int b : bases) {
            String s = Long.toString(i, b);
            HashSet<String> visited = new HashSet<String>();
            while (!visited.contains(s)) {
                visited.add(s);
                int k = 0;
                for (int j = 0; j < s.length(); j++) {
                        int digit = s.charAt(j) - '0';
                    k += (digit * digit);
                }
                s = Integer.toString(k,b);
            }
            good &= s.equals("1");
            if (!good) {
                break;
            }

        }
        return good;
    }

    public static void main(String[] args) {

        new Thread(new ProblemAtrick()).start();
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