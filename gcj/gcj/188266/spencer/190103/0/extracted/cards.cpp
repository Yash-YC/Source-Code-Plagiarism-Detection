#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX_DRAWS 5000 
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define CLEAR(t) memset(t, 0, sizeof(t))

double p[MAX_DRAWS+5][50];
double f[MAX_DRAWS+5][50];
double fact_save[50];

double fact(int n) {
    if (fact_save[n] != 0) return fact_save[n];
    if (n == 0 || n == 1) fact_save[n] = 1;
    else fact_save[n] =  n*fact(n-1);
    return fact_save[n];
}

double binom(int n, int k) {
    return fact(n)/fact(k)/fact(n-k);
}

double hypergeom(int N, int m, int n, int k) {
    return binom(m, k)*binom(N-m, n-k)/binom(N, n);
}

int main() {
    FILE *fin = fopen("cards.in", "r"), *fout = fopen("cards.out", "w");
    
    int tests; fscanf(fin, "%d", &tests);
    REP(t, tests) {
        CLEAR(p); CLEAR(f);
        int N, C; fscanf(fin, "%d %d", &N, &C);
        f[1][C] = p[1][C] = 1;
        FOR(d, 1, MAX_DRAWS-1) FOR(M, C, N) {
            p[d+1][M] += p[d][M]*hypergeom(N, M, C, C);
            FOR(k, 1, C) {
                if (M+k > N) break;
                double val = p[d][M]*hypergeom(N, M, C, C-k);
                p[d+1][M+k] += val;
                f[d+1][M+k] += val;
            }
        }

        double ev = 0;
        FOR(d, 1, MAX_DRAWS) ev += d*f[d][N];
        fprintf(fout, "Case #%d: %lf\n", t+1, ev);
    }
    return 0;
}
