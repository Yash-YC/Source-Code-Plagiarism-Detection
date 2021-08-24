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

#define NMAX 11
#define MMAX 5000
#define MASK (1 << 9)

int n;
int b[NMAX];
bool happy[NMAX][MMAX];
int next[NMAX][MMAX];
int ans[MASK];


bool hap(int n, int b)
{
    if (n < MMAX) return happy[b][n];
        int m = n;
        int x;
        int sum = 0;
        while (m > 0)
        {
            x = m % b;
            m /= b;
            x *= x;
            sum += x;   
        }
    return happy[b][sum];
}
int calcMask(int mask)
{
    for (int i = 2; ; i++)
    {
        bool f = true;
        forn(j, n)
        {
            if (!hap(i, b[j])) 
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            return i;
        }
    }
}

void calc(int n, int b)
{
    if (next[b][n] != 0) return;

        int m = n;
        int x;
        int sum = 0;
        while (m > 0)
        {
            x = m % b;
            m /= b;
            x *= x;
            sum += x;   
        }
        next[b][n] = sum;
    
    calc(next[b][n], b);
    happy[b][n] = happy[b][next[b][n]];
   
}

void solve(int test)
{
    printf("Case #%d: ", test);

    string s;
    getline(cin, s);
    istringstream sin(s);

    n = 0;
    while (sin >> b[n])
    {
        if (b[n] == 0) break;
        n++;
    } 

    int mask= 0;
    forn(i, n)
    {
        mask |= (1 << (b[i]-2));
    }

    printf("%d\n", ans[mask]);
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    for (int b = 2; b <= 10; b++)
    {
        happy[b][1] = true;
        next[b][1] = 1;
        for (int i = 2; i < MMAX; i++)
        {
            calc(i, b);
  //          if (happy[b][i]) printf("%d ", i);                    
        }
    //    printf("\n");
    }

    forn(mask, (1 << 9))
    {
        n = 0;
        forn(i, 9)
        {
            if (mask & (1 << i))
            {
                b[n] = i + 2;
                n++;
            }
        }
        ans[mask] = calcMask(mask);
    }
    int tc; scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }

    return 0;
}
