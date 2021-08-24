/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
import java.util.ArrayList;
/**
 *
 * @author Huy
 */
public class AAAAA {
    static String digit = "0123456789";
    static int[] square = {0, 1, 4, 9, 16, 25, 36 ,49, 64, 81};
    
    public static String translate(long num, int base) {
        String r = "";
        while (num != 0) {
            r = digit.charAt((int)(num % base)) + r;
            num = num / base;
        }
        return r;

    }

    public static long sumSquare(String s) {
        long r = 0;
        for (int i = 0; i < s.length(); i++)
            r = r + square[Integer.parseInt(""+s.charAt(i))];
        return r;
    }

    public static boolean checkHappy(long num, int base) {
        String s;
        switch (base) {
            case 3:
                s = translate(num, base);
                if (s.equals("2") || s.equals("12") || s.equals("22"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }                
            case 5:
                s = translate(num, base);
                if (s.equals("4") || s.equals("23") || s.equals("33"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }                
            case 6:
                s = translate(num, base);
                if (s.equals("32"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }
            case 7:
                s = translate(num, base);
                if (s.equals("2") || s.equals("34") || s.equals("13") || s.equals("23") || s.equals("63") || s.equals("44"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }
            case 8:
                s = translate(num, base);
                if (s.equals("4") || s.equals("5") || s.equals("32") || s.equals("24") || s.equals("64"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }
            case 9:
                s = translate(num, base);
                if (s.equals("55") || s.equals("58") || s.equals("45") || s.equals("75"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }
            case 10:
                s = translate(num, base);
                if (s.equals("0") || s.equals("4") || s.equals("16") || s.equals("20") || s.equals("37") || s.equals("42") || s.equals("58") || s.equals("89") || s.equals("145"))
                    return false;
                else if (s.equals("1"))
                    return true;
                else {
                    return checkHappy(sumSquare(s), base);
                }                                     
        }

        return true;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numtest = in.nextInt();
        in.nextLine();

        int k = 1;
        while (k <= numtest) {
            String line = in.nextLine();
            ArrayList<Integer> a = new ArrayList<Integer>();
            for (int i = 0; i < line.length(); i++)
                if (line.charAt(i) != ' ' && line.charAt(i) != '1' && line.charAt(i) != '2' && line.charAt(i) != '4') {
                    if (line.charAt(i) == '0')
                        a.add(10);
                    else
                        a.add(Integer.parseInt("" + line.charAt(i)));
                }
            long num = 2;
            while (true) {
                boolean kt = true;
                for (int i = 0; i < a.size(); i++)
                    if (!checkHappy(num, a.get(i))) {
                        kt = false;
                        break;
                    }
                if (kt) {
                    System.out.println("Case #" + k + ": " + num);
                    break;
                }
                num++;
            }
            k++;
        }
    }

}
