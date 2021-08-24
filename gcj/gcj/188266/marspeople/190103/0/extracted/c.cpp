#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double pd[50][5001];
int memo[50][5001],c,n;

long long binomial(int n, int k){
	if (n<k) return 0;
	if (n==0) return 1;
   k = min(k,n-k);
   if(k==0) return 1;
   return (n-k+1)*binomial(n,k-1)/k;
}

double calc(int a,int b) {
	if (b==5000) return 0.0;
	if (a>=c) return 0.0;
	if (memo[a][b]!=-1) return pd[a][b];
	
	double res=0;
	for (int i=0; i<=n; i++) {
		res+=(double) (binomial(a,n-i)*((double)binomial(c-a,i)/binomial(c,n)))*(calc(a+i,b+1)+1);
	}
		
	pd[a][b]=res;
	memo[a][b]=1;
	return res;
}

int main() {
	int nt;
	
	scanf(" %d",&nt);
	for (int ct=1; ct<=nt; ct++) {
		scanf(" %d %d",&c,&n);
		memset(memo,-1,sizeof(memo));
		
		printf("Case #%d: %lf\n",ct,calc(0,0));
	}
	
	return 0;
}
	
