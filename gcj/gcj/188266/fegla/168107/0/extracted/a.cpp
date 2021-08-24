/*
TASK:
LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
template<class key>
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;

#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
char toChar(int x)
{
	return x<10?x+'0':x-10+'A';
}

int toInt(char x)
{
	x=tolower(x);
	return x>='0' && x<='9'?x-'0':x-'a'+10;
}

string toBase(unsigned long long n,int b)
{
   string res;
   do
    {
    	res+=toChar(n%b);
    	n/=b;
    }
    while(n);
    reverse(res.begin(),res.end());
    return res;
}

unsigned long long toIntFromBase(string x,int b)
{
    unsigned long long y=0;
    unsigned long long p=1;
	for(int i=x.size()-1;i>=0;i--)
    {
       	y+=toInt(x[i])*p;
      	p*=b;
    }
    return y;
}
bool isOk(string &str,int b)
{
	set<int> s;

	while(1)
	{
		if(str=="1")
			return true;
		int x=0;
		foreach(s,str)
			x+=(*s-'0')*(*s-'0');
		if(!s.insert(x).second)
			return false;
		str=toBase(x,b);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("a.out","wt",stdout);
#endif
	string str;
	getline(cin,str);
	int T;
	sscanf(str.c_str(),"%d",&T);
	rep(tt,T)
	{
		getline(cin,str);
		int x;
		vector<int> bases;
		stringstream ss(str);
		while(ss>>x)
		{
			bases.push_back(x);
		}
		int cur=2;
		while(1)
		{
			rep(i,sz(bases))
			{
				string ss=toBase(cur,bases[i]);
				if(!isOk(ss,bases[i]))
					goto next;
			}
			break;
			next:cur++;
		}
		printf("Case #%d: %d\n",tt+1,cur);
	}
	return 0;
}
