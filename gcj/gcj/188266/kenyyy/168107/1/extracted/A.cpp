#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int q[100];
int n;
int flag[11][1000000];
int val[11][1000000];

int search( int a, int b)
{
	if( b >= 100000 )
	{
		printf("ERROR\n");
		return 1;
	}
	if( flag[a][b] == 1 )
	{
		return val[a][b];
	}
	flag[a][b] = 1;
	if( b == 1 )
	{
		val[a][b] = 1;
		return 1;
	}
	int temp = 0;
	int bb = b;
	while( b )
	{
		int t = b % a;
		temp += t*t;
		b /= a;
	}
	val[a][bb] = search(a,temp);
	return val[a][bb];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int ca;
	int i,j;
	for( ca = 1; ca <= T; ca ++ )
	{
		memset(flag, 0, sizeof(flag));
		memset(flag, 0, sizeof(val));
		n = 0;
		scanf("%d", &q[n++]);
		while( getchar() != '\n' )
		{
			scanf("%d", &q[n++]);
		}
		for( i = 0; i < n; i ++ )
		{
			for( j = 2; j < 100000; j ++ )
			{
				search(q[i], j);
			}
		}
		for( j = 2; j < 100000; j ++ )
		{
			for( i = 0; i < n ;i ++ )
			{
				if( val[q[i]][j] == 0 )
					break;
			}
			if( i == n )
				break;
		}
		printf("Case #%d: %d\n", ca, j);
		
	}
	return 0;
}