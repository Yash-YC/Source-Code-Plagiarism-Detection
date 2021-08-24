#include<sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define foru(i,a,b) for (int i=(a);i<=(b);i++)
#define ford(i,a,b) for (int i=(a);i>=(b);i--)

int a[10000];
int cas, nm[10000];
char str[100000];
int n, num, res;
int flg[1000000], tim;

const int size = 1000000;

int check(int dep, int x, int base) {
    if (x == 1) return 1;
    if (x == 0) return 0;
    if (x < size && flg[x] == tim) return 0;
    if (x < size) flg[x] = tim;
    
    int m = 0, sum = 0;
    while (x) {
        a[m++] = x % base;
        x /= base;
    }    
    
    for (int i = m - 1; i >= 0; i--) sum += a[i] * a[i];            
    return check(dep + 1, sum, base);    
}    

int main() {
    memset(flg, 0, sizeof(flg));
    tim = 0;
    scanf("%d", &cas);
    gets(str);
    for (int tt = 0; tt < cas; tt++) {
        gets(str);
        istringstream is(str);
        n = 0;
        while (is >> num) nm[n++] = num;
        sort(nm, nm + n);
        for (res = 3; ; res++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                tim++;
                if (!check(0, res, nm[i])) {
                    ok = 0;
                    break;
                }                
            }    
//            printf("%d ", res);
            if (ok) break;    
        }    
        printf("Case #%d: %d\n", tt+1, res);

    }    
}    

/*
25 7              34 25
*/
