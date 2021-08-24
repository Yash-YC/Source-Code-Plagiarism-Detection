package yr2009.round1A.a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Vector;


/**
 *
 * @author CuteCoke
 */
public class A {
    private static final String FILE_NAME = "A-small-attempt0.in";
    private static boolean bDebug = false;

    public static void main(String args[]) throws IOException {

     A b = new A();

        // Using Hard Code

        // Using File
        File f = new File(FILE_NAME);
        if (bDebug ) System.out.println("Reading file : " + f.getAbsolutePath() + " (exists? "+f.exists()+")...");
        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
        String sContent = "";
        int counter = 1;
        int iNumOfRowToRead = 0;
        int iNumOfKind = 0;
        String sHeader = br.readLine();
        while ((sContent = br.readLine()) != null) {
         int[] iArr = strToIntArr(sContent);
         if (bDebug ) System.out.println("Case #" + counter + ": ----------------------- ");
         long iOutput = b.processA(iArr);
            System.out.println("Case #" + counter + ": " + iOutput);// Do Output
            counter++;
        }
    }

    private long processA(int[] N) {

     int lSmHap = 2;
     boolean bFound = false;
     int cnt = 0;

     //while (!bFound && cnt < 10000000){
     while (!bFound){
         boolean bPass = true;
         for (int i=0; i<N.length; i++){
             if (bDebug ) System.out.println("Try "+lSmHap+" for base "+N[i]+" ...");
             if (!isHappy(lSmHap, N[i])){
                 if (bDebug ) System.out.println("Not Happy!");
                 bPass = false;
                 break;
             }else{
                 if (bDebug ) System.out.println("Happy!");
             }
         }
         if (bPass){
             bFound = true;
             break;
         }
         cnt++;
         lSmHap++;
     }

     return lSmHap;
    }

    private boolean isHappy(int n, int base){
        int cnt = 0;
        int tmp = n;
        HashSet cacheSum = new HashSet();
        while (cnt<100){
            // Find the base format of n
            char[] c = toBase(tmp, base);
            if (bDebug ) System.out.println(""+new String(c)+" = toBase("+tmp+", "+base+")");
            int sum = 0;
            for (int i=0; i<c.length; i++){//Add together
                int j = Integer.parseInt(c[i]+"");
                sum += j*j;
            }
            if (cacheSum.contains(sum)) return false;
            if (sum==1) return true;
            cacheSum.add(sum);
            tmp = sum;
            cnt++;
        }
        return false;
    }

    private char[] toBase(int n, int base){
        String s = "";
        int dvidend = n;
        while (dvidend > 0){
            int mod = dvidend % base;
            dvidend = dvidend / base;
            s = mod + s;
        }
        return s.toCharArray();
    }

    private static void printVec(Vector v){
         for (int i=0; i<v.size(); i++)
         System.out.print( v.get(i)+" ");
    }

  

    private boolean[] generateBooleanList(int iSize, boolean bValue){
        boolean[] bArr = new boolean[iSize];
        for (int i = 0; i < iSize; i++)
            bArr[i] = bValue;
        return bArr;
    }
    private int[] generateIntList(int iSize, int iValue){
     int[] bArr = new int[iSize];
        for (int i = 0; i < iSize; i++)
            bArr[i] = iValue;
        return bArr;
    }

    private static int[] strToIntArr(String s){
     String[] sArr = s.split(" ");
     int[] iArr = new int[sArr.length];
     for (int i=0; i<sArr.length; i++){
      iArr[i] = Integer.parseInt(sArr[i]);
     }
     return iArr;
    }

    private static long[] strToLongArr(String s){
     String[] sArr = s.split(" ");
     long[] iArr = new long[sArr.length];
     for (int i=0; i<sArr.length; i++){
      iArr[i] = Long.parseLong(sArr[i]);
     }
     return iArr;
    }

    private void printArr(Object[] o){
     for (int a=0; a<o.length; a++){
      System.out.println("Arr["+a+"]" + o[a]);
     }
    }
}
