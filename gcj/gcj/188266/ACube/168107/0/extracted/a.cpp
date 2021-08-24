/*
	Author: Ali-Amir Aldan
	Problem: Multi-base happiness
	Contest: Google Code Jam Round 1
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPower( int x, int base )
{
	int t=0;
	while( x )
	{
		t+=x%base;
		x/=base;
	}
	if( t==1 )
		return 1;
	else
		return 0;
}

int MBase( int x, int base )
{
	int t=0;
	while( x )
	{
		t+=( x%base )*( x%base );
		x/=base;
	}
	return t;
}

bool isHappy( int x, int base )
{
	bool b[ 3000 ]={ 0 };
	while( true )
	{
		if( b[ x ] )
		{
			return 0;
		}
		b[ x ]=1;
		if( isPower( x, base ) )
			return 1;
        	x=MBase( x, base );
	}
}

int res, T, x, top, a[ 100 ];
bool b;
char c;

int main()
{
	freopen( "input.txt","r",stdin );
	freopen( "output.txt","w",stdout );
	scanf( "%d\n",&T );
	for( int sw=0;sw<T;sw++ )
	{
		memset( a,0,sizeof( a ) );
		top=0;
		for( char c=' ';c!='\n'; )
		{
			scanf( "%d%c",&x,&c );
			a[ top++ ]=x;
		}
		for( int i=2;i<1000000;i++ )
		{
			b=1;
			for( int j=0;j<top;j++ )
				if( !isHappy( MBase( i, a[ j ] ), a[ j ] ) )
				{
					b=0;
					break;
				}
			if( b )
			{
				res=i;
				break;
			}
		}
		printf( "Case #%d: %d\n", sw+1, res );
	}
	return 0;
}
