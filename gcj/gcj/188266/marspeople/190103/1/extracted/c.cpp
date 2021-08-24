#include <cstdio>
#include <cstring>
#include <algorithm>
#define IT 2000
using namespace std;

double pd[50][IT+1];
int memo[50][IT+1],c,n;

long long bin[620][520];

long long binomial(int n, int k){
	if (n<k) return 0;
	if (n==0) return 1;
   k = min(k,n-k);
   if(k==0) return 1;
   return (n-k+1)*binomial(n,k-1)/k;
}

double calc(int a,int b) {
	if (b==IT) return 0.0;
	if (a>=c) return 0.0;
	if (memo[a][b]!=-1) return pd[a][b];
	
	double res=0;
	for (int i=0; i<=n; i++) {
		res+=(double) (bin[a][n-i]*((double)bin[c-a][i]/bin[c][n]))*(calc(a+i,b+1)+1);
	}
		
	pd[a][b]=res;
	memo[a][b]=1;
	return res;
}

int main() {
	int nt;
	
	for (int i=0; i<=100; i++)
	for (int j=0; j<=100; j++) bin[i][j]=binomial(i,j);
	
	scanf(" %d",&nt);
	for (int ct=1; ct<=nt; ct++) {
		scanf(" %d %d",&c,&n);
		memset(memo,-1,sizeof(memo));
		
		printf("Case #%d: %lf\n",ct,calc(0,0));
	}
	
	return 0;
}
	
