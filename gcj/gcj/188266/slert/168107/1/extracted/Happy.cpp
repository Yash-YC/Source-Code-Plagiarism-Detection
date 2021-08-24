#include <cstdio>
#include <cstring>
#define MAXR 11814490

int happyful[MAXR];
int happy[MAXR];
int stack[MAXR],t;

int main()
{
	int testIndex, testCount;
	scanf("%d\n", &testCount);

	int i,j,k,x,a,sum;

	for(i = 2; i <= 10; i++)
	{
		happy[1] = 1;
		for(j = 2; j < MAXR; j++)happy[j] = 0;
		for(j = 2; j < MAXR; j++)
		{
			t = 0;
			stack[t++] = j;
			while(happy[stack[t-1]] == 0)
			{
				happy[stack[t-1]] = -1;
				sum = 0;
				x = stack[t-1];
				a;
				while(x>0)
				{
					a = x%i;
					x = x/i;
					sum += a*a;
				}
				if(sum >= MAXR)return 0;
				stack[t++] = sum;
			}
			x = happy[ stack[t-1] ];
			if(x == 1)
			{
				for(k = 0; k < t; k++)
				{
					happyful[ stack[k] ] |= (1<<i);
					happy[ stack[k] ] = 1;
				}

			}
		}
	}

	char buf[100];
	char *buf2;
	int findx;
	int len;
	for(testIndex = 1; testIndex <= testCount; testIndex++)
	{
		gets(buf);
		buf2 = buf;
		findx = 0;
		len = strlen(buf);
		while(sscanf(buf2, "%d", &i))
		{
			findx |= (1<<i);
			if(i < 10){ buf2+=2; len-=2;}
			else {buf2+=3; len-=3;}
			if(len < 0)break;
		}
		printf("Case #%d: ", testIndex);
		for(i = 2; i < MAXR; i++)
		{
			if((happyful[i] & findx) == findx)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}