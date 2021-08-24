#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 200001
#define MAX_B  11

bool dp[2*MAX_NUM][MAX_B];
bool f[2*MAX_NUM][MAX_B];
int n, m;
int a[20];

bool Dp( int num, int base )
{
    if( f[num][base] ) return dp[num][base];
    f[num][base] = 1;
    if( num == 1 )
    {
        dp[num][base] = 1;
        return 1;
    }
    int t = num;
    int res = 0;
    while( t )
    {
        int temp = t % base;
        res += temp * temp;
        t /= base;
    }
    dp[num][base] = Dp( res, base );
    return dp[num][base];
}
int main( )
{
    freopen( "in.in", "r", stdin );
    freopen( "out.txt", "w", stdout );
    for( int i = 1; i < MAX_NUM; ++i )
        for( int j = 2; j < MAX_B; ++j )
            if( !f[i][j] ) Dp( i, j );
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i )
    {
        scanf( "%d", &m );
        for( int j = 0; j < m; ++j )
            scanf( "%d", &a[j] );
        for( int j = 2; j < MAX_NUM; ++j )
        {
            int flag = 0;
            for( int k = 0; k < m && !flag; ++k )
                if( !dp[j][a[k]] ) flag = 1;
            if( !flag )
            {
                printf( "Case #%d: %d\n", i + 1, j );
                break;
            } 
        }
    }
    return 0;
}


