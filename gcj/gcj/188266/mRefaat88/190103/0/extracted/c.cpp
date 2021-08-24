#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;

int oo = 10000001;
double C[203][203];
void buildnCr(int n)
{
	for(int i = 0 ; i < n ; i++)
			C[i][i]=C[i][0]=1;
		for(int i = 1 ; i < n ; i++)
			for(int j = 1 ; j < n ; j++)
				C[i][j] = C[i-1][j]+C[i-1][j-1]>oo?oo:C[i-1][j]+C[i-1][j-1];
}

double dp[41];

int N,c;
double doIt(int n)
{
	if(n==c)return 0;
	double &r = dp[n];
	if(r!=-1)return r;
	r= 0;
	for(int i = 1 ; i <= N && n+i<=c ; i++)
		r+=((C[c-n][i]*C[n][N-i])/C[c][N]) *(1+doIt(n+i));

	double res = (C[c][N]*r+C[n][N])/(C[c][N]-C[n][N]);
	r = res;
		return r;
}


int main()
{
	freopen("C-small-attempt0 (1).in","rt",stdin);
	freopen("C-small-attempt0 (1).out","wt",stdout);
	buildnCr(100);
	int tt;
	cin>>tt;
	for(int t = 0 ; t < tt ; t++)
	{
		cin>>c>>N;
		//cout<<N<<" "<<c<<endl;
	//	cout<<C[c][N]<<endl;
		for(int i = 0 ; i < 41 ; i ++)dp[i]=-1;
		printf("Case #%d: %.07lf\n",t+1,doIt(0));
	}
	return 0;
}
