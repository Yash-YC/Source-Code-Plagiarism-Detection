#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-8
#define maxa 300000

double dp[maxa+1][42];
double tr[42][42];
double pncr[50][50];
int nncr[50][50];

double ncr(int n, int r){
	if(n<r)return 0;
	if(r<0)return 0;
	if(nncr[n][r])return pncr[n][r];
	double aa = 1.0;
	for(int i=1;i<=r;i++){
		aa = aa * (n-i+1) / i;
	}
	nncr[n][r]=1;
	return pncr[n][r] = aa;
}

int main(){
	int nn,ii;
	int n,c;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		scanf("%d%d",&c,&n);
		memset(nncr,0,sizeof(nncr));
		for(int i=0;i<=c;i++){
			for(int j=0;j<=c;j++){
				tr[i][j] = ncr(j,n-i+j)*ncr(c-j,i-j)/ncr(c,n);
				//printf(" %d %d: %.7f\n",i,j,tr[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		double ans = 0;
		for(int i=1;i<=maxa;i++){
			for(int j=1;j<=c;j++){
				for(int k=0;k<=j;k++){
					dp[i][j] += dp[i-1][k]*tr[j][k];
				}
				//if(i<=10)printf(" dp %d %d: %.7f\n",i,j,dp[i][j]);
			}
			ans += (dp[i][c]-dp[i-1][c]) * i;
		}
		//ans /= maxa;
		printf("Case #%d: %.7f\n",ii, ans);
		
	}
	return 0;
}
