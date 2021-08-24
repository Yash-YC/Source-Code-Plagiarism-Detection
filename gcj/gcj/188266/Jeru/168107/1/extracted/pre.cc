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

const int RR = 12000000;

int f(int b, int n) {
    int r = 0;
    for (; n > 0; n /= b) {
        int t = n % b;
        r += t * t;
    }
    return r;
}

char _g(int b, char h[], int n) {
    int x1 = n, x2 = n;
    for (;;) {
        x1 = f(b, x1);
        for (int i = 0; i < 2; ++i) {
            x2 = f(b, x2);
            if (x2 < RR && h[x2])
                return h[x2];
        }
        if (x1 == x2) return -1;
    }
}

char g(int b, char h[], int n) {
    if (n < RR && h[n]) return h[n];
    int r = _g(b, h, n);
    if (n < RR) h[n] = r;
    return r;
}

char h[11][RR];
int N, hh[RR];

int main(int argc, char* argv[]) {
    for (int i = 2; i < 11; ++i) h[i][1] = 1;
    N = -1;
    for (int k = 2; k < RR; ++k) {
        int w = 0;
        for (int i = 2; i < 11; ++i)
            if (g(i, h[i], k) == 1)
                w |= 1 << i;
        hh[k] = w;
        if (w == 2044) {
            N = k + 1;
            break;
        }
    }
    FILE* f = fopen("a.bin", "w");
    fprintf(f, "%d\n", N);
    for (int i = 2; i < N; ++i)
        fprintf(f, "%d\n", hh[i]);
    return 0;
}
