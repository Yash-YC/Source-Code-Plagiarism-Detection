package a;

import java.util.*;
import static java.lang.System.*;
import java.io.*;
import static mylibrary.functions.MyMath.*;

public class B {

    static String fileName="B-small-attempt0";
//    static String fileName="B-large";
    //static String fileName="B-test";
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
                (new B()).Solve();
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

    int N,M;
    int[][] W,S,T;
    int[][][][] res;

    void Solve() {
        N=sc.nextInt();
        M=sc.nextInt();
        W=new int[N][M];
        S=new int[N][M];
        T=new int[N][M];
       int inf=Integer.MAX_VALUE;
 
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++){
                S[i][j]=sc.nextInt();
                W[i][j]=sc.nextInt();
                T[i][j]=sc.nextInt();
            }
        res = new int[N][M][2][2];
           for (int n=0; n<N; n++)
           for (int m=0; m<M; m++)
               for (int dn=0; dn<=1; dn++)
               for (int dm=0; dm<=1; dm++){
                   res[n][m][dn][dm]=inf;
               }
           res[0][0][0][0]=0;
         for (int i=0; i<4*N*M; i++){
           for (int n=0; n<N; n++)
           for (int m=0; m<M; m++)
               for (int dn=0; dn<=1; dn++)
               for (int dm=0; dm<=1; dm++){
                   int t=res[n][m][dn][dm];
                   int n0,m0;
                   n0=n; m0=m+(2*dm-1);
                   upd(n,m+(2*dm-1),dn,1-dm, t+2);
                   upd(n+(2*dn-1),m,1-dn,dm, t+2);

                   upd(n,m,1-dn,dm, minS(n,m,t)+1);
                   upd(n,m,dn,1-dm, minW(n,m,t)+1);

               }
        }
        out.println(res[N-1][M-1][1][1]);
    } //Solve

    private int minS(int n, int m, int x) {
        int w=W[n][m];
        int s=S[n][m];
        int t=T[n][m];
        return minSW(w,s,t,x);
    }

     private int minW(int n, int m, int x) {
        int w=W[n][m];
        int s=S[n][m];
        int t=T[n][m];
        return minSW(s,w,t+s,x);
    }

   private int minSW(int w, int s, int t, int x) {
    {
        int d=x-t;
        int rem=rem(d,w+s);
        if (rem<s) return x;
        return x+w+s-rem;
    }
    }

    private void upd(int n, int m, int dn, int dm, int x) {
        if (n>=0 && n<N && m>=0 && m<M)
            res[n][m][dn][dm]=Math.min(x,res[n][m][dn][dm]);
    }

}// class
