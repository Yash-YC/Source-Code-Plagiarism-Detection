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

int f(vector<int>&v)
{
	int r = 0;
	rep(i,0,v.size())
		r+=v[i]*v[i];
	return r;
}

vector<int> conv(int x,int base)
{
	vector<int> r;
	if(x == 0)
		r.PB(0);
	for(;x;x/=base)
		r.PB(x%base);
	return r;
}
vector<int> one;
char a[10000001];
bool solve(int n,int base)
{
	vector<int> v = conv(n,base);
	set<vector<int> >vis;
	vis.insert(v);
	while(1)
	{
		long long x= f(v);
		v = conv(x,base);
		if(v==one)
			return true;
		if(vis.count(v))
			return false;
		vis.insert(v);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	#endif
	int t,x;
	scanf("%d ",&t);
	one.PB(1);
	vector<int> bases;
	rep(tt,0,t)
	{
		bases.clear();
		gets(a);
		stringstream ss;
		ss<<a;
		while(1)
		{
			ss>>x;
			if(ss.fail())
				break;
			bases.PB(x);
		}
		printf("Case #%d: ",tt+1);
		for(int i = 2;;++i)
		{
			rep(j,0,bases.size())
				if(!solve(i,bases[j]))
					goto bara;
			printf("%d\n",i);
			break;
			bara:;
		}
	}
	
	return 0;
}
