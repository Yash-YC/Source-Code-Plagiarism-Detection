#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4530)
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof((x).begin())it=(x).begin();it!=(x).end();++it)
#define all(x) (x).begin(),(x).end()
#define CLR(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define sz size()
#define exist(c,x) ((c).find(x)!=(c).end())
#define cexist(c,x) (find(all(c),x)!=(c).end())
#define SMIN(a, b) a = min((a),(b))
#define SMAX(a, b) a = max((a),(b))

typedef long long ll;

double fact[42];

double comb(int a, int b) {
    double result = fact[b] / fact[a] / fact[b-a];
    //printf("%d %d %lf\n", a, b, result);
    return result;
}


double prob(int C, int N, int A, int i) {
    // 0 <= i <= A
    // 0 <= N-i <= C-A

    if (i < 0 || i > A) return 0.0;
    if ((N-i) < 0 || (C-A) < (N-i)) return 0.0;

    double result = comb(i, A) * comb(N-i, C-A) / comb(N, C);

    //printf("%d %d %d %d %lf\n", C, N, A, i, result);

    return result;

}

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    int Tests;
    cin >> Tests;

    fact[0] = 1.0;
    FOR(i, 1, 42) {
        fact[i] = fact[i-1] * i;
    }

    FOR(test, 1, Tests+1) {
        printf("Case #%d: ", test);
        int N, C;
        cin >>C >>N;
        double D[42];
        D[0] = 0;
        FOR(A, 1, C+1) {
            double left_side = 1 - prob(C, N, A, 0);
            double right_side = prob(C, N, A, 0);
            FOR(i, 1, N+1) {
                if (i <= A) {
                    double p = prob(C, N, A, i);
                    right_side = right_side + p * (D[A-i] + 1);
                }
            }
            D[A] = right_side / left_side;
        }
        printf("%.7lf\n", D[C]);
    }

}
