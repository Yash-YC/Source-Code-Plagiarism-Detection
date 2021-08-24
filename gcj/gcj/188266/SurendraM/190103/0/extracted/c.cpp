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
#define bp(i) __builtin_popcount(i)
typedef pair<int,int> PI;
#define MP(x,y) make_pair(x,y)
#define f first
#define s second
#define VP vector<PI>
#define S(t)	scanf("%d",&t)
int t,tot;
int r[2000];
double mem2[2000][2000];
int mem[2000][2000],MAX;

double fn(int mask,int st){
	if(st>1000)	return 0.0;
	if(mem[mask][st])	return mem2[mask][st];
	mem[mask][st]=1;
	if(mask+1==MAX)	return mem2[mask][st]=st*1.0;
	double ret=0;
	F(i,tot){
		int k=r[i];
		ret+=(fn((mask|k),st+1))/tot;
	}
	return mem2[mask][st]=ret;
}

int main(){
	cin>>t;
	FF(cas,1,t+1){
		int c,n;
		cin>>c>>n;
		MAX=(1<<c);
		tot=0;
		F(i,MAX)	if(bp(i)==n)	r[tot++]=i;
		CLR(mem,0);
		double ans=fn(0,0);
		cout<<"Case #"<<cas<<": "<<setiosflags(ios::fixed)<<setprecision(7)<<ans<<endl;
	}
	return 0;
}
