import java.io.*;
import java.util.*;

public class B {
 public static void main(String argv[]) throws Exception {
  BufferedReader in=new BufferedReader(new FileReader("B.in"));
  int c=Integer.parseInt(in.readLine());
  for(int i=0;i<c;i++) {
   StringTokenizer st=new StringTokenizer(in.readLine());
   int n=Integer.parseInt(st.nextToken());
   int m=Integer.parseInt(st.nextToken());
   int[][] s=new int[n][m];
   int[][] w=new int[n][m];
   int[][] t=new int[n][m];
   for(int j=n-1;j>=0;j--) {
    st=new StringTokenizer(in.readLine());
    for(int k=0;k<m;k++) {
     s[j][k]=Integer.parseInt(st.nextToken());
     w[j][k]=Integer.parseInt(st.nextToken());
     t[j][k]=Integer.parseInt(st.nextToken());
    }
   }
   int[][] max=new int[n*2][m*2];
   for(int j=0;j<n*2;j++)
    for(int k=0;k<m*2;k++)
     max[j][k]=Integer.MAX_VALUE;
   max[0][0]=0;
   test(0,0,max,s,w,t,n,m);

   System.out.println("Case #"+(i+1)+": "+max[n*2-1][m*2-1]);
  }
 }

 public static void test(int y,int x,int[][] max,int[][] s,int[][] w,int[][] t,int n,int m) {
 // System.out.println(y+" "+x+" "+max[y][x]);
  if(y==n*2-1 && x==m*2-1)
   return;
  if(y<n*2-1) {
   if(y%2==1) {
    if(max[y+1][x]>max[y][x]+2) {
     max[y+1][x]=max[y][x]+2;
     test(y+1,x,max,s,w,t,n,m);
    }
   } else {
    int cycle=s[y/2][x/2]+w[y/2][x/2];
    int start=t[y/2][x/2]%cycle;
    if(start<0) start+=cycle;
    boolean[] good=new boolean[cycle];
    for(int i=start;i<start+s[y/2][x/2];i++)
     if(i<cycle)
      good[i]=true;
     else
      good[i-cycle]=true;
    int current=max[y][x];
    while(!good[current%cycle])
     current++;
    current++;
    if(max[y+1][x]>current) {
     max[y+1][x]=current;
     test(y+1,x,max,s,w,t,n,m);
    }
   }
  }
  if(x<m*2-1) {
   if(x%2==1) {
    if(max[y][x+1]>max[y][x]+2) {
     max[y][x+1]=max[y][x]+2;
     test(y,x+1,max,s,w,t,n,m);
    }
   } else {
    int cycle=s[y/2][x/2]+w[y/2][x/2];
    int start=t[y/2][x/2]%cycle;
    if(start<0) start+=cycle;
    boolean[] good=new boolean[cycle];
    for(int i=start;i<start+s[y/2][x/2];i++)
     if(i<cycle)
      good[i]=true;
     else
      good[i-cycle]=true;
    int current=max[y][x];
    while(good[current%cycle])
     current++;
    current++;
    if(max[y][x+1]>current) {
     max[y][x+1]=current;
     test(y,x+1,max,s,w,t,n,m);
    }    
   }
  }


 }
}