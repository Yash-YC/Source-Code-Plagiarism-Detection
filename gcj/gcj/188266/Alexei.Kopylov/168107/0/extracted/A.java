package a;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.System.*;
import java.io.*;
import mylibrary.functions.*;
import static mylibrary.functions.MyPermutations.*;
import static mylibrary.functions.Arena.*;
import static mylibrary.functions.MyMath.*;
import static mylibrary.functions.Geometry.*;
import static mylibrary.functions.MyPermutations.*;
import static mylibrary.Iterators.*;
import static mylibrary.functions.Data.*;

public class A {

    static String fileName="A-small-attempt0";
//    static String fileName="A-large";
  //  static String fileName="A-test";
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

                    for (int b=2; b<=10; b++) {
            good[b][1]=true;
            visited[b][1]=true;
            for (int i=2; i<N; i++){
                good[b][i]=visit(b,i);
            }
        }



            NumberOfCases=sc.nextInt();
            sc.nextLine();
            for (caseN = 1; caseN <= NumberOfCases; caseN++) {
                out.print("Case #"+caseN+": ");
                (new A()).Solve();
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

        static int N=1000000;
        static boolean[][] good =new boolean[11][N];
        static boolean[][] visited =new boolean[11][N];

        static boolean visit(int b, int n){
            if (visited[b][n]) return good[b][n];
            visited[b][n]=true;
            return good[b][n]=visit(b,sq(b,n));
            
        }
    void Solve() {
        String[] s=sc.nextLine().trim().split(" ");
        int[] bases=new int[s.length];
        for (int i=0; i<s.length; i++){

            err.print(s[i]+" ");
            bases[i]=Integer.parseInt(s[i]);
        }

       i:
       for (int i=2; i<N; i++){
           boolean g=true;
           for (int b=0; b<bases.length; b++)
               if (!good[bases[b]][i]) continue i;
           out.println(i);
           return;
       }
    } //Solve

    static int sq(int b, int n) {
        String s=Integer.toString(n, b);
        int res=0;
        for (int i=0; i<s.length(); i++){
            int d=s.charAt(i)-'0';
            res+=d*d;

        }
        return res;
    }

}// class
