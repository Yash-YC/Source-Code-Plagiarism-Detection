
#include<algorithm>
#include<bitset>
#include<iostream>
#include<string>
#include<cstdio>
#include<sstream>
#include<vector>
#include<stack>
#include<deque>
#include<map>
#include<iterator>
#include<cmath>
#include<complex>
#include<queue>
#include<cassert>
#include<set>
#include<cstring>
#include<list>
#include<numeric>
#include<cassert>

#define FOREACH(it ,c ) for( typeof((c).begin()) it= (c).begin();it!=(c).end();++it) 
#define debug(x) cerr<< #x << " = " << x << "\n";
#define debugv(x) cerr<< #x << " = " ; FOREACH(it,(x)) cerr << *it << "," ; cerr<< "\n" ;
#define MP make_pair
#define PB push_back
#define siz(w) (int)w.size()
#define fup(i,st,ko) for(int i=st;i<=ko;i++)
#define fdo(i,st,ko) for(int i=st;i>=ko;i--)
#define REP(i,w) for(int i=0;i<siz(w);i++)
#define inf 100000000

using namespace std;

typedef long long ll;

int on_base(int base, int x)
{
	int score = 0;
	while(x > 0)
	{
		int kt = x % base;
		x /= base;
		score += kt * kt;
	}
	return score;
}

bool try_with(int base, int x)
{
	set<int> was;
	while(true)
	{
		int xx = on_base(base, x);
		if(xx == 1) return true;
		if(was.find(xx) != was.end()) return false;
		was.insert(xx);
		x = xx;
	}
}

int main()
{
	fup(i,2,10) fup(j,i + 1,10) fup(k, j, 10)
	{
		int x = 2;
		bool is = false;
		while(!is)
		{
			if(try_with(i, x) and try_with(j, x) and try_with(k, x))
			{
				cout << "tab[" << i << "][" << j << "][" << k  << "] = " << x << ";" << endl;
				break;
			}
			else
			{
				x ++;
			}
		}
	}

	return 0;
}



