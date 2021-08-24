#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

const int NN = 64;
int N, M;
int A[1<<20];

int main(int argc, char *argv[]) {
    int T; scanf("%d", &T);
    F1(Ti, T) {
        scanf("%d", &N);
        memset(A, 0, sizeof(A));
        int mm = 0;
        F0(i, 2*N-1) {
            F0(j, N) {
                int v = 0;
                scanf("%d", &v);
                A[v]++;
                mm = std::max(mm, v);
            }
        }
        printf("Case #%d:", Ti);
        for(int i=1; i<=mm; ++i) {
            if (A[i] & 1) printf(" %d", i);
        } printf("\n");
    }
    return 0;
}
