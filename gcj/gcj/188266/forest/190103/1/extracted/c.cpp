#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <set>
#include <queue>
#include <sstream>
#include <list>
#include <map>
#include <cmath>

#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FIR(k) FOR(i,0,k)
#define FJR(k) FOR(j,0,k)
#define FI FIR(n)
#define FJ FJR(n)
#define ALL(v) v.begin(), v.end()
#define LL long long

typedef vector<int> VI;
typedef pair<int, int> PI;

long double q[50][50];
void f(int have, int n, int c) {
	memset(q, 0, sizeof q);
	q[0][0]= 1;
	FORE(s, 1, n) {
		FOR(h, 0, have) {
			double same =  (double)(have-h)/(c+1-s);

			q[s][h] += q[s-1][h]*(1-same);
			q[s][h+1] += q[s-1][h]*same;
		}
	}
}

long double tr[50][50];
long double res[50];

int main() {
freopen("C-large.in", "rt", stdin);
freopen("C-large.out", "w", stdout);	

	int cases; cin >> cases;

	FOR(tc, 0, cases) {
		memset(tr, 0, sizeof tr);
		int n, c; cin >> c >> n;
		tr[0][n] = 1;

		FORE(i, n, c) {
			f(i, n, c);
			FORE(same, 0, n) tr[i][i+n-same] = q[n][same];
		}

		res[c] = 0;
		FORD(w, c-1, 0) {
			long double sum = 1;
			FORE(i, w+1, c) sum += res[i]*tr[w][i];
			res[w] = sum / (1-tr[w][w]);
		}

		printf("Case #%d: %.7lf\n", tc+1, (double)res[0]);
	}
}
