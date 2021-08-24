#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	freopen("inb1.in","r",stdin);
	freopen("outb1.txt","w",stdout);
	int i,j,t,test=0;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		test++;
		double n,c;
		scanf("%lf%lf",&c,&n);
		printf("Case #%d: ",test);
		if(n>=c)
		{
			printf("1.0000000\n");
			continue;
		}
		double s=0;
		s=(n+c)/n;
		printf("%.6f\n",s);
	}
	return 0;
}
