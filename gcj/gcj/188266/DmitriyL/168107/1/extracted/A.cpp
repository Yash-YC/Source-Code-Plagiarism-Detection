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
#include <fstream>

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

vector<int> mem[12001000];

bool used[12];

int getAns(const vector<int>& bases)
{
    for (int i = 2; i <= 12000000; ++i)
    {        
        memset(used, 0, sizeof(used));
        forv(j, mem[i])
            used[mem[i][j]] = true;
        bool flag = true;
        forv(j, bases)
            if (!used[bases[j]])
            {
                flag = false;
                break;
            }
        if (flag)
            return i;
    }

    return -1;
}

inline vector<int> parse(string s)
{
    vector<int> result;

    for (int i = 0; i < (int)s.length(); i += 2)
    {
        if (s[i] == '1')
        {
            result.pb(10);
            break;
        }

        if (!isdigit(s[i]))
            break;

        result.pb(s[i] - '0');
    }

    return result;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ifstream in("base.txt");
    for (int i = 2; i <= 12000000; ++i)
    {
        string s;
        getline(in, s);
        vector<int> t = parse(s);
        mem[i] = t;
    }

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
        sort(all(bases));
        printf("Case #%d: %d\n", test + 1, getAns(bases));
    }

    return 0;
}
