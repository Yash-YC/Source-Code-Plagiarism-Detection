#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const int N = 10000;
int v[N];

int main() {
    int T;
    freopen("/Users/vino/Downloads/B-small-attempt1.in", "r", stdin);
     freopen("/Users/vino/Downloads/B-small-attempt1.out", "w", stdout);
    cin >> T;
    int cas = 0;
    while (T--) {
        int n;
        cin >> n;
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                v[x]++;
            }
        }
        int ans[55], cnt = 0;
        for (int i = 1; i <= 2500; i++) {
            if (v[i] & 1)
                ans[cnt++] = i;
        }
        printf("Case #%d:", ++cas);
        for (int i = 0; i < n; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }


    return 0;
}