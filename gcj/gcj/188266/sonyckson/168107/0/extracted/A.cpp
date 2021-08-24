#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <queue>
 
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
 
#define forn(i, n) for(int i=0;i<int(n);i++)
#define FOR(i, a, b) for(int i=(a);i<int(b);i++)
#define RFOR(i, b, a) for(int i=(b);i>int(a);i--)
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define ALL(x)   (x).begin(),(x).end()
#define SIZE(x)   (int)(x).size()
#define SORT(x) sort(ALL(x))
using namespace std;
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define ISS istringstream
#define OSS ostringstream
typedef long long ll;
// NUNCA DEFINIR int max....

bool okey(int n, int base)
{
       map<int,bool> seen;
       
       while( !seen[n] && n != 1 )
       {
	      seen[n] = true; 
	      int tot = 0;
// 	      printf("%i n" , n);
	      while( n ){ int a = n%base; tot += a*a; n /= base; }
// 	      printf("%i %i %i\n", n, tot,  base);
	      n = tot;
	      
	     
       }
       
       return n == 1 ;
}
       



int main()
{
       int i, j , k;
       int N;
       int bases;
       cin >> N;
       int casos = 0;
       while(getchar()!='\n');
       for( int h = 0 ; h < N ; h ++ )
       {
	      casos++;
	      bases = 0;
	      string s;
	      getline(cin, s);
	      istringstream iss(s);
	      
	      while( iss >> k )
	      {
		     bases |= ( 1 << k ) ;
	      }
	      bool ok = false;
	      for( i = 2; !ok; i ++ )
	      {
		     ok = true;
// 		     if( i > 3 ) break;	
		     for( j = 2;  ok &&  j <= 10; j ++ ) if( bases &(1<<j) )
		     {
			    if( !okey(i,j) ) ok = false;
		     }
		     if(ok) break;
	      }
	      cout << "Case #" << casos << ": " << i << endl;
       }return 0;
}
