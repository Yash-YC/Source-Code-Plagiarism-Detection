#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <limits>
#include <iterator>
#include <sstream>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i != _b; ++i)
#define REP(i, N) FOR(i, 0, N)
#define REPK(K) REP(_crazyName, K)

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

template<typename CType, typename VType>
inline void REMOVE(CType &container, const VType &value) {
	container.erase(remove(ALL(container), value), container.end());
}

#define sz() size()
#define len() length()
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef long long LL;

const int mn = 3;

int N, M;
int dest;
int S[mn][mn], W[mn][mn], T[mn][mn];
int best[100][1000];
const int inf = int(1e8);
int bestSoFar = inf;
bool seen[100];

int calc(VVI &graph, int pos, int tm) {
	if (pos == dest) {
		if (tm < bestSoFar)
			bestSoFar = tm;
		return 0;
	}

	seen[pos] = true;
	if (tm > bestSoFar) return inf;

	int ret = inf;
	int row = (pos - 1) / (M * 4), col = (pos - 1) / 4, nt;
	for (int i = 0; i < graph[pos].sz(); ++i) {
		if (seen[graph[pos][i]])
			continue;

		if ((graph[pos][i] - 1) / 4 == (i - 1) / 4) {
			if (graph[pos][i] % 2 == pos % 2) {
				// N-S
				int cl = S[row][col] + W[row][col];
				if (((tm - T[row][col]) + cl * 10) % cl < S[row][col])
					nt = tm;
				else
					nt = tm + cl - (((tm - T[row][col]) + cl * 10) % cl);				
			}
			else {
				// W-E
				int cl = S[row][col] + W[row][col];
				if (((tm - T[row][col]) + cl * 10) % cl < S[row][col])
					nt = tm + S[row][col] - (((tm - T[row][col]) + cl * 10) % cl);
				else
					nt = tm;
			}

			++nt;
			ret = min(ret, (nt - tm) + calc(graph, graph[pos][i], nt));
		}
		else {
			ret = min(ret, 2 + calc(graph, graph[pos][i], tm + 2));
		}
	}

	seen[pos] = false;

	return best[pos][tm] = ret;
}

int main() {
	int C;
	scanf("%d", &C);

	REP (kase, C) {
		scanf("%d %d", &N, &M);

//		VVI S(N, VI(M)), W(N, VI(M)), T(N, VI(M));
		VVI graph(M * N * 4 + 1);
		int nodes[mn][mn][4], nodeCount = 1;
		bestSoFar = inf;
		memset(seen, 0, sizeof(seen));

		REP (i, N) {
			REP (j, M) {
				scanf("%d %d %d", &S[i][j], &W[i][j], &T[i][j]);
				REP (k, 4) {
					if (nodeCount + k - 2 >= nodeCount)
						graph[nodeCount + k].pb(nodeCount + k - 2);
					else if (nodeCount + k + 2 < nodeCount + 4)
						graph[nodeCount + k].pb(nodeCount + k + 2);
					if ((nodeCount + k) % 2 == 0) {
						graph[nodeCount + k].pb(nodeCount + k - 1);
						if ((nodeCount + k + 3) < graph.sz())
							graph[nodeCount + k].pb(nodeCount + k + 3);
					}
					else {
						graph[nodeCount + k].pb(nodeCount + k + 1);
						if (nodeCount + k - 3 > 0)
							graph[nodeCount + k].pb(nodeCount + k - 3);
					}
					if ((nodeCount + k) % 4 == 3 || (nodeCount + k) % 4 == 0) {
						if (nodeCount + k + (M * 4) - 2 < graph.sz())
							graph[nodeCount + k].pb(nodeCount + k + (M * 4) - 2);
					}
					else {
						if (nodeCount + k - (M * 4) + 2 > 0)
							graph[nodeCount + k].pb(nodeCount + k - (M * 4) + 2);
					}
				}
				nodeCount += 4;
			}
		}

		memset(best, -1, sizeof(best));
		dest = M * 4 - 2;
		memset(best[dest], 0, sizeof(best[dest]));
		int ret = calc(graph, (N - 1) * M * 4 + 3, 0);
		printf("Case #%d: %d\n", (kase + 1), bestSoFar);
	}
}
