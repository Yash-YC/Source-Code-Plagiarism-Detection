#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>

using namespace std;

int a[111], n;
int p[11][100];

char str[1111], *s;
char res[1111];
int x;

int Go(int x, int d)
{
	int l1;

	set<int> SET;

	while(1)
	{
		itoa(x, res, d);
		int y = 0;
		for(l1=0;res[l1];l1++)
		{
			y += (res[l1] - '0') * (res[l1] - '0');
		}
		if(x == y) return 0;
		if(y == 1) return 1;
		if(SET.count(y)) return 0;
		SET.insert(y);
		x = y;
	}
	return 0;
}

int main(void)
{
	int T, l1, l0;

	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	for(l0=2;l0<=10;l0++)
	{
		p[l0][0] = 1;
		for(l1=1;l1<100;l1++)
		{
			p[l0][l1] = p[l0][l1-1] * l0;
		}
	}

	scanf("%d",&T);
	scanf("\r\n");
	for(l0=1;l0<=T;l0++)
	{
		gets(str);
		n = 0;
		for(s=strtok(str," ");s;s=strtok(NULL," "))
		{
			sscanf(s,"%d",&a[n]);
			n++;
		}

		for(x=2;;x++)
		{
			for(l1=0;l1<n;l1++)
			{
				if(Go(x, a[l1]) == 0)
				{
					break;
				}
			}
			if(l1 == n)
			{
				printf("Case #%d: %d\n",l0,x);
				break;
			}
		}
	}
}