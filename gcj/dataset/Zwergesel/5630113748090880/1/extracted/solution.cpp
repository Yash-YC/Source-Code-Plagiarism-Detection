#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

int h[2501];

void solve()
{
	fill_n(h, 2501, 0);
	int n;
	cin >> n;
	FOR(i,2*n-1) {
		FOR(j,n) {
			int x;
			cin >> x;
			++h[x];
		}
	}
	FOR(i,2501) {
		if (h[i] % 2 == 1) cout << ' ' << i;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ":";
		solve();
		cout << "\n";
	}
	return 0;
}
