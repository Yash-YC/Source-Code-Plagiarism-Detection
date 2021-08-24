#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50

double bin[MAXN][MAXN];

int c,n;
double resp[MAXN];

int main(){
  
  int i,j;
  for(i=0;i<MAXN;i++){
      for(j=0;j<MAXN;j++){
	  bin[i][j] = 0;
      }
  }
  
  bin[0][0] = 1;
  for(i=1;i<MAXN;i++){
      bin[i][0] = 1;
      for(j=1;j<MAXN;j++){
	  bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
      }
  }
  
  int t,lp;
  
  scanf("%d",&t);
  for(lp=1;lp<=t;lp++){
      scanf("%d %d",&c,&n);
      resp[c] = 0;
      for(i=c-1;i>=0;i--){
	double den = bin[i][n]*bin[c-i][0];
	double num = 0;
	
	for(j=1;j<=n;j++){
	  if(i+j <= c){
	    den += bin[i][n-j] * bin[c-i][j];
	    num += bin[i][n-j] * bin[c-i][j] * resp[i+j];
	  }
	}
	//printf("%lf %lf %lf\n",num,den,bin[i][n]*bin[c-i][0]);
	resp[i] = (den+num)/(den - bin[i][n]*bin[c-i][0]);
	//printf("%lf\n",resp[i]);
      }
      
      printf("Case #%d: %lf\n",lp,resp[0]);
      
  }
  
  return 0;
}