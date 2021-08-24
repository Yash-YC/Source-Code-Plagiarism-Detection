#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i(a), _n(b); i<=_n; i++)
#define FR(i,b) FOR(i,0,b-1)
#define REP(i,a,b) for(int i(a), _n(b); i >= _n; i--)
#define _M(a) memset(a,0,sizeof(a))
#define IN scanf
#define OUT printf
#define sqr(q) ((q)*(q))
#define ll long long
#define ul unsigned ll
#define INF 100000
#define DF 100000

int KT;
char s[100];
int F[DF];
int os[100];
set <int> T;

bool happy(int c, int o)
{
	_M(F);
	T.clear();
	while ( 1 )
	{
	//	OUT("2");
		int t = 0;
		if (c < DF) F[c] = 1; else T.insert(c);
		
		while (c)
		{
			t += sqr(c % o); 
			c /= o;
		}
		
		if (t == 1) return true;
		if ((t < DF && F[t] == 1) || (t >= DF && T.find(t) != T.end())) return false;
		c = t;
	}
}


int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	IN("%d\n", &KT);
	
	FOR(test, 1, KT)
	{
		gets(s);
		_M(os);
		{
			int p = 0;
			int t = 0;
			
			while (s[p]) if (s[p] == ' ') os[t] = 1, t = 0, p++; else t = t*10+s[p++]-'0';	
			os[t] = 1;
		}
		
		int c = 2;
		while ( 1 )
		{
		//	OUT("1");
			bool f = 1;
			for(int i = 2; i<= 10 && f; i++) if (os[i]) f = happy(c, i);
			if (f)
			{
				OUT("Case #%d: %d\n", test, c);	
				break;
			}
			c++;
		}		
	}
	return 0;
}
