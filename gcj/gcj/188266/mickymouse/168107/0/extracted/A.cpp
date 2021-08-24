#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char in[1005];
int bases[25], a[1005], n;

bool used[1000005];

void solve(int number, int b)
{
	n = 0;
	while(number)
	{
		a[n ++] = number % b;
		number /= b;
	}
	for(int i=0; i<n/2; i++)
	{
		int temp;
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}


int main()
{
   // freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
	int test, i, j, k, len, cases = 1;
	scanf("%d", &test);
	getchar();
	while(test --)
	{
		gets(in);
		len = 0;
		bases[len] = 0;
		for(i=0; in[i]!='\0'; i++)
		{
			if(in[i] >= '0' && in[i] <= '9')
				bases[len] = bases[len] * 10 + (in[i] - '0');
			else 
			{
				len ++;
				bases[len] = 0;
			}
		}
		len ++;
		for(i=2; ; i++)
		{
			bool flag = true;
			for(j=0; j<len; j++)
			{
				solve(i, bases[j]);
				memset(used, false, sizeof(used));
				while(1)
				{
					int num = 0;
					for(k=0; k<n; k++)
					{
						num = num + a[k] * a[k];
					}
					if(used[num])
						break;
					used[num] = 1;
					if(num == 1)
						break;
					solve(num, bases[j]);
				}
				if(!used[1])
					flag = false;
			}
			if(flag)
			{
				printf("Case #%d: %d\n", cases ++, i);
				break;
			}
		}
	}
	return 0;
}