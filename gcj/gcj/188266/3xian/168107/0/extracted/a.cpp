#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;


typedef long long LL;

//const double eps = 1e-5;
//const double PI = acos(-1.0);
//const int R = 32768;
//const int NIL = INF;
//const int INF = ~0u>>1;
//const int N = 500020;
//const int M = N * 2;



#define abs(a) ((a)<0?-(a):(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define clr(x) memset((x),0,sizeof(x))
//inline void minl(int &a,int b){if(a>b)a=b;}
//inline void maxl(int &a,int b){if(a<b)a=b;}


set< int > hs;

inline int sqr( int x )
{
	return x * x;
}

int trans( int x, int base )
{
	int ret( 0 );
	
	while ( x )
	{
		ret += sqr( x % base );
		x /= base;
	}
	
	return ret;
}

bool fea( int x, int base )
{
	//printf( "%d (%d)", x, base );
	
	int sum = 0;
	hs.clear();
	
	while ( 1 )
	{
		x = trans( x, base );
		
		//printf("%d\n",x);
		//system("pause");
		
		if ( x == 1 )
		{
			return true;
		}
		
		if ( hs.find( x ) == hs.end() )
		{
			//puts( "not found" );
			hs.insert( x );
		}
		else
		{
			//puts( "found" );
			return false;
		}
	}
}


char buf[1024];
int base[16];
int base_n;

int main()
{
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "A-small-attempt0.out", "w", stdout );
	
	
	int T;
	int cas;
	
	scanf( "%d", &T );
	while ( getchar() != 10 ) ;
	
	for ( cas = 1; cas <= T; cas++ )
	{
		gets( buf );
		
		char *p = buf;
		int slip;
		base_n = 0;
		
		while ( ~sscanf( p, "%d%n", &base[base_n], &slip ) )
		{
			++base_n;
			p += slip;
		}
		
		for ( int i = 2; ; i++ )
		{
			bool flag = true;
			
			for ( int j = 0; j < base_n; j++ )
			{
				if ( !fea( i, base[j] ) )
				{
					flag = false;
					break;
				}
			}
			
			if ( flag )
			{
				printf( "Case #%d: %d\n", cas, i );
				break;
			}
		}
	}
    
	return 0;
}
