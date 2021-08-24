#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define sz(v) int((v).size())
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define mp(q, p) make_pair(q, p)
#define sqr(a) ((a) * (a))
#define pb push_back
#define ensure(a) assert(a)

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1E9 + 7;
const int NMAX = 1E3 + 7;
const ld EPS = 1E-9;

int z[20][100000];

bool happy(int a, int base){
    bool good = true;
    set<int> s;
    int idx = 0;
    while(true){
        idx++;
        if(a == 1) break;
        if(z[base][a] != -1){
            good = z[base][a];
            break;
        }
        if(s.count(a) || idx > 5000){
            good = false;
            break;
        }
        s.insert(a);
        int tmp = a, sum = 0;
        while(tmp > 0){
            sum += sqr(tmp % base);
            tmp /= base;
        }
        a = sum;
    }
    for(set<int>::iterator i = s.begin(); i != s.end(); ++i)
        z[base][(*i)] = good;
    return z[base][a];
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    memset(z, -1, sizeof(z));
    int test_case;
    scanf("%d\n", &test_case);
    string s;
    int h = 0;
    while(getline(cin, s)){
        h++;
        stringstream sin;
        sin << s;
        vector<int> v;
        for(int cur = -1; sin >> cur; v.pb(cur));
        fore(ans, 2, 100000){
            bool good = true;
            forn(i, sz(v)){
                if(!happy(ans, v[i])){
                    good = false;
                    break;
                }
            }
            if(good){
                printf("Case #%d: %d\n", h, ans);
                break;
            }
        }
    }
    return 0;
}
