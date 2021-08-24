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
    REP(sd,tt)
    {
        int c, n; scanf("%d %d", &c, &n);
        int s = 1 << c;
        vector<double> p(s, 0);
        vector<int> q;
        REP(i,s)
        {
            bitset<10> b(i);
            if (b.count() == n)
                q.push_back(i);
        }

        for (int i = s - 2; i >= 0; i--)
        {
            double pom = 0;
            double druha = 0;
            REP(j,q.size())
            {
                int r = i | q[j];
                if (r == i)
                    pom += 1.0 / q.size();
                else
                    druha += p[r] / q.size();
            }
            p[i] = (1 + druha) / (1 - pom);
        }

        printf("Case #%d: %.8lf\n", sd+1, p[0]);
    }
}
