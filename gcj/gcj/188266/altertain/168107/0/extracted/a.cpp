#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for( int i=(a); i<(b); ++i)
#define FORD(i,a,b) for( int i=(a); i>(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

#define M 100000

char ln[M];
VI dt;
int path[11][M];
int jud[11][M];
int chk[11][M];

int f(int base,int val)
{
	int h=0;
	while(val) {
		int d=val%base;
		h+=d*d;
		val/=base;
	}
	return h;
}

int dfs(int base,int v)
{
//	cout<<base<<" "<<v<<endl; char qqq[5]; gets(qqq);

	if (v==1 || jud[base][v]==1) return 1;

	chk[base][v]=1;

	int next=path[base][v];
	if (chk[base][next]==1) {
		if (jud[base][next]<1) jud[base][next]=0;
		jud[base][v] = jud[base][next];
		return jud[base][v];
	}

	jud[base][v]=dfs(base,next);

	return jud[base][v];
}

void solve()
{
	memset(path,-1,sizeof(path));
	FOR(base,2,11)
		FOR(i,2,M)
		if (path[base][i]==-1)
			path[base][i]=f(base,i);

	memset(jud,-1,sizeof(jud));
	FOR(base,2,11)
		FOR(i,2,M) {
			if (jud[base][i]==-1)
				dfs(base,i);
		}

/*	FOR(base,2,10)
		FOR(i,2,101)
		cout<<base<<", "<<i<<" : "<<jud[base][i]<<endl;
	
	FOR(base,2,10)
		FOR(i,2,101)
		cout<<base<<", "<<i<<" : "<<path[base][i]<<endl;
		*/
//	dfs(3,30);
}

int main()
{
	solve();

	int tn,qq=1;

	gets(ln);
	sscanf(ln,"%d",&tn);
	while (tn--) {
		gets(ln);
		stringstream in(ln);
		dt.clear();
		int ka;
		while (in>>ka)
			dt.PB(ka);
		
		int dp=0;
		FOR(i,2,M) {
			bool good=true;
			REP(j,SZ(dt))
				if (jud[dt[j]][i]!=1)
					good=false;

			if (good) {
				dp=i;
				break;
			}
		}

		if (dp==0) cout<<"Error!"<<endl;
		printf("Case #%d: %d\n",qq++,dp);
	}
	return 0;
}
