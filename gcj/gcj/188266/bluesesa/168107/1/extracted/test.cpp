#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int size = 20000000;
int buf[11][size+1];
int getSum(int base,int data)
{
	int sum=0;
	int tmp;
	while(data!=0)
	{
		tmp = data % base;
		sum += tmp * tmp;
		data = data / base;
	}
	return sum;
}
void fill(int i,int j)
{
	
	if(buf[i][j] !=0 )
		return;
	int tmp;
	buf[i][j] = -1;	
	tmp = getSum(i,j);
	if(tmp == 1 || buf[i][tmp] == 1)
	{
		buf[i][j] = 1;		
	}
	else if(buf[i][tmp] == -1)
	{
		buf[i][j] = -1;		
	}
	else if(buf[i][tmp] == 0)
	{
		fill(i,tmp);
		buf[i][j] = buf[i][tmp];
	}
	
}
int main()
{
	int i,j,k;
	int n;
	char tmp[30];
	char *p;
	int data[10];
	int count;
	bool flag;
	memset(buf,0,sizeof(buf));
	
	for(i=2;i<=10;i++)
	{
		for(j=1;j<=size;j++)
		{			
			fill(i,j);			
		}
	}
	printf("ok!\n");
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		gets(tmp);
		count =0;
		p = strtok(tmp," \n");
		while(p)
		{
			data[count++] = atoi(p);
			p = strtok(NULL," \n");
		}
		
		for(j=2;j<=size;j++)
		{
			flag = true;
			for(k = 0;k<count;k++)
			{
				if(buf[data[k]][j] == -1)
				{
					flag = false;
					break;
				}
			}
			if(flag)
				break;
		}
		printf("Case #%d: %d\n",i,j);
		
	}
	return 0;
}