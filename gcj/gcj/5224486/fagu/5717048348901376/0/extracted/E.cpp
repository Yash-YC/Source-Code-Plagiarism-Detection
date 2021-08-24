#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}

int N, M;
int h[100][8];

void docase() {
	scanf("%d%d", &N, &M);
	REP(i,0,N) REP(j,0,M)
		scanf("%d", &h[i][j]);
	int res = 0;
	if (M == 1) {
		REP(i,0,N)
			if (h[i][0] > 0)
				res += h[i][0];
	} else {
		REP(run,0,2) {
			int q = 0;
			int w = 0;
			REP(i,0,N) {
				if (h[i][0] >= 0 && h[i][1] >= 0) {
					q += h[i][0]+h[i][1];
				} else if (h[i][0] <= 0 && h[i][1] <= 0) {
				} else if (h[i][0] >= 0) {
					w += h[i][0];
				} else {
				}
			}
			REP(i,0,N) {
				if (h[i][0] >= 0 && h[i][1] >= 0) {
				} else if (h[i][0] <= 0 && h[i][1] <= 0) {
				} else if (h[i][0] >= 0) {
				} else {
					w += h[i][0];
					q += h[i][1];
				}
			}
			fprintf(stderr, "q=%d,w=%d\n", q, w);
			if (w > 0)
				q += w;
			setmax(res, q);
			REP(i,0,N)
				swap(h[i][0], h[i][1]);
		}
	}
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
