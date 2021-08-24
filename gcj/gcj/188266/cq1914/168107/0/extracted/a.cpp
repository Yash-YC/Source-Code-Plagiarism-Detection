#include<iostream>
#include<string.h>
#include<map>
using namespace std;

int n, base[10];
int b_n;
char a[20];
map< int, int > r1[11];

bool ok( int m, int base ){
    int i, j, k = 0, res;
    bool f[100005];
    memset( f, false, sizeof( f ) );
    int t, tmp;
	res = m;
	tmp = 1;
    while( res > 0 ){
		k = k + ( res % base ) * tmp;
        res /= base;
		tmp *= 10;
    }
	f[k] = true;
	res = k;
    while( true ){
        t = res;
        int u = 0, o;
        while( t > 0 ){
            o = t % 10;
            u += o * o;
            t /= 10;
        }
        res = 0, tmp = 1;
        while( u > 0 ){
            res = res + ( u % base ) * tmp;
            u /= base;
			tmp *= 10;
        }
        if( res == 1 ) return true;
        if( f[res] ) return false;
        f[res] = true;
    }
}

void init( ){
    int i, j;
    for( i = 3; i <= 10; i++ ){
        if( i == 4 ) continue;
        for( j = 2; j <= i * i * i; j++ ){
			if( ok( j, i ) )
				r1[i][j] = 1;
		}
    }
}

int main( ){
    int i, j, t, k, cas = 1, l;
    init( );
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "A-small-attempt0.out", "w", stdout );
    scanf( "%d", &t );gets( a );
    while( t-- ){
        gets( a );
        l = strlen( a );
        k = 0;
        b_n = 0;
        for( i = 0; i <= l; i++ ){
            if( i < l && a[i] != ' ' ){
                k = k * 10 + a[i] - '0';
            }else{
                base[b_n++] = k;
                k = 0;
            }
        }
        for( i = 2; i <= 30000000; i++ ){
            for( j = 0; j < b_n; j++ ){
                if( base[j] == 2 || base[j] == 4 ) continue;
				int u = i, o, res = u, tmp, r;
				if( i == 143 )
					i = 143;
				while( res > base[j] * base[j] * base[j] ){
					r = res;
					tmp = 1;
					res = 0;
					while( r > 0 ){
						res = res + ( r % base[j] ) * tmp;
						r /= base[j];
						tmp *= 10;
					}
					int t = res;
					res = 0;
					while( t > 0 ){
						o = t % 10;
						res += o * o;
						t /= 10;
					}
				}

                if( r1[base[j]][res] == 0 ) break;
            }
            if( j == b_n ) break;
        }
        printf( "Case #%d: %d\n", cas++, i );
    }
    return 0;
}
