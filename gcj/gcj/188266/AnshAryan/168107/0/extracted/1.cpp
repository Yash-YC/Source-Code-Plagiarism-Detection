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
int bases[20],Next[100005][11];

int findNext(int x,int base){
	int ans=0;
	while(x){
		int r=x%base;ans+=(r*r);
		x/=base;
	}
	return ans;
}

int solve(int num,int base){
	if(Next[num][base]!=-1)return Next[num][base];
	if(num==1)return 1;
	Next[num][base]=2;
	return Next[num][base]=solve(findNext(num,base),base);
}


int main(){
	int cas=0;
	memset(Next,-1,sizeof(Next));
	FOR(i,2,100000){
		FOR(base,2,11)Next[i][base]=solve(i,base);
	}
	int t;scanf("%d\n",&t);while(t--){
		cas++;cout<<"Case #"<<cas<<": ";
		string s;getline(cin,s);
		istringstream ii(s);
		int n=0,base;
		while(ii>>base){
			bases[n++]=base;
		}
		bool printed=0;
		FOR(i,2,100000){
			bool flag=1;
			REP(j,n)if(Next[i][bases[j]]!=1){flag=false;break;}
			if(flag){
				printed=1;
				cout<<i<<endl;break;
			}
		}
		assert(printed);
	}
	return 0;
}

