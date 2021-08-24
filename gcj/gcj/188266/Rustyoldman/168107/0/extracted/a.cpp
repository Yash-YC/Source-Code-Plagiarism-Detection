// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// ****************************************************************************
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#define enld endl
using namespace std ;
// ****************************************************************************
void iter ( long long * dig , int & ndig , int base ) 
// ****************************************************************************
{
long long sum = 0 ;
for ( int d = 0  ; d < ndig ; d ++ )
   sum += dig[d]*dig[d] ;
dig[0] = sum%base ;
sum = sum/base ;
ndig = 1 ;
while ( sum > 0 )
   {
   dig[ndig] = sum%base ;
   sum = sum/base ;
   ndig ++ ;
   }
}
// ****************************************************************************
int happy ( int n , int base )
// ****************************************************************************
{
long long b1 [100] ;
long long b2 [100] ;
int nd1 ;
int nd2 ;

int m = n ;
nd1 = nd2 = 0 ;
while ( m > 0 )
   {
   b2[nd2] = b1[nd1] = m%base;
   m /= base ;
   nd1 ++ ;
   nd2 ++ ;
   }
      
int loop = 0 ;
while ( b1[0] != 1 || nd1 != 1 )
   {
   //   cout << b[0] << " " << nd << endl ;
   iter ( b1 , nd1 , base ) ;
   iter ( b2 , nd2 , base ) ;
   iter ( b2 , nd2 , base ) ;
//    cout << "sum1 " ;
//    for ( int j = nd1-1 ; j >= 0 ; j -- )
//       cout << b1[j] << " " ;
//    cout << endl ;

//    cout << "sum2 " ;
//    for ( int j = nd2-1 ; j >= 0 ; j -- )
//       cout << b2[j] << " " ;
//    cout << endl ;
   loop = (nd1 == nd2 ) ;
   for ( int j = 0 ; loop && j < nd2 ; j ++ )
      if ( b1[j] != b2[j] )
         loop = 0 ;
   if ( loop == 1 ) break ;
   
   }
if ( b1[0] == 1 && nd1 == 1 )
return 1 ;
return 0 ;
}
// ****************************************************************************
void do_case ( int cas )
// ****************************************************************************
{
cout << "Case #" << cas << ": " ;

int base [100] ;
int nb = 1 ;


int ch ;
base[0] = 0 ;
ch=cin.get() ;

while ( ch != '\n' )
   {
//    cout << "char " << (char) ch << " " << ch << endl ;
   
   if ( ch == ' ' )
      {
      ch = cin.get() ;
      base[nb] = 0 ;
//       cout << " space " << base[nb-1] << endl ;
      nb ++ ;
      }
   else if ( ch <= '9' && ch >= '0' ) 
      {
      base[nb-1] = base[nb-1]*10 + ch-'0' ;
//       cout << " num " << base[nb-1] << endl ;
      ch = cin.get() ;
      }
   }

// cout << "read " ;
// for ( int i = 0 ; i < nb ; i ++ )
//    cout << base[i] << " " ;
// cout << endl ;


int i = 2 ;
int hap ;

while ( 1 )
   {
   
   hap = 1 ;
   for ( int bi = nb-1 ; hap && bi >= 0 ; bi -- )
   {
   hap &= happy ( i , base[bi] ) ;
   }
   if ( hap )
      {
      cout << i << endl ;
      return ;
      }
   i ++ ;
   }

}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int n ;
cin >> n ;
int ch =  cin.get() ;

for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
