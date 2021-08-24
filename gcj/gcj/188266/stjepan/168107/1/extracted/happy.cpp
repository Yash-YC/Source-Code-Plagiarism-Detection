#include <algorithm>
#include <vector>
#include <string>

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char line[ 100 ];

int cookie = 1;
int bio[ 20000 ];

bool prec[ 11 ][ 20000 ];
int data[ 1 << 9 ];

bool brute( int x, int baza )
{
    ++cookie;

    while( bio[x] != cookie ) {
        if( x == 1 ) return true;
        bio[x] = cookie;

        int sum = 0;

        for( int y = x; y > 0; y /= baza ) {
            int z = y % baza;
            sum += z * z;
        }

        x = sum;
    }

    return false;
}

bool solve( int x, int baza )
{
    int sum = 0;

    for( int y = x; y > 0; y /= baza ) {
        int z = y % baza;
        sum += z * z;
    }

    if( sum == 1 ) return sum;
    return prec[baza][sum];
}

int main( void )
{
    for( int i = 2; i <= 10; ++i )
        for( int j = 2; j < 20000; ++j )
            prec[i][j] = brute( j, i );

    /*
    for( int mask = 1; mask < (1<<9); ++mask ) {
        fprintf( stderr, "mask = %d of %d\n", mask, (1<<9) );

        for( int i = 2; i < 100000000; ++i ) {
            bool ok = true;

            for( int j = 2; j <= 10; ++j )
                if( (mask>>(j-2))&1 )
                    ok &= solve( i, j );

            if( ok ) {
                printf( "%d\n", i );
                break;
            }
        }
    }
    
    return 0;
    */

    FILE *f = fopen( "data.txt", "r" );

    for( int mask = 1; mask < (1<<9); ++mask )
        fscanf( f, "%d", data + mask );

    int test; scanf( "%d\n", &test );

    for( int t = 0; t < test; ++t ) {
        fgets( line, 100, stdin );

        int mask = 0;

        for( char *c = line; *c; ++c ) {
            if( !isdigit( *c ) ) continue;
            if( *c == '0' ) continue;

            if( *c == '1' )
                mask |= 1 << 8;
            else
                mask |= 1 << (*c-'0'-2);
        }

        printf( "Case #%d: %d\n", t+1, data[mask] );
    }

    return 0;
}

