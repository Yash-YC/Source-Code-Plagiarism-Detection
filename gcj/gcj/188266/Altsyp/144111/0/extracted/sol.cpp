#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <ctime>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin() ,a.end()

typedef long long int64;
typedef pair <int , int > pii;
typedef pair <double , double > pdd;
typedef vector<int > vi;

const double eps = 1e-9;

int64 t [ 30 ] [30 ] [ 4 ] ;
int s [ 30 ] [ 30 ] , w [ 30 ][ 30 ] , tt [ 30 ][30] ;
int n , m ;
int c ;

void go ( int i , int j , int k )
{
  int64 ttt , ws , ww ; 
     ttt = (t [ i ] [ j ] [ k ] - tt [i ] [ j ] ) % (w [i ] [ j ] + s [ i ] [ j ]);
     if ( ttt < 0 ) ttt += s [ i ] [ j ] + w [ i ] [ j ] ;
     if ( ttt < s [ i ] [ j ] )
     {
       ws = 0;
       ww = s [ i ] [ j ] - ttt;
     } else
     {
       ww = 0;
       ws = s [ i ] [ j ]+ w [ i ] [ j ] - ttt;
     }
  

  if ( k == 0 )
  {
     if ( i < n - 1 && t [i + 1 ] [ j ] [ 1 ] > t[ i ] [ j ] [ k ] + 2 )  
     {
        t [i + 1 ] [ j ] [ 1 ] = t [ i ] [ j ] [ k ] + 2 ;
        go ( i + 1 , j , 1 );
     }
     if ( j > 0 && t [ i ][ j - 1 ] [ 2 ] > t [ i ] [ j ] [ k ] + 2 )
     {
       t [i ] [ j - 1 ] [ 2 ] = t [i ] [ j ] [ k ] + 2 ;
       go ( i , j - 1 , 2 );
     }
     if ( t [i ][ j ] [ 1] > t [i ] [ j ] [ k ] + ws + 1 )
     {
       t [i ] [ j ] [ 1 ] = t [ i ] [ j ] [ k ] + ws + 1 ;
       go ( i , j , 1 );
     } 
     if ( t [i ][ j ] [ 2] > t [i ] [ j ] [ k ] + ww + 1 )
     {
       t [i ] [ j ] [ 2 ] = t [ i ] [ j ] [ k ] + ww + 1 ;
       go ( i , j , 2 );
     }
  }

  if ( k == 1 )
  {
     if ( i > 0 && t [i -1 ] [ j ] [ 0 ] > t[ i ] [ j ] [ k ] + 2 )  
     {
        t [i - 1 ] [ j ] [ 0 ] = t [ i ] [ j ] [ k ] + 2 ;
        go ( i - 1 , j , 0 );
     }
     if ( j > 0 && t [ i ][ j - 1 ] [ 3 ] > t [ i ] [ j ] [ k ] + 2 )
     {
       t [i ] [ j - 1 ] [ 3 ] = t [i ] [ j ] [ k ] + 2 ;
       go ( i , j - 1 , 3 );
     }
     if ( t [i ][ j ] [ 0] > t [i ] [ j ] [ k ] + ws + 1 )
     {
       t [i ] [ j ] [ 0 ] = t [ i ] [ j ] [ k ] + ws + 1 ;
       go ( i , j , 0 );
     } 
     if ( t [i ][ j ] [ 3] > t [i ] [ j ] [ k ] + ww + 1 )
     {
       t [i ] [ j ] [ 3 ] = t [ i ] [ j ] [ k ] + ww + 1 ;
       go ( i , j , 3 );
     }
  }

  if ( k == 2 )
  {
     if ( i < n - 1 && t [i + 1 ] [ j ] [ 3 ] > t[ i ] [ j ] [ k ] + 2 )  
     {
        t [i + 1 ] [ j ] [ 3 ] = t [ i ] [ j ] [ k ] + 2 ;
        go ( i + 1 , j , 3 );
     }
     if ( j <m-1 && t [ i ][ j + 1 ] [ 0 ] > t [ i ] [ j ] [ k ] + 2 )
     {
       t [i ] [ j + 1 ] [ 0 ] = t [i ] [ j ] [ k ] + 2 ;
       go ( i , j + 1 , 0 );
     }
     if ( t [i ][ j ] [ 3] > t [i ] [ j ] [ k ] + ws + 1 )
     {
       t [i ] [ j ] [ 3 ] = t [ i ] [ j ] [ k ] + ws + 1 ;
       go ( i , j , 3 );
     } 
     if ( t [i ][ j ] [0] > t [i ] [ j ] [ k ] + ww + 1 )
     {
       t [i ] [ j ] [ 0 ] = t [ i ] [ j ] [ k ] + ww + 1 ;
       go ( i , j , 0 );
     }
  }

  if ( k == 3 )
  {
     if ( i > 0 && t [i - 1 ] [ j ] [ 2 ] > t[ i ] [ j ] [ k ] + 2 )  
     {
        t [i - 1 ] [ j ] [ 2 ] = t [ i ] [ j ] [ k ] + 2 ;
        go ( i - 1 , j , 2 );
     }
     if ( j < m-1 && t [ i ][ j + 1 ] [ 1 ] > t [ i ] [ j ] [ k ] + 2 )
     {
       t [i ] [ j + 1 ] [ 1 ] = t [i ] [ j ] [ k ] + 2 ;
       go ( i , j + 1 , 1 );
     }
     if ( t [i ][ j ] [ 2] > t [i ] [ j ] [ k ] + ws + 1 )
     {
       t [i ] [ j ] [ 2 ] = t [ i ] [ j ] [ k ] + ws + 1 ;
       go ( i , j , 2 );
     } 
     if ( t [i ][ j ] [ 1] > t [i ] [ j ] [ k ] + ww + 1 )
     {
       t [i ] [ j ] [ 1 ] = t [ i ] [ j ] [ k ] + ww + 1 ;
       go ( i , j , 1 );
     }
  }




} 

int main()
{
  freopen("input.txt" ,"r" , stdin );
  freopen ("output.txt", "w", stdout );
  freopen ("log", "w" , stderr );
  scanf ("%d", &c );
  forn ( g , c )
  {
    scanf ("%d%d" , &n , &m );
    forn ( i , n )
      forn ( j , m )
        forn ( k , 4 )
          t [ i ] [ j ] [ k ] = (int64)1e20;
    t[ n-1 ] [ 0 ][ 0 ] = 0;
    forn( i , n )
      forn( j , m )
        scanf ("%d%d%d" , &s [ i ] [ j ] , &w [ i ] [ j ] , &tt[ i][ j ] );
    go ( n-1 ,0, 0);
    forn  ( i , n )
    {
       forn ( j ,m )
         {
           cerr << "( ";
           forn( k , 4 )
             cerr << t [ i ] [j ] [k ] << " " ;
           cerr << ")";
         }
       cerr << endl;
    }
    cerr << "case done" << endl;

    cout << "Case #" << g + 1 << ": "<< t [ 0 ] [ m - 1 ][ 3] << endl;
  }


}
