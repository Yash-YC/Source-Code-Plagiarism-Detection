#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double dp[1000][42]={0};
double c[42][42];
double eps = 1e-9;

void calc()
{
	int i,j;
	c[1][1]=c[1][0]=1.0;
	for(i=2;i<41;i++)
	{	c[i][0]=c[i][i]=1.0;
		for(j=1;j<i;j++)
			c[i][j] = c[i-1][j]+c[i-1][j-1];
	}
}

int main()
{
	freopen("cin.txt","r",stdin);
	freopen("cout.txt","w",stdout);
	calc();
	int T;
	scanf("%d",&T);
	int i;
	int N,C;
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&C,&N);
		memset(dp,0,sizeof(dp));
		int j;
		int t;
		dp[1][N]=1.0;
		for(t=2;t<1000;t++)
		{
			for(j=N;j<=C;j++)
			{
				int k;
				for(k=N;k<=j;k++)
				{
				//	if(dp[t-1][k]<eps)continue;
					if(j-k<=N)
						dp[t][j] += dp[t-1][k]*c[k][N-j+k]*c[C-k][j-k]/c[C][N];
				}
			}
		}
		double ret = 0.0;
		for(j=1; j<1000;j++)
			ret+=dp[j][C]*j;
		printf("Case #%d: %.7f\n",i,ret);
	}
}