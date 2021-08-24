#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

double table[1<<10];
int C, N;
int T;

double odd;

double expect(int mask) {
    if(mask == (1<<C)-1) return 0.0;
    if(table[mask] > -0.5) return table[mask];
    double resp = 1.0;
    int rep = 0;
    for(int j=0;j<(1<<C);++j) if(__builtin_popcount(j)==N) {
        int m = mask | j;
        if(m == mask) {
            rep ++;
            continue;
        }
        resp += odd * expect(m);
    }
    resp /= (1 - rep*odd);

    return table[mask] = resp;
}

double comp(int x, int y) {
    double ret = 1.0;
    for(int i=x;i>y;--i) ret *= i;
    for(int i=1;i<=(x-y);++i) ret /= i;
    return ret;
}

int main(void) {
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        scanf("%d%d", &C, &N);
        odd = 1.0 / comp(C, N);
        for(int i=0;i<(1<<10);++i) table[i]=-1.0;
        double resp = expect(0);
        printf("Case #%d: %.8f\n", t+1, resp);
    }
    return 0;
}
