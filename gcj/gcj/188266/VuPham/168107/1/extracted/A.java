import java.io.*;
import java.util.*;

public class A {
 public static void main(String argv[]) throws Exception {
  BufferedReader in=new BufferedReader(new FileReader("A.in"));
  int n=Integer.parseInt(in.readLine());
  for(int i=0;i<n;i++) {
   StringTokenizer st=new StringTokenizer(in.readLine());
   boolean[] bases=new boolean[11];
   while(st.hasMoreTokens()) {
    int z=Integer.parseInt(st.nextToken());
    bases[z]=true;
   }

   boolean found=false;
   int count=2;
   while(!found) {
    count++;
    boolean good=true;
    for(int j=3;j<11 && good;j++)
     if(bases[j]) {
      Vector<Integer> v=new Vector<Integer>();
      if(!test(count,j,v))
       good=false;
     }
    if(good)
     found=true;
   }
   
   System.out.println("Case #"+(i+1)+": "+count);
  }
 }

 public static boolean test(int n,int b,Vector<Integer> v) {
  if(v.contains(n))
   return false;
  if(n==1)
   return true;
  v.addElement(n);
  int t=0;
  while(n>0) {
   int z=n%b;
   t+=z*z;
   n=n/b;
  }  
  return test(t,b,v);
 }
}