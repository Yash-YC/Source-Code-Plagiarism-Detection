/**********************************************************************
Author: hanshuai
Created Time:  2009-09-12 9:10:40
File Name: test.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
const int maxn = 100005;
int a[11][maxn + 2], b;
int dfs(int v){
    a[b][v] = 2;
    int x = v, s = 0;
    while(x){
        s += ((x%b)*(x%b));
        x /= b;
    }
//    printf("v = %d x = %d\n", v, x);
    if(a[b][s] == 2) a[b][v] = 0;
    else{
        if(a[b][s] == -1) dfs(s);
        a[b][v] = a[b][s];
    }
    return a[b][v];
}
int q[12];
char s[10000];
int main() {
    int test;
    for(int j = 2; j <= 10; j ++){
        b = j;
        memset(a[b], -1, sizeof(a[b]));
        a[b][1] = 1;
        for(int i = 2; i <= maxn; i ++){
            if(a[b][i] == -1){
                dfs(i);
            }
            //        printf("i = %d a[i] = %d\n", i, a[i]);
          //  if(a[i] == 1) printf("%d ", i);
        }
    }
    freopen("a.out", "w", stdout);
    scanf("%d\n", &test); 
    int cas = 0;
    while(test --){
        gets(s);
        int n = 0, x = 0, len = strlen(s);
        while(x < len){
            sscanf(s + x, "%d", &q[n]);
            if(q[n] == 10) x += 3;
            else x += 2;
            n ++;
        }
      //  for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
        for(int i = 2; i <= maxn; i ++){
            bool ok = true;
            for(int j = 0; j < n; j ++){
                if(!a[q[j]][i]){
                    ok = false; break;
                }
            }
            if(ok){
                printf("Case #%d: %d\n", ++cas, i);
                break;
            }
        }
    }
    return 0;
}


