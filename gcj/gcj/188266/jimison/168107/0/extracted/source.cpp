#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int base[10];
int n;
char tmp[10000];
bool visit[1001];
int a[100];
int an;
int tt[100];
int tn;
void tran(int x, int b)
{
    an = 0;
    while (x) {
        a[an++] = x % b;
        x /= b;
    }
}
bool check(int x)
{
    for (int i = 0; i < n; ++i) {
        tran(x, base[i]);
        memset(visit, false, sizeof(visit));
        for (;;) {
            int t = 0;
            for (int j = 0; j < an; ++j) {
                t += a[j] * a[j];
            }
            if (visit[t]) return false;
            visit[t] = true;
            if (t == 1) break;
            tran(t, base[i]);
        }
    }
    return true;
}
int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out","w", stdout);
    int T;
    scanf("%d", &T);
    fgets(tmp, 10000, stdin);
    for (int k = 1; k <= T; ++k) {
        fgets(tmp, 10000, stdin);
        n = 0;
        int len = strlen(tmp);
        for (int i = 0; i < len;) {
            if (tmp[i] >= '0' && tmp[i] <= '9') {
                int x = 0;
                while (tmp[i] >= '0' && tmp[i] <= '9') {
                    x = x * 10 + tmp[i++] - '0';
                }
                base[n++] = x;
            } else i++;
        }
        for (int i = 2; ; i++) {
            if (check(i)) {
                printf("Case #%d: %d\n", k, i);
                break;
            }
        }
    }
    return 0;
}
