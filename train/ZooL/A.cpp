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

const int maxn = 1005;
struct st
{
	int t[4 * maxn];
	int pos[4 * maxn];

	void build(int v, int tl, int tr, const string &s)
	{
		if (tl == tr)
		{
			t[v] = s[tl];
			pos[v] = tl;
		}
		else
		{
			int tm = (tl + tr) / 2;

			build(2 * v, tl, tm, s);
			build(2 * v + 1, tm + 1, tr, s);

			if (t[2 * v] <= t[2 * v + 1])
			{
				t[v] = t[2 * v + 1];
				pos[v] = pos[2 * v + 1];
			}
			else
			{
				t[v] = t[2 * v];
				pos[v] = pos[2 * v];
			}
		}
	}

	pii getMax(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return pii(-1, -1);

		if (tl == l && tr == r)
			return mp(t[v], pos[v]);
		else
		{
			int tm = (tl + tr) / 2;

			pii v1 = getMax(2 * v, tl, tm, l, min(tm, r));
			pii v2 = getMax(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);

			if (v1 <= v2)
				return v2;
			else
				return v1;
		}
	}
};
void solve()
{
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		string s;
		cin >> s;

		st sg;
		int n = s.size();
		sg.build(1, 0, n - 1, s);

		stack<pii> r;
		r.push(mp(0, n - 1));
		string t;
		string add;
		while (!r.empty())
		{
			pii cur = r.top();
			r.pop();

			pii ans = sg.getMax(1, 0, n - 1, cur.X, cur.Y);

			t.pb(char(ans.X));

			pii v1 = mp(cur.X, ans.Y - 1);
			pii v2 = mp(ans.Y + 1, cur.Y);

			string tmp = s.substr(ans.Y + 1, cur.Y - ans.Y - 1 + 1);
			add = tmp + add;
			if (v1.Y - v1.X >= 0)
				r.push(v1);
		}
		t += add;
		cout << "Case #" << q + 1 << ": " << t << endl;
	}
}

int main()
{
	
	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
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