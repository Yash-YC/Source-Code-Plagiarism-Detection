#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define FOR(A, I, B) for(int A = (int)I; A < (int)B; A++)
#define SZ(A) (int)(A).size()
#define vi vector<int>
#define pb push_back
#define ll long long
#define ERRO 1e-12
#define DEQ(X,Y) ( fabs((X) - (Y)) < ERRO)

#define MAX 100000

char buff[20];
vector<int> bases;

int happybase[11][MAX + 5];
int hpd[MAX + 5];
set<long long> cycle;

long long tobase(long long n, int base)
{
    if(base == 10) return n;
    long long res = 0;
    int mult = 1;
    //printf("convert %d to base %d\n", n, base);
    while(n > 0){
        res += (n%base)*mult;
        mult *= 10;
        n /= base;
    }
    //printf("res %d\n", res);
    return res;
}

bool isHappy(long long n, int b)
{
    //printf("n %d b %d\n", n, b);
    if(n == 1) return true;

    //if(n < MAX && happybase[b][n] != -1)
    //    return (happybase[b][n] == 1);

    if(cycle.count(n)) return false;
    cycle.insert(n);

    long long res = 0;
    while(n > 0){
        res += ((n%10) * (n%10));
        n /= 10;
    }
   
    long long nn = tobase(res, b);

    bool happy = isHappy(nn, b);

    //if(nn < MAX){
    //    if(happy)
    //        happybase[b][nn] = 1;
    //    else
    //        happybase[b][nn] = 0;
    //}
        
    return happy;
}

void preproc(){
    memset(happybase, -1, sizeof(happybase));
    //memset(hpd, -1, sizeof(hpd));
    FOR(b, 2, 11){
        FOR(i, 2, MAX){
            cycle.clear();
            //if(b == 3 && i < 10) printf("Chamando %d\n", i);
            if(isHappy(tobase((long long)i, b), b)){
                happybase[b][i] = 1;
                //if(b == 7) printf("%d é happy na base %d\n", i, b);
            } else happybase[b][i] = 0;
        }
    }
}

int main()
{
    int t;
    
    preproc();
    
    scanf("%d", &t); getchar();
    FOR(test, 0, t){
        bases.clear();
        fgets(buff, 20, stdin);
        int bb, bb2, bb3;
        int ns = sscanf(buff, "%d %d %d", &bb, &bb2, &bb3);
        if(ns > 2)
            bases.push_back(bb3);
        if(ns > 1)
            bases.push_back(bb2);
        bases.push_back(bb);

        int res = 2;
        while( true ){
            if(SZ(bases) == 3 && happybase[bases[0]][res] && happybase[bases[1]][res] && happybase[bases[2]][res])
                break;
            if(SZ(bases) == 2 && happybase[bases[0]][res] && happybase[bases[1]][res])
                break;
            if(SZ(bases) == 1 && happybase[bases[0]][res])
                break;
            res++;
        }
        printf("Case #%d: %d\n", test + 1, res);
    }
    return 0;

}

