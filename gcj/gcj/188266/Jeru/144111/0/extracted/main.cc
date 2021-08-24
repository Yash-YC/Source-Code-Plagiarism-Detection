#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

const int INF = 0x7fffffff;

struct Light {
    int S, W, T;

    void read() {
        cin >> S >> W >> T;
        T %= (S + W);
    }

    int NextNS(int t) const {
        int tt = ((t - T) % (S + W) + S + W) % (S + W);
        if (tt < S) return t;
        return t + (S + W - tt);
    }

    int NextWE(int t) const {
        int tt = ((t - T - S) % (S + W) + S + W) % (S + W);
        if (tt < W) return t;
        return t + (S + W - tt);
    }
} lt[20][20];
int R, C, N, dist[40 * 40];
bool mark[40 * 40];

void update(int x, int y, int v) {
    int p = x * C + y;
    if (!mark[p] && v < dist[p])
        dist[p] = v;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    }
    int cc = 0, ccc = 0;
    for (cin >> ccc; cc < ccc; ++cc) {
        cin >> R >> C;
        for (int i = R - 1; i >= 0; --i)
            for (int j = 0; j < C; ++j)
                lt[i][j].read();
        R *= 2;
        C *= 2;
        N = R * C;
        fill(dist, dist + N, INF);
        fill(mark, mark + N, false);
        dist[0] = 0;
        for (;;) {
            int best = INF, bx = -1, by = -1;
            for (int i = 0; i < N; ++i)
                if (!mark[i] && dist[i] < best) {
                    best = dist[i];
                    bx = i / C;
                    by = i % C;
                }
            if (bx == -1) break;
            mark[bx * C + by] = true;

            Light& lt = ::lt[bx / 2][by / 2];
            int nx = bx + 2 * (bx & 1) - 1, ny = by + 2 * (by & 1) - 1;

            update(bx ^ 1, by, lt.NextNS(best) + 1);
            update(bx, by ^ 1, lt.NextWE(best) + 1);
            if (nx >= 0 && nx < R) update(nx, by, best + 2);
            if (ny >= 0 && ny < C) update(bx, ny, best + 2);
        }
        printf("Case #%d: %d\n", cc + 1, dist[N - 1]);
    }
    return 0;
}
