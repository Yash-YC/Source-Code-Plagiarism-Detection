#include<stdio.h>
#define tamNC 50
#define NITER 2231

int max(int a,int b){ return (a>b)?a:b;}
int min(int a,int b){ return (a<b)?a:b;}
double nChoose(int n,int k){
  if(n-k < k) return nChoose(n,n-k);
  double res =1.0;
  for(int i=0;i<k;i++){
    res *= (n-i);
  }
  for(int i=2;i<=k;i++){
    res /= i;    
  }
  return (double)res;
}
double prob(int jaTem, int repetido, int naoTem, int novo){
  if((jaTem < repetido) || (naoTem < novo)) return 0.0;
  return nChoose(jaTem,repetido)*nChoose(naoTem,novo)/nChoose(jaTem+naoTem,repetido+novo);
}


int main(){
  double P[tamNC];
  double Pprox[tamNC];
  double cF[NITER];
  int N,C,T;
  scanf("%d",&T);
  for(int caso=1;caso<=T;caso++){
    scanf(" %d %d ",&C,&N);
    if(N>=C){
      printf("Case #%d: %.6f\n",caso,1.0);
      continue;
    }
    for(int i=0;i<=C;i++) P[i]=Pprox[i]=0.0;
    for(int i=0;i<NITER;i++) cF[i]=1.0;
    P[0]=1.0;
    cF[0]=1.0;
    double res=0.0;
    double fatorRestante = 1.0;
    for(int b=1;b<NITER;b++){
      for(int i=0;i<=C;i++) Pprox[i]=0.0;
      for(int i=0;i<=C;i++){
	for(int x=0;x<=N;x++){
	  Pprox[i] += P[i-x]*prob(i-x,N-x,C-(i-x),x);
// 	  printf("%f,%f,%d,%d,%d,%d\n",prob(i-x,N-x,C-(i-x),x),P[i-x],i-x,N-x,C-(i-x),x);
	}
      }
      for(int i=0;i<=C;i++) {P[i]=Pprox[i];}
      cF[b] = cF[b-1] *(1.0- P[C]);
      res+=cF[b-1]*P[C]*b;
      for(int i=0;i<=C;i++) P[i] /= (1.0-P[C]);
      P[C]=0.0;
    }
    printf("Case #%d: %.6f\n",caso, res);
  } 
  return 0;
}
