import java.io.*;
import java.util.*;
import java.text.*;

public class C {
 public static void main(String argv[]) throws Exception {
  BufferedReader in=new BufferedReader(new FileReader("C.in"));
  int t=Integer.parseInt(in.readLine());
  for(int i=0;i<t;i++) {
   StringTokenizer st=new StringTokenizer(in.readLine());
   int c=Integer.parseInt(st.nextToken());
   int n=Integer.parseInt(st.nextToken());

   double tot=1;
   long num=c;
   for(int j=c-1;j>=c-n+1;j--)
    num*=j;
   for(int j=n;j>=1;j--)
    num/=j;
   long den=num*n/c;
   for(int j=1;j<=c-n;j++)
    tot+=(double)num/(den*j);

   NumberFormat nf=NumberFormat.getInstance();
   nf.setMinimumFractionDigits(7);
   nf.setMaximumFractionDigits(7);

   System.out.println("Case #"+(i+1)+": "+nf.format(tot));
  }
 }
}