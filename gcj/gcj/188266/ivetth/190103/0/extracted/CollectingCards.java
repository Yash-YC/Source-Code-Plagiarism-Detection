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


/**
 *
 * @author Ivetth
 */
public class CollectingCards {
    
    public static void main(String[] args) {

        String fileName = "C-small-attempt1";

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
                    int c = Integer.parseInt(line.split(" ")[0]);
                    int n = Integer.parseInt(line.split(" ")[1]);
                    if (c==n)
                        outFile.println("Case #" + currentCase + ": " + 1);
                    else if (c==n+1)
                        outFile.println("Case #" + currentCase + ": " + (1+c));
                    else
                        outFile.println("Case #" + currentCase + ": " + 0);
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

}
