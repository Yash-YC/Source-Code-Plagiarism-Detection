#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

int k, n, m, r[110000];

void read() {
	cin >> k >> n >> m;
	forn(i, k)
		scanf("%d", &r[i]);
}

multiset<pair<int, int> > a;
bool u[1100];
pair<int, int> ans[1100];
vector<int> h;

inline void add(pair<int, int> p) {
	if (p.fs <= n && p.sc <= m)
		a.insert(p);
}

inline void del(pair<int, int> p) {
	if (p.fs <= n && p.sc <= m)
		a.erase(a.find(p));
}

bool rec(int p, int dep) {
	if (dep == k) {
		forn(i, k)
			printf("%d %d ", ans[i].fs, ans[i].sc);
		puts("");
		return true;
	}

	if (a.empty())
		return false;

	pair<int, int> c = *a.begin();
	a.erase(a.begin());
	while (u[p])
		p++;

	bool one = false;
	for (int i = p; i < k; i++) 
		if (!u[i]) {
			ans[i] = c;
			if (c.fs)
				ans[i].fs += r[i];
			if (c.sc)
				ans[i].sc += r[i];
			if (ans[i].fs > n || ans[i].sc > m)
				continue;

			bool fl = true;
			forn(j, h.size())
				if (sqrt(double(ans[i].fs - ans[h[j]].fs) * (ans[i].fs - ans[h[j]].fs) + 
				double(ans[i].sc - ans[h[j]].sc) * (ans[i].sc - ans[h[j]].sc)) 
				< r[i] + r[h[j]] - EPS) {
					fl = false;
					break;
				}

			if (!fl)
				continue;

			one = true;

			h.pb(i);
			u[i] = true;
			add(mp(ans[i].fs + r[i], max(0, ans[i].sc - r[i])));
			add(mp(max(0, ans[i].fs - r[i]), ans[i].sc + r[i]));
			if (rec(p, dep + 1))
				return true;
			del(mp(ans[i].fs + r[i], max(0, ans[i].sc - r[i])));
			del(mp(max(0, ans[i].fs - r[i]), ans[i].sc + r[i]));
			h.pop_back();
			u[i] = false;
		}

	if (rec(p, dep))
		return true;

	a.insert(c);
	return false;
}

void solve() {
//	sort(r, r + k);
//	reverse(r, r + k);

	a.insert(mp(0, 0));
	memset(u, 0, sizeof(u));
	h.clear();
	rec(0, 0);
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
	
	int tt;
	cin >> tt;
	forn(ii, tt) {
		cerr << ii << "/" << tt << endl;
		read();
		printf("Case #%d: ", ii + 1);
		solve();
	}
	
	return 0;
}