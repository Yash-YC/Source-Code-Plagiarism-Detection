#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
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
#define INPUT "a-small.in"
#define OUTPUT "a-small.out"



LL baseconvert( int no , int k ) {
	LL ret = 0;
	LL ten = 1;
	while( no ) {
		ret += ten*(no%k);
		no /= k;
		ten *= 10;	
	}
	return ret;
}


bool ishappy( LL x , int base ) {
	map<LL,bool> seen;
	x = baseconvert( x , base );
	
	REP(i,5000){
		if( seen.count( x ) ) return false;
		seen[x] = 1;
		int sum = 0;
		while( x ) sum += (x%10)*(x%10) , x/= 10;
		x = baseconvert( sum  , base );
		if( x == 1 ) return true;
	}
	
	return false;
}


int main(){
	freopen( INPUT , "r" , stdin );
	freopen( OUTPUT , "w" , stdout );
	
	
	int T = GI;
	getchar();
	FOR(tt,1,T){
		VI bases;
		static char buffer[1024];
		gets( buffer );
		stringstream ss( buffer );
		int x;
		while( ss >> x ) bases.pb( x );

		for( int no = 2; ; ++no ) {
			bool ok = true;			
			EACH(it,bases) if( !ishappy( no , *it ) ){ ok = false;break;}
			if( ok ) {
				printf("Case #%d: %d\n" , tt , no );
				break;			
			}
		}

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
#include <sstream>
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
#define INPUT "a-small.in"
#define OUTPUT "a-small.out"



LL baseconvert( int no , int k ) {
	LL ret = 0;
	LL ten = 1;
	while( no ) {
		ret += ten*(no%k);
		no /= k;
		ten *= 10;	
	}
	return ret;
}


bool ishappy( LL x , int base ) {
	map<LL,bool> seen;
	x = baseconvert( x , base );
	
	REP(i,5000){
		if( seen.count( x ) ) return false;
		seen[x] = 1;
		int sum = 0;
		while( x ) sum += (x%10)*(x%10) , x/= 10;
		x = baseconvert( sum  , base );
		if( x == 1 ) return true;
	}
	
	return false;
}


int main(){
	freopen( INPUT , "r" , stdin );
	freopen( OUTPUT , "w" , stdout );
	
	
	int T = GI;
	getchar();
	FOR(tt,1,T){
		VI bases;
		static char buffer[1024];
		gets( buffer );
		stringstream ss( buffer );
		int x;
		while( ss >> x ) bases.pb( x );

		for( int no = 2; ; ++no ) {
			bool ok = true;			
			EACH(it,bases) if( !ishappy( no , *it ) ){ ok = false;break;}
			if( ok ) {
				printf("Case #%d: %d\n" , tt , no );
				break;			
			}
		}

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
#include <sstream>
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
#define INPUT "a-small.in"
#define OUTPUT "a-small.out"



LL baseconvert( int no , int k ) {
	LL ret = 0;
	LL ten = 1;
	while( no ) {
		ret += ten*(no%k);
		no /= k;
		ten *= 10;	
	}
	return ret;
}


bool ishappy( LL x , int base ) {
	map<LL,bool> seen;
	x = baseconvert( x , base );
	
	REP(i,5000){
		if( seen.count( x ) ) return false;
		seen[x] = 1;
		int sum = 0;
		while( x ) sum += (x%10)*(x%10) , x/= 10;
		x = baseconvert( sum  , base );
		if( x == 1 ) return true;
	}
	
	return false;
}


int main(){
	freopen( INPUT , "r" , stdin );
	freopen( OUTPUT , "w" , stdout );
	
	
	int T = GI;
	getchar();
	FOR(tt,1,T){
		VI bases;
		static char buffer[1024];
		gets( buffer );
		stringstream ss( buffer );
		int x;
		while( ss >> x ) bases.pb( x );

		for( int no = 2; ; ++no ) {
			bool ok = true;			
			EACH(it,bases) if( !ishappy( no , *it ) ){ ok = false;break;}
			if( ok ) {
				printf("Case #%d: %d\n" , tt , no );
				break;			
			}
		}

	}
	
	return 0;
}