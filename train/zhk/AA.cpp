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
#include <deque>
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



int main(int argc, char *argv[]) {
    int T;scanf("%d", &T);
    char buf[1024];
    F1(Ti, T) {
        scanf("%s", buf);
        deque<char> Q;
        Q.push_back(buf[0]);
        for(int i=1; buf[i]; ++i) {
            char c = buf[i];
            if (c >= Q.front()) Q.push_front(c);
            else Q.push_back(c);
        }
        printf("Case #%d: ", Ti);
        for(size_t i=0; i<Q.size(); ++i) printf("%c", Q[i]);
        printf("\n");
    }
    return 0;
}
