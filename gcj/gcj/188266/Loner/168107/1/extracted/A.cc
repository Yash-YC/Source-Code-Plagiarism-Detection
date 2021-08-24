#include <cstdio>
#include <cstring>

#include <sstream>

using namespace std;

int bases;

bool visited[1000000][11];
bool _happy[1000000][11];

bool happy( int x, int base )
{
//	printf( "x = %d, base = %d\n", x, base );

	if( x >= 1000000 ) {
		int sd = 0, y = x;

		while( y ) {
			sd += (y%base) * (y%base);
			y /= base;
		}

		return happy(sd, base);
	}

	if( x == 1 ) return _happy[x][base] = true;
	if( visited[x][base] ) return _happy[x][base];

	visited[x][base] = true;
	_happy[x][base] = false;

	int sd = 0, y = x;

	while( y ) {
		sd += (y%base) * (y%base);
		y /= base;
	}

//	if (x == 3 && base == 2) printf("sd = %d\n", sd);

	return _happy[x][base] = happy(sd, base);
}

int main( void )
{
//	freopen( "A.in", "r", stdin );

	int prob, nprob; scanf( "%d", &nprob );
	char buff[1000]; gets( buff );

	for( prob = 0; prob < nprob; ) {
		gets( buff );

		istringstream strin(buff);
		int x;

		for( bases = 0; strin >> x; )
			bases |= 1<<x;

		//printf( "bases = %d\n", bases );

		memset(visited, false, sizeof(visited));

		int answer = 2;

//		printf( "%d\n", happy(3, 2) );

		for( ; ; ++answer ) {
			bool done = true;

			for( int x = 2; x <= 10; ++x )
				if( (bases & (1<<x)) && !happy(answer, x) ) {
					//printf( "answer = %d, x = %d\n", answer, x );
					done = false;
					break;
				}
			if( done ) break;
		}

		printf( "Case #%d: %d\n", ++prob, answer );
	}

	return 0;
}

