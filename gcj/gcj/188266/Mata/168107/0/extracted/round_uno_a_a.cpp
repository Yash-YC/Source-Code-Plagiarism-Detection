#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

#define MAX 100000

using namespace std;

bool is_happy( int n, int base );

int M[ 11 ][ MAX ];
bool T[MAX];

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    for( int i = 0; i < 11; ++i )
        for( int j = 0; j < MAX; ++j )
            M[i][j]=-1;
    int t, k = 0;
    scanf("%d", &t );
    while( k++ < t )
    {
        vector< int > base;
        char c;
        int d;
        while( scanf("%d", &d ) == 1 )
        {
            base.push_back( d );
            c = getchar();
            if( c == '\n' || c == EOF )
                break;
        }
        for( int n = 2; n < MAX; ++n )
        {
            bool solution = true;
            for( int i = 0; i < MAX; ++i )
                T[i]=false;
            for( int i = 0; i < base.size(); ++i )
            {
                if( !is_happy( n, base[i] ) )
                {
                    solution = false;
                    break;
                }
            }
            if( solution )
            {
                printf( "Case #%d: %d\n", k, n );
                break;
            }
        }
    }
    return 0;
}

bool is_happy( int n, int base )
{
    T[n] = true;
    if( M[ base ][ n ] != -1 )
    {
        if( M[ base ][ n ] == 1 )
            return true;
        return false;
    }
    int sum = 0;
    while( n > 0 )
    {
        sum += (n%base)*(n%base);
        n /= base;
    }
    if( M[ base ][ sum ] != -1 )
    {
        if( M[ base ][ sum ] == 1 )
            return true;
        return false;
    }
    if( sum == 1 )
    {
        M[ base ][ n ] = 1;
        M[ base ][ sum ] = 1;
        return true;
    }
    if( T[ sum ] && M[ base ][ sum ] != 1 )
    {
        M[ base ][ n ] = 2;
        M[ base ][ sum ] = 2;
        return false;
    }
    if( is_happy( sum, base ) )
    {
        M[ base ][ n ] = 1;
        M[ base ][ sum ] = 1;
        return true;
    }
    M[ base ][ n ] = 2;
    M[ base ][ sum ] = 2;
    return false;
}
/*
Case #1: 3879
Case #2: 97
Case #3: 7
Case #4: 97
Case #5: 219
Case #6: 216
Case #7: 2207
Case #8: 1001
Case #9: 79
Case #10: 1001
Case #11: 7
Case #12: 49
Case #13: 143
Case #14: 49
Case #15: 6393
Case #16: 47089
Case #17: 97
Case #18: 7
Case #19: 3
Case #20: 49
Case #21: 7
Case #22: 49
Case #23: 608
Case #24: 1177
Case #25: 6
Case #26: 23
Case #27: 27
Case #28: 3
Case #29: 23
Case #30: 27
Case #31: 143
Case #32: 27
Case #33: 8
Case #34: 6
Case #35: 79
Case #36: 3
Case #37: 34527
Case #38: 7
Case #39: 49
Case #40: 27
Case #41: 27
Case #42: 6
*/

