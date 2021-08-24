#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

#define MAX 1500

int record[MAX][11];

void find( int, int );
bool ishappy( int, int );
main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	int i, j, cnt, t;
	int top, Num[512];
	int minimum[512];
	
	memset ( record, -1, sizeof ( record ) );
	memset ( minimum, -1, sizeof ( minimum ) );
	for ( i = 2; i < 1000; i ++ ){
		cnt = 0;
		for ( j = 2; j < 11; j ++ ){
			if ( record[i][j] == -1 )
				find( i, j );
			if ( record[i][j] == 1 )
				cnt += ( 1 << ( j - 2 ) );
		}
		if ( minimum[cnt] == -1 )
			minimum[cnt] = i;
	}
	for ( i = 1000; i < 11814486; i ++ ){
		cnt = 5;
		for ( j = 3; j < 11; j ++ )
			if ( j != 4 && ishappy ( i, j ) )
				cnt += ( 1 << ( j - 2 ) );
		if ( minimum[cnt] == -1 )
			minimum[cnt] = i;
	}
	
	for ( i = 0; i < 512; i ++ ){
		cnt = 11814485;
		for ( j = 0; j < 512; j ++ )
			if ( ( i & j ) == i )
				if ( minimum[j] != -1 && cnt > minimum[j] )
					cnt = minimum[j];
		minimum[i] = cnt;
	}
	
	int tt = 0, a;
	char readin[1000];
	string str;
	scanf ( "%d", &t );
	gets( readin );
	while( t -- ){
		gets( readin );
		str = readin;
		istringstream is( str );
		
		cnt = 0;
		while( is >> a )
			cnt += ( 1 << ( a - 2 ) );
		printf( "Case #%d: %d\n", ++ tt, minimum[ cnt ] );
	}
	
	return 0;
}

int sqr( int x ){
	return x * x;
}

void find( int a, int b ){
	if ( a == 1 ){
		record[a][b] = 1;
		return;
	}
	
	int ret = 0;
	int tmp = a;
	while( tmp ){
		ret += sqr( tmp % b );
		tmp /= b;
	}
	record[a][b] = -2;
	if ( record[ret][b] == -2 ){
		record[a][b] = 0;
		return;
	}
	if ( record[ret][b] != -1 ){
		record[a][b] = record[ret][b];
		return;
	}
	
	find( ret, b );
	record[a][b] = record[ret][b];
}

bool ishappy( int a, int b ){
	int ret = 0;
	int tmp = a;
	while( tmp ){
		ret += sqr( tmp % b );
		tmp /= b;
	}
	
	if ( ret < 1000 )
		return record[ret][b] == 1;
	else
		return ishappy( ret, b );
}
