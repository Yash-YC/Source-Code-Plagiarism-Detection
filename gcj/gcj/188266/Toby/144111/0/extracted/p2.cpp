#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int C;
int N, M;
int S[30][30], W[30][30], T[30][30];
int d[100][100];
bool visit[100][100];

int dist(int x, int y, int dx, int dy, int time) {
    int s = S[x/2][y/2];
    int w = W[x/2][y/2];
    int t = T[x/2][y/2];
    int p = time - t;
    while (p < 0) p += s + w;
    p %= s + w;
    if (dx != 0) {
        if (((x & 1) == 0) == (dx > 0)) {
            if (p < s)
                return 1;
            else
                return s + w - p + 1;
        } else {
            return 2;
        }
    } else {
        if (((y & 1) == 0) == (dy > 0)) {
            if (p >= s)
                return 1;
            else
                return s - p + 1;
        } else {
            return 2;
        }
    }
}

void solve() {
    memset(d, -1, sizeof(d));
    memset(visit, 0, sizeof(visit));
    d[N*2-1][0] = 0;

    while (1) {
        int minx, miny;
        int mind = 20*10000*10000;
        for (int i = 0; i < N*2; i++) {
            for (int j = 0; j < M*2; j++) {
                if (visit[i][j]) continue;
                if (d[i][j] >= 0 && d[i][j] < mind) {
                    mind = d[i][j];
                    minx = i;
                    miny = j;
                }
            }
        }

        if (minx == 0 && miny == M*2-1) break;

        visit[minx][miny] = 1;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx + dy != 1 && dx + dy != -1) continue;
                if (minx + dx < 0 || minx + dx >= N*2) continue;
                if (miny + dy < 0 || miny + dy >= M*2) continue;
                int delta = dist(minx, miny, dx, dy, d[minx][miny]);
                if (d[minx+dx][miny+dy] < 0 || d[minx+dx][miny+dy] > d[minx][miny] + delta) {
                    d[minx+dx][miny+dy] = d[minx][miny] + delta;
                }
            }
        }
    }

    printf("%d\n", d[0][M*2-1]);
    /*
    for (int i = 0; i < N*2; i++) {
        for (int j = 0; j < M*2; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    */
}

int main() {
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        printf("Case #%d: ", i+1);
        scanf("%d %d", &N, &M);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                scanf("%d %d %d", &S[j][k], &W[j][k], &T[j][k]);
            }
        }
        solve();
    }

    return 0;
}
