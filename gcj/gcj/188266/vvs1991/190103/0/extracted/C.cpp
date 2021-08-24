#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#pragma warning(disable: 4996)
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

int i,j,k,x,y,z;
int T,C,N;

int cards[41];

int c[41];
int d[41];
double calc(int C, int N)
{


    int buyt=0;
    int totaltry = 100000;
    for(int p = 0;p<totaltry;++p)
    {
        memset(cards,0,sizeof(cards));
        int buy=0;
        while (1)
        {   
            ++buy;
            memset(d,0,sizeof(c));
            // shuffle C
            for(int i=0;i<C;++i) c[i] = i;

            for(int i=0;i<C;++i)
            {
                int j = rand()%C;
                int t = c[i];
                c[i]=c[j];
                c[j]=t;
            }

            //for(int i=0;i<N;++i)
            //{

            //    int cc = rand()%C;
            //    while (c[cc] )
            //        //cc = rand()%C;
            //        cc = (cc+1)%C;
            //    //cards[rand()%C] = 1;
            //    c[cc]=1;
            //    //printf("%d,", cc);
            //}
            //printf("\n");
            int k = rand()%C;
            for(int i=0;i<N;++i)
                cards[c[(i+k)%C]] =1;

            bool full=true;
            for (int i=0;i<C;++i)
            {
                if (cards[i] == 0) 
                {
                    full=false;
                    break; // not covered.
                }
            }
            if (full) 
            {
              //  printf("buy=%d\n", buy);
                break;
            }
        }
        buyt += buy;
        
    }
    //printf(" totaltry = %d\n", buyt);
    return (double) buyt/totaltry;
            
    

}

int main()
{
    srand(time(0));
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%d%d",&C,&N);
        printf("Case #%d: %.8lf\n", t, calc(C,N));
    }

}