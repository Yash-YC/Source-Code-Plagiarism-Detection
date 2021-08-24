#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

double ch[50][50];

struct Prob {
    double f[50];

    double Go(int N, int C) {
        f[0] = 0;
        for (int n = 1; n <= C - N; ++n) {
            double c[50];
            for (int k = 0; k <= n; ++k)
                c[k] = ch[C - n][N - k] * ch[n][k] / ch[C][N];
            double s = 1;
            for (int k = 1; k <= n; ++k)
                s += c[k] * f[n - k];
            f[n] = s / (1 - c[0]);
        }
        return f[C - N] + 1;
    }
};

double ans[50][50];

void init() {
    for (int n = 0; n <= 40; ++n) {
        ch[n][0] = 1;
        for (int k = 1; k <= n; ++k)
            ch[n][k] = ch[n][k - 1] * (n - k + 1) / k;
    }
    Prob p;
    for (int C = 1; C <= 40; ++C)
        for (int N = 1; N <= C; ++N)
            ans[C][N] = p.Go(N, C);
}

int main(int argc, char* argv[]) {
    init();

    if (argc > 1) {
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    }
    int cc = 0, ccc = 0;
    for (cin >> ccc; cc < ccc; ++cc) {
        int N, C;
        cin >> C >> N;
        printf("Case #%d: %.10lf\n", cc + 1, ans[C][N]);
    }
    return 0;
}
