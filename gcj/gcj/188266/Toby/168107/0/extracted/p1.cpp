#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int T;
bool base[11];

bool check(int ans, int b) {
    int count = 0;
    while (ans != 1) {
        if (ans < b * b) count++;
        if (count > b * b) return 0;

        int x = ans;
        int sum = 0;
        while (x > 0) {
            int res = x % b;
            sum += res * res;
            x /= b;
        }
        ans = sum;
    }
    return 1;
}

void solve() {
    int ans = 2;

    while (1) {
        int flag = 1;
        for (int i = 2; i <= 10; i++) {
            if (base[i])
                if (!check(ans, i)) {
                    flag = 0;
                    break;
                }
        }
        if (flag) {
            printf("%d\n", ans);
            return;
        }
        ans++;
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        printf("Case #%d: ", i+1);
        memset(base, 0, sizeof(base));

        char c = 'x';
        while (c != '\n' && c != '\r') {
            int b;
            scanf("%d%c", &b, &c);
            base[b] = 1;
        }

        solve();
    }

    return 0;
}
