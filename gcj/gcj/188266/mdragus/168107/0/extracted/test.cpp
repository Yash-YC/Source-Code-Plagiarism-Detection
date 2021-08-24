#include<stdio.h>
#include<string.h>

const int maxn = 10000000;
const int maxb = 12;

char ANS[maxn][maxb];
char VER[maxn][maxb];
int NRT,X;
int B[20];

void verif(int nr,int b)
{
	if (VER[nr][b]) return ;
	VER[nr][b] = 1;
	int x = nr;
	int cur = 0;
	while(x)
	{
		int cif = x % b;
//		printf("%d\n",cif);
		cur += cif * cif;
		x /= b;
	}
//	printf("\n--%d\n",cur);
	if (cur == 1) {ANS[nr][b] = 1;return;}
	verif(cur,b);
//	printf("%d %d\n",cur,ANS[cur][b]);
	if (ANS[cur][b]) ANS[nr][b] = 1;
}

int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d\n",&NRT);
	for(int i1 = 1;i1 <= NRT; ++i1)
	{
		B[0] = 0;
		for(int i = 1;; ++i)
		{
			char c;
			scanf("%d%c",&B[i],&c);
			B[0]++;
			if (c != ' ') break;
		}
		
		for(int i = 2;i <= 10000000;++i)
		{
			X = 1;
			for(int j = 1;j <= B[0]; ++j)
			{
				verif(i,B[j]);
				if (ANS[i][B[j]] == 0) X = 0;
			}
			if (X) {printf("Case #%d: %d\n",i1,i);break;}
		}
	}

}

