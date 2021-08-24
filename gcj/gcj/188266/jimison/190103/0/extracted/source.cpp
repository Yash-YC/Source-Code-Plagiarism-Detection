#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int xx[1 << 10];
int xn;
double pp[1 << 10][11];
bool visit[1 << 10][11];
int C, N;
int n;
int num(int x)
{
    int r = 0;
    while (x) {
        r += (x & 1);
        x >>= 1;
    }
    return r;
}
void gen()
{
    xn = 0;
    for (int i = 0; i < (1 << C); ++i) {
        int t = num(i);
        if (t == N) {
            xx[xn++] = i;
        }
    }
}
int cmn(int m, int n)
{
    if (n == 0 || n == m) return 1;
    long long r = 1;
    for (int i = 0; i < n; ++i)
        r *= (m - i);
    while (n > 1) {
        r /= n;
        n--;
    }
    return r;
}
double dfs(int x, int c)
{
    if (c <= 0) return 0;
    if (visit[x][c]) return pp[x][c];
    double ans = n;
    int q = 0;
    for (int i = 0; i < xn; ++i) {
        int k = 0;
        for (int j = 0; j < C; ++j)
            if ((xx[i] & (1 << j)) && !(x & (1 << j))) k++;
        if (k == 0) {
            q++;
            continue;
        }
        ans += dfs(xx[i] | x, c - k);
    }
    ans /= (n - q);
    visit[x][c] = true;
    return pp[x][c] = ans;
}
int main()
{
    //freopen("C-small-attempt1.in", "r", stdin);
    //freopen("C-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        scanf("%d%d", &C, &N);
        n = cmn(C, N);
        gen();
        memset(visit, false, sizeof(visit));
        double s = dfs(0, C);
        printf("Case #%d: %.7lf\n", k, s);
    }
    return 0;
}
