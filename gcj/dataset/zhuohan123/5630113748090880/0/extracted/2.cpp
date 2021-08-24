#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int n;
struct col
{
	int a[60];
	friend bool operator<(col x,col y)
	{
		for(int i=1;i<=n;i++)
			if(x.a[i]!=y.a[i])return x.a[i]<y.a[i];
		return false;
	}
}c[5000];

int b[100][100],num[100][100];
bool checkx(int x,int wc)
{
	for(int i=1;i<=n;i++)
		if(num[x][i]>0&&b[x][i]!=c[wc].a[i])return false;
	return true;
}
bool checky(int y,int wc)
{
	for(int i=1;i<=n;i++)
		if(num[i][y]>0&&b[i][y]!=c[wc].a[i])return false;
	return true;
}
bool dfs(int x,int y,int wc)
{
	if(wc==2*n)return true;
	if(x<=n&&checkx(x,wc))
	{
		for(int i=1;i<=n;i++)
			b[x][i]=c[wc].a[i],num[x][i]++;
		if(dfs(x+1,y,wc+1))return true;
		for(int i=1;i<=n;i++)
			b[x][i]=c[wc].a[i],num[x][i]--;
	}
	if(y<=n&&checky(y,wc))
	{
		for(int i=1;i<=n;i++)
			b[i][y]=c[wc].a[i],num[i][y]++;
		if(dfs(x,y+1,wc+1))return true;
		for(int i=1;i<=n;i++)
			b[i][y]=c[wc].a[i],num[i][y]--;
	}
	x++;
	if(x<=n&&checkx(x,wc))
	{
		for(int i=1;i<=n;i++)
			b[x][i]=c[wc].a[i],num[x][i]++;
		if(dfs(x+1,y,wc+1))return true;
		for(int i=1;i<=n;i++)
			b[x][i]=c[wc].a[i],num[x][i]--;
	}
	y++;x--;
	if(y<=n&&checky(y,wc))
	{
		for(int i=1;i<=n;i++)
			b[i][y]=c[wc].a[i],num[i][y]++;
		if(dfs(x,y+1,wc+1))return true;
		for(int i=1;i<=n;i++)
			b[i][y]=c[wc].a[i],num[i][y]--;
	}
	return false;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		memset(num,0,sizeof num);
		memset(b,0,sizeof b);
		
		cout<<"Case #"<<ti<<": ";
		cin>>n;
		for(int i=1;i<=2*n-1;i++)
			for(int j=1;j<=n;j++)cin>>c[i].a[j];
		sort(c+1,c+2*n);
		dfs(1,1,1);
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<num[i][j]<<" ";
			cout<<endl;
		}*/
		for(int i=1;i<=n;i++)
		{
			bool o=true;
			for(int j=1;j<=n;j++)
				if(num[i][j]!=1)o=false;
			if(o)
			{
				for(int j=1;j<n;j++)cout<<b[i][j]<<" ";
				cout<<b[i][n]<<endl;
			}
		}
		for(int i=1;i<=n;i++)
		{
			bool o=true;
			for(int j=1;j<=n;j++)
				if(num[j][i]!=1)o=false;
			if(o)
			{
				for(int j=1;j<n;j++)cout<<b[j][i]<<" ";
				cout<<b[n][i]<<endl;
			}
		}
		
	}
	return 0;
}
