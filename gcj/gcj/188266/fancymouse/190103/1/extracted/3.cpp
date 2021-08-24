#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

const int Max = 40;
double factorial(int r){return r==0 ? 1 : factorial(r-1)*r;}
double C(int n,int m){return m<0 || m>n ? 0.0 : factorial(n)/factorial(n-m)/factorial(m);}
int main()
{
	int T;
	cin>>T;
	cout<<setiosflags(ios::fixed)<<setprecision(10);
	for(int cases=1;cases<=T;cases++)
	{
		int c,n;
		cin>>c>>n;
		double dp[Max+1],dp2[Max+1];
		dp[0] = 1.0;
		for(int i=1;i<=c;i++)
			dp[i] = 0.0;
		double result = 0.0;
		double total = C(c,n);
		for(int step=1;;step++)
		{
			for(int i=0;i<=c;i++)
			{
				dp2[i] = 0.0;
				for(int j=0;j<=n;j++)
					dp2[i] += dp[i-j]*C(c-i+j,j)*C(i-j,n-j)/total;
			}
			memcpy(dp,dp2,sizeof(double)*(c+1));
			result += dp[c]*step;
			dp[c] = 0.0;
			double temp = 0.0;
			for(int i=0;i<c;i++)
				temp += dp[i];
			if(temp < 1e-15) break;
		}
		cout<<"Case #"<<cases<<": "<<result<<endl;
	}
	return 0;
}
