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
map<int, bool> hap;
int nove(int a, int b)
{
    int res = 0;
    while (a > 0)
    {
        int r = a % b;
        res += r * r;
        a /= b;
    }
    return res;
}
bool happy(int a, int b, set<int> &uz)
{
    if (uz.count(a))
        return false;
    if (a == 1)
        return true;
    int o = (a << 4) + b;
    if (hap.count(o))
        return hap[o];
    uz.insert(a);
    hap[o] = happy(nove(a, b), b, uz);
}
int main() {
    int tt; scanf("%d", &tt);
    string s;
    getline(cin, s);
    REP(sd,tt)
    {
        getline(cin, s);
        stringstream w(s);
        int x; vector<int> a;
        while (w >> x)
            a.push_back(x);

        x = 2;
        while (true)
        {
            bool ok = true;
            REP(i,a.size())
            {
                set<int> uz;
                if (!happy(x, a[i], uz))
                {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
            x++;
        }

        printf("Case #%d: %d\n", sd+1, x);
    }
}
