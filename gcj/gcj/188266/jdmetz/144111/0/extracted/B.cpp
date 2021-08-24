#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}

int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}

vector<int> readVI() {
	int n;
	scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}

long long solveIt(const vector<vector<int> > &S, const vector<vector<int> > &W, const vector<vector<int> > &T) {
	int N = S.size(), M = S[0].size();
	vector<vector<long long> > mt(N*2+2, vector<long long>(M*2+2, 1000000000000000000ll));
	for (int i = 0; i < N*2+1; i++) mt[i][0] = mt[i][M*2+1] = 0;
	for (int i = 0; i < M*2+1; i++) mt[0][i] = mt[N*2+1][i] = 0;
	priority_queue<pair<long long, int> > pq;
	pq.push(make_pair(0, N*2*256+1));
	mt[N*2][1] = 0;
	while (!pq.empty()) {
		long long t = pq.top().first;
		int xy = pq.top().second, y = xy/256, x = xy%256;
		pq.pop();
		if (t != mt[y][x]) continue;
//printf("At %d, %d (%lld)\n", y, x, t);

		int iy = (y-1)/2, ix = (x-1)/2;
		int sT = T[iy][ix]%(S[iy][ix]+W[iy][ix]);
		int cyct = t < sT ? S[iy][ix]+W[iy][ix]-sT+t : (t-sT)%(S[iy][ix]+W[iy][ix]);
//		int cyct = (t-T[iy][ix]+1000000000)%(S[iy][ix]+W[iy][ix]);
		int wns = cyct < S[iy][ix] ? 0 : S[iy][ix]+W[iy][ix] - cyct;
		int wew = cyct >= S[iy][ix] ? 0 : S[iy][ix] - cyct;
//printf("At %d, %d -> cyct %d, wns %d, wew %d\n", x, y, cyct, wns, wew);

		if (y&1) {
			if (mt[y-1][x] > t+2) {
				mt[y-1][x] = t+2;
//printf("%d %d -> %d %d (%lld -> %lld)\n", y, x, y-1, x, mt[y-1][x], t+2);
				pq.push(make_pair(t+2, (y-1)*256+x));
			}
			if (mt[y+1][x] > t+1+wns) {
//printf("%d %d -> %d %d (%lld -> %lld)\n", y, x, y+1, x, mt[y+1][x], t+1+wns);
				mt[y+1][x] = t+1+wns;
				pq.push(make_pair(t+1+wns, (y+1)*256+x));
			}
		} else {
			if (mt[y-1][x] > t+1+wns) {
//printf("%d %d -> %d %d (%lld -> %lld)\n", y, x, y-1, x, mt[y-1][x], t+1+wns);
				mt[y-1][x] = t+1+wns;
				pq.push(make_pair(t+1+wns, (y-1)*256+x));
			}
			if (mt[y+1][x] > t+2) {
//printf("%d %d -> %d %d (%lld -> %lld)\n", y, x, y+1, x, mt[y+1][x], t+2);
				mt[y+1][x] = t+2;
				pq.push(make_pair(t+2, (y+1)*256+x));
			}
		}
		if (x&1) {
			if (mt[y][x-1] > t+2) {
				mt[y][x-1] = t+2;
				pq.push(make_pair(t+2, y*256+x-1));
			}
			if (mt[y][x+1] > t+1+wew) {
				mt[y][x+1] = t+1+wew;
				pq.push(make_pair(t+1+wew, (y)*256+x+1));
			}
		} else {
			if (mt[y][x-1] > t+1+wew) {
				mt[y][x-1] = t+1+wew;
				pq.push(make_pair(t+1+wew, (y)*256+x-1));
			}
			if (mt[y][x+1] > t+2) {
				mt[y][x+1] = t+2;
				pq.push(make_pair(t+2, (y)*256+x+1));
			}
		}
	}
//	for (int y = 1; y <= N*2; y++) {
//		for (int x = 1; x <= M*2; x++) printf("%5lld ", mt[y][x]);
//		printf("\n");
//	}
	return mt[1][M*2];
}

int main(int argc, char ** /*argv*/) {
	dbg = argc;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int N, M;
		scanf("%d %d", &N, &M);
		vector<vector<int> > S(N, vector<int>(M)), W = S, T = S;
		for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
			scanf("%d %d %d", &S[y][x], &W[y][x], &T[y][x]);

		long long res = solveIt(S, W, T);
		printf("Case #%d: %lld\n", cn, res);
	}
	return 0;
}

