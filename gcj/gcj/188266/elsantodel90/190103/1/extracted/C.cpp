#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

tdbl c[1024][1024];

void icomb()
{
	forn(i, 1024)
	{
		c[i][i] = c[i][0] = 1.0;
		forsn(j,1,i)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
}

tdbl comb(int a,int b)
{
	if (0 <= b && b <= a)
		return c[a][b];
	else
		return 0;
}

tdbl e[64];

int main()
{
	icomb();
	freopen("entrada.in","r",stdin);
	freopen("salida.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		int C,n;
		cin >> C >> n;
		
		e[C] = 0.0;
		dforsn(t,n,C)
		{
			tdbl s = 0.0;
			forsn(i,1,min(C-t,n)+1)
				s += (e[t+i] * comb(C-t,i)) * comb(t,n-i);
			s = (s / comb(C,n)) + 1.0;
			s /= (1.0 - comb(t,n) / comb(C,n));
			e[t] = s;
		}
		double res = 1.0 + e[n];
		printf("Case #%d: %.25lf\n",caso+1,res);
		//cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}

