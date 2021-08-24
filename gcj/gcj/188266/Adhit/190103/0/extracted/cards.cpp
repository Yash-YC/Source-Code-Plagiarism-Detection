#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;

double dp[1<<11];
int T,tc,i,ambil,N,M;

int popcount(int x) {
	int i,temp;
	temp=0;
	for(i=0;i<N;i++) {
		if(x&(1<<i)) temp++;
	}
	return temp;
}

double dfs(int x) {
	if(x==(1<<N)-1) return 0;
	if(dp[x]>-1) return dp[x];
	int i,bnyk,sama;
	double temp=0,temp1=0;
	bnyk=0;
	sama=0;
	for(i=1;i<(1<<N);i++) {
		if(popcount(i)!=M) continue;
		bnyk++;
		if((x|i)==x) {
			sama++;
			continue;
		}
		temp+=(1+dfs(x|i));
		//cout<<"masuk!"<<endl;
	}
	temp1=((double)sama+temp)/(double)(bnyk-sama);
	dp[x]=temp1;
	/*cout<<"crnt: "<<x<<endl;
	cout<<"a: "<<sama<<endl;
	cout<<"n: "<<bnyk<<endl;
	cout<<"c: "<<temp<<endl;
	cout<<"x: "<<temp1<<endl;*/
	return temp1;
}	

int main() {
	cin>>T;
	for(tc=1;tc<=T;tc++) {
		cin>>N>>M;
		for(i=0;i<(1<<N);i++) dp[i]=-1;
		printf("Case #%d: %lf\n",tc,dfs(0));
	}
	return 0;
}
