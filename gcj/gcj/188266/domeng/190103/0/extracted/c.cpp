#include <stdio.h>
double comb[45][45];
double solve(int n,int c)
{
	double ex[50];
	ex[c]=0.0;
	for (int have=c-1;have>=0;have--)
	{
		ex[have]=1.0;
		int isR=0;
		double rev=0.0;
		for (int old=0;old<=have && old<=n;old++)
		{
			int got = n - old;
			if (have+got > c) continue;
			int vd = c - have;
			double p = comb[vd][got]*comb[have][old]/comb[c][n];
			if (got==0) { isR=1; rev=p; }
			else ex[have] += ex[have+got] * p;
		}
		if (isR) ex[have]/=(1-rev);
	}
	return ex[0];
}
int main()
{
	for (int q=0;q<=40;q++) for (int w=0;w<=q;w++)
	{
		if (w==0 || w==q) comb[q][w]=1.0;
		else comb[q][w]=comb[q-1][w-1]+comb[q-1][w];
	}
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,c;
		scanf("%d %d",&c,&n);
		printf("Case #%d: %.6lf\n",kase,solve(n,c));
	}
	return 0;
}
