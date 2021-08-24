#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
using namespace std;
const int BUF = 45;

int N, K;

void read(){
  cin >> N >> K;
}

long double bino(int n, int k){
  if(k==0) return 1;
  return bino(n-1,k-1)*n/k;
}

double rec(int nKnow, int nTotal, double dp[BUF]){
  double &ret = dp[nKnow];
  if(nKnow==nTotal) return ret = 0;
  if(ret>=0) return ret;

  long double selfP = 0, sum = 0;
  long double toDiv = bino(nTotal,K);
  double ppp = 0;
  for(int nAddKnow=0;nAddKnow<=K;nAddKnow++){
    if((K-nAddKnow)>nKnow || nKnow+nAddKnow>nTotal) continue;
    long double p =  bino(nKnow,K-nAddKnow)*bino(nTotal-nKnow,nAddKnow)/toDiv;
    ppp += p;
    if(nAddKnow==0) 
      selfP = p;
    else
      sum += p*(rec(nKnow+nAddKnow,nTotal,dp)+1);
  }
  if(fabs(ppp-1)>1.0e-6){
    cout << ppp << " " << nKnow << ' '<< nTotal << ' ' << N << ' ' << K << endl;
    assert(false);
  }
  return ret = (selfP+sum)/(1-selfP);
}

void work(int cases){
  double dp[BUF];
  for(int i=0;i<BUF;i++) dp[i] = -1;
  printf("Case #%d: %.8lf\n",cases,rec(0,N,dp));
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
