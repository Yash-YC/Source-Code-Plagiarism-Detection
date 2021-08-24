#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
#define DBG(x) cerr << #x << ": " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


int n, a[1000010];
int fl[202][1000010], fr[202][1000010];
int dnext[1000010][10], dprev[1000010][10];
char s[1000010];
int last[11];


int getMaxC(int L, int R) {
    if (L == R) return a[L];
    int M = (L + R) >> 1;
    int res = a[M];
    if (L <= M - 1) res = max(res, getMaxC(L, M - 1) + a[M]);
    if (M + 1 <= R) res = max(res, getMaxC(M + 1, R) + a[M]);
    return res;
}

void pp() {
    forn(i, 10) last[i] = -1;
    forn(i, n) {
        last[a[i]] = i;
        forn(j, 10) dprev[i][j] = last[j];
    }

    forn(i, 10) last[i] = n;
    for (int i = n-1; i >= 0; i--) {
        last[a[i]] = i;
        forn(j, 10) dnext[i][j] = last[j];
    }
}

int u[1010][1010], f[1010][1010], it;

int get(int L, int R) {
    if (L > R) return 0;
    if (L == R) return a[L];
    if (u[L][R] == it) return f[L][R];
    u[L][R] = it;
    int& res = f[L][R];
    res = a[L] + get(L + 1, R);
    int b = L;
    for (int i = L + 1; i <= R; i++) {
        int z = a[i] + max(get(L, i - 1), get(i + 1, R));
        if (z < res) {
            res = z;
            b = i;
        }
    }
    printf("best for [%d %d] is %d\n", L, R, b);
    return res;
}

void naive() {
    it++;
    printf("%d\n", get(0, n - 1));
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    forn(i, n) a[i] = s[i] - '0';

    pp();

    int maxc = getMaxC(0, n - 1);
    int ans = maxc;
    // fl[i][0] = fr[i][0] = 0 is always true
    for (int c = 1; c <= maxc; c++)
        forn(i, n) {
            {
                // left
                int& cur = fl[c][i];
                cur = 0;
                int m = i - fl[c-1][i] - 1;
                if (m < 0) fl[c][i] = i;
                else {
                    for (int j = 1; j < 10; j++) {
                        if (c - j < 0) break;
                        int q = dnext[m][j];
                        if (q > i) continue;
                        if (fr[c - j][q] >= i - q - 1) {
                            cur = max(cur, i - q + fl[c - j][q]);
                        }
                        while (q < i) {
                            q = dnext[q+1][j];
                            if (q > i) break;
                            if (fr[c - j][q] >= i - q - 1) {
                                cur = max(cur, i - q + fl[c - j][q]);
                            }
                        }
                    }
                }
            }

            {
                // right
                int& cur = fr[c][i];
                cur = 0;
                int m = i + fr[c-1][i] + 1;
                if (m >= n) fr[c][i] = n - i - 1;
                else {
                    for (int j = 1; j < 10; j++) {
                        if (c - j < 0) break;
                        int q = dprev[m][j];
                        //if (c == 19 && i == 5)
                        //    printf("dprev[%d][%d] = %d\n", m, j, q);
                        if (q < i) continue;
                        //if (c == 19 && i == 5)
                        //    printf("%d %d: try %d for r\n", c, i, q);
                        if (fl[c - j][q] >= q - i - 1) {
                            // if (c == 19 && i == 5) printf("ok\n");
                            cur = max(cur, q - i + fr[c - j][q]);
                        }
                        while (q > i) {
                            q = dprev[q-1][j];
                            if (q < i) break;
                            if (fl[c - j][q] >= q - i - 1) {
                                cur = max(cur, q - i + fr[c - j][q]);
                            }
                        }
                    }
                }
            }

            if (fl[c][i] >= i && fr[c][i] >= n - i - 1) {
                ans = min(ans, a[i] + c);
            }
            //printf("fl[%d][%d] = %d, fr[%d][%d] = %d\n", c, i, fl[c][i], c, i, fr[c][i]);
        }

    printf("%d\n", ans);
    // naive();
}

int main() {
	int tc;
    auto start = clock();
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done, %.3f sec.\n",
                q, double(clock() - start) / CLOCKS_PER_SEC);
	}
	return 0;
}
