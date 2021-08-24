#include <cstdio>
#include <cctype>
#include <cstring>
#define max( a, b ) ( ( a ) > ( b ) ? ( a ) : ( b ) )

using namespace std;

class BigInteger
{
    const static int DN = 100;
    const static int F = 10000, FK = 4;
    int n[ DN ], len;
    bool negative;
    void add( const BigInteger& );
    void sub( const BigInteger&, int );
    void format();
    bool lessthan( const BigInteger&, int ) const;
public:
    BigInteger( int = 0 );
    BigInteger( char*, int = -1 );

    BigInteger& operator = ( int b ) { return *this = BigInteger( b ); }

    bool operator < ( const BigInteger& ) const;
    bool operator > ( const BigInteger& b ) const { return b < *this; };
    bool operator <= ( const BigInteger& b ) const { return !( *this > b ); }
    bool operator >= ( const BigInteger& b ) const { return !( *this < b ); }
    bool operator != ( const BigInteger& b ) const { return *this < b || *this > b; }
    bool operator == ( const BigInteger& b ) const { return !( *this != b ); }

    bool operator < ( const int& b ) const { return *this < BigInteger( b ); }
    bool operator > ( const int& b ) const { return *this > BigInteger( b ); }
    bool operator <= ( const int& b ) const { return *this <= BigInteger( b ); }
    bool operator >= ( const int& b ) const { return *this >= BigInteger( b ); }
    bool operator != ( const int& b ) const { return *this != BigInteger( b ); }
    bool operator == ( const int& b ) const { return *this == BigInteger( b ); }

    void operator += ( const BigInteger& );
    void operator -= ( const BigInteger& );
    void operator *= ( const BigInteger& );
    void operator /= ( const BigInteger& );
    void operator %= ( const BigInteger& b ) { *this -= *this / b * b; }

    BigInteger operator + ( const BigInteger& b ) const { BigInteger r = *this; r += b; return r; };
    BigInteger operator - ( const BigInteger& b ) const { BigInteger r = *this; r -= b; return r; };
    BigInteger operator * ( const BigInteger& b ) const { BigInteger r = *this; r *= b; return r; };
    BigInteger operator / ( const BigInteger& b ) const { BigInteger r = *this; r /= b; return r; };
    BigInteger operator % ( const BigInteger& b ) const { BigInteger r = *this; r %= b; return r; };

    void operator += ( const int& b ) { *this += BigInteger( b ); }
    void operator -= ( const int& b ) { *this -= BigInteger( b ); }
    void operator *= ( const int& );
    void operator /= ( const int& );
    void operator %= ( const int& b ) { *this -= *this / b * b; }

    BigInteger operator + ( const int& b ) const { BigInteger r = *this; r += b; return r; }
    BigInteger operator - ( const int& b ) const { BigInteger r = *this; r -= b; return r; }
    BigInteger operator * ( const int& b ) const { BigInteger r = *this; r *= b; return r; }
    BigInteger operator / ( const int& b ) const { BigInteger r = *this; r /= b; return r; }
    BigInteger operator % ( const int& b ) const { BigInteger r = *this; r %= b; return r; }

    BigInteger& operator ++ () { *this += 1; return *this; }
    BigInteger& operator -- () { *this -= 1; return *this; }
    BigInteger operator ++ ( int ) { BigInteger r = *this; *this += 1; return r; }
    BigInteger operator -- ( int ) { BigInteger r = *this; *this -= 1; return r; }

    BigInteger operator - () { BigInteger r = *this; r.negative = !negative; r.format(); return r; }

    friend BigInteger operator + ( int k, const BigInteger& b ) { return BigInteger( k ) + b; }
    friend BigInteger operator - ( int k, const BigInteger& b ) { return BigInteger( k ) - b; }
    friend BigInteger operator * ( int k, const BigInteger& b ) { return BigInteger( k ) * b; }
    friend BigInteger operator / ( int k, const BigInteger& b ) { return BigInteger( k ) / b; }
    friend BigInteger operator % ( int k, const BigInteger& b ) { return BigInteger( k ) % b; }

    void print() const;
    void sprint( char* ) const;
};

