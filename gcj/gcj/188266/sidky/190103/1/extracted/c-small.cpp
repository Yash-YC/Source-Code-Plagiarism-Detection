#include <iostream>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

#define	sz(v)	(int)v.size()
#define	rep(i,n)	for((i)=0;(i) < (n); (i)++)
#define	rab(i,a,b)	for((i)=(a);(i) <= (b); (i)++)
#define	Fi(N)		rep(i,N)
#define	Fj(N)		rep(j,N)
#define	Fk(N)		rep(k,N)

long long	ncr[100][100];
double	ex[100];

int main()
{
	int	T,cs;
	int	i,j;
	int	C,N;
	double	prob;

	rab(i,0,50) ncr[i][0] = 1;
	rab(i,1,50) rab(j,1,50) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];

	scanf("%d",&T);

	rab(cs,1,T)
	{
		scanf("%d %d",&C,&N);
		ex[C] = 0.0;

		prob = 1.0 / ncr[C][N];

		for(i = C - 1; i >= 0; i--)
		{
			ex[i] = 0;

			for(j = 0; j < N && j <= i; j++)
			{
				if(i + N - j > C) continue;
				double	curr = ncr[i][j];
				curr *= prob;
				curr *= ncr[C - i][N - j];

				ex[i] += curr * (1 + ex[i + N - j]);
			}

			if(i >= N)
			{
				double	p = ncr[i][N] * prob;
				ex[i] = (ex[i] + p) / (1 - p);
			}

		}

		printf("Case #%d: %.10lf\n",cs,ex[0]);
	}
	return 0;
}
