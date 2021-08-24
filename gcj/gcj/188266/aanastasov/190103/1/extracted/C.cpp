
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

ll choose[64][64];

int C, N;
bool got[64];
double exp[64];

double get(int have) {
    if (have == C)
        return 0.0;
    if (got[have])
        return exp[have];
    got[have] = true;
    
    long long total = 0;
    for (int nu = 0; nu <= N && have + nu <= C; ++nu)
        total += choose[C - have][nu] * choose[have][N - nu];
    
    double sum = 0.0;
    for (int nu = 1; nu <= N && have + nu <= C; ++nu)
        sum += get(have + nu) * ((choose[C - have][nu] * choose[have][N - nu]) / (total + 0.0));
    sum = sum + 1.0;
    double res = 1.0 - ((choose[C - have][0] * choose[have][N - 0]) / (total + 0.0));
    return exp[have] = sum / res;
}

double solve(int C, int N) {
    ::C = C;
    ::N = N;
    memset(got, 0, sizeof(got));
    return 1.0 + get(N);
}

int main() {
    for (int n = 0; n < 64; ++n) {
        choose[n][0] = 1;
        choose[n][n] = 1;
        for (int k = 1; k < n; ++k)
            choose[n][k] = choose[n - 1][k] + choose[n - 1][k - 1];
    }
    
    int tst;
    cin >> tst;
    for (int cas = 0; cas < tst; ++cas) {
        int C, N;
        cin >> C >> N;
        
        printf("Case #%d: %lf\n", cas + 1, solve(C, N));
    }
    return 0;
}