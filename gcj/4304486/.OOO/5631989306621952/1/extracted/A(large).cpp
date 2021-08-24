#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a; i <=b ; i++)
#define FO(i,a,b) for (int i=a; i < b ; i++)
#define FORD(i,a,b) for (int i=a; i >=b ; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define SET(arr,c) memset(arr,c,sizeof(arr))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define PI 2 * acos(0.0)
#define debug cout << "#PASS" << endl;
using namespace std;

template <class T> int getbit(int i, T X) { return (X & (1<<(i-1))); }
template <class T> T onbit(int i, T X) { return (X | (1<<(i-1))); }
template <class T> T offbit(int i, T X) { return (X | (1<<(i-1)) - (1<<(i-1))); }
template <class T> T sqr(T x) { return (x*x); }
template <class T> T cube (T x) { return (x*x*x); }
template <class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int csx[4]={0,0,-1,1};
int csy[4]={-1,1,0,0};

typedef pair <int, int> II;
const int MOD = 1000000007;
const int inf = 1e9;
const ll linf = 1e18;
const int maxn = 2e5 + 5;

/******VAR******/
int test;
string s;
/***************/

int main() {
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        cin >> s;
        string ans = "";
        int sz = s.size();
        ans += s[0];
        FO(i, 1, sz) if (s[i] >= ans[0]) ans = s[i] + ans; else ans = ans + s[i];
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}

