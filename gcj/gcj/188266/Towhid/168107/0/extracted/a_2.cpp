#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define SZ 2000000

bool store[11][SZ];

int convert(int n, int b)
{
	if(n < b)
		return n;
	return(convert(n / b, b) * 10 + n % b);
}


bool visited[1000];

bool is_happy(int n, int b)
{
	memset(visited, false, sizeof(visited));
	int k = n;
	int sum = 0;
	int temp;
	int prev = k;
	if(k < 1000)
		visited[k] = true;
	while(true)
	{
		while(k)
		{
			temp = ((k % b) * (k % b));
			sum += temp;
//			sum = convert(sum, b);
			k /= b;
		}
		if(sum == 1)
			return true;
		if(sum == prev || visited[sum] == true)
		{
			return false;
		}
		if(sum < SZ * 10)
			visited[sum] = true;
		k = sum;
		prev = k;
		sum = 0;
	}
	if(k == 1)
		return true;
	return false;
}

int main()
{
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("A-small.out", "wt", stdout);
	char line[1000];
	char *ptr;
	int num[15];
	int i, j;
/*	memset(store, false, sizeof(store));
	
	for(i = 2; i < 11; i++)
	{
		for(j  = 2; j < 200; j++)
		{
			store[i][j] = is_happy(j, i);
		}
	}
	*/
	int kase, inp;
	scanf("%d", &inp);
	gets(line);
	for(kase = 1; kase <= inp; kase++)
	{
		gets(line);
		i = 0;
		ptr = strtok(line, " ");
		while(ptr != NULL)
		{
			num[i++] = atoi(ptr);
			ptr = strtok(NULL, " ");
		}
		int tot = i;
		for(j = 2;  ; j++)
		{
			for(i = 0; i < tot; i++)
			{
				if(!is_happy(j, num[i]))
					break;
			}
			if(i == tot)
				break;
		}
		//if(j < SZ)
			printf("Case #%d: %d\n", kase, j);
		//else
		//	printf("Not in SZ\n");
	}
	return 0;
}
