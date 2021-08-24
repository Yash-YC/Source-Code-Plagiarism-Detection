#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const int N = 10000;
int p[N];
int vis[N];
int n;
int ans;

void dfs(int rt, int last, int first, int isOk, int num) {
    if (rt != first) {
        if (isOk || p[first] == rt) {
            if (p[rt] == last || p[rt] == first) {
                ans = max(ans, num);
            }
        }
    }

    if (last != -1) {
        if (p[rt] == last) {
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    vis[i] = true;
                    dfs(i, rt, first, isOk, num + 1);
                    vis[i] = false;
                }
            }
        } else {
            int i = p[rt];
            if (!vis[i]) {
                vis[i] = true;
                dfs(i, rt, first, isOk, num + 1);
                vis[i] = false;
            }
        }
    } else if (last == -1) {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                int ok = p[rt] == i;
                dfs(i, rt, first, ok, num + 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    int T;
    freopen("/Users/vino/Downloads/C-small-attempt0.in", "r", stdin);
    freopen("/Users/vino/Downloads/C-small-attempt0.in.out", "w", stdout);
    cin >> T;
    int cas = 0;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            p[i] = x;
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            vis[i] = true;
            dfs(i, -1, i, 0, 1);
            vis[i] = false;
        }
        printf("Case #%d: ",++cas);
        cout << ans << endl;
    }


    return 0;
}