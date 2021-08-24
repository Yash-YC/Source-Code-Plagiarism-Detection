#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <utility>

using namespace std;

#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define inf (1<<30)
#define PB push_back
#define mset(x,a) memset(x,(a),sizeof(x))
typedef long long LL;
#define twoL(X) (((LL)(1))<<(X))
const double PI = acos(-1.0);
const double eps = 1e-8;

template <class T> T sqr(T x)
{
    return x*x;
}

template <class T> T gcd(T a, T b)
{
    if(a < 0) return (gcd(-a, b));
    if(b < 0) return (gcd(a, -b));
    return (b == 0) ? a : gcd(b, a % b);
}

#define FOREACH(it, a) for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
#define ALL(x) (x).begin(), (x).end()

int work(string c)
{
    int res = 0;
    for(int i = 0; i < c.size(); i++)
    {
        res += (c[i] - '0')*(c[i] - '0');
    }
    return res;
}

string tobase(int c, int base)
{
    string res;
    while(c)
    {
        res += (c % base) + '0';
        c /= base;
    }
    reverse(ALL(res));
    return res;
}

bool check(int c, int base)
{
    string str = tobase(c, base);
    map < string, bool > m;
    while(str != "1" && !m[str])
    {
        m[str] = 1;
        int tmp = work(str);
        str = tobase(tmp, base);
    }
    if(str == "1") return 1;
	else return 0;
}

int main(int argc, char** argv)
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
	string str;
	getline(cin,str);
    for(int ti = 0; ti < t; ti++)
    {
        vector < int > v;
        getline(cin, str);
        istringstream istr(str);
        int num;
        while(istr >> num) v.PB(num);
        int cur = 2;
        while(1)
        {
            bool b = 1;
            for(int i = 0; i < v.size(); i++)
            {
                if(!check(cur, v[i])) b = 0;
            }
            if(b) break;
			cur++;
        }
        printf("Case #%d: %d\n", ti+1, cur);
    }
    return (EXIT_SUCCESS);
}

