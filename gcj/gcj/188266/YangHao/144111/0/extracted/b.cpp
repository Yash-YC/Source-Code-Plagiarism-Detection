#include <stdio.h>
const int maxn = 30;
int i,j,k,t,cases,n,m,x,y,z;
int ntime[maxn][maxn],mtime[maxn][maxn],btime[maxn][maxn],f[maxn][maxn][5];
bool bol[maxn][maxn][5];
bool able(int x,int y,int z,int k)
{
	if (x<1||y<1||x>n||y>m) return false;
	if (!bol[x][y][z]) return false;
	if (f[x][y][z]>=0&&f[x][y][z]<=k) return false;
	return true;
}
int calc(int x,int y,int z1,int z2,int k,int flag)
{
	int t,s,time;
	t=k-btime[x][y];
	s=ntime[x][y]+mtime[x][y];
	t%=s;
	if (t<0) t+=s;
	if (flag)
	{
		if (t<ntime[x][y]) time=k+1; else
		time=s-t+k+1;
	} else
	{
		if (t>=ntime[x][y]) time=k+1; else
		time=ntime[x][y]-t+k+1;
	}
	return time;
}
bool able1(int x,int y,int z1,int z2,int k,bool flag)
{
	if (!bol[x][y][z2]) return false;
	if (f[x][y][z2]>=0&&f[x][y][z2]<=calc(x,y,z1,z2,k,flag)) return false;
	return true;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&cases);
	for (t=1;t<=cases;t++)
	{
		scanf("%d%d",&n,&m);
		for (i=n;i>=1;i--)
			for (j=1;j<=m;j++)
			{
				scanf("%d%d%d",&ntime[i][j],&mtime[i][j],&btime[i][j]);
				f[i][j][1]=f[i][j][2]=f[i][j][3]=f[i][j][4]=-1;
				bol[i][j][1]=bol[i][j][2]=bol[i][j][3]=bol[i][j][4]=true;
			}
		f[1][1][1]=0;
		while (true)
		{
			x=y=z=-1;
			for (i=1;i<=n;i++)
				for (j=1;j<=m;j++)
					for (k=1;k<=4;k++)
						if (bol[i][j][k]&&f[i][j][k]>=0)
							if (x<0||f[x][y][z]>f[i][j][k])
							{
								x=i;
								y=j;
								z=k;
							}
			if (x<0) break;
			bol[x][y][z]=false;
			k=f[x][y][z];
			if (z==1)
			{
				if (able(x-1,y,4,k+2)) f[x-1][y][4]=k+2;
				if (able(x,y-1,2,k+2)) f[x][y-1][2]=k+2;
				if (able1(x,y,1,2,k,false)) f[x][y][2]=calc(x,y,1,2,k,false);
				if (able1(x,y,1,4,k,true)) f[x][y][4]=calc(x,y,1,4,k,true);
			} else
			if (z==2)
			{
				if (able(x-1,y,3,k+2)) f[x-1][y][3]=k+2;
				if (able(x,y+1,1,k+2)) f[x][y+1][1]=k+2;
				if (able1(x,y,2,1,k,false)) f[x][y][1]=calc(x,y,2,1,k,false);
				if (able1(x,y,2,3,k,true)) f[x][y][3]=calc(x,y,2,3,k,true);
			} else
			if (z==3)
			{
				if (able(x+1,y,2,k+2)) f[x+1][y][2]=k+2;
				if (able(x,y+1,4,k+2)) f[x][y+1][4]=k+2;
				if (able1(x,y,3,2,k,true)) f[x][y][2]=calc(x,y,3,2,k,true);
				if (able1(x,y,3,4,k,false)) f[x][y][4]=calc(x,y,3,4,k,false);
			} else
			{
				if (able(x+1,y,1,k+2)) f[x+1][y][1]=k+2;
				if (able(x,y-1,3,k+2)) f[x][y-1][3]=k+2;
				if (able1(x,y,4,1,k,true)) f[x][y][1]=calc(x,y,4,1,k,true);
				if (able1(x,y,4,3,k,false)) f[x][y][3]=calc(x,y,4,3,k,false);
			}
		}
		printf("Case #%d: %d\n",t,f[n][m][3]);
	}
	return 0;
}