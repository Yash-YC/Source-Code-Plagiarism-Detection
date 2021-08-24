#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*fo;
	fp=fopen("B-small-attempt0.in","r");
	fo=fopen("B-one2.txt","w");
	int t,m=1;
	fscanf(fp,"%d",&t);
	while(t--)
	{
		int n,x;
		fscanf(fp,"%d",&n);
		int a[2501],i;
		for(i=0;i<2501;i++)
		{
			a[i]=0;
		}
		for(i=0;i<n*((2*n)-1);i++)
		{
			fscanf(fp,"%d",&x);
			a[x]++;
		}
		fprintf(fo,"Case #%d:",m);
		m++;
		for(i=0;i<2501;i++)
		{
			if(a[i]%2==1 && a[i]!=0)
			{
				fprintf(fo," %d",i);
			}
		}
		fprintf(fo,"\n");
	}
}
