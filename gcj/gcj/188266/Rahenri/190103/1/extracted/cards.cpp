#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

double table[50];
int C, N;
int T;

double comb(int y, int x) {
    if(y<0 or y>x) return 0.0;
    double ret = 1.0;
    for(int i=x;i>y;--i) ret *= i;
    for(int i=1;i<=(x-y);++i) ret /= i;
    return ret;
}

double expect(int k) {
    if(k == C) return 0.0;
    if(table[k] > -0.5) return table[k];
    double resp = 1.0;
    for(int i=1;i<=N;++i) {
        if(C-k>=i and N-i>=0 and k>=N-i)  {
            double c = comb(i, C-k) / comb(N, C) * comb(N-i, k);
            resp += c * expect(k+i);
        }
    }
    double rep = comb(N, k) / comb(N, C);
    resp /= (1 - rep);

    return table[k] = resp;
}

int main(void) {
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        scanf("%d%d", &C, &N);
        for(int i=0;i<50;++i) table[i]=-1.0;
        double resp = expect(0);
        printf("Case #%d: %.8f\n", t+1, resp);
    }
    return 0;
}
