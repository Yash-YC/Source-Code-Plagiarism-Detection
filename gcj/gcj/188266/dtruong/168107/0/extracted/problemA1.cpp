 #include <conio.h>
 #include <stdio.h>
 #include <memory.h>
 #include <string.h>
 
 #define fi "A-small.in"
 #define fo "A-small.out"
 #define maxN 50000
 
 char h[maxN][8];
 char d[maxN],c;
 long s[500],k;
 int count,T,i,b[9],num,check,j;
 
 void readfile(){
      FILE *f=fopen(fi,"rt");
      FILE *g=fopen(fo,"wt");
      fscanf(f,"%d",&T);
      for (i=0;i<T;i++){
	  count=0;
	  c=0;
          do{
	      fscanf(f,"%d",&num);
	      if (num>2){
		 b[count]=num;
		 count++;
              }
	      c=fgetc(f);
	  }while (c!='\n');

	  for (k=2;k<maxN;k++){
		check=1;
	      for (j=0;j<count;j++)
		  if (h[k][b[j]-3]!=1) {check=0;break;}
	      if (check){
			 printf("%d\n",k);
 	         fprintf(g,"Case #%d: %d\n",i+1,k); 
			 break;
              }
          }
          
      }
      fclose(f);
      fclose(g);
 }
 /*****************************/
 void writefile(){
 }
 /***************************/
 long sumOfSquareDigit(long n,int b){
      long m=n,s=0,r;
      while (m>0){
	    r=m%b;
	    s+=r*r;
	    m=m/b;
      }
      return s;
 }
 /***************************/
 void happy(long n,int b){
     int check=(h[n][b-3]!=0),e,i;
     count=0;
     while (!check){
	   s[count]=n;
	   d[n]=1;
	   count++;
	   n=sumOfSquareDigit(n,b);
	   check=(h[n][b-3]!=0)||(d[n]!=0);
     }
     if (h[n][b-3]==0) e=2; else e=h[n][b-3];
     for (i=0;i<count;i++) h[s[i]][b-3]=e;
 }
 /***************************/
 void solve(){
      int i;
      long k,j;
      for (i=0;i<8;i++) h[1][i]=1;
      for (i=0;i<8;i++){
	   for (j=0;j<maxN;j++) d[j]=0;
      for (k=2;k<maxN;k++){
//	  if (k%(i+3)==0) h[k][i+3]=h[k/(i+3)][i+3]; else
	      happy(k,i+3);
	  }
      }
//      for (i=0;i<100;i++)
//      if (h[i][1]==0) printf("%3d",i);
 }
  /***************************/
 int main(){
//     clrscr();
     solve();
     readfile();
//     for (int i=0;i<8;i++)
//	 if (h[2][i]==1) printf("%3d",i+3);

     return 0;
 }
