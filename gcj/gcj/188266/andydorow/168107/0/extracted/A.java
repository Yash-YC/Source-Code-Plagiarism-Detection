import java.io.File;
import java.io.InputStream;
import java.util.Scanner;


public class A {

//    static InputStream in;
    static Scanner in;
//    
//    static byte[] buffer;
//    static int pos;
//    static int max;
    
    static final int MAX_H = 10000;

    // -1 == unhappy
    //  0 == not defined
    // +1 == happy
    // -2 == unknown
    static long[][] happiness = new long[10000][11];// 10 bases// DP
    
    public static void main(String[] args) throws Throwable {
//        in = System.in;
//        in = new Scanner(System.in);
//        in = new Scanner(new File("A-large.in"));
        in = new Scanner(new File("A-small-attempt0.in"));
        
        
        
        long[] bases = new long[11];
        int numBases = 0;
        String[] read;

        for (int i = 0; i < bases.length; i++) {
            happiness[1][i] = 1;// == 1? then it is happy!
        }
        
        int tests = Integer.parseInt(in.nextLine());
        
        for (int caseno = 1; caseno <= tests; caseno++) {
            read = in.nextLine().split(" ");
            numBases = read.length;
            for (int i = 0; i < numBases; i++) {
                bases[i] = Integer.parseInt(read[i]);
            }
            long val = 2;
            while (!happy(val, bases, numBases)) val++;
            System.out.printf("Case #%d: %d\n", caseno, val);
        }
        
    }
    
    private static boolean happy(long val, long[] bases, int numBases) {
        for (int i = 0; i < numBases; i++) {
            if (!happy(val, bases[i])) return false;
        }
        
        return true;
    }

    private static boolean happy(long lnumber, long lbase) {
        while (lnumber >= MAX_H) {
            lnumber = divideAndSum(lnumber, lbase);
        }
        int number = (int) lnumber;
        int base = (int) lbase;
        long v = happiness[number][base];
        if (v != 0) { 
            return v == 1;
        }
        
        happiness[number][base] = -2;//set unknown
        long newNumber = divideAndSum(number, base);
        v = (happy(newNumber, base)) ? 1 : -1;
        happiness[number][base] = v;
        return v == 1;
    }

    private static long divideAndSum(long number, long base) {
        long ret = 0;
        while (number > 0) {
            long tmp = (number % base);
            ret += (tmp*tmp);
            number /= base;
        }
        return ret;
    }

}
