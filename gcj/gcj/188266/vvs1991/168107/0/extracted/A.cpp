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
#include <deque>
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

int i,j,k,x,y,z,t,T,base;
char buf[1024];
int b[10]; // bases

typedef deque<int> DI;

void convert(int x1, int base,DI & a)
{
    while (x1 >= base)
    {
       a.push_front(x1%base);
       x1=x1/base;
    }
    a.push_front(x1);
};

set<int> history;
bool happy(int x, int base)
{
    //printf("test %d in base %d\n", x, base);
    // split number into array of numbers in base.
    // for each digit s = a[i]*a[i]
    deque<int> a;
    history.clear();
    history.insert(x);
    
    convert(x,base,a);
    DI b;
    while(1) {
        
        //for each (int i in a)
        //    printf("%d, ", i);
        //printf("\n");
        int sum=0;
        for(DI::iterator it = a.begin(); it!=a.end();++it)    
            sum +=  (*it)*(*it);
         
        b.clear();
        convert(sum, base, b);
        if (history.find(sum) != history.end())
            return false;

        history.insert(sum);
        if (a==b)
            return false;
        if (b.size()==1)
        {
            if (b.front() == 1) 
                return true;            
        }
        a=b;
    };


 
    
    

    return true;
}
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &T);    
    gets(buf);
    for(t=1;t<=T;++t)
    {
        gets(buf);
        stringstream ss(buf);
        memset(b,0,sizeof(b));
        int i=0;
        while (!ss.eof())
        {
            ss >> b[i];
            ++i;
        }
        int n = i;  // n bases
        x=2; // test from 2;
        bool found=false;

        while(1)
        {
            //printf ("try %d\n", x);            
            if (x==91)
               z=1;
            for (i=0;i<n;++i)
            {
                if (!happy(x,b[i]))
                {
                    break;
                }
            }
            if (i==n) break; // found
            ++x;
        }
        printf("Case #%d: %d\n", t, x);


    }
    

}