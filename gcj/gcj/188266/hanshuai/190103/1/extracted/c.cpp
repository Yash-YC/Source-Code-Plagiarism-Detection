/**********************************************************************
Author: hanshuai
Created Time:  2009-09-12 10:34:42
File Name: c.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int maxint = 0x7FFFFFFF;
const LL maxint64 = 0x7FFFFFFFFFFFFFFFLL;
LL com[45][45];
void init(){
    for(int i = 0; i <= 41; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0){
                com[i][j] = 1; continue;
            }
            if(i == j) com[i][j] = 1;
            else com[i][j] = com[i-1][j] + com[i-1][j-1];
//             printf("i = %d j = %d com[i][j] = %I64d\n", i, j, com[i][j]);
        }
    }
}
int c, n;
double dp[50], sum;
bool vis[50];
double dfs(int v){
    if(v == c) return 0.0;
    if(vis[v]) return dp[v];
    vis[v] = true;
    int l = c - v;
    double p = 0.0, px;
    for(int i = 1; i <= min(l, n); i ++){
        p += (((dfs(v+i)+1)*com[l][i]*com[v][n-i])/sum);
//        printf("com[l][i] = %.4lf %.4lf %.4lf\n", (double)com[l][i], (double)com[v][n-i], sum);
    }
    if(v >= n) px = double(com[v][n])/sum;
    else px = 0.0;
    dp[v] = (p+px)/(1-px);
//    printf("v = %d dp[v] = %.4lf px = %.4lf p = %.4lf\n", v, dp[v], px, p);
    return dp[v];
}
int main(){
    init();
    freopen("c.out", "w", stdout);
    int test, cas = 0;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &c, &n);
        memset(vis, false, sizeof(vis));
        sum = com[c][n];
        printf("Case #%d: %.9lf\n", ++cas, dfs(0));
    }
    return 0;
}

