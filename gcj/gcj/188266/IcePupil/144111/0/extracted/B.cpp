#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,S[42][42],W[42][42],T[42][42];
long long F[42][42][4];
bool visit[42][42][4];

inline long long Calc_S(int x,int y,long long F)
{
	long long K=(F-T[x][y])/(S[x][y]+W[x][y]);
	long long Ret=T[x][y]+(S[x][y]+W[x][y])*(K-1);
	for (;Ret+S[x][y]<=F;Ret+=S[x][y]+W[x][y]);
	return max(Ret,F);
}

inline long long Calc_W(int x,int y,long long F)
{
	long long K=(F-T[x][y])/(S[x][y]+W[x][y]);
	long long Ret=T[x][y]+(S[x][y]+W[x][y])*(K-1)+S[x][y];
	for (;Ret+W[x][y]<=F;Ret+=S[x][y]+W[x][y]);
	return max(Ret,F);
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int Test;scanf("%d",&Test);
	for (int Case=1;Case<=Test;Case++) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			scanf("%d%d%d",&S[i][j],&W[i][j],&T[i][j]);
			T[i][j]%=(S[i][j]+W[i][j]);
		}
		memset(F,63,sizeof(F));
		memset(visit,0,sizeof(visit));
		F[1][1][0]=0;
		for (;;) {
			int i=0,j=0,k=0;
			for (int x=1;x<=n;x++)
			for (int y=1;y<=m;y++)
			for (int z=0;z<4;z++)
			if (!visit[x][y][z] && F[i][j][k]>F[x][y][z])
				i=x,j=y,k=z;
			visit[i][j][k]=1;
			if (i==n && j==m && k==2) break;
			if (k==0) {
				F[i][j-1][1]<?=F[i][j][0]+2;
				F[i-1][j][3]<?=F[i][j][0]+2;
				F[i][j][3]<?=Calc_S(i,j,F[i][j][0])+1;
				F[i][j][1]<?=Calc_W(i,j,F[i][j][0])+1;
			} else if (k==1) {
				F[i-1][j][2]<?=F[i][j][1]+2;
				F[i][j+1][0]<?=F[i][j][1]+2;
				F[i][j][0]<?=Calc_W(i,j,F[i][j][1])+1;
				F[i][j][2]<?=Calc_S(i,j,F[i][j][1])+1;
			} else if (k==2) {
				F[i+1][j][1]<?=F[i][j][2]+2;
				F[i][j+1][3]<?=F[i][j][2]+2;
				F[i][j][1]<?=Calc_S(i,j,F[i][j][2])+1;
				F[i][j][3]<?=Calc_W(i,j,F[i][j][2])+1;
			} else if (k==3) {
				F[i][j-1][2]<?=F[i][j][3]+2;
				F[i+1][j][0]<?=F[i][j][3]+2;
				F[i][j][0]<?=Calc_S(i,j,F[i][j][3])+1;
				F[i][j][2]<?=Calc_W(i,j,F[i][j][3])+1;
			}
		}
		printf("Case #%d: %I64d\n",Case,F[n][m][2]);
	}
	return 0;
}
