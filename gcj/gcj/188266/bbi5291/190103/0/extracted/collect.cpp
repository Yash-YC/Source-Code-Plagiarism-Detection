#include <iostream>
#include <cmath>
using namespace std;
long double binom_coeff(int n, int k)
{
	if (k<0||k>n) return 0;
	long double res=1;
	int i;
	for (i=1; i<=n; i++)
		res*=i;
	for (i=1; i<=k; i++)
		res/=i;
	for (i=1; i<=n-k; i++)
		res/=i;
	return res;
}
int main()
{
	int T,i,j,C,k,m;
	cin >> T;
	for (i=1; i<=T; i++)
	{
		cin >> C >> k;
		long double dp[100]={0};
		dp[C]=0;
		for (j=C-1; j>=0; j--)
		{
			long double tmp=0;
			for (m=0; m<k; m++)
				tmp+=binom_coeff(j,m)*binom_coeff(C-j,k-m)/binom_coeff(C,k)*dp[j+(k-m)];
			tmp+=1;
			dp[j]=tmp/(1.0-binom_coeff(j,k)*binom_coeff(C-j,0)/binom_coeff(C,k));
		}
		printf("Case #%d: %Lf\n",i,dp[0]);
	}
	return 0;
}