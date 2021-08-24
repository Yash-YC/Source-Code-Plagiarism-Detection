#include<cstdio>
int N,C,Z,i,j,k,q,z;
double dp[45][45],t,c;
int main(){
	for (i=1;i<=40;++i){
		for (j=i;j<=40;++j){
			if (i==j) dp[i][j] = 1;
			else{
				k = 1;
				t = 0;
				dp[i][j] = 0;
				for (k=1;k<=i && j-k>=i ;++k){
					q = j-k;
					++t;
					dp[i][j] += (dp[i][j-1] + 1.0*q*(j*1.0)/(j-1.0)/(1-1.0/j)/j);
					
				}
				dp[i][j]/=t;
			}
//			printf("%d %d %.7lf\n",q,j,1.0*q*(j)/(j-1)/(1-1.0/j)/j);
		}
	}
	scanf("%d",&Z);

	for (z=1;z<=Z;++z){
		scanf("%d%d",&N,&C);
		printf("Case #%d: %.7lf\n",z,dp[C][N]);
	}

	return 0;
}
