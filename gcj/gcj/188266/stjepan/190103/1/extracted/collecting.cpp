#include <algorithm>
#include <vector>
#include <string>

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;

long double choose[ 50 ][ 50 ];
long double dp[ 42 ][ 2000 ];

long double solve( int x, int step )
{
    if( step == 2000 ) return 0;
    if( x == n ) return 0;
    if( dp[x][step] > -0.5 ) return dp[x][step];

    long double sum = 0;
    long double cnt = 0;

    for( int i = 0; i <= min( n-x, m ); ++i ) {
        long double novi = choose[n-x][i];
        long double stari = choose[x][m-i];
        sum += novi * stari * ( 1 + solve( x + i, step + 1 ) );
        cnt += novi * stari;
    }

    return dp[x][step] = sum / cnt;
}

int main( void )
{
    for( int i = 0; i < 50; ++i )
        choose[i][0] = 1;

    for( int i = 1; i < 50; ++i )
        for( int j = 1; j < 50; ++j )
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];

    int test; scanf( "%d", &test );

    for( int t = 0; t < test; ++t ) {
        scanf( "%d %d", &n, &m );
        memset( dp, -1, sizeof dp );
        printf( "Case #%d: %Lf\n", t+1, solve( 0, 0 ) );
    }

    return 0;
}

