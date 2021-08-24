#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i,N) for(int i = 0;i < (N); ++i )
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it )
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define sz size()
#define pb push_back
#define mkp make_pair
#define INF (int(1e9))
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long int LL;

#define GI ({int t;scanf("%d",&t);t;})
#define INPUT "c-small.in"
#define OUTPUT "c-small.out"

double Memo[1024];
int Seen[1024], Seenid = 0, N , C;

double go( int bitset ) {
	if( Seen[bitset] == Seenid ) return Memo[ bitset ];
	Seen[bitset] = Seenid;	
	assert( Memo[ bitset ] > -1 ); // Check to avoid self-calling
	double& ret = Memo[ bitset ];
	ret = -1;
	if( bitset == (1<<C)-1 ) return ret = 0;
	
	double self = 0 , other = 0;
	double x = 0;
	REP(i,(1<<C)) if( __builtin_popcount( i ) == N ) {
		int next = ( bitset | i );
		if( next == bitset ) self++;
		else other++, x += go( next );
	}

	double pself = self / ( self + other ) , pother = 1 / other;
	assert( fabs(pself-1) > 1e-9 );
	ret = ( 1 + x * pother ) / ( 1 - pself );
	return ret;
}

int main(){
	freopen( INPUT , "r" , stdin );
	//freopen( OUTPUT , "w" , stdout );
	int T = GI;
	FOR(tt,1,T){
		C = GI, N = GI;
		++Seenid;		
		double r = go( 0 );
		printf("Case #%d: %.9lf\n", tt , r );
	}
	
	return 0;
}#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i,N) for(int i = 0;i < (N); ++i )
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it )
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define sz size()
#define pb push_back
#define mkp make_pair
#define INF (int(1e9))
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long int LL;

#define GI ({int t;scanf("%d",&t);t;})
#define INPUT "c-small.in"
#define OUTPUT "c-small.out"

double Memo[1024];
int Seen[1024], Seenid = 0, N , C;

double go( int bitset ) {
	if( Seen[bitset] == Seenid ) return Memo[ bitset ];
	Seen[bitset] = Seenid;	
	assert( Memo[ bitset ] > -1 ); // Check to avoid self-calling
	double& ret = Memo[ bitset ];
	ret = -1;
	if( bitset == (1<<C)-1 ) return ret = 0;
	
	double self = 0 , other = 0;
	double x = 0;
	REP(i,(1<<C)) if( __builtin_popcount( i ) == N ) {
		int next = ( bitset | i );
		if( next == bitset ) self++;
		else other++, x += go( next );
	}

	double pself = self / ( self + other ) , pother = 1 / other;
	assert( fabs(pself-1) > 1e-9 );
	ret = ( 1 + x * pother ) / ( 1 - pself );
	return ret;
}

int main(){
	freopen( INPUT , "r" , stdin );
	//freopen( OUTPUT , "w" , stdout );
	int T = GI;
	FOR(tt,1,T){
		C = GI, N = GI;
		++Seenid;		
		double r = go( 0 );
		printf("Case #%d: %.9lf\n", tt , r );
	}
	
	return 0;
}#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i,N) for(int i = 0;i < (N); ++i )
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it )
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define sz size()
#define pb push_back
#define mkp make_pair
#define INF (int(1e9))
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long int LL;

#define GI ({int t;scanf("%d",&t);t;})
#define INPUT "c-small.in"
#define OUTPUT "c-small.out"

double Memo[1024];
int Seen[1024], Seenid = 0, N , C;

double go( int bitset ) {
	if( Seen[bitset] == Seenid ) return Memo[ bitset ];
	Seen[bitset] = Seenid;	
	assert( Memo[ bitset ] > -1 ); // Check to avoid self-calling
	double& ret = Memo[ bitset ];
	ret = -1;
	if( bitset == (1<<C)-1 ) return ret = 0;
	
	double self = 0 , other = 0;
	double x = 0;
	REP(i,(1<<C)) if( __builtin_popcount( i ) == N ) {
		int next = ( bitset | i );
		if( next == bitset ) self++;
		else other++, x += go( next );
	}

	double pself = self / ( self + other ) , pother = 1 / other;
	assert( fabs(pself-1) > 1e-9 );
	ret = ( 1 + x * pother ) / ( 1 - pself );
	return ret;
}

int main(){
	freopen( INPUT , "r" , stdin );
	//freopen( OUTPUT , "w" , stdout );
	int T = GI;
	FOR(tt,1,T){
		C = GI, N = GI;
		++Seenid;		
		double r = go( 0 );
		printf("Case #%d: %.9lf\n", tt , r );
	}
	
	return 0;
}
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i,N) for(int i = 0;i < (N); ++i )
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it )
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define sz size()
#define pb push_back#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define REP(i,N) for(int i = 0;i < (N); ++i )
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it )
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define sz size()
#define pb push_back
#define mkp make_pair
#define INF (int(1e9))
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long int LL;

#define GI ({int t;scanf("%d",&t);t;})
#define INPUT "c-small.in"
#define OUTPUT "c-small.out"

double Memo[1024];
int Seen[1024], Seenid = 0, N , C;

double go( int bitset ) {
	if( Seen[bitset] == Seenid ) return Memo[ bitset ];
	Seen[bitset] = Seenid;	
	assert( Memo[ bitset ] > -1 ); // Check to avoid self-calling
	double& ret = Memo[ bitset ];
	ret = -1;
	if( bitset == (1<<C)-1 ) return ret = 0;
	
	double self = 0 , other = 0;
	double x = 0;
	REP(i,(1<<C)) if( __builtin_popcount( i ) == N ) {
		int next = ( bitset | i );
		if( next == bitset ) self++;
		else other++, x += go( next );
	}

	double pself = self / ( self + other ) , pother = 1 / other;
	assert( fabs(pself-1) > 1e-9 );
	ret = ( 1 + x * pother ) / ( 1 - pself );
	return ret;
}

int main(){
	freopen( INPUT , "r" , stdin );
	//freopen( OUTPUT , "w" , stdout );
	int T = GI;
	FOR(tt,1,T){
		C = GI, N = GI;
		++Seenid;		
		double r = go( 0 );
		printf("Case #%d: %.9lf\n", tt , r );
	}
	
	return 0;
}