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

const int dx[3] = {1, 0, 0};
const int dy[3] = {0, +1, -1};

string s[110];
int n, m;
map<int, int> ans1;
map<int, string> ans2;

void read() {
	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
}

vector<pair<int, int> > v;
bool u[110][110];

void dfs(int x, int y) {
	if (u[x][y] || s[x][y] == '#')
		return;
	u[x][y] = true;
	v.pb(mp(x, y));

	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}

set<vector<bool> > used;
vector<bool> fin;

bool rec(vector<bool> a) {
	if (a == fin)
		return true;
	if (used.count(a))
		return false;
	used.insert(a);

	forn(dir, 3) {
		vector<bool> na(a.size(), 0);
		bool bad = false;
		forn(i, v.size())
			if (a[i]) {
				int nx = v[i].fs + dx[dir];
				int ny = v[i].sc + dy[dir];
				if (s[nx][ny] == '#') {
					nx = v[i].fs;
					ny = v[i].sc;
				}
				int pos = int(lower_bound(all(v), mp(nx, ny)) - v.begin());
				if (pos < (int)v.size() && v[pos] == mp(nx, ny))
					na[pos] = true;
				else {
					bad = true;
					break;
				}
			}

		if (bad)
			continue;

		if (rec(na))
			return true;
	}

	return false;
}

void solve(int x, int y) {
	v.clear();
	memset(u, 0, sizeof(u));
	dfs(x, y);
	sort(all(v));
	ans1[s[x][y] - '0'] = (int)v.size();

	used.clear();
	vector<bool> a(v.size(), 1);
	fin = vector<bool> (v.size(), 0);
	forn(i, v.size())
		if (v[i] == mp(x, y))
			fin[i] = true;

	if (rec(a))
		ans2[s[x][y] - '0'] = "Lucky";
	else
		ans2[s[x][y] - '0'] = "Unlucky";
}

void solve() {
	ans1.clear();
	ans2.clear();
	forn(i, n)
		forn(j, m)
			if (isdigit(s[i][j]))
				solve(i, j);

	for (map<int, int>::iterator it = ans1.begin(); it != ans1.end(); it++)
		printf("%d: %d %s\n", it->fs, it->sc, ans2[it->fs].c_str());
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
		printf("Case #%d:\n", ii + 1);
		solve();
	}
	
	return 0;
}