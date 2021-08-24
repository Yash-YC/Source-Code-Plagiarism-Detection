// round1a A1.cpp
#include<iostream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<climits>
#include<cfloat>

using namespace std;
string convert( int n, int b );
bool ishappy( string number, int b )
{
    map<string, int> occured;
     while( true )
     {
//	 cout << number << endl;
	 int sum = 0;
	 for( int i = 0; i < number.size(); i++ )
	     sum += (number[i] - '0') * ( number[i] - '0' );
	 number = convert( sum, b );
	 if( number.size() == 1 && number[0] == '1' )
	     return 1;
	 if( occured[number] == 1 )
	     return 0;
	 else
	     occured[number] = 1;
     }
     if( number.size() == 1 && number[0] == '1' )
	 return 1;
     else
	 return 0;
}

string convert( int number, int base )
{
    string r;
    int x = number;
    while( number )
    {
	r += ( number % base ) + '0';
	number /= base;
    }
    reverse( r.begin(), r.end() );
    //cout << x << "->"  << r << endl;
    return r;
}

int main()
{
    int t;
    scanf( "%d", &t );
    getchar();
    for( int caseNo = 1; caseNo <= t; caseNo++ )
    {
	printf( "Case #%d: ", caseNo );
	vector<int> bases;
	string s;
	getline( cin, s );
	stringstream ss( s );
	int x;
	while( ss >> x )
	    bases.push_back( x );
	int i;
	for(  i = 2; ; i++ )
	{
	    bool ok = true;
	    for( int j = 0; j < bases.size(); j++ )
	    {
		if( !ishappy( convert( i, bases[j] ), bases[j] ) )
		    ok = false;
	    }
	    if( ok == true )
		break;
	}
	printf( "%d\n", i );

    }
    return 0;
}
