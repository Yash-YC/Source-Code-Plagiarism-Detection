#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    vector<vector<int>> list;
    int n;
    scanf("%d", &n);
    int m = n * 2 - 1;
    for (int i = 0; i < m; ++i) {
        list.pb({});
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            list[i].pb(x);
        }
    }
    sort(list.begin(), list.end(), [](const vector<int> &a, const vector<int>& b){ return a[0] < b[0]; });
    int w = 1 << m;
    for (int k = 0; k < w; ++k) {
        vector<int> pick(m, 0);
        int cnt = 0;
        for (int b = 0; b < m; ++b) {
            pick[b] = k & (1 << b);
            if (pick[b]) ++cnt;
        }
        if (cnt != n) continue;
        vector<vector<int>> ar;
        for (int b = 0; b < m; ++b) {
            if (pick[b]) ar.pb(list[b]);
        }
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if (ar[i][0] == ar[i - 1][0]) { valid = false; break; }
        }
        if (!valid) continue;
        vector<int> vis(n, 0);
        bool bk = false;
        for (int b = 0; b < m; ++b) {
            if (!pick[b]) {
                for (int j = 0; j < n; ++j) {
                    if (list[b][0] == ar[0][j]) {
                        bool good = true;
                        for (int i = 0; i < n; ++i) {
                            if (list[b][i] != ar[i][j]) { good = false; break; }
                        }
                        if (!good) { bk = true; break; }
                        else vis[j] = true;
                    }
                }
                if (bk) break;
            }
        }
        int vc = 0;
        for (int i = 0; i < n; ++i) vc += vis[i];
        if (vc != n - 1) continue;
        if (!bk) {
            int mj = 0;
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) { mj = j; break; }
            }
            for (int i = 0; i < n; ++i) {
                if (i != 0) printf(" ");
                printf("%d", ar[i][mj]);
            }
            printf("\n");
            return;
        }
    }
}

int main() {
    int case_n;
    scanf("%d", &case_n);
    for (int case_i = 1; case_i <= case_n; ++case_i) {
        printf("Case #%d: ", case_i);
        solve();
    }
    return 0;
}

