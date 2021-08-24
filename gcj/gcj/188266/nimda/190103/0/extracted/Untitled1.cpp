#include <stdio.h>
#include <stdlib.h>

int t;
double c, n;
int main( )
{
    freopen( "in.in", "r", stdin );
    freopen( "out.txt", "w", stdout );
    scanf( "%d", &t );
    for( int i = 0; i < t; ++i )
    {
       scanf( "%lf %lf", &c, &n );
       printf( "Case #%d: %lf\n", i + 1, 1 / ( 1 - ( c - n ) / c ) + c - n );
    }    
    return 0;
}



