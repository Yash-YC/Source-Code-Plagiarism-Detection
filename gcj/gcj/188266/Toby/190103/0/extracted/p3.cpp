#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int T;

double p[50];
double trans[50][50];

double choose(int n, int k) {
    double ans = 1;
    if (k > n/2) k = n - k;
    for (int i = 0; i < k; i++) {
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}

void solve(int C, int N) {
    memset(p, 0, sizeof(p));
    memset(trans, 0, sizeof(trans));
    p[N] = 1;

    if (C == N) {
        printf("%.7lf\n", 1.);
        return;
    }
    for (int i = N; i < C; i++) {
        double stop = choose(i, N);
        double all = choose(C, N);
        trans[i][0] = stop / all;
        for (int j = 1; j <= N; j++) {
            if (i + j > C) break;
            double move = choose(C-i, j) * choose(i, N-j);
            trans[i][j] = move / all;
        }
    }

    int t = 2;
    double ans = 0;
    while (1) {
        p[C] = 0;
        for (int i = C; i >= N; i--) {
            p[i] *= trans[i][0];
            for (int j = 1; j <= N; j++) {
                p[i] += p[i-j] * trans[i-j][j];
            }
        }
        
        ans += t * p[C];
        if (ans > 0 && t * p[C] < 1e-7) break;
//printf("%d %.7lf\n", t, ans);
        t++;
    }
    printf("%.7lf\n", ans);
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int C, N;
        printf("Case #%d: ", i+1);
        scanf("%d %d", &C, &N);
        solve(C, N);
    }

    return 0;
}
