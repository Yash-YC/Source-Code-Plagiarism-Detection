#include <stdio.h>
#include <string>

const int MaxN = 41;

int T, C, i, j, k, l, x, y;
double tmp;
double p[MaxN][MaxN][MaxN][MaxN], d[50];

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    memset(p, 0, sizeof(p));
    for (i=1; i<MaxN; i++) for (j=0; j<=i; j++) for (k=0; k<=i; k++) for (l=0; l<=j && l<=k; l++)
    {
        tmp = 1.0;
        for (x=1; x<=l; x++) tmp = tmp * (k - x + 1.0) / (l - x + 1.0);
        for (x=1; x<=j-l; x++) tmp = tmp * (i - k - x + 1.0) / (j - l - x + 1.0);
        for (x=1; x<=j; x++) tmp = tmp * (j - x + 1.0) / (i - x + 1.0);
        p[i][j][k][l] = tmp;
    }
    scanf("%d", &T);
    for (C=1; C<=T; C++)
    {
        scanf("%d %d", &x, &y);
        d[0] = 0;
        for (i=1; i<=x; i++)
        {
            tmp = 1.0;
            for (k=1; k<=y && k<=i; k++) tmp += d[i - k] * p[x][y][i][k];
            d[i] = tmp / (1.0 - p[x][y][i][0]);
        }
        printf("Case #%d: %.8lf\n", C, d[x]);
    }
}

