#pragma warning (disable:4786) 
#pragma warning (disable:4996) 
#include <time.h>
#include <algorithm> 
#include <iostream>  
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <stack>
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <cassert>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
#define FILL(a,b) memset(a, (b), sizeof(a));
typedef long long ll; 
const double EPS = 1e-7;

void openfiles() {
	#ifndef ONLINE_JUDGE
		freopen("A-small-attempt0.in","rt",stdin);
		freopen("test.out","wt",stdout);   
	#endif
}

const int MAX = 600000;
const int BASES = 10;
int ismagic[BASES + 1][MAX];

void find_magics ( int base ) {
	map < int , vector < int > > mp;
	typedef vector < int >::iterator ITER;
	for (int i = 2; i < MAX; i++) {
		int ii = i;
		int u = 0;
		if ( base == 9 && i == 91 ) {
			int stop = i;
		}

		while ( ii ) {
			u += ( ii % base ) * ( ii % base );
			ii /= base;
		}

		//if ( i % 100000 == 0 )
		//	cout << i << endl;

		if ( u == 1 || ismagic [ base ] [ u ] == 1 ) {
			ismagic [ base ] [ i ] = 1;
			queue < int > q;
			q.push ( i );
			while ( !q.empty () ) {
				int k = q.front ();
				q.pop ();
				ismagic [ base ] [ k ] = 1;
				for ( ITER jj = mp [ k ].begin (); jj != mp [ k ].end (); ++jj) {
					q.push ( *jj );
				}
				mp [ k ].clear ();
			}
		}
		else if ( u != i ) {
			mp [ u ].push_back ( i );
		}

	}
}

int answers[ 1 << 9 ];

void precalc () {
	for (int i = 2; i <= BASES; i++) {
		find_magics ( i );
		//cout << i << endl;
	}

	//for (int i = 2; i <= BASES; i++) {
	//	for (int j = 2; j <= 91; j++) {
	//		cout << ismagic [ i ] [ j ] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 2; i < MAX; i++) {
		int bits = 0;
		for (int j = 2; j <= BASES; j++) {
			bits |= ( ismagic [ j ] [ i ] << ( j - 2 ) );
		}
		if ( answers [ bits ] == 0 ) {
			answers [ bits ] = i;
			//cout << bits << " " << i << endl;
		}
	}

}

void solve() {
	char line [ 1000 ];
	gets ( line );
	stringstream ss ( line );
	int u = 0, bits = 0;
	while ( ss >> u ) {
		bits |= ( 1 << ( u - 2 ) );
	}

	int best = MAX;
	for (int i = 0; i < (1 << 9); i++) {
		if ( ( i & bits ) == bits && answers [ i ] ) {
			best = min ( best, answers [ i ] );
		}
	}

	static int test = 0;

	printf("Case #%d: %d\n", ++test, best);
}

int main() {
	precalc ();

	//freopen ( "test.in", "wt", stdout );
	//for (int i = 0; i < ( 1 << 9 ); i++) {
	//	for (int j = 0; j < 9; j++) {
	//		if ( ( i >> j ) & 1 ) {
	//			cout << (2 + j) << " ";
	//		}
	//	}
	//	cout << endl;
	//}
	//return 0;

	openfiles();
	int n;
	scanf("%d ",&n);
	REP(i,n) solve();

	return 0;
}