#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair <LL, int> PLLI;

const int MAXN = 2000;
const int MAXM = 50;
const LL INF = 9012345678901234567LL;

class Edge {
public:
	int y;
	LL S, T, TT;
	bool stop;
	
	Edge() {}
	
	Edge(int y, LL S, LL T, LL TT, bool stop) : y(y), S(S), T(T), TT(TT), stop(stop) {};
};

LL mmin[MAXN];
int N, M;
LL S, W, T;
vector <Edge> edge[MAXN];
priority_queue <PLLI> heap;

inline void addEdge(int x, int y, LL S, LL T, LL TT, bool stop) {
	edge[x].push_back(Edge(y, S, T, TT, stop));
}

inline LL calc() {
	while (!heap.empty()) heap.pop();
	int source = ((N - 1) * M << 2) | 0, sink = ((M - 1) << 2) | 3;
	mmin[source] = 0LL;
	heap.push(make_pair(0LL, source));
	while (!heap.empty()) {
		PLLI plli = heap.top();
		heap.pop();
		LL value = -plli.first;
		int ind = plli.second;
		if (mmin[ind] != value) continue;
//		printf("value = %lld ind = %d\n", value, ind);
		for (int i = (int)edge[ind].size() - 1; i >= 0; i--) {
			Edge tmpedge = edge[ind][i];
			if (tmpedge.stop) {
				LL times = (value - tmpedge.T) / tmpedge.TT;
				LL T = tmpedge.T + times * tmpedge.TT;
				if (value - T < tmpedge.S) {
					if (mmin[tmpedge.y] > value + 1LL) {
						mmin[tmpedge.y] = value + 1LL;
						heap.push(make_pair(-value - 1LL, tmpedge.y));
//						printf("ind = %d value = %lld ", ind, value);
//						printf("-> y = %d value = %lld\n", tmpedge.y, value + 1LL);
					}
				} else if (mmin[tmpedge.y] > T + tmpedge.TT + 1LL) {
					mmin[tmpedge.y] = T + tmpedge.TT + 1LL;
					heap.push(make_pair(-T - tmpedge.TT - 1LL, tmpedge.y));
//					printf("ind = %d value = %lld ", ind, value);
//					printf("-> y = %d value = %lld\n", tmpedge.y, T + tmpedge.TT + 1LL);
				}
			} else {
				if (mmin[tmpedge.y] > value + 2LL) {
					mmin[tmpedge.y] = value + 2LL;
					heap.push(make_pair(-value - 2LL, tmpedge.y));
//					printf("ind = %d value = %lld ", ind, value);
//					printf("-> y = %d value = %lld\n", tmpedge.y, value + 2LL);
				}
			}
		}
	}
	return mmin[sink];
}

int main() {
	int task;
	scanf("%d", &task);
	for (int oo = 0; oo < task; oo++) {
		scanf("%d%d", &N, &M);
		for (int i = (N * M << 2) - 1; i >= 0; i--) {
			mmin[i] = INF;
			edge[i].clear();
		}
//		puts("here1");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%lld%lld%lld", &S, &W, &T);
				LL times = T / (S + W);
				T -= (S + W) * (times + 1LL);
				int ind = (i * M + j) << 2;
//				printf("%d %d %d\n", i, j, ind);
				addEdge(ind | 0, ind | 1, W, T + S, S + W, true);
				addEdge(ind | 1, ind | 0, W, T + S, S + W, true);
				addEdge(ind | 2, ind | 3, W, T + S, S + W, true);
				addEdge(ind | 3, ind | 2, W, T + S, S + W, true);
				addEdge(ind | 0, ind | 2, S, T, S + W, true);
				addEdge(ind | 2, ind | 0, S, T, S + W, true);
				addEdge(ind | 1, ind | 3, S, T, S + W, true);
				addEdge(ind | 3, ind | 1, S, T, S + W, true);
			}
		}
//		puts("here2");
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < M; j++) {
				int ind1 = (i * M + j - 1) << 2, ind2 = (i * M + j) << 2;
				addEdge(ind1 | 3, ind2 | 2, 0, 0, 0, false);
				addEdge(ind2 | 2, ind1 | 3, 0, 0, 0, false);
				addEdge(ind1 | 1, ind2 | 0, 0, 0, 0, false);
				addEdge(ind2 | 0, ind1 | 1, 0, 0, 0, false);
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int ind1 = ((i - 1) * M + j) << 2, ind2 = (i * M + j) << 2;
				addEdge(ind1 | 3, ind2 | 1, 0, 0, 0, false);
				addEdge(ind2 | 1, ind1 | 3, 0, 0, 0, false);
				addEdge(ind1 | 2, ind2 | 0, 0, 0, 0, false);
				addEdge(ind2 | 0, ind1 | 2, 0, 0, 0, false);
			}
		}
//		puts("here");
		printf("Case #%d: %lld\n", oo + 1, calc());
	}
	return 0;
}
