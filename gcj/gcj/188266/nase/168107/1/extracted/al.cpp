#include "al.h"

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
set<int> good[11];

int doCase()
{
    int res;
    
    //
    // READ INPUT
    //
    VI tmp = readMulti<int>();
    VI bases;
    FOR( i, 0, tmp.size() )
        if ( tmp[i] != 2 && tmp[i] != 4 )
            bases.push_back( tmp[i] );
            
    if ( bases.size() == 0 ) return 2;
    
    //
    // DOIT!
    //
    for ( set<int>::iterator it = good[bases[0]].begin(); it != good[bases[0]].end(); it ++ )
    {
        int cand = *it;
        bool ok = true;
        for ( int i = 1; i < bases.size(); i ++ )
        {
            if ( good[bases[i]].count( cand ) == 0 )
            {
                ok = false;
                break;
            }
        }
        if ( ok ) return cand;
    }
    
    return -1;
}

int main()
{
    FOR( i, 0, sizeof( tbl3 ) / sizeof( int ) )
        good[3].insert( tbl3[i] );
        
    FOR( i, 0, sizeof( tbl5 ) / sizeof( int ) )
        good[5].insert( tbl5[i] );
        
    FOR( i, 0, sizeof( tbl6 ) / sizeof( int ) )
        good[6].insert( tbl6[i] );
        
    FOR( i, 0, sizeof( tbl7 ) / sizeof( int ) )
        good[7].insert( tbl7[i] );
        
    FOR( i, 0, sizeof( tbl8 ) / sizeof( int ) )
        good[8].insert( tbl8[i] );
        
    FOR( i, 0, sizeof( tbl9 ) / sizeof( int ) )
        good[9].insert( tbl9[i] );
        
    FOR( i, 0, sizeof( tbl10 ) / sizeof( int ) )
        good[10].insert( tbl10[i] );
    
    int cases = readOne<int>();
	for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;

	return 0;
}

