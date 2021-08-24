#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

double prb[2][1<<10];
int mark[2][1<<10];
double prm[11];
int t,c,n;

int main ()
{
	freopen ("a.in", "r", stdin);
	freopen ("b.out", "w", stdout);

	prm[1]=1;
	for (int i=2;i<=10;i++)
	prm[i]=prm[i-1]*i;
		

	scanf ("%d", &t);

	for (int cas=1;cas<=t;cas++)
	{
		memset(mark,-1,sizeof(mark));
		scanf ("%d%d", &n ,&c);
		double res=0;
		
		prb[1][0]=1;
		mark[1][0]=0;
		double ps=1.0/(prm[n]/(prm[c]*prm[n-c]));
		int all=0;
		for (int i=0;i<n;i++)
			all|=(1<<i);

		for (int i=1;i<=100;i++)

		{
			int a=i%2;
			int b=!a;

			for (int mask1=0;mask1<(1<<n)-1;mask1++)
				if (mark[a][mask1]==i-1 && prb[a][mask1]>0)
				for (int mask2=1;mask2<(1<<n);mask2++)
				{
					int bits=0;
					for (int k=0;k<n;k++)
						bits+=(mask2>>k)&1;

					if (bits==c)
					{
						int mask3=mask1|mask2;
						if (mark[b][mask3]!=i)
						{
							prb[b][mask3]=0;
							mark[b][mask3]=i;
						}

						prb[b][mask3]+=prb[a][mask1]*ps;
					}
				}
			res+=prb[b][all]*i;
		}
		if (c==n)
			res=1;
		cout.precision(7);
		cout<<fixed<<"Case #"<<cas<<": "<<res<<endl;
	}


	return 0;
}
