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
#include <sstream>

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

const int mn=200005,mb=11;
int mem[mb][mn];
VI happy[mb];

int go(int base,int v){
	int & ret=mem[base][v];
	if(ret!=-1)	return ret;
	if(v==1)	return ret=1;
	ret=0;
	int next=0;
	while(v){
		int r=(v%base);
		next+=r*r;
		v/=base;	
	}
	return ret=go(base,next);
}

int main(){
	
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	REP(i,mb)	REP(j,mn)	mem[i][j]=-1;
	FOR(i,2,mb){
		FOR(j,1,mn){
			int z=go(i,j);	
			if(z==1)	happy[i].pb(j);
		}
	}
//	FOR(i,2,mb)	{REP(j,5)	cout<<happy[i][j]<<" ";cout<<endl;}
	int Kase;cin>>Kase;cin.get();
	FOR(kase,1,Kase+1){
		
		VI bases;
		string inp;
		getline(cin,inp);
		istringstream iss(inp);
		int a;
		while(iss>>a)	bases.pb(a);
		VI pt(int(bases.sz),1);
		int ans=-1;
		while(1){
			int mi=INF,pos=-1;
			REP(i,bases.sz){
				if(happy[ bases[i] ][ pt[i] ]<mi){
					mi=happy[ bases[i] ][ pt[i] ];
					pos=i;	
				}
			}
			if(pos)	goto label;
			REP(i,bases.sz){
				if(happy[ bases[i] ][ pt[i] ]!=mi)	goto label;	
			}
			ans=mi;
			break;
			label:;
			pt[pos]++;
		}
		printf("Case #%d: %d\n",kase,ans);
	}

//	GI;
	return 0;
}
