#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define rep2(i,x,m) for(int i=x;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo = (int) 1e9;
int N,n,c;
vector<int> v;
void gen(int cur,int mask,int cnt){
	if(cnt==n){
		v.pb(mask);
		return;
	}
	if(cur==c)
		return;
	gen(cur+1,mask,cnt);
	gen(cur+1,mask|(1<<cur),cnt+1);
}
const int MX=300;
double dp[1<<10][MX];
double vis[1<<10][MX];
double calc(int mask,int cnt){
	if(mask==(1<<c)-1 || cnt==MX)
		return 0;
	if(vis[mask][cnt])
		return dp[mask][cnt];
	double ret=0;
	rep(i,v.sz)
		ret+=(1./v.sz)*(1+calc(mask|v[i],cnt+1));
	vis[mask][cnt]=1;
	return dp[mask][cnt]=ret;
}
int main() {
//#define SAMPLE
#ifndef SAMPLE
	freopen("C-small-attempt1.in","rt",stdin);
	freopen("C-small-attempt0.out","wt",stdout);
#endif
#ifdef SAMPLE
	freopen("a.txt", "rt", stdin);
#endif
	cin>>N;
	rep(nn,N){
		cin>>c>>n;
		v.clear();
		gen(0,0,0);
		mem(vis,0);
		printf("Case #%d: %.6lf\n",nn+1,calc(0,0));
		//cout<<v.sz<<endl;
		fflush(stdout);
	}
	return 0;
}
