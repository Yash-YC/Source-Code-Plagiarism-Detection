#include <iostream>
using namespace std;

int bases[15];
bool visited[100000];

int getkey(char str[], int num[])
{
	int i,j,n=0;
	char c;

	for (i=0,j=0; str[i]; i++)
	{
		c = str[i];

		if (c==' ')
		{
			num[j++] = n;
			n = 0;
		}
		else
			n = 10*n + c-'0';
	}
	num[j] = n;
	return j+1;
}

bool calc(int num, int base)
{
	if(num==1)
		return true;
	if(num==0)
		return false;

	visited[num]=true;
	int n=num,nn=0;
	while(n)
	{
		nn += (n%base)*(n%base);
		n/=base;
	}
	if(visited[nn])
		return false;
	return calc(nn,base);
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tcase,t,i,b,num;
	char temp[100];
	bool flag;
	scanf("%d",&tcase);
	getchar();
	for(t=1;t<=tcase;t++)
	{
		gets(temp);
		b=getkey(temp,bases);
		num=2;
		flag = false;
		while(!flag)
		{
			for(i=0;i<b;i++)
			{
				memset(visited,0,sizeof(visited));
				if(!calc(num,bases[i]))
					break;
			}
			if(i==b)
				break;
			num++;
		}
		printf("Case #%d: %d\n",t,num);
	}
	return 0;
}