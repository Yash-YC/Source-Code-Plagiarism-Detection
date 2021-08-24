#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<conio.h>

#define REPEAT 100

void openfiles( FILE **fin, FILE **fout )
{
	char filename[32] = "";
	char infile[32];
	char outfile[32];

	printf( "filename: " );
	scanf( "%s", filename );
	strcpy( infile, filename );
	strcpy( outfile, filename );
	
	strcat( infile, ".in" ); 
	strcat( outfile, ".out" );
	
	*fin = fopen( infile, "r" );
	*fout = fopen( outfile, "w" );
}


int sumdigit( int number, int base )
{
	int res;
	int d;

	res = 0;
	while( number )
	{
		d = number % base;
		res += (d*d);
		number = number / base;
	}

	return res;
}


int ishappy( int number, int base )
{
	int i;

	for( i=0; i<REPEAT; i++ )
	{
		number = sumdigit( number, base );
		if( number == 1 )
			return 1;
	}
	
	return 0;
}


int main()
{
	FILE *fin;
	FILE *fout;
	int T;
	int i, k, j, t, r;
	unsigned int max = -1;
	int bases[10];
	int happy[10];
	char c;


	openfiles( &fin, &fout );

	fscanf( fin, "%d\n", &T );
	for( i=0; i<T; i++ )
	{
		k = 0;

		do
		{
			fscanf( fin, "%d", &bases[k++] );
		}
		while( fgetc( fin ) != '\n' && !feof( fin ) );


		for( j=2; j<max; j++ )
		{
			memset( happy, 0, sizeof(int)*10 );

			for( t=0; t<k; t++ )
			{
				happy[t] = ishappy( j, bases[t] );
			}

			r = 0;
			for( t=0; t<k; t++ )
				r += happy[t];
			
			if( r == t )
			{
				printf( "Case #%d: %d\n", i+1, j );
				fprintf( fout, "Case #%d: %d\n", i+1, j );
				break;
			}
		}
	}

	fclose( fin );
	fclose( fout );

	getch();
	return 0;
}