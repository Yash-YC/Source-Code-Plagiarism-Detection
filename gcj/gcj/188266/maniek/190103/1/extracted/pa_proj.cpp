#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;


double cac[55];
int C,N;

double cacc[55][55];

double nck(int n,int k){
	if(k>n) return 0;
	if(k==n) return 1;
	if(k==0) return 1;
	if(k<0) assert(false);
	if(cacc[n][k] >= 0) return cacc[n][k];
	return cacc[n][k] = nck(n-1,k-1) + nck(n-1,k);
}

double dp(int have){
	if(N>=C) return 1;
	if(have >= C) return 0;
	double &ret = cac[have];
	if(ret >= 0) return ret;
	ret = 0;
	for(int i=1;i<=N;++i){
		ret += nck(C-have,i) * nck(have,N-i) *(1+dp(have+i));
	}

	ret /= (nck(C,N)-nck(have,N));
	double p = 1-nck(have,N)/nck(C,N),q=1-p;
//	fprintf(stderr,"before dp(%d):%lf\n",have,ret);

	ret = (p*ret+q)/p;


//	fprintf(stderr,"dp(%d):%lf\n",have,ret);
	return ret;
}

int main(){
	for(int i=0;i<55;++i) for(int j=0;j<55;++j) cacc[i][j] =-1;


	int T;
	cin >> T;
	for(int cas=1;cas<=T;++cas){
		cin >> C >> N;
		for(int i=0;i<55;++i) cac[i]=-1;
		printf("Case #%d: %lf\n",cas,dp(0));
	}
}















/*
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};


int pos(int x, int y){
	if(x%2 == 0 && y%2==0) return 0;
	if(x%2==1 && y%2==0) return 1;
	if(x%2==1 && y%2==1) return 2;
	return 3;
}


long long time(int x, int y, int dx, int dy, long long t,int S, int W, int T){
	int p1=pos(x,y);
	int p2=pos(x+dx,y+dy);
	if(p2<p1) swap(p1,p2);
	if(p1==0&&p2==1 ||

		p1==2
}
*/