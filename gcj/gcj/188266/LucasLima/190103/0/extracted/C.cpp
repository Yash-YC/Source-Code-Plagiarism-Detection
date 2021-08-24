#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

template <class A, class B> void CONV(A& x, B& y) { stringstream s; s << x; s >> y; }
typedef long long LL;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORE(i, v) FOR(i, 0, v.size())
#define FORU(i, a) for (int i = a; ; ++i)
#define SORT(v) sort(v.begin(), v.end())
#define SET(a, n) memset(a, n, sizeof a)

double comb[41][41], total, dp[40][41];
int n;
bool vis[40][41];

double go(int rem, int chosen) {
	if (rem == 0) return 0;
	if (vis[rem][n]) return dp[rem][n];
	vis[rem][n] = true;
	double p0 = comb[chosen][n]/total;
	int bound = min(n, rem);
/*
	double res = 0;
	FOR(i, 1, bound+1) {
		double prob = (double)(comb[rem][i]*comb[chosen][n-i])/total;
		res += prob*(1+go(rem-i, chosen+i));
	}
	res += p0;
	res /= 1-p0;
*/
	double res = 0;
	FOR(i, 1, bound+1) res += comb[rem][i]*comb[chosen][n-i]*(1.+go(rem-i, chosen+i));
	res /= total;
	res += p0;
	res /= 1.-p0;
	return dp[rem][n] = res;
}

int main() {
	comb[0][0] = 1;
	FOR(i, 1, 41) {
		comb[i][0] = 1;
		FOR(j, 1, 41) comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
  	}
  	int t;
	cin >> t;
	SET(vis, false);
	FOR(i, 0, t) {
		int c;
		cin >> c >> n;
		total = comb[c][n];
		//cout << "Case #" << i+1 << ": " << fixed << setprecision(7) << (double)1.+go(c-n, n) << endl;
		cout << "Case #" << i+1 << ": ";
		printf("%.7f\n", 1.+go(c-n, n));
	}
}
