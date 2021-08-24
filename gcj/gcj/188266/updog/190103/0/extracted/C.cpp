#include <myheading.h>

void SetFile( string s )
{
	while( s.size()>0 && s[0]<=' ' ) s.erase( 0, 1 ) ;
	while( s.size()>0 && s[s.size()-1]<=' ' ) s.erase( s.size()-1 ) ;
	string::size_type p = s.find('.') ;
	if( p!=string::npos ) s = s.substr( 0, p ) ;
	string sin  = s+".in" ;  freopen( sin. c_str() , "r" , stdin  );
	string sout = s+".out";  freopen( sout.c_str() , "w" , stdout );
}

#define myfor(i,c,d) for( int i=(c); i<=(d); ++i )

const int MAXN = 41  ;

double C[ MAXN+1 ][ MAXN+1 ];
void comb( int n )
{
	int i,j;
	memset( C, 0, sizeof(C[0])*(n+1) );
	C[0][0] = 1 ;
	for( i=1; i<=n; ++i )
		for( C[i][0]=C[i][i]=1, j=1; j+j<=i; ++j )
			C[i][i-j] = C[i][j] = C[i-1][j] + C[i-1][j-1] ;
}

int n, k ;

void readin()
{
	cin>>n>>k ;
}

double f[ MAXN+1 ] ;

void dp( int s )
{
	int i ;
	int mini = max( 0, k-s ) ;
	int maxi = min( k, n-s ) ;

	double c0, sum, c ;
	
	c0 = 0 ;
	sum = 0 ;
	for( i = mini ; i<=maxi; ++i )
	{
		c = C[ n-s ][ i ] * C[ s ][ k-i ] / C[ n ][ k ] ;

		if( i == 0 ) c0 = c ;
		else sum = sum + c * f[ s+i ] ;
	}

	f[s] = ( 1 + sum ) / ( 1 - c0 ) ;
}

void work()
{
	myfor( i, 0, n ) f[i] = -1 ;
	f[n] = 0 ;

	for( int i=n-1; i>=0 ; --i ) dp( i ) ;

	printf("%.9lf\n",f[0]) ;
}


int main()
{
	SetFile( "         C-small-attempt0         " ) ;

	int test ; cin>>test ; readln();
	cerr<<"n_test = "<<test<<endl;

	comb( 40 ) ;

	myfor( _u, 1, test )
	{ 
		cout<<"Case #"<<_u<<": ";
		cerr<<"Running on Case #_"<<_u<<endl ;

		readin() ;
		work() ;
		//cout<<ans<<endl;

	}

	if( !seekeof( cin ) ) cout<<("wrong")<<endl;

	fclose( stdin ); fclose( stdout );
	return 0;
}
