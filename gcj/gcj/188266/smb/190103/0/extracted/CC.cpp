#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include<math.h>
#include<sstream>
#include <algorithm>
using namespace std;
//ofstream fo("G:\\ASmallAns.txt",ios_base::out);
int main()
{
	long i,j,ij,ji,n,t,m,c;
	double p,q,x,y;
	double a[10],b[10],ans[50];
	//ofstream fo("G:\\CaAns.txt",ios_base::out);
	scanf("%d",&t);
	for (n=1;n<=t;n++)
	{
		scanf("%d%d",&c,&m);
		for (i=0;i<=c;i++)
			ans[i]=0;
		ans[m]=1;
		for (i=m;i<c;i++)
		{
			j=1;
			a[0]=i;
			a[1]=c-i;
			a[2]=m;
			a[3]=c-m;
			b[0]=c;
			b[1]=m-j;
			b[2]=i+j-m;
			b[3]=j;
			b[4]=c-i-j;
			for (ij=0;ij<4;ij++)
				if (a[ij]==0)
					a[ij]=1;
			for (ij=0;ij<5;ij++)
				if (b[ij]==0)
					b[ij]=1;
			p=1.0;ji=0;
			for (ij=0;ij<4;ij++)
			{
				while(p<100000000&&a[ij]>1.0)
				{
					p=p*a[ij];
					a[ij]=a[ij]-1;
				}
				while(p>1000)
				{
					while (ji<5&& b[ji]<=1.0)
						ji++;
					if (ji==5)
						break;
					p=p/b[ji];
					b[ji]=b[ji]-1;							
				}
			}
			for (ij=0;ij<5;ij++)
			{
				while(b[ij]>1.0)
				{
					p=p/b[ij];
					b[ij]=b[ij]-1;
				}
			}

			a[0]=i;			a[1]=1;			a[2]=1;			a[3]=c-m;	
			b[0]=c;			b[1]=i-m;			b[2]=1;			b[3]=1;
			b[4]=1;
			for (ij=0;ij<4;ij++)
				if (a[ij]==0)
					a[ij]=1;
			for (ij=0;ij<5;ij++)
				if (b[ij]==0)
					b[ij]=1;
			q=1.0;ji=0;
			for (ij=0;ij<4;ij++)
			{
				while(q<100000000&&a[ij]>1.0)
				{
					q=q*a[ij];
					a[ij]=a[ij]-1;
				}
				while(q>1000)
				{
					while (ji<5&& b[ji]<=1.0)
						ji++;
					if (ji==5)
						break;
					q=q/b[ji];
					b[ji]=b[ji]-1;							
				}
			}
			for (ij=0;ij<5;ij++)
			{
				while(b[ij]>1.0)
				{
					q=q/b[ij];
					b[ij]=b[ij]-1;
				}
			}
			
			ans[i+j]=ans[i+j]+(ans[i]+1)*p;
			x=ans[i]+2;y=q;

			while(p*x*y>0.0000000001)
			{
				ans[i+j]=ans[i+j]+p*x*y;
				x=x+1;
				y=y*q;
				
			}
			
		}
		printf("Case #%d: %lf\n",n,ans[c]);
	}
	//cin>>i;

	return 0;
}