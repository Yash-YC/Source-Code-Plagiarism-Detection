#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4530)
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof((x).begin())it=(x).begin();it!=(x).end();++it)
#define all(x) (x).begin(),(x).end()
#define CLR(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define sz size()
#define exist(c,x) ((c).find(x)!=(c).end())
#define cexist(c,x) (find(all(c),x)!=(c).end())
#define SMIN(a, b) a = min((a),(b))
#define SMAX(a, b) a = max((a),(b))

typedef long long ll;

int infty = 1000000000;

int N, M;
int S[50][50], W[50][50], T[50][50];
int D[10000];
bool checked[10000];

int encode(int r, int c, int p, int q) {
    return (2 * r + p) * (2 * M) + (2 * c + q);
}

void decode(int code, int &r, int &c, int &p, int &q) {
    int colc = code % (2 * M);
    int rowc = code / (2 * M);

    r = rowc / 2;
    p = rowc % 2;
    c = colc / 2;
    q = colc % 2;

}

int cross_ns(int r, int c, int t) {
    int s = S[r][c], w = W[r][c];
    int period = s+w;
    int nt = (t / period * period) + (T[r][c] % period) + 2*period;
    while (nt > t) nt -= period;
    if (nt <= t && t < nt + s) return (t + 1);
    nt += period;
    return nt + 1;
}

int cross_we(int r, int c, int t) {
    int s = S[r][c], w = W[r][c];
    int period = s+w;
    int nt = (t / period * period) + (T[r][c] % period) + 2*period + s;
    while (nt > t) nt -= period;
    if (nt <= t && t < nt + w) return (t + 1);
    nt += period;
    return nt + 1;
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    int Tests;
    cin >> Tests;
    FOR(test, 1, Tests+1) {
        printf("Case #%d: ", test);
        cin >>N >>M;
        REP(i, N) {
            REP(j, M) {
                cin >>S[i][j] >>W[i][j] >>T[i][j];
                int p = S[i][j] + W[i][j];
                T[i][j] = ((T[i][j] % p) + p) % p;
            }
        }

        int V = (2 * N) * (2 * M);
        int startp = encode(N-1, 0, 1, 0);
        int endp = encode(0, M-1, 0, 1);

        REP(i, V) {
            D[i] = infty;
            checked[i] = false;
        }
        D[startp] = 0;

        while(true) {
            int maxd = infty;
            int tp = -1;
            REP(i, V) {
                if (!checked[i] && maxd > D[i]) {
                    maxd = D[i];
                    tp = i;
                }
            }
            if (maxd == infty) break;
            int r, c, p, q;
            int nr, nc, np, nq, nd, ntp;
            decode(tp, r, c, p, q);
            checked[tp] = true;

            //  north - south
            nr = r; nc = c; np = p; nq = q;
            if (np == 1) {
                nr += 1; np = 0;
            }
            else {
                nr -= 1; np = 1;
            }
            nd = maxd + 2; 
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                ntp = encode(nr, nc, np, nq);
                if (nd < D[ntp]) {
                    //printf(">> %d %d %d %d %d\n", r, c, p, q, maxd);
                    //printf("> %d %d %d %d %d\n", nr, nc, np, nq, nd);
                    D[ntp] = nd;
                }
            }

            //  west - east
            nr = r; nc = c; np = p; nq = q;
            if (nq == 1) {
                nc += 1; nq = 0;
            }
            else {
                nc -= 1; nq = 1;
            }
            nd = maxd + 2;
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                ntp = encode(nr, nc, np, nq);
                if (nd < D[ntp]) {
                    //printf(">> %d %d %d %d %d\n", r, c, p, q, maxd);
                    //printf("> %d %d %d %d %d\n", nr, nc, np, nq, nd);
                    D[ntp] = nd;
                }
            }

            //  crossing - south to north
            nr = r; nc = c; np = 1-p; nq = q;
            nd = cross_ns(nr, nc, maxd);
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                ntp = encode(nr, nc, np, nq);
                if (nd < D[ntp]) {
                    //printf(">> %d %d %d %d %d\n", r, c, p, q, maxd);
                    //printf("> %d %d %d %d %d\n", nr, nc, np, nq, nd);
                    D[ntp] = nd;
                }
            }

            //  crossing - west to east
            nr = r; nc = c; np = p; nq = 1-q;
            nd = cross_we(nr, nc, maxd);
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                ntp = encode(nr, nc, np, nq);
                if (nd < D[ntp]) {
                    //printf(">> %d %d %d %d %d\n", r, c, p, q, maxd);
                    //printf("> %d %d %d %d %d\n", nr, nc, np, nq, nd);
                    D[ntp] = nd;
                }
            }
        }
        cout <<D[endp] <<endl;
    }

}
