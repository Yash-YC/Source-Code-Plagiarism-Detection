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

const int MaxX = 5000000 ;

int f[ MaxX+1 ][ 10+1 ] ;
int maxno ;

bool used[ 1001 ] ;
int check( int x, int base )
{
	int &re = f[x][base] ;
	if( re != -1 ) return re ;
	if( x <= 1 ) return re = x==1 ;

	int sum = 0 ;
	while( x > 0 )
	{
		sum += ( x%base ) * ( x%base ) ;
		x /= base ;
	}

	if( used[sum] ) return re = 0 ;
	used[sum] = true ;

	return re = check( sum, base ) ;
}

vector<int> a ;

void readin()
{
	a.clear() ;
	while( !seekeoln() )
	{
		int t ;
		cin>>t ;
		a.push_back( t ) ;
	}

	readln() ;
}

void work()
{
	bool ok ;
	int x = 1 ;
	while( ++x <= MaxX )
	{
		ok = true ;
		myforv( i, a )
		{
			memset( used, 0, sizeof(used) ) ;
			if( check( x, a[i] ) != 1 )
			{
				ok = false ;
				break ;
			}
		}

		if( ok )
		{
			cout<<x<<endl;
			return ;
		}
	}

	cerr<<"shit"<<endl;

}

int main()
{
	SetFile( "        A-small-attempt1.in       " ) ;

	int test ; cin>>test ; readln();
	cerr<<"n_test = "<<test<<endl;

	memset( f, 255, sizeof(f) ) ;

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
