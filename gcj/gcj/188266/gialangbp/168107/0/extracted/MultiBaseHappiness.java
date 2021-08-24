/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Round1A_A_2009;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author user
 */
public class MultiBaseHappiness {

    private String changeBase(long num, int base) {
        String result = "";
        while(num > 0) {
            result += num % base;
            num /= base;
        }
        return result;
    }

    private long getSquareOfDigit(String strNum) {
        long result = 0;
        for(int i = 0; i < strNum.length(); i++) {
            int temp = Integer.parseInt(String.valueOf(strNum.charAt(i)));
            result += temp * temp;
        }
        return result;
    }

    private boolean checkNumber(long num, int base) {
        ArrayList<Long> checked = new ArrayList<Long>();
        String baseNum = base == 10 ? String.valueOf(num): changeBase(num, base);
        num = getSquareOfDigit(baseNum);
        do {
            if(num == 1) {
                return true;
            }
            checked.add(num);
            baseNum = base == 10 ? String.valueOf(num): changeBase(num, base);
            num = getSquareOfDigit(baseNum);
        }while(!checked.contains(num));
        return false;
    }

    private int[] getBaseList(String line) {
        String[] strList = line.split(" ");
        int[] result = new int[strList.length];
        for(int i = 0; i < result.length; i++) {
            result[i] = Integer.parseInt(strList[i]);
        }
        return result;
    }

    public void mainProcess() {
        Scanner scan = new Scanner(System.in);
        int testcase = scan.nextInt();
        scan.nextLine();
        for(int i = 1; i <= testcase; i++) {
            int[] baseList = getBaseList(scan.nextLine());
            for(int num = 2; num < Integer.MAX_VALUE; num++) {
                int b;
                for(b = 0; b < baseList.length; b++) {
                    if(!checkNumber(num, baseList[b])) {
                        break;
                    }
                }
                if(b >= baseList.length) {
                    System.out.println("Case #" + i + ": " + num);
                    break;
                }
            }
        }
    }
}
