
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int N, C;
long long c[41][41];

void calc() {
    c[0][0] = 1;
    for (int n = 1; n < 41; n++) {
        c[n][0] = c[n][n] = 1;
        for (int k = 1; k < n; k++)
            c[n][k] = c[n-1][k-1] + c[n-1][k];
    }
}

double e[41];

double solve() {   
    e[C] = 0;
    for (int i = C-1; i >= 0; --i) {
        e[i] = 1;
        for (int j = 1; j <= N; j++)
            if (N-j <= i && j <= C-i)
                e[i] += 1.0 * c[i][N-j] / c[C][N] * c[C-i][j] * e[i+j];
        
        if(i >= N)
            e[i] /= (1.0 - 1.0 * c[i][N] / c[C][N]);
    }
    return e[0];
}

int main() {
    FILE *fin = fopen("C-small.in", "r"), *fout = fopen("C-small.out", "w");
    int T;
    fscanf(fin, "%d", &T);
    calc();
    
    for(int i = 0; i < T; i++) {
        fscanf(fin, "%d%d", &C, &N);
        fprintf(fout, "Case #%d: %lf\n", i+1, solve());    
    }
    return 0;
}
