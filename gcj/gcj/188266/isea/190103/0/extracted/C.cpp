#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-10;
typedef long long int64;

double dp[100000][42];
int Case = 1, N, C;

int sgn(double x)
{
    return (x > eps) - (x < -eps);
}

double com(int x, int y)
{
    if (y == 0)
        return 1.0;
        
    if (y > x - y)
        y = x - y;
        
    double res = 1;
    for (int i = 1; i <= y; ++i) 
        res *= (double)(x - y + i) / i;
    
    return res;
}

void solve()
{
    if (N == C) {
        printf ("Case #%d: 1.0000000\n", Case++);
        return ;
    }
    
    dp[1][N] = 1.0;
    double ans = 0.0;
    double p = pow(1.0 / C, 1.0 * N);
    
    for (int i = 2; ; ++i) {
        for (int j = N; j <= C; ++j) {
            dp[i][j] = 0;
            int l = max(N, j - N);
            int r = min(C - 1, j);
            for (int k = l; k <= r; ++k) {         //from dp[i - 1][k] to dp[i][j];
                int t = k + N - j;
                dp[i][j] += com(N, t) * com(k, t) * p * dp[i - 1][k];
            }
        }
        ans += i * dp[i][C];
        if (i * N >= C && sgn(dp[i][C]) == 0)
            break;
    }
    printf ("Case #%d: %.7lf\n", Case++, ans);
}

int main()
{
    int t;
    freopen ("C-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &C, &N);
        solve();
    }
    
    return 0;
}
