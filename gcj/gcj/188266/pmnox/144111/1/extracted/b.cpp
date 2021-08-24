
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define vv vector
#define pb push_back
#define ull unsigned long long
#define ll long long
#define ld long double
#define rep(i,n) for(int i=(0);i<(n);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(var(a,(b).begin());a!=(b).end();++a)
#define var(a,b) __typeof(b) a=(b)
#define ss(a) ((int)((a).size()))
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
#define pii pair<int, int>
#define x first
#define y second
int cond = 1;
#define db(x) { if (cond > 0) { cond--; cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

#define MOD (2e9+33)
#define pll pair<ull,ull>
map<pll,pll> MAP;
#define x first
#define y second

int n, m;

int s[80][80];
int w[80][80];
int t[80][80];


#define mp make_pair
set<pair<ll, pii> > q;
map<pii, ll> odp;

void add(int r, int c, ll val) {
    if (r >= 1 && r < 1 + 2 * n && c >= 1 && c < 1 + 2 * m) {
        db(r<<" "<<c<<" "<<val);
        if (odp.count(pii(r,c)) == 0) {
            odp[pii(r,c)] = val;
            q.insert(mp(val, pii(r,c)));
        }
        if (odp[pii(r,c)] > val) {
            odp[pii(r,c)] = val;
            q.insert(mp(val, pii(r,c)));
        }
    }
}

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

ll solve() {
    scanf("%d%d", &n, &m);

    clr(t, 0x3f);
    clr(s, 0x3f);
    clr(w, 0x3f);
    rep (i, n) {
        rep (j, m) scanf("%d%d%d", &s[i][j], &w[i][j], &t[i][j]);
    }
    q.clear(); odp.clear();
    add(2*n,1,0);

    while (q.size()) {
        ll val = q.begin()->x;
        pii pos = q.begin()->y;
        q.erase(q.begin());

        rep (d, 4) {
            int ni = pos.x + dr[d];
            int nj = pos.y + dc[d];
            if (pos.x/2 == ni/2 && pos.y/2 == nj / 2) {
                add(ni,nj,val+2);
            }
            else {
                if (pos.x != ni) {
                    int r = (ni-1) / 2;
                    int c = (nj-1) / 2;

                    ll s0 = s[r][c];
                    ll w0 = w[r][c];
                    ll cycle = (s0 + w0);
                    ll v0 = val % cycle;
                    ll t0 = t[r][c] % cycle;
                    bool ok = 0;
                    fo (j, -3, 3) {
                        if (t0 <= v0  + cycle * j && v0 + cycle * j < t0 + s0) {
                            ok = 1;
                        }
                    }
                    db(ok<<" "<<val<<" "<<t0<<" "<<v0);
                    if (ok) {
                        add(ni, nj, val + 1);
                    }
                    else if (v0 <= t0)
                        add(ni, nj, 1 + val + t0 - v0);
                    else if (v0 <= t0 + cycle)
                        add(ni, nj, 1 + val + (cycle + t0) - v0);
                    else
                        throw 0;

                }
                else if (pos.y != nj) {
                    int r = (ni-1) / 2;
                    int c = (nj-1) / 2;
                    ll s0 = s[r][c];
                    ll w0 = w[r][c];
                    ll cycle = (s0 + w0);
                    ll v0 = val % cycle;
                    ll t0 = (t[r][c] + s0) % cycle;
                    bool ok = 0;
                    fo (j, -2, 2) {
                        if (t0 <= v0  + cycle * j && v0 + cycle * j < t0 + w0) {
                            ok = 1;
                        }
                    }
                    db(ok<<" "<<val<<" "<<s0<<" "<<t0<<" "<<v0);
                    if (ok) {
                        add(ni, nj, val + 1);
                    }
                    else if (v0 <= t0)
                        add(ni, nj, 1 + val + t0 - v0);
                    else if (v0 <= t0 + cycle)
                        add(ni, nj, 1 + val + (cycle + t0) - v0);
                    else
                        throw 0;
                }
                else throw 0;
            }
        }
    }
#if 0
    db(n<<" "<<m);
    fo (r, 0, 2 * n + 1) {
        fo (c, 0, 2 * m + 1) {
            cerr << odp[pii(r,c)] << " ";
        }
        cerr << endl;
    }
#endif
    return odp[pii(1, 2*m)];
}

int main(int argc, char ** argv) {
    cond = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    ll T;
    cin >> T;
    fo (i, 1, T) {
        cout << "Case #" << i << ": "<< solve() << endl;
    }
    return 0;
}

