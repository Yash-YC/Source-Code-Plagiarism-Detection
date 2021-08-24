#include<stdio.h>

#define EPS 1e-12
int n, m;
int pack[3333], pn;
int ALL;
double pb;
int maxstep;

double A[1024][1024], b[1024], c[1024];
int nonzero[1024][1024], nn[1024];

int bc(int x)
{
	if(x == 0) return 0;
	if(x == 1) return 1;
	
	return bc(x >> 1) + (x & 1);
}

int main(void)
{
	int T;
	int l0, l1, l2, l3;
	int step;

	freopen("C1.in","r",stdin);
	freopen("C1.out","w",stdout);

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		fprintf(stderr,"..%d\n",l0);
		scanf("%d %d",&n,&m);
		pn = 0;
		for(l1=0;l1<(1<<n);l1++)
		{
			if(bc(l1) == m)
			{
				pack[pn++] = l1;
			}
		}
		pb = (double)1 / pn;
		ALL = (1 << n) - 1;
		for(l1=0;l1<(1<<n);l1++) for(l2=0;l2<(1<<n);l2++) A[l1][l2]=0;

		for(l1=0;l1<(1<<n);l1++)
		{
			for(l2=0;l2<pn;l2++)
			{
				int l3 = (l1 | pack[l2]);

				A[l3][l1] += pb;
			}
		}
		for(l1=0;l1<=ALL;l1++)
		{
			nn[l1] = 0;
			for(l2=0;l2<=ALL;l2++)
			{
				if(A[l1][l2] > EPS)
				{
					nonzero[l1][nn[l1]] = l2;
					nn[l1]++;
				}
			}
		}
		for(l1=0;l1<=ALL;l1++) b[l1] = c[l1] = 0;
		b[0] = 1;

		double ret = 0;
		for(step=1;step<=5000;step++)
		{
			for(l1=0;l1<=ALL;l1++) c[l1] = 0;
			for(l1=0;l1<=ALL;l1++)
			{
				//for(l2=0;l2<=ALL;l2++)
				for(l3=0;l3<nn[l1];l3++)
				{
					l2 = nonzero[l1][l3];
					c[l1] += A[l1][l2] * b[l2];
				}
			}
			ret += c[ALL] * step;
			for(l1=0;l1<=ALL;l1++)
			{
				b[l1] = c[l1];
			}
			b[ALL] = 0;
		}

		printf("Case #%d: %lf\n",l0,ret);
		fflush(stdout);
	}
}