#include<stdio.h>

const int maxn = 55;

long long C[maxn][maxn];
int NRT;

int main()
{
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	scanf("%d\n",&NRT);
	C[0][0] = 1;
	for(int i = 1;i <= 40; ++i)
			for(int j = 0;j <= i; ++j)
			{
				C[i][j] = C[i - 1][j];
				if (j != 0) C[i][j] += C[i - 1][j - 1];
			}
	for(int i = 1;i <= NRT; ++i)
	{
		int X,Y;
		scanf("%d %d\n",&X,&Y);
		printf("Case #%d: %lf\n",i,(1 + (double) C[X - 1][Y - 1] / C[X][Y]) * X / Y);
	}
	return 0;
}



