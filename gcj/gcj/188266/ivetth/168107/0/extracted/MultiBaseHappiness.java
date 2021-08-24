/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package round1A;

import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Ivetth
 */
public class MultiBaseHappiness {

    public static void main(String[] args) {

        String fileName = "A-small-attempt0";

        File fileIn = new File(fileName + ".in");
        File fileOut = new File(fileName + ".out");
        FileInputStream fis = null;
        BufferedInputStream bis = null;
        DataInputStream dis = null;
        PrintWriter outFile = null;



        try {

            fis = new FileInputStream(fileIn);
            bis = new BufferedInputStream(fis);
            dis = new DataInputStream(bis);
            outFile = new PrintWriter(new BufferedWriter(new FileWriter(fileOut)));

            int lineNumber = 0;
            int totalCases = 0;
            int currentCase = 0;
            while (dis.available() != 0) {
                String line = dis.readLine();
                System.out.println("line = " + line);
                if (lineNumber == 0) {
                    totalCases = Integer.parseInt(line);
                } else {
                    currentCase++;
                    String[] sBases = line.split(" ");
                    int[] iBases = new int[sBases.length];
                    int result = 0;
                    for (int i = 0; i < iBases.length; i++) {
                        iBases[i] = Integer.parseInt(sBases[i]);
                    }
                    result = getMinHappyNumber(iBases);
                    outFile.println("Case #" + currentCase + ": " + result);
                }
                lineNumber++;
            }

            fis.close();
            bis.close();
            dis.close();
            outFile.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int getMinHappyNumber(int[] iBases) {
        int result = 0;
        boolean resultFound = false;
        int tmp = 2;
        while (!resultFound) {
            resultFound = true;
            for (int i = 0; i < iBases.length; i++) {
                resultFound = resultFound && isHappy(tmp, iBases[i]);
            }
            tmp++;
        }
        result = tmp - 1;
        return result;
    }

    private static boolean isHappy(int i, int radix) {
        ArrayList numbers = new ArrayList();
        while (true) {
            numbers.add(new Integer(i));
            String number = Integer.toString(i, radix);
            i=0;
            for (int j=0; j<number.length(); j++){
                i+=(number.charAt(j)-'0') * (number.charAt(j)-'0');
            }
            if(i==1)
                return true;
            if(numbers.contains(new Integer(i)))
                return false;
        }
    }
    
    public static void amain(String[] args){
        System.out.println("Is Happy: "+isHappy(81, 10));
    }
    
    
}
