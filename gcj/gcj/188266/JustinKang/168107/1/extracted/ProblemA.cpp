////////////////////////////////////////////////////////////////////////////////
//
// Google Codejam 2009
// Round ? - Problem A.
//
// Author : Kang, Jin-Kook, 2009.??.??
//
// * 
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
/*
*/

//ifstream fin("input.txt");
//#define cin fin

#define MAX_HAPPY	1000000
#define MAX_LENGTH	100

bool isHappyNumber( int base, int num, vector< int >& path )
{
	int sum = 0;

	if ( num == 1 ) return true;

	for ( int i = path.size() - 2; i >= 0; --i ) {
		if ( path[ i ] == num ) return false;
	}

	while ( num > 0 ) {
		int digit = num % base;
		num = num / base;
		sum += digit * digit;
	}

	path.push_back( sum );

	bool result = isHappyNumber( base, sum, path );

	path.pop_back();

	return result;
}

void calcHappyNumbers( int base, vector< int >& happy )
{
	vector< int > path;
	happy.resize( MAX_HAPPY + 1 );
	for ( int i = 2; i < MAX_HAPPY; ++i ) {
		if ( isHappyNumber( base, i, path ) )
			happy[ i ] = true;
			//happy.push_back( i );
	}
}

int main( int argc, char *argv[] )
{
	vector< int > happy[ 11 ];
	for ( int i = 2; i <= 10; ++i ) {
		calcHappyNumbers( i, happy[ i ] );
	}

	int count;
	cin >> count;

	char buf[ MAX_LENGTH + 1 ];
	cin.getline( buf, MAX_LENGTH + 1 );

	for ( int i = 1; i <= count; ++i ) {
		buf[ MAX_LENGTH + 1 ];
		cin.getline( buf, MAX_LENGTH + 1 );

		vector< int > bases;
		for ( size_t n = 0; n < strlen( buf ); ) {
			int base = atoi( buf + n );
			if ( base != 10 ) n += 2;
			else n += 3;
			bases.push_back( base );
		}

		int result = 0;
		for ( int num = 2; num < MAX_HAPPY; ++num ) {
			bool bFound = true;
			for ( vector< int >::const_iterator iter = bases.begin(); iter != bases.end(); ++iter ) {
				if ( happy[ *iter ][ num ] == false ) {
					bFound = false;
					break;
				}
			}
			if ( bFound ) {
				result = num;
				break;
			}
		}

		cout << "Case #" << i << ": " << result << endl;
	}

	return 0;
}
