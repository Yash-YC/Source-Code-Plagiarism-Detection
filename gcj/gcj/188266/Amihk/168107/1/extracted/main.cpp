#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <strstream>

using namespace std;

const char* INPUT_FILE_NAME  = "A-large.in";
const char* OUTPUT_FILE_NAME = "A-large.out";
//const char* INPUT_FILE_NAME  = "A-small-attempt0.in";
//const char* OUTPUT_FILE_NAME = "A-small-attempt0.out3";
//const char* INPUT_FILE_NAME  = "A-small.in";
//const char* OUTPUT_FILE_NAME = "A-small.out";

typedef map<unsigned int, bool> HAPPY_NUMBER;
map<unsigned int, HAPPY_NUMBER> happyNumberCache;

void AddToCache( unsigned int base, unsigned int number, bool IsHappyNumber )
{
	happyNumberCache[ base ].insert( make_pair( number, IsHappyNumber ) );
}

bool IsInCache( bool& value, unsigned int base, unsigned int number )
{
	map<unsigned int, bool>::const_iterator it = happyNumberCache[ base ].find( number );
	if( it != happyNumberCache[ base ].end() )
	{
		value = it->second;
		return true;
	}
	return false;
}

void ConvertDecNumberTo( vector<unsigned int>& outNumber, unsigned int inNumber, unsigned int base )
{
	outNumber.clear();
	outNumber.reserve( 2 );
	while( inNumber != 0 )
	{
		unsigned int c = inNumber % base;
		inNumber /= base;
		outNumber.push_back( c );
	}
}

bool IsEqual( const vector<unsigned int>& n1, const vector<unsigned int>& n2 )
{
	if( n1.size() != n2.size() )
		return false;
	for( unsigned int i=0 ; i<n1.size(); ++i)
	{
		if( n1[ i ] != n2[ i ] )
			return false;
	}
	return true;
}

bool IsHappyNumber( unsigned int currentIndex, unsigned int base, unsigned int depth )
{
	if( depth > 10 )
		return false;

	bool result;
	if( IsInCache( result, base, currentIndex ) )
	{
		return result;
	}

	vector<unsigned int> inNumber;
	ConvertDecNumberTo( inNumber, currentIndex, base );

	unsigned int squareSum = 0;
	for( unsigned int i = 0; i < inNumber.size() ; ++i )
	{
		squareSum += inNumber[ i ] * inNumber[ i ];
	}

	if( squareSum != 1 )
	{
		if( currentIndex == squareSum )
			result = false; 
		else
			result = IsHappyNumber( squareSum, base, depth + 1 );
	}
	else
	{
		result = true;
	}
	AddToCache( base, currentIndex, result );
	return result;
}

unsigned int GetOutput( const char* str )
{
	vector<unsigned int> bases;

	unsigned int maxBase = 0;
	istrstream stringStream( str );
	while(1)
	{
		unsigned int base = 0;
		stringStream >> base;
		if(stringStream.fail())
			break;
		if( base > maxBase )
			maxBase = base;
		bases.push_back(base);
	}

	unsigned int currentIndex = 2;
	unsigned int baseSize = bases.size();
	bool notHappyNumber;
	while( 1 )
	{
		notHappyNumber = false;
		for( unsigned int i = 0; i < baseSize; ++i )
		{
			if( IsHappyNumber( currentIndex, bases[ i ], 0 ) == false )
			{
				notHappyNumber = true;
				break;
			}
		}
		if( notHappyNumber == false )
			return currentIndex;
		++currentIndex;
	}

	return 0;
}

string getZeroPadding( unsigned int num )
{
	string zeros;
	if( num < 10 )
		return "000";
	else if( num < 100 )
		return "00";
	else if( num < 1000 )
		return "0";
	else
		return "";
};

unsigned int main()
{
	unsigned int N;
	string strOutput;
	string strInput;

	fstream inputFileStream(INPUT_FILE_NAME, ios_base::in);
	fstream outputFileStream(OUTPUT_FILE_NAME, ios_base::out|ios_base::trunc);
	outputFileStream.setf(ios_base::floatfield, ios_base::fixed);
	outputFileStream.precision(7);
	cout.setf(ios_base::floatfield, ios_base::fixed);
	cout.precision(7);

	inputFileStream >> N;

	for( unsigned int i = 2 ; i <= 10 ; ++i )
	{
		happyNumberCache.insert( make_pair( i, HAPPY_NUMBER() ) );
	}

	char buffer[8192];
	inputFileStream.getline(buffer, 8192);

	for( unsigned int i = 0; i < N; ++i )
	{
		inputFileStream.getline(buffer, 8192);
		strInput = buffer;

		unsigned int count = GetOutput( buffer );

		outputFileStream << "Case #" << i+1 << ": " << count << endl;
		cout << "Case #" << i+1 << ": " << count << endl;
	}

	inputFileStream.close();
	outputFileStream.flush();
	outputFileStream.close();

	return 0;
}
