#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <cassert>

using namespace std;

inline void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("test.out", "wt", stdout);
#endif
}


void solve();

int main() {
	openFiles();
	int t; scanf("%d\n", &t);
	while (t--)	solve();
	return 0;
}


double dp[1100][50];
int calc[1100][50];
int k, n;
double cnkm[50][50];

double cnk(int k, int n) {
	if (k == n || k == 0) return 1;
	if (k > n || k < 0 || n < 0) return 0;
	if (cnkm[n][k] == 0) {
		cnkm[n][k] = cnk(k-1, n-1) + cnk(k, n-1);
	}
	return cnkm[n][k];
}

double prob(int h, int g) {
	int left = n - h;
	if (left < 0) return 0;
	double val = cnk(g, left) / cnk(k, n) * cnk(k - g, h);
	if (val <= 0)
		return 0;
	return val;
}

double f(int x, int h) {
	if (x == 0 && h == 0)
		return 1;
	if (x <= 0 || h < 0)
		return 0;
	if (!calc[x][h]) {
		double ret = 0;
		for (int i = 0; i <= k; ++i) {
			ret += f(x - 1, h - i) * prob(h - i, i);
		}
		dp[x][h] = ret;
		calc[x][h] = true;
	}
	return dp[x][h];
}

void solve() {
	const double EPS = 1e-12;
	memset(calc, 0, sizeof(calc));
	memset(dp, 0, sizeof(dp));
	scanf("%d %d\n", &n, &k);
	double ret = 0;
	for (int i = 1; i < 1000; ++i) {
		double prob = f(i, n) - f(i - 1, n);
		ret += prob * i;
	}
	static int ntest = 0;
	printf("Case #%d: %.7lf\n", ++ntest, ret);
}
