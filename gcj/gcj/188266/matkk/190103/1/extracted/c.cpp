
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
#define maxn 10000
double tab[43][maxn];
double prob[41][41][41][41];
double eps = 1e-10;

double policz(int c, int n)
{
	fup(i, 0, 40) fup(j, 0, maxn - 1) tab[i][j] = 0;	

	double wynik = 0;
	tab[n][1] = 1.0;
	if(n == c) return 1;
	fup(j,2, maxn - 1)
	{
		fup(have, 1, c) fup(to_have, have, c)
		{
			tab[to_have][j] += tab[have][j - 1] * prob[c][have][to_have][n];
		}
		double diff = (tab[c][j] - tab[c][j - 1]) * j;
		if(tab[c][j] >= 1 - eps) break;
		wynik += diff;
	}
	return wynik;
}

int count(int x)
{
	int ile = 0;
	while(x > 0)
	{
		ile += x % 2;
		x /= 2;
	}
	return ile;
}

long long D[50][50];

int main()
{
	fup(i,1,40) 
	{
		D[i][0] = 1;
		D[0][i] = 0;
		D[0][0] = 1;
	}
	fup(i, 1, 40) fup(j, 1, 40)
	{
		D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
	}

	fup(ile, 1, 40) fup(st, 1, 40) fup(nowy, st, 40) fup(all, nowy, 40)
	{
		int ad = nowy - st;
		prob[all][st][nowy][ile] = D[st][ile - ad] * 1.0 / D[all][ile] * D[all - st][ad];
	}

	int cas;
	cin >> cas;
	fup(i, 1, cas)
	{
		int N, C;
		cin >> C >> N;
		cout << "Case #" << i << ": " << policz(C, N) << endl;
	}

	return 0;
}