BigInteger::BigInteger( int e )
{
    if ( e < 0 )
    {
        negative = true;
        e = -e;
    }
    else
    {
        negative = false;
    }
    memset( n, 0, sizeof( n ) );
    len = 1;
    n[ 0 ] = e;
    while ( n[ len - 1 ] >= F )
    {
        n[ len ] += n[ len - 1 ] / F;
        n[ len - 1 ] %= F;
        ++len;
    }
}

BigInteger::BigInteger( char* str, int slen )
{
    memset( n, 0, sizeof( n ) );
    negative = *str == '-' ? true : false;
    if ( !isdigit( *str ) )
    {
        ++str;
    }
    slen = slen == -1 ? strlen( str ) : slen;
    len = ( slen + FK - 1 ) / FK;
    for ( int i = 0; i < len; ++i )
    {
        int sum = 0;
        for ( int j = max( 0, slen - FK ); j < slen; ++j )
        {
            sum = sum * 10 + str[ j ] - '0';
        }
        n[ i ] = sum;
        slen -= FK;
    }
    format();
}

void BigInteger::format()
{
    for ( ; len > 1 && n[ len - 1 ] == 0; --len );
    if ( len == 1 && n[ 0 ] == 0 )
    {
        negative = false;
    }
}

bool BigInteger::lessthan( const BigInteger& b, int bg = 0 ) const
{
    if ( len - bg != b.len )
    {
        return len - bg < b.len;
    }
    else
    {
        bool ret = false;
        for ( int i = len - bg - 1; i > -1; --i )
        {
            if ( n[ bg + i ] != b.n[ i ] )
            {
                ret = n[ bg + i ] < b.n[ i ];
                break;
            }
        }
        return ret;
    }
}

bool BigInteger::operator < ( const BigInteger& b ) const
{
    if ( negative != b.negative )
    {
        return negative;
    }
    else
    {
        bool ret = false;
        if ( negative )
        {
            ret = b.lessthan( *this );
        }
        else
        {
            ret = lessthan( b );
        }
        return ret;
    }
}

void BigInteger::add( const BigInteger& b )
{
    len = max( len, b.len );
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        n[ i ] += b.n[ i ] + r;
        r = n[ i ] / F;
        n[ i ] %= F;
    }
    if ( r )
    {
        n[ len++ ] = r;
    }
    format();
}

void BigInteger::sub( const BigInteger& b, int bg = 0 )
{
    int length = len - bg;
    for ( int i = 0; i < length; ++i )
    {
        n[ i + bg ] -= b.n[ i ];
        if ( n[ i + bg ] < 0 )
        {
            n[ i + bg ] += F;
            --n[ i + bg + 1 ];
        }
    }
    format();
}

void BigInteger::operator += ( const BigInteger& b )
{
    if ( negative == b.negative )
    {
        add( b );
    }
    else
    {
        if ( b.lessthan( *this ) )
        {
            sub( b );
        }
        else
        {
            BigInteger r = b;
            r.sub( *this );
            *this = r;
        }
    }
}

void BigInteger::operator -= ( const BigInteger& b )
{
    if ( negative == b.negative )
    {
        if ( b.lessthan( *this ) )
        {
            sub( b );
        }
        else
        {
            BigInteger r = b;
            r.sub( *this );
            *this = r;
            negative = !negative;
            format();
        }
    }
    else
    {
        add( b );
    }
}

void BigInteger::operator *= ( const BigInteger& b )
{
    BigInteger a = *this;
    memset( n, 0, sizeof( n ) );
    len += b.len;
    negative ^= b.negative;
    for ( int i = 0; i < a.len; ++i )
    {
        for ( int j = 0; j < b.len; ++j )
        {
            int k = i + j;
            n[ k ] += a.n[ i ] * b.n[ j ];
            if ( n[ k ] >= F )
            {
                n[ k + 1 ] += n[ k ] / F;
                n[ k ] %= F;
            }
        }
    }
    format();
}

