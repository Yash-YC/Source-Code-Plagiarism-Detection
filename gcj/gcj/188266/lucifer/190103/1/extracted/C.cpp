#include <stdio.h>
#include <cstring>
#include <cmath>

double C[50][50];

int c, n;

double f[50];

void get_c()
{
    memset(C, 0, sizeof C);
    for(int i=0; i<=40; ++i) C[i][0] = C[i][i] = 1;

    for(int i=1; i<=40; ++i)
    {
        for(int j=1; j<i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

void solve(int tc)
{
    f[0] = 0;
    
    for(int i=1; i<=c; ++i)
    {
        double tmp = 1.0;

        for(int j=1; j<=i && j<=n; ++j)
        {
            tmp += f[i-j] * C[i][j] * C[c-i][n-j] / C[c][n];
        }

        f[i] = tmp * 1.0 / (1.0 - (C[c-i][n] * 1.0 / C[c][n]));
    }

    printf("Case #%d: %.9lf\n", tc, f[c]);
}

int main()
{

    get_c();
    
    int t, tc = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &c, &n);
        solve(++tc);
    }
    return 0;
}

