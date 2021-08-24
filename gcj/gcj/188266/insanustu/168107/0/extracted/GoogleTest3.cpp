#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

std::vector<unsigned> stack;
bool isHappy( unsigned num, unsigned base )
{
	if ( num == 1 )
		return true;
	if ( std::find(stack.begin(), stack.end(), num ) != stack.end() )
		return false;
	stack.push_back(num);
	unsigned sum = 0;
	unsigned rest = num;
	while(rest > 0 )
	{
		unsigned ost = rest % base;
		sum += ost * ost;
		rest /= base;
	}
	return isHappy( sum, base );
}
void SolveTask( const char* inputFileName, const char* outputFileName )
{
	std::ifstream inFile( inputFileName );
	std::ofstream oFile( outputFileName );

	// initialization
	unsigned N(0);
	inFile >> N;

	std::string bufStr;
	std::getline( inFile, bufStr );
	for( unsigned i = 0; i < N; i++ )
	{
		std::getline( inFile, bufStr );
		std::istringstream iStr( bufStr );
		std::list<unsigned> bases;
		unsigned curBase(0);
		while(!iStr.eof())
		{
			iStr >> curBase;
			bases.push_back(curBase);
		}
		bases.remove(0);
		bases.remove(2);
		unsigned res(0);
			bool isFinded = false;
			res = 1;
			while(!isFinded)
			{
				res++;
				for( std::list<unsigned>::iterator it = bases.begin(); it != bases.end(); it++ )
				{
					stack.clear();
					if ( !isHappy( res, *it ))
					{
						isFinded = false;
						break;
					}
					isFinded = true;
				}
			}
		oFile << "Case #" << ( i+1 )<< ": " << res << std::endl;
	}
}

void main()
{
	SolveTask( "d:/1.txt", "d:/2.txt");
}