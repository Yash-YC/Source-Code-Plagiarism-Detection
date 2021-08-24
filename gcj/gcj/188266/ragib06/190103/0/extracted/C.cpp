#include <iostream>
using namespace std;

int C,N;
double E;

int com(int n,int k)
{
	int comb=1,m;

	if(k>n/2)
		k=n-k;

	for(m=1; m<=k; m++)
	{
		comb *= n;
		comb /= m;
		n--;
	}

	return comb;
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tcase,t;

	scanf("%d",&tcase);

	for(t=1;t<=tcase;t++)
	{
		scanf("%d %d",&C,&N);
		E=0;
		if(N==C)
			E=1.00;
		else
		{
			E = 1 + (C*1.0)/N;
		}
		printf("Case #%d: %0.7lf\n",t,E);
	}
	return 0;
}