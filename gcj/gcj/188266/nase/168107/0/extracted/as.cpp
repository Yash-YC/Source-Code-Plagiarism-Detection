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

int memo[11][1000000];

int good( int cand, int base, set<int>& foo )
{
    if ( cand == 1 ) return 1;
    if ( foo.count( cand ) ) return 0;
    foo.insert( cand );
    
    int next = 0;
    while ( cand )
    {
        int t = cand % base;
        next += t * t;
        cand /= base;
    }
    return good( next, base, foo );
}

int doCase()
{
    //
    // READ INPUT
    //
    VI bases = readMulti<int>();
    
    //
    // DOIT!
    //
    for ( int cand = 2; ; cand ++ )
    {
        bool ok = true;
        for ( int i = 0; i < bases.size(); i ++ )
        {
            set<int> foo;
            if ( !good( cand, bases[i], foo ) )
            {
                ok = false;
                break;
            }
        }
        if ( ok )
            return cand;
    }
    
    return -1;
}

int main()
{
    int cases = readOne<int>();
    memset( memo, -1, sizeof( memo ) );
	for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;

	return 0;
}

