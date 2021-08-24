#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "basket"

vector <int> g;
vector <int> used;
vector <int> tin;

int ans;
void dfs(int v, int it, int time = 0)
{
	used[v] = it;
	tin[v] = time;

	int to = g[v];

	if (used[to] == 0)
		dfs(to, it, time + 1);
	else
	{
		if (used[to] != it)
			return;
		else
			ans = max(ans, time - tin[to] + 1);
	}
}

vector <vector <int> > rg;

void solve()
{
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		int n;
		scanf("%d", &n);

		g.clear();
		g.resize(n);
		rg.clear();
		rg.resize(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &g[i]);
			g[i]--;
			rg[g[i]].pb(i);
		}
		ans = 1;
		int it = 1;
		used.clear();
		used.resize(n);
		tin.clear();
		tin.resize(n);
		for (int i = 0; i < n; i++)
		{
			if (used[i] == 0)
				dfs(i, it);
			it++;
		}
		vector <pii> ps;
		int ans2 = 0;
		for (int i = 0; i < n; i++)
		{
			int to = g[i];
			if (to < i)
				continue;
			if (g[to] == i)
			{
				ps.pb(mp(i, to));
			}
		}

		
		for (int i = 0; i < ps.size(); i++)
		{
			vector <int> d(n, inf);
			queue<int> Q;
			Q.push(ps[i].X);
			d[ps[i].X] = d[ps[i].Y] = 0;
			int mx = 0;
			while (!Q.empty())
			{
				int v = Q.front();
				Q.pop();

				for (int j = 0; j < rg[v].size(); j++)
				{
					int to = rg[v][j];
					if (d[to] == inf)
					{
						d[to] = d[v] + 1;
						mx = max(mx, d[to]);
						Q.push(to);
					}
				}
			}
			d.assign(n, inf);
			Q.push(ps[i].Y);
			d[ps[i].X] = d[ps[i].Y] = 0;
			int mx2 = 0;
			while (!Q.empty())
			{
				int v = Q.front();
				Q.pop();

				for (int j = 0; j < rg[v].size(); j++)
				{
					int to = rg[v][j];
					if (d[to] == inf)
					{
						d[to] = d[v] + 1;
						mx2 = max(mx2, d[to]);
						Q.push(to);
					}
				}
			}
			ans2 += mx + mx2 + 2;
		}

		printf("Case #%d: %d\n", q + 1, max(ans, ans2));
	}
}

int main()
{

	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);
	solve();
	//END
	return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
	forn(i, v.size())
		is >> v[i];
	return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
	forn(i, v.size())
		os << v[i];
	return os;
}
#endif