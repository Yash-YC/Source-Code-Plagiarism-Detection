#include <iostream>
#include <string>
using namespace std ;

int a[12] , m ;
int b[55] ;
bool check[100005] ;

bool Check( int ans )
{
     int i , j , t , k ;
     for( i = 0 ; i < m ; i ++ )
     {
          t = ans ;
          memset( check , 0 , sizeof(check) ) ;
          while( t != 1 ){
              if( check[t] ) 
                  return false ;
              check[t] = true ;
              k = 0 ;
              while( t > 0 ) 
              {
                     b[k++] = t%a[i] ;
                     t /= a[i] ; 
              }
              t = 0 ;
              for( j = 0 ; j < k ; j ++ )
                   t += b[j]*b[j] ;
          }
     }
     return true ;
}
int main(){
    freopen("A-small-attempt1.in","r",stdin) ;
    freopen("A-small-attempt1.out","w",stdout) ;
    int test , cnt ;
    scanf("%d" , &test ) ;
    getchar();
	cnt = 1 ;
    while( test -- )
    {
           int i ;
           m = 0 ;
           string s ;
           getline( cin , s ) ;
           int n = s.size() ;
           int t = 0 ;
           for( i = 0 ; i < n ; i ++ )
           {
                if( s[i] >= '0' && s[i] <= '9' )
                    t = t*10 + s[i] - '0' ;
                else
                {
                    if( t != 0 )
                    {
                        a[m++] = t ;
                        t = 0 ;
                    }
                }
           }
           if( t != 0 )
               a[m++] = t ;
           int ans = 2 ;
           while( !Check( ans ) )
           {
                  ans ++ ;
           }
           printf("Case #%d: %d\n" , cnt ++ , ans ) ;
    }
    return 0 ;
}
/*
3
2 3
2 3 7
9 10
*/
