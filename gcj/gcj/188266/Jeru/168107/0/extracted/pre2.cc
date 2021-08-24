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

int N;

bool mask[1 << 11];

void Mark(int x) {
    mask[x] = true;
    for (int i = 0; i < 11; ++i)
        if ((x >> i & 1) && !mask[x ^ 1 << i])
            Mark(x ^ 1 << i);
}

int nH;
pair<int, int> h[100];

int main(int argc, char* argv[]) {
    {
        FILE* f = fopen("a.bin", "r");
        fscanf(f, "%d", &N);
        for (int i = 2; i < N; ++i) {
            int t;
            fscanf(f, "%d", &t);
            if (!mask[t]) {
                Mark(t);
                h[nH++] = make_pair(i, t);
            }
        }
    }
    freopen("a2.bin", "w", stdout);
    cout << nH << endl;
    for (int i = 0; i < nH; ++i)
        cout << h[i].first << ' ' << h[i].second << endl;
    return 0;
}
