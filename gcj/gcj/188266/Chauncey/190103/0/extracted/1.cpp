#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <functional>

using namespace std;

#define Rep(i,n) for (int i(0); i<(n); ++i)
#define Vs vector<string>
#define Vsi vector<string>::iterator
#define Vi vector<int>
#define Vii vector<int>::iterator
#define Wilv(v,iter,iter_end) (iter)=(v).begin(),(iter_end)=(v).end();while( (iter)!=(iter_end) )

typedef map<string, string> PMap;

inline int sq(int n)
{
    return n*n;
}

inline int next(int num, int base)
{
    int ret=0;
    while(num>0) {
        ret += sq(num%base);
        num /= base;
    }
    return ret;
}

char happynum[11][2000]={0};

int main()
{
    int N;
    freopen("..\\in.txt", "r", stdin);
    freopen("..\\out.txt", "w", stdout);

    scanf("%d", &N);

    for(int ncase=1; ncase<=N; ncase++) {
        int c,n;
        scanf("%d%d", &c, &n);

        printf("Case #%d: %.7f\n", ncase, (double)(c+n)/(double)n);
    }

    return 0;
}

