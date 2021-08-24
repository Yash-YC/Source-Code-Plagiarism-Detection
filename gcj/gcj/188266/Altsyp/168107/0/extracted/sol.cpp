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

  vi v ;

  int64 calc(int64 v, int base )
  {
    cerr << v << " " << base << endl;
    int64 ans = 0;
    while ( v > 0 )
    {
      ans += (v % base ) * ( v % base );
      v /= base;
    }
    cerr << ans << endl;
    return ans ;
  }

  bool check(int num)
  {                  
    cerr << num << endl;
    int64 tv;
    bool bd;
    forn( j , (int)v.size() )
    {
      tv = num;
      bd = false;
     // cerr << tv << endl;
      forn( i , 30 )
      {
        tv = calc( tv , v [j]);
    //    cerr << tv << endl;
        if ( tv == 1 ) 
        {
          bd = true;
          break;
        }
      }
    //  cerr << endl;
      if ( !bd ) return false;
    }
    cerr << endl;
    return true;
  }

  int t;

  int solve()
  {
    int tv = 2 ;
    while ( 1)
    {
      if ( check ( tv ) ) return tv; else tv ++;
    }
  }

int main()
{
  freopen ("log" , "w" , stderr );
  freopen("input.txt" ,"r" , stdin );
  freopen ("output.txt", "w", stdout );
  scanf ("%d\n" , &t );

  string s ;
  forn ( i , t )
  {
    v.clear();
    s.clear();
    
    getline ( cin, s );
    scanf ("\n");
    forn( j , (int)s.length () )
      if ( s [ j ] >= '2' && s [ j ] <= '9' ) v.pb ( s [ j ] - '0' );
       else if ( s [ j ] == '1' ) v.pb ( 10 );
    forn ( g , (int)v.size() )
      cerr << v [ g] << " " ;
    cerr << endl;
    int ans = solve();
    printf ("Case #%d: %d\n", i + 1 , ans );
  }
}
