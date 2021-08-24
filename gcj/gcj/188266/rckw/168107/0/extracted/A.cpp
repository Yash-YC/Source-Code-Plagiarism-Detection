#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_n=(b);i<=_n;i++)
#define FORD(i,a,b) for(int i=(a),_n=(b);i>=_n;i--)
#define REP(i,n) FOR(i,0,n-1)
typedef long long int64;
#define two(X) (1<<(X))
#define two64(X) (((int64)1)<<(X))
#define contain(S,x) (((S)&two(x))>0)

int numb[15];
int nnum;

char str[105];
int f[505000][15];
int vis[505000];

int solve( int n, int b ) {
	int &ret = f[n][b];
	if ( ret!=-1 ) return ret;

	if ( n==1 ) return 1;
	if ( vis[n] )
		return 0;
	
	ret = 0;
	
	int t=n;
	int xs[10];
	int nxs=0;

	while ( t>0 ) {
		xs[nxs++] = t%b;
		t/=b;
	}
	
	vis[n] = 1;
	t=0;
	REP(j,nxs)
		t += xs[j]*xs[j];
	
	ret = solve( t,b );
	vis[n] = 0;

	return ret;
}

int main() {
	freopen( "A.in", "r", stdin );
	freopen( "A.out", "w", stdout );
	int ntc;
	scanf( "%d",&ntc );
	getchar();
	REP(tc,ntc) {
		gets(str);
		nnum=0;
		int len=strlen(str);
		int ii=0;
		while ( ii<len ) {
			if ( str[ii]>='0' && str[ii]<='9' ) {
				int nuu=0;
				while ( str[ii]>='0' && str[ii]<='9' )
					nuu = nuu*10 + (str[ii]-'0'), ii++;
				numb[nnum++] = nuu;
			}
			else ii++;
		}
		int x=2;
		memset( vis,0,sizeof(vis) );
		memset( f,-1,sizeof(f) );

		while ( 1 ) {
			int found=1;
			REP(i,nnum) {
				if ( !solve(x,numb[i]) ) {
					found=0;
					break;
				}
			}
			if  (found) break;
			x++;
		}
		printf( "Case #%d: %d\n",tc+1, x );
	}
	return 0;
}
