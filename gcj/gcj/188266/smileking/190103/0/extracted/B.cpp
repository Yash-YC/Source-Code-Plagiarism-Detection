#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define eps 1e-9
int mat[100][100];
int c,n;
double dp[3][100];
bool flag[100];
int main(void)
{
	
	mat[0][0]=1;
	for(int i=1;i<=40;i++)
	{
		mat[i][0]=1;
		mat[i][i]=1;
		for(int j=1;j<i;j++)
	         mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
	}
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int tn;
	int cas=0;
	scanf("%d",&tn);
	while(tn--)
	{
	scanf("%d%d",&c,&n);
	double m=(double)mat[c][n];
	int s=0,t=1;
	int d=1;
	memset(dp,0,sizeof(dp));
	dp[s][n]=1;

	memset(flag,0,sizeof(flag));
	flag[n]=true;
	double ans=0.0;
	for(d=1;;d++)
	{
/*		for(int i=0;i<=c;i++)
		  cout<<dp[s][i]<<" ";
  cout<<endl;*/
		double temp=(double)d*(double)dp[s][c];
	    //if(flag[c])
	      //cout<<"fuck"<<endl;
		if(flag[c]&&temp<eps)
		   break;
        dp[s][c]=0.0;
        ans+=temp;
		for(int i=n;i<=c;i++)
		{
			if(dp[s][i]>eps)
			{
			    for(int j=min(c-i,n);j>=0;j--)
			    {
				   dp[t][i+j]+=dp[s][i]*((double)mat[c-i][j]*(double)mat[i][n-j])/m;
			       flag[i+j]=true;   
			    }
			}
			dp[s][i]=0.0;
		}
		s=1-s;
		t=1-t;
	}
	printf("Case #%d: %.7lf\n",++cas,ans);
	}
	return 0;
}

