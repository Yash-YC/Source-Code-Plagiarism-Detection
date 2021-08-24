#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long lint;

lint C(lint m, lint n) {
    lint s = 1;
    for(int i=1; i<=m; ++i)
        s = s*(n-i+1) / i;
    return s;
}

double p[10010][100], ans;

int n, c;

int main() {
    int z, ca=0;
    freopen("c.txt", "w", stdout);
    scanf("%d", &z);
    while(z--) {
        scanf("%d%d", &c, &n);
        memset(p, 0, sizeof(p));
        p[1][n] = 1;
        ans = 0;
        for(int i=1; i<10000; ++i) {
            for(int j=n; j<=c; ++j) {
                if(j == c) {
                    ans += i * p[i][c];
                    continue;
                }
                for(int k=0; k<=n && j+k <= c; ++k) {
                    p[i+1][j+k] += p[i][j] * C(n-k, j) * C(k, c-j) / C(n, c);
                }
            }
        }
        printf("Case #%d: %.10lf\n", ++ca, ans);
    }
    return 0;
}
