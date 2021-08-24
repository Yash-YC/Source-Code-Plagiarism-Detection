#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define INF int(1e9)

typedef long long LL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long double LD;

const int mn=41,mc=41;
LD C[mn][mn];
LD mem[mn];
int n,c;

LD go(int have){
	LD & ret=mem[have];
	if(ret>-0.5)	return ret;
	ret=0;
	if(have>=c)	return ret;
	int left=c-have;	
	bool ispos=0;
	REP(k,n+1){
		if(k>have)	break;
		if(n-k>left)	continue;
		if(n-k==0)	{ispos=1;continue;}
		ret+=(C[have][k]*C[left][n-k]*(1+go(have+n-k)));	
//		den+=C[have][k]*C[left][n-k];
	}
	LD den=C[c][n];
	if(ispos){
		ret+=C[have][n];
		den-=C[have][n];
	}
	ret/=den;
//	cout<<"In go:"<<have<<" "<<ret<<" "<<C[c][n]<<" "<<den<<endl;
	return ret;
}

int main(){
	
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	REP(i,mn)	REP(j,i+1){
		if(j==0 || j==i)	C[i][j]=1;
		else	C[i][j]=C[i-1][j]+C[i-1][j-1];	
	}
//	REP(i,10)	{REP(j,10)	cout<<C[i][j]<<" ";cout<<endl;}
	int Kase=GI;
	FOR(kase,1,Kase+1){
		
		c=GI,n=GI;
		REP(i,mn)	mem[i]=-1;
		printf("Case #%d: %.7lf\n",kase,double(go(0)));
	}
	
	return 0;
}
