/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define ALL(s) (s).begin(),(s).end()
#define R(i,m,n)	for(int i=m;i>=n;i--)
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define VI vector<int>
#define PB push_back
#define CLR(s,v) memset(s,v,sizeof(s))
string to_str(LL x){ ostringstream o;o<<x;return o.str();}
LL to_int(string s){ istringstream st(s); LL i;	st>>i;return i;}
#define FR(it,t) for(typeof(t.begin()) it=t.begin(); it!=t.end(); ++it)
typedef pair<int,int> PI;
#define MP(x,y) make_pair(x,y)
#define f first
#define s second
#define VP vector<PI>
#define S(t)	scanf("%d",&t)

int _tobase(int n,int b){
	int tn=1,ret=0;
	while(n){
		ret+=tn*(n%b);
		n/=b;
		tn*=10;
	}
	return ret;
}

int mp[1000000][11];
int fn(int k,int b){
//	cout<<k<<" "<<b<<endl;
	int &ret=mp[k][b];
	if(ret!=-1)	return ret;
	if(k==1)	return ret=1;
	ret=0;
	k=_tobase(k,b);
	int sm=0;
	while(k){
		sm+=(k%10)*(k%10);
		k/=10;
	}
	return ret=fn(sm,b);
}

int ans[1000];

int main(){
	VI v;
	int k;
	CLR(mp,-1);
	CLR(ans,0);
	F(ii,(1<<9)){
		k=ii;
		int cnt=2;
		v.clear();
		while(k){
			if(k&1)	v.PB(cnt);
			cnt++;
			k>>=1;
		}
		int i=2;
		while(true){
			int jj=1;
			k=i;
			F(j,v.size()){
				if(fn(k,v[j]))	continue;
				else{	jj=0;break;}
			}
			if(jj)	break;
			i++;
		}
		ans[ii]=i;
	}

	int t;
	string s;
	cin>>t;
	getline(cin,s);
	FF(cas,1,t+1){
		getline(cin,s);
		stringstream sm(s);
		VI v;
		int k;
		int mask=0;
		while(sm>>k){
			v.PB(k);
			mask|=(1<<(k-2));
		}
		cout<<"Case #"<<cas<<": "<<ans[mask]<<endl;
	}

	return 0;
}
