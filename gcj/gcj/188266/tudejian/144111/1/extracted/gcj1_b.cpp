#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef __int64 ll;
const ll INF = ll(1) << 60;

struct Edge {
	int from, to;
	ll w;
	ll T, D, NOT;
};

Edge edge[100009];
int nEdge;
int N, M;
int src, dst;

void init() {
	nEdge = 0;
}

void link(int x, int y, ll D, ll NOT, ll T) {
	Edge *p = &edge[nEdge++];
	p->from = x;
	p->to = y;
	p->D = D;
	p->NOT = NOT;
	p->T = T;
}

ll bellmanFord(int src, int dst, int n, int m) {
	int i, j, k;
	bool ok = true;
	static ll d[100009];

	for (i = 0; i < n; ++i) d[i] = INF;
	d[src] = 0;
	while (ok) {
		ok = false;
		for (i = 0; i < m; ++i) {
			Edge *p = &edge[i];
			ll t;
			if (p->D < 0) t = d[p->from] + 2;
			else {
				ll k = (d[p->from] - p->T) % (p->D + p->NOT);
				if (k < p->D) {
					t = d[p->from] + 1;
				} else
					t = d[p->from] + (p->D + p->NOT) - k + 1;
			}
			if (t < d[p->to]) {
				d[p->to] = t;
				ok = true;
			}
		}
	}
	return d[dst];
}

struct Intersect {
	ll S, W, T;
};

Intersect inter[29][29];

ll getStart(ll T, ll L) {
	if (T <= 0) return T;
	return T - (T / L + 1) * L;
}

int main() {
	freopen("F:\\B-large.in", "r", stdin);
	freopen("F:\\B-large.out", "w", stdout);
	int T;
	int i, j, k;
	int n, m;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		init();
		for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j)
				scanf("%I64d%I64d%I64d", &inter[i][j].S, &inter[i][j].W, &inter[i][j].T);
		n = 0;
		for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j) {
				int u1, u2, v1, v2;
				u1 = (2 * i) * 2 * M + 2 * j;
				v1 = (2 * i) * 2 * M + 2 * j + 1;
				u2 = (2 * i + 1) * 2 * M + 2 * j;
				v2 = (2 * i + 1) * 2 * M + 2 * j + 1;

				link(u1, v1, inter[i][j].W, inter[i][j].S, getStart(inter[i][j].T + inter[i][j].S, inter[i][j].S + inter[i][j].W));
				link(v1, u1, inter[i][j].W, inter[i][j].S, getStart(inter[i][j].T + inter[i][j].S, inter[i][j].S + inter[i][j].W));



				link(u2, v2, inter[i][j].W, inter[i][j].S, getStart(inter[i][j].T + inter[i][j].S, inter[i][j].S + inter[i][j].W));
				link(v2, u2, inter[i][j].W, inter[i][j].S, getStart(inter[i][j].T + inter[i][j].S, inter[i][j].S + inter[i][j].W));

				link(u1, u2, inter[i][j].S, inter[i][j].W, getStart(inter[i][j].T, inter[i][j].S + inter[i][j].W));
				link(u2, u1, inter[i][j].S, inter[i][j].W, getStart(inter[i][j].T, inter[i][j].S + inter[i][j].W));

				link(v1, v2, inter[i][j].S, inter[i][j].W, getStart(inter[i][j].T, inter[i][j].S + inter[i][j].W));
				link(v2, v1, inter[i][j].S, inter[i][j].W, getStart(inter[i][j].T, inter[i][j].S + inter[i][j].W));

				int upu, upv, leftu, leftv;
				if (i > 0) {
					upu = (2 * (i - 1) + 1) * 2 * M + 2 * j;
					upv = (2 * (i - 1) + 1) * 2 * M + 2 * j + 1;
					link(upu, u1, -1, -1, -1);
					link(u1, upu, -1, -1, -1);
					link(upv, v1, -1, -1, -1);
					link(v1, upv, -1, -1, -1);
				}
				if (j > 0) {
					leftu = 2 * i * 2 * M + 2 * (j - 1) + 1;
					leftv = (2 * i + 1) * 2 * M + 2 * (j - 1) + 1;
					link(leftu, u1, -1, -1, -1);
					link(u1, leftu, -1, -1, -1);
					link(leftv, u2, -1, -1, -1);
					link(u2, leftv, -1, -1, -1);
				}
				
			}
		src = (2 * (N - 1) + 1) * 2 * M;
		dst = 2 * (M - 1) + 1;
		printf("Case #%d: %I64d\n", ++cas, bellmanFord(src, dst, (2 * N) * (2 * M), nEdge));
	}
	return 0;

}


