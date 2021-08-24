#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=41;
double c[maxn][maxn];
double f[maxn];
int n,k;

void init(){
	scanf("%d%d",&n,&k);
	return;
}

void preprocess(){
	memset(c,0,sizeof(c));
	for (int i=0;i<maxn;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	return;
}

double getc(int a,int b){
	if (b>k){
		return 0;
	}
	return c[a][k-b]*c[n-a][b]/c[n][k];
}

double dp(){
	memset(f,0,sizeof(f));
	f[n]=0;
	for (int i=n-1;i>=k;i--){
		double curcost=1;
		for (int j=i+1;j<=i+k;j++){
			if (j>n){
				break;
			}
			curcost+=getc(i,j-i)*f[j];
		}
		f[i]=curcost/(1.0-getc(i,0));
	}
	return f[k];
}

int main(){
	int t;
	scanf("%d",&t);
	preprocess();
	for (int k=1;k<=t;k++){
		init();
		printf("Case #%d: %.6lf\n",k,dp()+1.0);
	}
	return 0;
}


