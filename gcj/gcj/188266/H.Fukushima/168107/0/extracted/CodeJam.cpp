// CodeJam.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <tchar.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <vector>
#include <list>
#include <set>
#include <map>

#include <algorithm>
#include <numeric>

#include <cmath>
#include <limits>

using namespace std;


// -------------------------------------------------------------------------

//#if 0
#if 1

#include <windows.h>

class DebugStreambuf : public std::streambuf 
{
public:
	DebugStreambuf(void)
	{
		m_buf[0] = '\0' ;
		m_buf[1] = '\0' ;
	}

	virtual int_type overflow( int_type i_char = EOF )
	{
		if( i_char != EOF )
		{
			m_buf[0] = (char)i_char;
			OutputDebugString( m_buf );
		}
		return i_char;
	}

private:
	static const size_t BUFFER_SIZE = 2;
	char m_buf[BUFFER_SIZE];
};

class DebugStream : public std::ostream
{
public:
	DebugStream(void) : std::ostream( &m_buf )
	{}

private:
	DebugStreambuf m_buf;
};

DebugStream dout;

#endif

// -------------------------------------------------------------------------




template<typename To, typename From>
To lexical_cast(const From& i_from)
{
	To result;
	std::stringstream ss;

	ss << i_from;
	ss >> result;

	return result;
}


template<typename T> inline T (min)( const T& a , const T& b )                           { return a < b ? a : b ;                                                          }
template<typename T> inline T (min)( const T& a , const T& b , const T& c )              { return (math_lib::min)( (math_lib::min)( a , b ) , c ) ;                        }
template<typename T> inline T (min)( const T& a , const T& b , const T& c , const T& d ) { return (math_lib::min)( (math_lib::min)( a , b ) , (math_lib::min)( c , d ) ) ; }
template<typename T> inline T (max)( const T& a , const T& b )                           { return a > b ? a : b ;                                                          }
template<typename T> inline T (max)( const T& a , const T& b , const T& c )              { return (math_lib::max)( (math_lib::max)( a , b ) , c ) ;                        }
template<typename T> inline T (max)( const T& a , const T& b , const T& c , const T& d ) { return (math_lib::max)( (math_lib::max)( a , b ) , (math_lib::max)( c , d ) ) ; }

template<typename T> inline T clamp( const T& i_min , const T& i_value , const T& i_max ) 
{
#ifdef _DEBUG
	assert( i_min <= i_max );
#endif

	return (math_lib::min)( (math_lib::max)( i_min , i_value ) , i_max );
}


template<typename T> inline T pow2( const T& v ) { return v * v ;             }
template<typename T> inline T pow3( const T& v ) { return v * v * v ;         }
template<typename T> inline T pow4( const T& v ) { return pow2( v * v ) ;     }
template<typename T> inline T pow5( const T& v ) { return pow2( v * v ) * v ; }
template<typename T> inline T pow6( const T& v ) { return pow3( v * v ) ;     }
template<typename T> inline T pow7( const T& v ) { return pow3( v * v ) * v ; }
template<typename T> inline T pow8( const T& v ) { return pow4( v * v ) ;     }


template<typename T> inline T gcd( T a , T b )
{
	if( b > a ) (std::swap)( a , b );
	while( ( a = a % b ) != 0 ) (std::swap)( b , a );
	return b;
}

template<typename T> inline T lcm( const T& a , const T& b )
{
	return a * b / gcd( a , b );
}


#define foreach( TYPE_ , CONTAINER_ , ITERATOR_ ) for( TYPE_::iterator ITERATOR_ = (CONTAINER_).begin() ; ITERATOR_ != (CONTAINER_).end() ; ++ITERATOR_ )
#define c_foreach( TYPE_ , CONTAINER_ , ITERATOR_ ) for( TYPE_::const_iterator ITERATOR_ = (CONTAINER_).begin() ; ITERATOR_ != (CONTAINER_).end() ; ++ITERATOR_ )


// ------------------------------------------------------------------------


int getr(vector<int>& vals)
{
	int i = 2;
	for(;;i++)
	{
		bool bTrue = true;

		for( int j = 0 ; j < vals.size() ; ++j )
		{
			set<int> sums;
			
			int v = vals[j];

			vector<int> ve;
			{
				int x = i;
				for(;;)
				{
					ve.push_back( x % v );
					x /= v;
					if( x == 0 )break;
				}
			}

			for(;;)
			{
				int sum = 0;
				for( int k = 0 ; k < ve.size() ; ++k )
					sum += ve[k] * ve[k];
			
				if( sum == 1 ) break;

				if( sums.find( sum ) != sums.end() )
				{
					bTrue = false; break;
				}

				sums.insert(sum);

				ve.clear();
				for(;;)
				{
					ve.push_back( sum % v );
					sum /= v;
					if( sum == 0 )break;
				}
			}
		}

		if( bTrue ) return i;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int T;

	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	ifs >> T;

	//cout << T << endl;

	for( int i = 0 ; i < T ; ++i )
	{
		vector<int> vals;
		int result = 0;

		for(;;)
		{
			int v;
			ifs >> v;
			vals.push_back(v);

			if( ifs.peek() == '\n' ) break;
			if( ifs.eof() ) break;
		}

		result = getr(vals);

		//for( int j = 0 ; j < vals.size() ; ++j )
		//	cout << vals[j];
		//cout << endl;

		cout << "Case #" << (i+1) << ": " << result << endl;
		ofs << "Case #" << (i+1) << ": " << result << endl;
	}

	cout << "end" << endl;
	//getchar();

	return 0;
}

