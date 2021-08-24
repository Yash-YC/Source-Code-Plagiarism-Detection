// Welcome to Code Jam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h" 
#define MAX 502
#define MAX2 21
bool *l=new bool[1000];
bool is(int a,int b)
{
	int t=a,i,d,r=0;
	memset(l,0,1000);
	while(1)
	{
		r=0;
        for(i=a;i!=0;i=i/b)
		{
			d=(i%b);
            r+=d*d;
		}
		if(r==1)
			return true;
		else if(r==t||l[r]!=0)
			return false;
		a=r;
		l[a]=1;
	}
}
int main()
{
	int i,j,k,ts,m;
	FILE *in; in=fopen("d:\\A-large.in.txt","r");
	FILE *out;
	out=fopen("d:\\A-large.out.txt","w");
	char s[MAX],t[10],tc=0;
	int ba[10],bs=0;

	/*

	if(is(143,7))
		printf("true");
	else
		printf("false");
	if(is(143,3))
		printf("true");
	else
		printf("false");
	if(is(143,2))
		printf("true");
	else
		printf("false");
*/
	bool get=false;
	fscanf(in,"%d",&ts);
	fgets(s,MAX,in);//jump the first number line
	for(k=1;k<=ts;k++)
	{
		fgets(s,MAX,in);
		tc=0;
		bs=0;
		for(i=0;i<MAX;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
		      t[tc++]=s[i];
			else if(s[i]==' ')
			{
				t[tc]='\0';
				tc=0;
                ba[bs++]=atoi(t);
			}
			else if(s[i]=='\0'||s[i]=='\n')
			{
				t[tc]='\0';
				tc=0;
                ba[bs++]=atoi(t);
				break;
			}
		}
		for(j=2;;j++)
		{
			get=true;
			if(is(j,ba[bs-1]))
			{
				for(m=bs-2;m>=0;m--)
				{
					if(is(j,ba[m])==false)
					{
						get=false;
						break;
					}
				}
				if(get==true)
					break;
			}
			//printf("%d false\n",j);
		}
		fprintf(out,"Case #%d: %d\n",k,j);
		//printf("Case #%d: %d\n",k,j);
		//fprintf(out,"Case #%d: %04d\n",k,dp[l][19]);
	}
	
 
}