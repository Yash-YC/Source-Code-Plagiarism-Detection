#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50
#define INF 1000000000000000000LL

int m,n;
long long S[MAXN][MAXN];
long long W[MAXN][MAXN];
long long T[MAXN][MAXN];

long long resp[MAXN][MAXN];

inline long long gettime(long long arrival,long long green,long long tot,long long begin){
    long long beg = begin % tot;
    //printf("%lld %lld\n",arrival,beg);
    if(arrival < beg){
	//printf("oi\n");
	if(arrival < beg - (tot-green)){
	  return arrival;
	}
	return beg;
    }
    
    long long arr = (arrival - beg) % tot;
    if(arr < green){
	return arrival;
    }
    
    return (arrival - arr + tot);
}

int main(){
  int i,j;
  int t,lp;
  
  scanf("%d",&t);
  for(lp=1;lp<=t;lp++){
    scanf("%d %d",&m,&n);
    for(i=m-1;i>=0;i--){
     for(j=0;j<n;j++){
      scanf("%lld %lld %lld",&S[i][j],&W[i][j],&T[i][j]); 
     }
    }
    
    for(i=0;i<=2*m;i++){
     for(j=0;j<=2*n;j++){
      resp[i][j] = INF;
     }
    }
    
    resp[0][0] = 0;
    
    for(i=0;i<2*m;i++){
	for(j=0;j<2*n;j++){
	    //printf("%d %d\n",i,j);
	    //north
	    if(i & 1){
		resp[i+1][j] = min(resp[i+1][j],resp[i][j]+2);
	    }
	    else{
		resp[i+1][j] = min(resp[i+1][j],gettime(resp[i][j],S[i/2][j/2],S[i/2][j/2]+W[i/2][j/2],T[i/2][j/2])+1);
	    }
	    
	    //east
	    if(j & 1){
		resp[i][j+1] = min(resp[i][j+1],resp[i][j]+2);
	    }
	    else{
		resp[i][j+1] = min(resp[i][j+1],gettime(resp[i][j],W[i/2][j/2],S[i/2][j/2]+W[i/2][j/2],T[i/2][j/2]+S[i/2][j/2])+1);
	    }
	  
	}
    }
    
    /*
    for(i=0;i<2*m;i++){
	for(j=0;j<2*n;j++){
	    printf("%lld ",resp[i][j]);
	}
	printf("\n");
    }
    */
    
    printf("Case #%d: %lld\n",lp,resp[2*m-1][2*n-1]);
    
  }
  
  return 0;
}