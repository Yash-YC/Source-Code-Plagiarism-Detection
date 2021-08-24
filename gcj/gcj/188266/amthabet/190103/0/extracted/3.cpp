#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

#define MAX 41

double C[MAX][MAX];
bool vis[MAX];
double dp[MAX];
int c,n;

double f(int cur)	{
	if(cur>=c) return 0;
	if(vis[cur]) 
		return dp[cur];
	long double ans=0;
	for(int i=1;i<n;i++)	{
		ans += ( (C[cur][n-i]*C[c-cur][i]) / C[c][n]) * ( f(cur+i) + 1 );
	}
	ans += (C[c-cur][n]/C[c][n]) * (f(cur+n)+1);
	double x = C[cur][n]/C[c][n];
	ans = (x+ans)/(1-x);
	vis[cur]=1;
	return dp[cur]=ans;
}

int main()	{
	
	freopen("3_small.in","rt",stdin);
	freopen("3_small.out","wt",stdout);
	
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			C[i][j]=0;
	
	C[0][0]=1;
	for(int i=1;i<MAX;i++)	{
		C[i][0]=1;
		for(int j=1;j<MAX;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	
	int t;
	cin>>t;
	//cout<<"hellooooooooooooooooooo "<<t<<endl;
	for(int tt=1;tt<=t;tt++)	{
		for(int i=0;i<MAX;i++) vis[i]=0;
		cin>>c>>n;
		//printf("Case %d: %0.7lf\n", f(0));
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<"Case #"<<tt<<": "<<f(0)<<endl;
	}

	return 0;
}