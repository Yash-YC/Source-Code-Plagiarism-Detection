#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#define sz(x) ((int)(x.size()))
#define all(c) (c).begin(),(c).end() 
#define pb push_back 
#define mp make_pair
#define foreach(T, x, it) for (T::iterator it = x.begin(); it != x.end(); ++it)
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

int S[30][30], W[30][30], T[30][30];
int N, M;

bool Valid(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

struct Item {
	int i, j, p, t;
	int val;
	Item(int i = 0, int j = 0, int p = 0, int val = 0) : i(i), j(j), p(p), val(val) {
		if (i < 0 || j < 0 || i >= N || j >= M) return;
		t = (val - T[i][j]) % (S[i][j] + W[i][j]);
		if (t < 0) t += S[i][j] + W[i][j];
	}
};

bool operator <(const Item &a, const Item &b) {
	return a.val > b.val;
}

set<int> Was[30][30][4];

bool IsWas(Item &x) {
	int i = x.i;
	int j = x.j;
	int t = x.t;
	int p = x.p;
	return (Was[i][j][p].count(t));
}

int GetS(int i, int j, int t) {
	if (t < S[i][j]) return 0;
	return W[i][j] + S[i][j] - t;
}

int GetW(int i, int j, int t) {
	if (t >= S[i][j]) return 0;
	
	return S[i][j] - t;
}

void Solve(int num) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> S[i][j] >> W[i][j] >> T[i][j];
			for (int k = 0; k < 4; ++k) {
				Was[i][j][k].clear();
			}
		}
	}
	priority_queue<Item> q;
	
	q.push(Item(N - 1, 0, 1, 0));

	int ans = -1;

	while (!q.empty()) {
		Item f = q.top();
		q.pop();

		if (f.i == 0 && f.j == M - 1 && f.p == 3) {
			ans = f.val;
			break;
		}

		if (IsWas(f)) continue;

		vector<Item> v;
		int i = f.i;
		int j = f.j;
		int p = f.p;

		if (f.p == 1) {
			v.pb(Item(i, j, 0, f.val + GetS(i, j, f.t) + 1));
			v.pb(Item(i, j, 2, f.val + GetW(i, j, f.t) + 1));
			v.pb(Item(i, j - 1, 2, f.val + 2));
			v.pb(Item(i + 1, j, 0, f.val + 2));
		}

		if (f.p == 2) {
			v.pb(Item(i, j, 3, f.val + GetS(i, j, f.t) + 1));
			v.pb(Item(i, j, 1, f.val + GetW(i, j, f.t) + 1));
			v.pb(Item(i, j + 1, 1, f.val + 2));
			v.pb(Item(i + 1, j, 3, f.val + 2));
		}

		if (f.p == 3) {
			v.pb(Item(i, j, 2, f.val + GetS(i, j, f.t) + 1));
			v.pb(Item(i, j, 0, f.val + GetW(i, j, f.t) + 1));
			v.pb(Item(i - 1, j, 2, f.val + 2));
			v.pb(Item(i, j + 1, 0, f.val + 2));
		}

		if (f.p == 0) {
			v.pb(Item(i, j, 1, f.val + GetS(i, j, f.t) + 1));
			v.pb(Item(i, j, 3, f.val + GetW(i, j, f.t) + 1));
			v.pb(Item(i - 1, j, 1, f.val + 2));
			v.pb(Item(i, j - 1, 3, f.val + 2));
		}

		for (int k = 0; k < sz(v); ++k) {
			if (!Valid(v[k].i, v[k].j)) continue;
			if (IsWas(v[k])) continue;
			q.push(v[k]);
		}


	}
	
	assert(ans != -1);

	printf("Case #%d: %d\n", num, ans);


}

int main() {	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i)
		Solve(i);
	return 0;
}

