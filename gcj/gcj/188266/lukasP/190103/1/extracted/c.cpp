#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); ++i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> PI;
template <class T> void zlepsi(T &a, T b)
{
    a = max(a, b);
}
int main() {
    int tt; scanf("%d", &tt);
    double k[55][55];
    REP(i,50)
    {
        k[i][0] = 1;
        k[i][i + 1] = 0;
        FOR(j,1,i+1)
            k[i][j] = k[i - 1][j] + k[i - 1][j - 1];
    }

    REP(sd,tt)
    {
        int c, n; scanf("%d %d", &c, &n);
        vector<double> p(c + 1, 0);

        for (int i = c - 1; i >= 0; i--)
        {
            double sp = k[c][n];
            double pom = k[i][n] / sp;
            double druha = 0;

            FOR(j,1,n + 1) if (i + j <= c)
                druha += k[c - i][j] * k[i][n - j] * p[i + j] / sp;
            p[i] = (1 + druha) / (1 - pom);
        }

        printf("Case #%d: %.8lf\n", sd+1, p[0]);
    }
}
