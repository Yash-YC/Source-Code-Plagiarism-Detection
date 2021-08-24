#include<stdio.h>
#include<string.h>
#define MAX 10000000000
int min[20];
bool v[100000];
int b[20],m;
bool happy(int x,int y)                //x进制，数为y
{

	int sum,temp,bit;
	temp=y;
	memset(v,false,sizeof(v));
	while(1)
	{
		sum=0;
		while(temp)
		{
			bit=temp%x;
			temp/=x;
			sum+=bit*bit;
		}
		temp=sum;
		if(v[temp])
			break;
		if(temp==1)
			break;
		v[temp]=true;
		if(temp>m)
			m=temp;
	}
	return temp==1;
}
int main()
{	
	int n,t,i,k,j;
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	scanf("%d",&t);
	getchar();
	for(k=1;k<=t;++k)
	{
		m=0;
		scanf("%d",&b[0]);
		n=1;
		while(getchar()!='\n')
			scanf("%d",&b[n++]);
		for(j=2;;++j)
		{
			for(i=0;i<n;++i)
				if(!happy(b[i],j))
					break;
				if(i==n)
					break;
		}
		printf("Case #%d: %d\n",k,j);
	//	printf("%d\n",m);
	}
	return 0;
}
