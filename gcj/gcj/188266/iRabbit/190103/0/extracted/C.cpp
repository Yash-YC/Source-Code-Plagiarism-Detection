#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

double p[100];
double dp[100];

double cr(int n, int m) {
    if (m > n) return 0.0;
    double sum = 1.0;
    int j = n - m;
    for (int i = m + 1; i <= n; i++) {
        sum = sum * i / j;
        j--;
    }
    return sum;
}

double pr(int x, int i, int c, int n) {
    int t = i + x;
    return 1.0 * cr(n - i, t - i) * cr(i, c - t + i) / cr(n, c);
}

int solve() {
    scanf("%d %d", &N, &C);
    dp[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        double sum = 1.0;
        for (int x = 1; i + x <= N; x++) {
            sum += pr(x, i, C, N) * dp[i + x];
        }
        dp[i] = sum / (1 - pr(0, i, C, N));
    }
    printf("%.7lf\n", dp[0]);
}

int main()
{
    freopen("C-test.in", "r", stdin);
    freopen("C-test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
