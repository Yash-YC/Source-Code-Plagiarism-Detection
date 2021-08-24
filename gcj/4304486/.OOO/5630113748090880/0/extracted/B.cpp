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
const int maxn = 55;

/******VAR******/
int n, m[maxn + 5][maxn + 5], a[maxn + 5][maxn + 5], dd[2 * maxn + 5];
/***************/

II find_id(int id) {
    int ans = 3000;
    vector <int> v;
    FOR(i, 1, 2 * n - 1) if (dd[i] == 0) {
        if (a[i][id] < ans) ans = a[i][id];
    }
    FOR(i, 1, 2 * n - 1) if (a[i][id] == ans) v.pb(i);
    if (v.size() < 2) {
            //cout << "v0 = " << v[0] << endl;
            dd[v[0]] = 1;
            return mp(-1, v[0]);
    }
    //cout << "V = " << v[0] << " " << v[1] << endl;
    dd[v[0]] = 1;
    dd[v[1]] = 1;
    return mp(v[0], v[1]);
}

bool insert_row(int id, int pos) {
    FOR(i, 1, pos - 1) if ((m[pos][i] != -1) && (m[pos][i] != a[id][i])) return false;
    return true;
}

bool insert_col(int id, int pos) {
    FOR(i, 1, pos - 1) if ((m[i][pos] != -1) && (m[i][pos] != a[id][i])) return false;
    return true;
}


bool find_v(vector <int> v) {
    FOR(i, 1, 2 * n - 1) if (dd[i] == 0) {
        int ok = 0;
        FOR(j, 1, n) if ((a[i][j] != v[j - 1])) ok = 1;
        if (ok == 0) {
                dd[i] = 1;
                return true;
        }
    }
    return false;
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test) {
        cout << "Case #" << t << ": ";
        cin >> n;
        SET(dd, 0);
        SET(m, -1);
        FOR(i, 1, 2 * n - 1) FOR(j, 1, n) cin >> a[i][j];
        int idd, iddd;
        FOR(i, 1, n) {
            //cout << "i = " << i << endl;
            II p = find_id(i);
            if ((p.fi == -1)) {
                    idd = i;
                    iddd = p.se;
                    continue;
            }
            //cout << "i = " << i << " " << p.fi << " " << p.se << endl;
            //if ()
            if (insert_row(p.fi, i) && (insert_col(p.se, i))) {
                FOR(j, 1, n) m[i][j] = a[p.fi][j];
                FOR(j, 1, n) m[j][i] = a[p.se][j];
            }
            else {
                FOR(j, 1, n) m[i][j] = a[p.se][j];
                FOR(j, 1, n) m[j][i] = a[p.fi][j];
            }
        }


        m[idd][idd] = a[iddd][idd];
        SET(dd, 0);
        /*FOR(i, 1, n) {
            FOR(j, 1, n) cout << m[i][j] << " ";
            cout << endl;
        } */

        vector <int> v;
        int ff = false;
        FOR(i, 1, n) {
            v.clear();
            FOR(j, 1, n) v.pb(m[i][j]);
            if ((!ff) && (!find_v(v))) {
                FOR(j, 1, n) cout << v[j - 1] << " ";
                ff = true;

            }
        }

        FOR(i, 1, n) {
            v.clear();
            FOR(j, 1, n) v.pb(m[j][i]);
            if ((!ff) && (!find_v(v))) {
                FOR(j, 1, n) cout << v[j - 1] << " ";
                ff = true;
            }
        }
        cout << endl;
    }
    return 0;
}

