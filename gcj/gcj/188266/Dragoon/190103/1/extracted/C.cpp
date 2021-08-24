#include<stdio.h>
#include<string.h>

typedef __int64 LL;

LL ncr[50][50];
int N,C;
int mark[50];
double e[50];
double probablity;

int P(int notun, int ase)
{
	int i ;
	if(C-ase < notun) return 0;
	probablity = 1.*ncr[ase][N-notun] * ncr[C-ase][notun] / ncr[C][N];
/*
	probablity = (double)ncr[N][notun];
	for(i=0;i<N-notun;i++)
		probablity/=(ase-i);
	for(i=0;i<notun;i++)
		probablity/=(C-ase-i);
	probablity /= ncr[C][N];
	for(i=1;i<=N;i++)
		probablity*=i;
*/
	return 1;
}

double E(int a)
{
	if(a==C) return 0;

	if(mark[a]) return e[a];
	mark[a]=1;

	int i;
	int temp;
	double now=0,here;
	for(i=1;i<=N;i++)
		if(a+i>C) break;
		else
		{
			temp = P(i,a);
			here=probablity;

			if(temp)
				now+=here*(1+E(a+i));
		}

	P(0,a);
	e[a] = (now + probablity)/ (1 - probablity);

	return e[a];
}

int main()
{
	freopen("c2.out","w",stdout);

	int i,j,T,ks;

	ncr[0][0]=1;
	int limncr = 40;
	for(i=1;i<=limncr;i++)
		for(j=0;j<=limncr;j++)
		{
			if(j>i) ncr[i][j]=0;
			else if(j==i || j==0) ncr[i][j]=1;
			else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
		}
	
	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{
		memset(mark,0,sizeof(mark));
		scanf("%d%d",&C,&N);
		if(N==C)
			printf("Case #%d: 1.000000\n",ks);
		else
			printf("Case #%d: %lf\n",ks,E(N)+1);
	}

	return 0;
}
