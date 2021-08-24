#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

const int MAXB  =   10 + 2;
const int MAXN  =   1000000;

int f[MAXN][MAXB];

string str;
int tb[MAXB];
int bc;

void readin(){
    int t;
    
    getline(cin, str);
    istringstream sin(str);
    bc = 0;
    while(sin>>t){
        tb[bc++] = t;
    }
}

inline int sqr(int a){return a*a;}

bool check(int n, int b){
    //printf("check %d %d\n", n, b);
    if(n < MAXN && f[n][b] != -1)
        return f[n][b] == 1;
    if(n == 1)
        return !!(f[n][b] = 1);
    
    f[n][b] = 2;
    int tn = n, next = 0;
    while(tn){
        next += sqr(tn%b);
        tn /= b;
    }
    return (f[n][b] = check(next, b)) == 1;
}

void solve(){
    for(int i=2; ; ++i){
        bool ok = true;
        for(int j=0; j<bc; ++j)
            if( ( ok = check(i, tb[j]) ) == false)
                break;
        if(ok){
            printf("%d\n", i);
            break;
        }
    }
}

int main(){
    int t;
    memset(f, -1, sizeof(f));
    scanf("%d", &t);
    getline(cin, str);
    for(int i=1; i<=t; ++i){
        readin();
        printf("Case #%d: ", i);
        solve();
    }
}
