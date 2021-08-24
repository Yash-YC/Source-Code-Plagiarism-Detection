#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<cassert>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

#define LET(x,a) 	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define FOR(i,a,b)  	for(int i=(int)(a) ; i < (int)(b);++i)
#define REP(i,n) 	FOR(i,0,n)
#define PB		push_back
#define MP 		make_pair
#define EPS		1e-9
#define INF 2000000000

typedef vector<int>	VI;
typedef long long	LL;
typedef pair<int,int>	PI;
LL nCr[50][50];
void ncr() {
	nCr[0][0] = 1;
	for(int i = 1; i < 50; ++i) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for(int j = 1; j < i;++j){
			nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
		}
	}
}
long double dp[50][50][50];
long double calc(int p,int n,int c){
	if( p >= c) return 0.0;
	if(dp[p][n][c] > -1e-3) return dp[p][n][c];
	long double p1,ret = 0;
	p1 = (nCr[p][n])/((long double)(nCr[c][n]));
	for(int i = 1; i< n+1;++i){
		long double tmp = (((long double)nCr[p][n-i])*nCr[c-p][i])/((long double)nCr[c][n]);
		ret += tmp*(1+ calc(p+i,n,c));
	}
	ret += p1;
	ret /= (1-p1);
	return dp[p][n][c] = ret;
	

}
int main() {
	int t;
	ncr();
	scanf("%d",&t);
	for (int kases = 1; kases <= t; ++ kases) { 
		cout << "Case #"<<kases <<": ";
		int n,c;
		scanf("%d%d",&c,&n);
		REP(i,c+1) REP(j,c+1) REP(k,c+1) dp[i][j][k] = -1;
		if (n == c) {cout <<"1.0000000000"<<endl;
			continue;
		}
		printf("%.10LF\n", calc(n,n,c) +1);
	}

return 0;
}

