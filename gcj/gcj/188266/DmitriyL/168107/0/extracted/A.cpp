#pragma comment(linker, "/STACK:1000000000")

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <utility>
#include <memory>
#include <cstdlib>
#include <cctype>
#include <queue>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define forn1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define forv(i, v) forn(i, v.size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define two(n) (1 << (n))
#define has(mask, i) ((((mask) & two(i)) != 0) ? true : false)

typedef long long int64;

const double EPS = 1e-8;
const double PI = 3.1415926535897932384626433832795;
const int INF = 1000000000;

inline vector<int> toBase(int x, int base)
{
    if (x == 0)
        return vector<int>(1, 0);
    vector<int> result;
    while (x > 0)
    {
        result.pb(x % base);
        x /= base;
    }
    return result;
}

inline bool ok(int x, int base)
{
    set<int> s;
    s.insert(x);

    while (true)
    {
        vector<int> a = toBase(x, base);
        int t = 0;
        forv(i, a)
            t += sqr(a[i]);
        if (t == 1)
            return true;

        if (s.count(t) == 0)
		{
            x = t;
			s.insert(x);
		}
        else
            break;
    }

    return false;
}

int getAns(const vector<int>& bases)
{
    for (int i = 2; ; ++i)
    {
		if (i == 143)
		{
			int t = 9875;
		}
        bool flag = true;

        forv(j, bases)
            if (!ok(i, bases[j]))
            {
                flag = false;
                break;
            }

        if (flag)
            return i;
    }
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int tests;
    scanf("%d\n", &tests);

    forn(test, tests)
    {
        string s;
        getline(cin, s);
        vector<int> bases;
		stringstream ss(s);
        while (true)
        {
            int x;
            ss >> x;
            if (ss.fail())
                break;
            bases.pb(x);
        }
        printf("Case #%d: %d\n", test + 1, getAns(bases));
    }

    return 0;
}
