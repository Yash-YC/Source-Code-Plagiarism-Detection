#include <cstdio>
#include <set>

using namespace std;

long long cmb[50][50];
int c, n;
double cover[10010][50];

void solve();

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cmb[0][0] = 1;
    for (int i = 1; i <= 40; ++i) {
        cmb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            cmb[i][j] = cmb[i - 1][j] + cmb[i - 1][j - 1];
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

void solve() {
    scanf("%d%d", &c, &n);
    if (n >= c) {
        printf("%.7lf\n", 1.0);
        return;
    }
    double ans = 0, sum = 0;
    memset(cover, 0, sizeof(cover));
    cover[1][n] = 1.0 / cmb[c][n];
    for (int i = 2; i <= 10000; ++i) {
        for (int j = n; j <= c; ++j) {
            cover[i][j] = j == c ? 0 : cover[i - 1][j] * 1.0 * cmb[j][n] / cmb[c][n];
            for (int k = 1; k <= n; ++k)
                cover[i][j] += cover[i - 1][j - k] * (1.0 * cmb[j][n - k] / cmb[c][n]);
        }
        ans += i * cover[i][c];
        sum += cover[i][c];
    }
    //printf("%.7lf %.7lf\n", sum, ans);
    printf("%.7lf\n", ans / sum);
}
