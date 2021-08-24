#include <cstdio>
#include <cstring>
long long cb[41][41];
void CB(){
	memset(cb,0,sizeof(cb));
	cb[0][0]=1;
	for(int i=1;i<=40;++i){
		cb[i][0]=cb[i][i]=1;
		for(int j=1;j<i;++j) cb[i][j]=cb[i-1][j]+cb[i-1][j-1];
	}
}
double dp[41];
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	CB();
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas){
		int n,m;
		scanf("%d %d",&n,&m);
		memset(dp,0,sizeof(dp));
		dp[m]=1;
		double ans=dp[n],pp=dp[n];
		for(int L=2;pp<1-1e-9;++L){
			dp[n]=0;
			for(int i=n;i>=m;--i){
				dp[i]=dp[i]*cb[i][m]/cb[n][m];
				for(int j=1;j<=m;++j){
					dp[i]+=dp[i-j]*cb[i-j][m-j]*cb[n-i+j][j]/cb[n][m];
				}
			}
			ans+=dp[n]*L;
			pp+=dp[n];
		}
		printf("Case #%d: %f\n",cas,ans);
	}
	return 0;
}
