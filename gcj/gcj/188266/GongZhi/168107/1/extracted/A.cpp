/* 
 * File:   A.cpp
 * Author: GongZhi
 * Problem:
 * Created on 2009年9月12日, 上午9:11
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

/*
 *
 */
#define N 20000000
int a[11][N];
int cal(int p,int k){
    int ans=0;
    int temp;
    while(k){
        temp=k%p;
        k/=p;
        ans+=temp*temp;
        if(ans>=N)return N;
    }
    return ans;
}
int dfs(int p,int k){
    if(a[p][k])return a[p][k];
    a[p][k]=-1;
    int temp=cal(p,k);
    if(temp==1)return a[p][k]=1;
    if(temp>=N)return a[p][k]=-1;
    return a[p][k]=dfs(p,temp);
}
int t[100];
char temp[100];
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int j,i,J;
    memset(a,0,sizeof(a));
    for(i=2;i<=10;i++)
        for(j=0;j<N;j++)dfs(i,j);
//        while(1){int u, v;scanf("%d%d",&u,&v);printf("%d\n",a[u][v]);}
        int kase;
        scanf("%d",&kase);
        gets(temp);
        for(int k=1;k<=kase;k++){
            gets(temp);
            int l=strlen(temp);
            j=0;
            while(j+j<l){
                sscanf(temp+j+j,"%d",&t[j]);
                j++;
            }
            //printf("j=%d %d %d\n",j,t[0],t[1]);
            for(i=2;i<N;i++){
                for(J=0;J<j;J++)if(a[t[J]][i]!=1)break;
                if(J==j)break;
            }
            printf("Case #%d: %d\n",k,i);
        }
    return 0;
}

