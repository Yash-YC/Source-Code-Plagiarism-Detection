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

int Pre()
{
	if(n == 6 && a[0] == 3 && a[1] == 6 && a[2] == 7 && a[3] == 8 && a[4] == 9 && a[5] == 10)
	{
		return 4817803;
	}
	if(n == 6 && a[0] == 3 && a[1] == 5 && a[2] == 7 && a[3] == 8 && a[4] == 9 && a[5] == 10)
	{
		return 346719;
	}
	if(n == 6 && a[0] == 3 && a[1] == 5 && a[2] == 6 && a[3] == 8 && a[4] == 9 && a[5] == 10)
	{
		return 28099;
	}
	if(n == 6 && a[0] == 3 && a[1] == 5 && a[2] == 6 && a[3] == 7 && a[4] == 9 && a[5] == 10)
	{
		return 711725;
	}
	if(n == 6 && a[0] == 3 && a[1] == 5 && a[2] == 6 && a[3] == 7 && a[4] == 8 && a[5] == 10)
	{
		return 2688153;
	}
	if(n == 6 && a[0] == 3 && a[1] == 5 && a[2] == 6 && a[3] == 7 && a[4] == 8 && a[5] == 9)
	{
		return 569669;
	}
	return 0;
}

int Go(int x, int d)
{
	int l1;

//	if(d == 2 || d == 4) return 1;

	if(d == 3)
	{
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
			if(y == 2 || y == 4) return 0;
			x = y;
		}
	}

	if(d == 5)
	{
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
			if(y == 4 || y == 16 || y == 10) return 0;
			x = y;
		}
	}

	if(d == 6)
	{
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
			if(y == 5) return 0;
			x = y;
		}
	}
	if(d == 7)
	{
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
			if(y == 2 || y == 4 || y == 17) return 0;
			x = y;
		}
	}
	if(d == 8)
	{
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
			if(y == 4 || y == 5 || y == 13) return 0;
			x = y;
		}
	}

	if(d == 9)
	{
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
			if(y == 89 || y == 74) return 0;
			x = y;
		}
	}
	if(d == 10)
	{
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
			if(y == 4) return 0;
			x = y;
		}
	}
	return 0;
}

int main(void)
{
	int T, l1, l0, l2;

	freopen("A2.in","r",stdin);
	
	freopen("A2.out","w",stdout);

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
			if(a[n] != 2 && a[n] != 4)
				n++;
		}
		
		if(n == 7)
		{
			printf("Case #%d: %d\n",l0,11814485);
			continue;
		}
		if(n == 6 && a[0] == 5)
		{
			printf("Case #%d: %d\n",l0,11814485);
			continue;
		}

		if(Pre())
		{
			printf("Case #%d: %d\n",l0,Pre());
			continue;
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