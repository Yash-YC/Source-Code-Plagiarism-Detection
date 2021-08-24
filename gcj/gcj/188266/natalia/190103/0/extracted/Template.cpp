#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cassert>
#include <cmath>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (int i = 1; i <= int(n); i++)

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef long long ll;

#define NMAX 45

int n, c;
double p[NMAX][NMAX], d[NMAX], q[NMAX][NMAX][NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);
    cin >> c >> n;
    
    memset(q, 0, sizeof(q));
    memset(p, 0, sizeof(p));
    memset(d, 0, sizeof(d));

    forn(k, c)
    {
        q[k][0][0] = 1.0;
        forn(i, n)
        {
            forn(j, i + 1)
            {
                q[k][i + 1][j] += q[k][i][j] * double(k - i + j) / (c - i);
                q[k][i + 1][j + 1] += q[k][i][j] * double(c - k - j) / (c - i);
            }
        } 
    }

    forn(k, c)
    {
        forn(j, n + 1)
        {
            p[k][j] = q[k][n][j];
        }
        
    }
    d[c] = 0;
    for (int k = c-1; k >= 0; k--)
    {
        d[k] = 1.0;
        for1(j, c - k)
        {
            d[k] += p[k][j] * d[k + j];
        }
        d[k] /= (1.0 - p[k][0]);
    }

    printf("%.10lf\n", d[0]);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tc; scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }

    return 0;
}
