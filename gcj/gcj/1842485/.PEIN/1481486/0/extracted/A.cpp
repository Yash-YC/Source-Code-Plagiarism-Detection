#pragma comment(linker, "/STACK:16777216")
#pragma warning(disable:4786)

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX_SIZE 100100
#define MAX_LENGTH 10001
#define INF ( 1 << 29 )

#define CLR( a ) memset( a , NULL , sizeof( a ) )
#define MEM( a ) memset( a , -1 , sizeof( a ) )
#define fort( a , b ) for( ind = ( a ) ; ind <= ( b ) ; ind++ )
#define foriab( a , b ) for( i = ( a ) ; i < ( b ) ; i++ )
#define fori( a ) for( i = 0 ; i < ( a ) ; i++ )
#define forj( a ) for( j = 0 ; j < ( a ) ; j++ )
#define print1( a ) printf( "%lld ---\n" , ( a ) )
#define print2( a , b ) printf( "%lld %lld ---\n" , ( a ) , ( b ) )

typedef long long lll ;

lll MIN( lll a , lll b ) { return a < b ? a : b ; }
int MAX( int a , int b ) { return a > b ? a : b ; }
int GCD( int a , int b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
int LCM( int a , int b ) { return a * ( b / GCD( a , b ) ) ; }
void SWAP( int &a , int &b ) { a = a ^ b ; b = a ^ b ; a = a ^ b ; }

const double PI = acos( -1 ) ;
const double EPS = 1e-11 ;

struct st {
    lll d , h ;
    bool operator () ( const st &a , const st &b ) {
        if( a.d == b.d ) {
            return a.h < b.h ;
        }
        return a.d < b.d ;
    }
} arr[ MAX_LENGTH ] , cmp ;

lll memo[ MAX_LENGTH ][ MAX_LENGTH ][ 2 ] , N ;
bool FL ;

lll dp( lll i , lll j , bool fl ) {
    if( i >= N ) {
        FL = 1 ;
        return 0 ;
    }
    lll &ret = memo[ i ][ j ][ fl ] ;
    if( ret != -1 ){
        return ret ;
    }
    lll res = 0 ;
    ret = 0 ;
    lll k ;
    for( k = 0 ; k <= N ; k++ ) {
        lll d = arr[ k ].d - arr[ i ].d ;
        lll e = arr[ i ].d - arr[ j ].d ;
        if( d < 0 ) {
            d *= -1 ;
        }
        if( e < 0 ) {
            e *= -1 ;
        }
        if( i != 0 ) {
            e = MIN( e , arr[ i ].h ) ;
        }
        else {
            e = arr[ i ].d ;
            e = MIN( e , arr[ i ].h ) ;
        }
        //printf( "%lld %lld :: %lld %lld :: %lld\n" , i , j , d , e , k ) ;
        if( d > 0 && d <= e ) {
            bool nfl = 0 ;
            if( k < i ) {
                nfl = 1 ;
            }
            //print2( k , i ) ;
            dp( k , i , nfl ) ;
        }
    }
    return ret = res ;
}

int main() {
    freopen( "as.in" , "r" , stdin ) ;
	freopen( "out.txt" , "w" , stdout ) ;
	lll T , res , n , i , ind , D ;
	scanf( "%lld" , &T ) ;
	fort( 1 , T ) {
		scanf( "%lld" , &n ) ;
		fori( n ) {
		    scanf( "%lld%lld" , &arr[ i ].d , &arr[ i ].h ) ;
		}
		scanf( "%lld" , &D ) ;
		arr[ n ].d = D ;
		arr[ n ].h = -1 ;
		//sort( arr , arr + n + 1 , cmp ) ;
		N = n ;
		FL = 0 ;
		MEM( memo ) ;
        res = dp( 0 , 0 , 0 ) ;
        if( FL ) {
            printf( "Case #%lld: YES\n" , ind ) ;
        }
        else {
            printf( "Case #%lld: NO\n" , ind ) ;
        }
	}
	return 0 ;
}
