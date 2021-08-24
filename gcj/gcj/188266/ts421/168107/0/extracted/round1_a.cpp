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












int convert_nbase( int num, int base ){

    int ret = 0;
    int shisuu = 1;
    vector <int> store;

    while( num > 0 ){
        store.push_back( num % base );
        num /= base;
    }

    for( int i = 0; i < store.size(); i++ ){
        ret += store[i] * shisuu;
        shisuu *= 10;
    }

    return ret;
}

vector <int>
divid_num( int num ){

    vector<int> ret;

    while( num > 0 ){
        ret.push_back( num % 10 );
        num /= 10;
    }

    return ret;
}

int calc_it( vector <int> num ){

    int ret = 0;

    for( int i = 0; i < num.size(); i++ ){
        ret += (num[i] * num[i]);
    }

    return ret;
}

int doit( vector<int> base ){
    
    int decimal = 2;
    int base_num;

    while( 1 ){
        int happy = 1;
        for( int i = 0; i < base.size(); i++ ){
            base_num = convert_nbase( decimal, base[i] );
            vector <int> store( 1, -1 );
            while( 1 ){
                vector <int> devided_num = divid_num( base_num );

                base_num = calc_it( devided_num );
                base_num = convert_nbase( base_num, base[i] );

                if( base_num == 1 ) break;

                for( int j = 0; j < store.size(); j++ ){
                    if( base_num == store[j] ){
                        happy = 0;
                        goto JUMP;
                    }
                }
                store.push_back( base_num );
            }
        }
JUMP: ;
        if( happy ) return decimal;
        
        decimal++;
    }

    return decimal;

}

int main()
{
    vector <int> cases = readMulti<int>();
    vector <int> base;
    
    int num_word = cases[0];

    for( int i = 0; i < cases[0]; i++ ){
        base = readMulti<int>();
        printf("Case #%d: %d\n", i+1, doit(base) );
    }

    /*
    for (int caseno = 1; caseno <= cases[2]; caseno++){
        string word = readOne<string>();
        printf("Case #%d: %d\n", caseno, doit( num_word, dictionary, word ) );
    }
    */
    
	return 0;
}
