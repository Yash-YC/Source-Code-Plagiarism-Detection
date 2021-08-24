#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(i,0,x.size()) cout << x[i] << " "; cout << endl


template< typename type > type readOne()
{
    type res;
    char inp[5000];
    
    gets( inp );
    stringstream ss( inp );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char inp[5000];
    
    gets( inp );
    stringstream ss( inp );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

//
//
// LET'S START
//
//

int C, N;

#define ld long double
double memo[50];
ld kprob[50][50];

#define CSIZE 42
ld choose[ CSIZE+1 ][ CSIZE+1 ];
void choose_init()
{
    FOR( i, 0, CSIZE + 1 ) FOR( j, 0, CSIZE + 1 )
        choose[i][j] = 0;
    for ( int i = 0; i <= CSIZE; i++ ) {
        choose[i][0] = 1;
        for ( int j = 1; j <= i; j++ )
            choose[i][j] = ( choose[i-1][j-1] + choose[i-1][j] );
    }
}

ld kProbability( int C, int N, int cur, int k )
{
    if ( cur < k ) return 0;
    return ( choose[cur][k] * choose[C-cur][N-k] ) / choose[C][N];
}

double solve( int cur )
{
    if ( cur >= C ) return 0;
    double& res = memo[cur];
    if ( res >= -0.5 ) return res;
    
    double t = 0;
    
    // k = N “Á•Êˆµ‚¢
    // res = 1 + ‡”{0..N-1}P(k)*solve(cur+N-k) + P(N)*res
    // res = ( 1 + t ) / ( 1 - P(N) )
    for ( int k = 0; k < N; k ++ )
    {
        if ( kprob[cur][k] > 0 )
            t += kprob[cur][k] * solve( cur + N - k );
    }
    
    return res = ( 1 + t ) / ( 1 - kprob[cur][N] );
}

double doCase()
{
    double res;
    
    //
    // READ INPUT
    //
    
    VI tmp = readMulti<int>();
    C = tmp[0];
    N = tmp[1];
    
    
    //
    // DOIT!
    //
    if ( C <= N ) return 1;
    
    FOR( i, 0, 50 ) memo[i] = -1;
    
    choose_init();
    FOR( cur, 0, C )
        FOR( k, 0, N + 1 )
        {
            kprob[cur][k] = kProbability( C, N, cur, k );
        }
        
    return solve( 0 );
}

int main()
{
    int cases = readOne<int>();
	for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;

	return 0;
}

