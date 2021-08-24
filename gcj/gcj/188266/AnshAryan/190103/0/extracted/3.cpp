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

typedef long double LD;

LL nCr[45][45];

LD solve(int X,int N,int C){
	if(X>=C)return 0;
	LD p1=(LD)nCr[X][N]/(LD)nCr[C][N];
	LD e=0;
	FOR(n,1,N+1){
		LD p=((LD)nCr[X][N-n]*nCr[C-X][n])/(LD)nCr[C][N];
		e+=p*(1+solve(X+n,N,C));
	}
	e+=p1;
	e/=(1-p1);
	return e;
}

int main(){
	int cas=0;
	FOR(i,1,41){
		nCr[i][0]=1;
		nCr[i][i]=1;
		FOR(j,1,i)nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];

	}
	int t;cin>>t;while(t--){
		cas++;cout<<"Case #"<<cas<<": ";
		int C,N;
		cin>>C>>N;
		if(N==C){
			cout<<"1.000000\n";continue;
		}
		LD ans=1+solve(N,N,C);
		printf("%.10Lf\n",ans);
	}
	return 0;
}
