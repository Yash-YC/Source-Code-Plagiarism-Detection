#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std ;

#define fv(i, s, n) for ( int i = s ; i < n ; i++ )
#define fb(i, n) fv (i, 0, n)
#define fe(i, n) fb (i, n.size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define fi(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)

typedef vector <int> vi ;
typedef pair<int, int> pii ;

int gf[20000000][15] ;

int hp ( int n, int b )
{
	if ( gf[n][b] != 0  ) return gf[n][b] ;
	if ( n == 1 ) return 1 ;
	
	int f = n ;
	int j = (f % b) * (f % b) ;
	while (f /= b) j += (f % b) * (f % b) ;
	
	gf[n][b] = 2 ;
	//cout << gf[n][b] << ' ' << n << ' ' << b << endl ;
	if ( hp(j, b) == 1 ) gf[n][b] = 1 ;
	
	return gf[n][b] ;
}

int solve ( vi p )
{
	for ( int h = 2 ; ; h++ )
	{
		bool g = false ;
		fe (i, p) if ( hp(h, p[i]) == 2 ) { g = true ; break ; }
		
		if ( !g ) return h ;
	}
}

int main()
{
	int t ;
	cin >> t ;
	
	stringstream a ;
	string g ;
	
	getline (cin, g) ;
	
	fb (i, t)
	{
		getline (cin, g) ;
		vi z ;
		
		while ( g.size() )
		{
			int h = atoi( g.c_str() ) ;
			z.pb (h) ;
			g.erase (0, (int)log10(h) + 2) ;
		}
		
		cout << "Case #" << i + 1 << ": " << solve(z) << endl ;
	}
}

