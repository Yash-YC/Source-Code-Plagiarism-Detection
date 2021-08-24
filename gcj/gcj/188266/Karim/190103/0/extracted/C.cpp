#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <queue>
#include <complex>
#include <ctime>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define rep(i,x,n) for(int i = (x) ; i < (n) ; ++i)
#define repit(it,x,n) for(__typeof(x) it = (x) ; it!=(n) ;++it)

int n,c;
int end;
double mem[(1<<10)+1],p;
bool vis[(1<<10)+1];
int cnt[(1<<10)+1];

double f(int mask)
{
	if(mask == end)
		return 0.;
	if(vis[mask])
		return mem[mask];
	double r = 0.,T=0;
	rep(i,1,1<<c)
	{
		if(cnt[i] == n)
		{
			if((i&mask) == i )
			{
				T++;
				continue;
			}
			r+=1./p*(1.+f(mask|i));
		}
	}
	double ans = (p*r+T)/(p-T);
	vis[mask]=1;
	return mem[mask]=ans;
}

long long fact(int x)
{
	long long r = 1;
	for(int i = 2;i<=x;++i)
		r*=i;
	return r;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	#endif
	int t;
	rep(i,0,1<<10)
		cnt[i]=__builtin_popcount(i);
	scanf("%d",&t);
	rep(tt,0,t)
	{
		scanf("%d %d",&c,&n);
		end = (1<<c)-1;
		p = (1.*fact(c)/(fact(n)))/(fact(c-n));
		printf("Case #%d: ",tt+1);
		memset(vis,0,sizeof(vis));
		printf("%.07lf\n",f(0));
	}
	
	
	return 0;
}
