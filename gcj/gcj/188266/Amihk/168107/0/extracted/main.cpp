#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <strstream>

using namespace std;

//const char* INPUT_FILE_NAME  = "A-large.in";
//const char* OUTPUT_FILE_NAME = "A-large.out";
const char* INPUT_FILE_NAME  = "A-small-attempt2.in";
const char* OUTPUT_FILE_NAME = "A-small-attempt2.out1";
//const char* INPUT_FILE_NAME  = "A-small.in";
//const char* OUTPUT_FILE_NAME = "A-small.out";

void ConvertDecNumberTo( vector<int>& outNumber, int inNumber, int base )
{
	outNumber.clear();
	outNumber.reserve( 10 );
	while( inNumber != 0 )
	{
		int c = inNumber % base;
		inNumber /= base;
		outNumber.push_back( c );
	}
}

bool IsEqual( const vector<int>& n1, const vector<int>& n2 )
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

bool IsHappyNumber( vector<int>& inNumber, int base, int depth )
{
	if( depth > 20 )
		return false;

	int squareSum = 0;
	for( unsigned int i = 0; i < inNumber.size() ; ++i )
	{
		squareSum += inNumber[ i ] * inNumber[ i ];
	}

	if( squareSum != 1 )
	{
		vector<int> newNumber;
		ConvertDecNumberTo( newNumber, squareSum, base );
		if( IsEqual( newNumber, inNumber ) )
			return false; 
		return IsHappyNumber( newNumber, base, depth + 1 );
	}
	else
	{
		return true;
	}
}

int GetOutput( const char* str )
{
	vector<int> bases;

	int maxBase = 0;
	istrstream stringStream( str );
	while(1)
	{
		int base = 0;
		stringStream >> base;
		if(stringStream.fail())
			break;
		if( base > maxBase )
			maxBase = base;
		bases.push_back(base);
	}

	int currentIndex = 2;
	while( 1 )
	{
		bool notHappyNumber = false;
		for( unsigned int i = 0; i < bases.size(); ++i )
		{
			vector<int> baseValue;
			ConvertDecNumberTo( baseValue, currentIndex, bases[ i ] );
			if( IsHappyNumber( baseValue, bases[ i ], 0 ) == false )
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

string getZeroPadding( int num )
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

int main()
{
	int N;
	string strOutput;
	string strInput;

	fstream inputFileStream(INPUT_FILE_NAME, ios_base::in);
	fstream outputFileStream(OUTPUT_FILE_NAME, ios_base::out|ios_base::trunc);
	outputFileStream.setf(ios_base::floatfield, ios_base::fixed);
	outputFileStream.precision(7);
	cout.setf(ios_base::floatfield, ios_base::fixed);
	cout.precision(7);

	inputFileStream >> N;

	char buffer[8192];
	inputFileStream.getline(buffer, 8192);

	for( int i = 0; i < N; ++i )
	{
		inputFileStream.getline(buffer, 8192);
		strInput = buffer;

		int count = GetOutput( buffer );

		outputFileStream << "Case #" << i+1 << ": " << count << endl;
		cout << "Case #" << i+1 << ": " << count << endl;
	}

	inputFileStream.close();
	outputFileStream.flush();
	outputFileStream.close();

	return 0;
}
