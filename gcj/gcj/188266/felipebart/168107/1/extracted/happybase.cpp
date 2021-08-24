#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define MAXN 11000000
#define MAXB 11

bool ishappy[MAXN][MAXB];
bool mrk1[MAXN][MAXB];
bool mrk2[MAXN][MAXB];

int nxt(int v,int b){
    int ret = 0;
    int k = v;
    int d;
    while(k > 0){
	d = k % b;
	ret += d*d;
	k /= b;
    }
    return ret;
}

int main(){
  
  int i,j,k;
  
  for(i=0;i<MAXN;i++){
      for(j=2;j<MAXB;j++){
	ishappy[i][j] = false;
	mrk1[i][j] = false;
	mrk2[i][j] = false;
      }
  }
  
  for(j=2;j<MAXB;j++){
      ishappy[1][j] = true;
      mrk1[1][j] = true;
      mrk2[1][j] = true;
  }
  
  for(i=2;i<MAXN;i++){
      for(j=2;j<MAXB;j++){
	k = i;
	while(!mrk1[k][j]){
	  //printf("%d %d\n",k,nxt(k,j));
	  mrk1[k][j] = true;
	  k = nxt(k,j); 
	}
	if(ishappy[k][j]){
	  k = i;
	  while(!mrk2[k][j]){
	    mrk2[k][j] = true;
	    ishappy[k][j] = true;
	    k = nxt(k,j);
	  }
	}
      }
  }
  
  int t,lp;
  int n;
  int bases[MAXB];
  char buf[1000];
  string hlp;
  
  scanf(" %d ",&t);
  
  for(lp=1;lp<=t;lp++){
    gets(buf);
    hlp = string(buf);
    stringstream o(hlp);
    n = 0;
    while(o >> bases[n]){
      n++;
    }
    
    int ret;
    for(i=2;i<MAXN;i++){
	bool ok = true;
	for(j=0;j<n;j++){
	    if(!ishappy[i][bases[j]]){
	      ok = false;
	      break;
	    }
	}
	if(ok){
	  ret = i;
	  break;
	}
    }
    
    printf("Case #%d: %d\n",lp,ret);
    
  }
  
  return 0;
}