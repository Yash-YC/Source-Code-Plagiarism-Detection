#include <iostream>

using namespace std ;
int a[1025] ;
double dp[2][1025] ;
int Count( int c , int n )
{
       int i ;
       if( c - n < n )
           n = c - n ;
       int p = 1 , t = n ;
       for( i = c ; i > c - n ; i -- )
       {
            p *= i ;
            while( t != 1 && p%t == 0 )
            {
                   p /= t ;
                   t -- ;
            }
       }
       return p ;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int test , t ;
    scanf("%d" , &test ) ;
    t = 1 ;
    while( test -- )
    {
           int n , c , m , i , j , cnt , k ;
           scanf("%d%d" , &c , &n ) ;
           m = 0 ;
           int up = 1<<c ;
           for( i = 0 ; i < up ; i ++ )
           {
                cnt = 0 ;
                for( j = 0 ; j < 10 ; j ++ )
                     if( i&(1<<j) )
                         cnt ++ ;
                if( cnt == n )
                    a[m++] = i ;
           }
           int p = Count( c , n ) ;
           double reg = 1.0/p ;
           for( i = 0 ; i < m ; i ++ )
                dp[0][a[i]] = reg ;
           int d = 0 ;
           double ans = 0 ;
           if( dp[0][up-1] )
               ans += dp[0][up-1] ;
           for( i = 2 ; i <= 1000 ; i ++ )
           {
                for( j = 0 ; j < up ; j ++ )
                     dp[1-d][j] = 0 ;
                for( j = 0 ; j < up - 1 ; j ++ )
                {
                     if( dp[d][j] )
                     {
                         for( k = 0 ; k < m ; k ++ )
                              dp[1-d][j|a[k]] += dp[d][j]*reg ;
                     }
                }
                if( dp[1-d][up-1] )
                {
                    ans += dp[1-d][up-1]*i ;
                }
                d = 1 - d ;
           }
           printf("Case #%d: %.5lf\n" , t ++  , ans ) ;
    }
    return 0 ;
}
/*
10
2 1
3 2
*/