void BigInteger::operator /= ( const BigInteger& b )
{
    BigInteger a = *this;
    len = max( 0, len - b.len + 1 );
    memset( n, 0, sizeof( n ) );
    negative ^= b.negative;
    for ( int i = len - 1; i > -1; --i )
    {
        int head = 0;
        int tail = F - 1;
        int times = 0;
        while ( head <= tail )
        {
            int mid = head + tail >> 1;
            if ( !( a.lessthan( b * mid, i ) ) )
            {
                times = mid;
                head = mid + 1;
            }
            else
            {
                tail = mid - 1;
            }
        }
        a.sub( b * times, i );
        n[ i ] = times;
    }
    if ( len == 0 )
    {
        ++len;
    }
    format();
}

void BigInteger::operator *= ( const int& b )
{
    negative = negative ^ ( b < 0 );
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        n[ i ] = n[ i ] * b + r;
        r = n[ i ] / F;
        n[ i ] %= F;
    }
    while ( r )
    {
        n[ len++ ] = r % F;
        r /= F;
    }
    format();
}

void BigInteger::operator /= ( const int& b )
{
    negative = negative ^ ( b < 0 );
    int r = 0;
    for ( int i = len - 1; i > -1; --i )
    {
        n[ i ] += r * F;
        r = n[ i ] % b;
        n[ i ] /= b;
    }
    format();
}

void BigInteger::print() const
{
    if ( negative )
    {
        putchar( '-' );
    }
    printf( "%d", n[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
    {
        printf( "%0*d", FK, n[ i ] );
    }
    return;
}

void BigInteger::sprint( char* str ) const
{
    int index = 0;
    if ( negative )
    {
        str[ index++ ] = '-';
    }
    sprintf( str + index, "%d", n[ len - 1 ] );
    index = strlen( str );
    for ( int i = len - 2; i > -1; --i, index += FK )
    {
        sprintf( str + index, "%0*d", FK, n[ i ] );
    }
}

#include<algorithm>
#include<cassert>
#include<cstdio>
#include<cmath>

struct Matrix{
	BigInteger **a;
	int n,m;
	Matrix():a(0),n(0){}
	Matrix(int b,int c):a(0),n(0){
		resize(b,c);
	}
	~Matrix(){ clear(); }
	void clear(){
		for(int i=0;i<n;i++)
			delete[]a[i];
		delete[]a;
		n=m=0;
		a=0;
	}
	void resize(int b,int c){
		if(b>n||c>m){
			clear();
			n=b;m=c;
			a=new BigInteger*[n];
			for(int i=0;i<n;i++) a[i]=new BigInteger[m];
		}else n=b,m=c;
	}
	void Output(){
		printf("============== DEBUG ==============\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j].print();
				printf(" ");
			}
			printf("\n");
		}
	}
	void gauss(){ // O(n^3LogC)
		for(int i=0,j=0;i<n&&j<m;i++,j++){
			for(int k=i+1;k<n;k++)
				while(a[k][j]!=0){
					BigInteger t=a[i][j]/a[k][j];
					for(int l=j;l<m;l++){
						a[i][l]=a[i][l]-t*a[k][l];
						std::swap(a[i][l],a[k][l]);
					}
				}
			if(a[i][j]==0)--i;
		}
	}
};
BigInteger c[42][42];
#include<iostream>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	c[0][0]=1;
	for(int i=0;i<42;i++)
		for(int j=1;j<42;j++){
			c[i][j]=c[i][j-1];
			if(i)c[i][j]+=c[i-1][j-1];
		}
	int t,n,m;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		Matrix a(n+1,n+2);
		a.a[0][0]=1;
		for(int p=1;p<=n;p++){
			a.a[p][p]=c[m][n]-c[m][n-p];
			for(int k=1;k<=m;k++){
				if(p-k<0)break;
				a.a[p][p-k]=-c[m-k][n-p]*c[k][p];
			}
			a.a[p][n+1]=c[m][n];
		}
		a.gauss();
		BigInteger ans=1000000*a.a[n][n+1]/a.a[n][n];
		printf("Case #%d: ",i);
		(ans/1000000).print();
		printf(".");
		char s[10];
		(ans%1000000).sprint(s);
		for(int i=strlen(s);i<6;i++)printf("0");
		printf(s);
		printf("\n");
	}
}


