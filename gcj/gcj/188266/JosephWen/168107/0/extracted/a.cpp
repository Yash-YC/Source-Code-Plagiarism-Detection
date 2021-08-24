#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
int bn;
int base[ 10 ];
char DP[ 10000000 ][ 10 ]; // 1 used, 2 happy 3 unhappy

int isHappy( int n, int base )
{
	int sum = 0;
	int org = n;
	int x;
	assert( n < 10000000 );
	if( DP[n][base] == 1 ) {
		DP[n][base] = 3;
		return 3;
	}
	if( DP[n][base] != 0 )
		return DP[n][base];
	DP[ n ][ base ] = 1;
	while( n > 0 ) {
		x = n % base;
		n /= base;
		sum += x * x;
	}
	if( sum == 1 )
		return DP[ org ][ base ] = 2;
	return DP[ org ][ base ] = isHappy( sum, base );
}
int main()
{
	int ccN;
	int d;
	char c;
	scanf(" %d ",&ccN);
	for( int cc=0;cc<ccN;cc++ ) {
		bn = 0;
		while( scanf("%d%c", &d, &c ) == 2 && c != '\n' )
			base[bn++] = d;
		base[bn++] = d;
		//for( int i=0;i<bn;i++ )
		//	printf( "%d\n", base[i] );
		int i=2;
		while( 1 ) {
			int j;
			for( j=0;j<bn;j++ ) {
				if( isHappy( i, base[j] ) != 2 )
					break;
			}
			if( j == bn )
				break;
			i++;
		}
		printf("Case #%d: %d\n", cc+1, i);
	}
}
