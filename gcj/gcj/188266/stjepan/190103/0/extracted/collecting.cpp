#include <algorithm>
#include <vector>
#include <string>

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;

double dp[ 1 << 10 ][ 200 ];

double solve( int mask, int step )
{
    if( step == 200 ) return 0;
    if( mask == (1<<n)-1 ) return 0;
    if( dp[mask][step] > -0.5 ) return dp[mask][step];

    double sum = 0;
    int cnt = 0;

    for( int i = 0; i < (1<<n); ++i ) {
        if( __builtin_popcount( i ) != m ) continue;
        ++cnt, sum += 1 + solve( mask | i, step+1 );
    }

    return dp[mask][step] = sum / cnt;
}

int main( void )
{
    int test; scanf( "%d", &test );

    for( int t = 0; t < test; ++t ) {
        scanf( "%d %d", &n, &m );
        memset( dp, -1, sizeof dp );
        printf( "Case #%d: %lf\n", t+1, solve( 0, 0 ) );
    }

    return 0;
}

