package a;

import java.util.*;
import static java.lang.System.*;
import java.io.*;

public class C {

//    static String fileName="C-small-attempt0";
   static String fileName="C-large";
//   static String fileName="C-test";
    static Scanner sc;
    static PrintStream out;
    static long timer;
    static int NumberOfCases;
    static int caseN;
    public static void main(String[] args) {
        timer=currentTimeMillis();
        if (args.length>0) fileName=args[0];
          try{
            if (fileName.endsWith(".in"))
                fileName=fileName.substring(0, fileName.length()-3);
            if (fileName.equals("-")) {
                sc=new Scanner(System.in);
                out=System.out;
            } else {
                sc=new Scanner(new File(fileName+".in"));
                out=new PrintStream(new File(fileName+".out"));
            }
            NumberOfCases=sc.nextInt();
            for (caseN = 1; caseN <= NumberOfCases; caseN++) {
                out.print("Case #"+caseN+": ");
                (new C()).Solve();
            }
            out.close();
            System.err.println("Done "+(currentTimeMillis()-timer)/1000.0);
            if (!fileName.equals("-")) {
                 Scanner f=new Scanner(new File(fileName+".out"));
                 while (f.hasNextLine()){
                     System.out.println(f.nextLine());
                 }
             }
        }catch (FileNotFoundException e) {err.println(e.getMessage()+"("+fileName+")");}
    } // main

    void Solve() {
        int L=sc.nextInt();
        int N=sc.nextInt();

        long[][] C=new long[L+1][];
        for (int i =0; i<C.length; i++){
            C[i]=new long[i+1];
            C[i][0]=1; C[i][i]=1;
            for (int j=1; j<i; j++)
                C[i][j]=C[i-1][j-1]+C[i-1][j];
        }

        double [] a=new double[L+1];
        a[0]=0;
        for (int i=1; i<=L; i++){
            double s=C[L][N];
            int j=1;
            if (N-L+i>=1) j=N-L+i;
            for (; j<=i && j<=N; j++){
                s+= C[i][j]*C[L-i][N-j]*a[i-j];
            }
            a[i]=s/(C[L][N]- ((L-i>=N)?C[L-i][N]:0));
        }
        out.println(a[L]);
    } //Solve

}// class
