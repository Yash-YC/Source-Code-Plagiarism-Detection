#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <queue>
 
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
 
#define forn(i, n) for(int i=0;i<int(n);i++)
#define FOR(i, a, b) for(int i=(a);i<int(b);i++)
#define RFOR(i, b, a) for(int i=(b);i>int(a);i--)
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define ALL(x)   (x).begin(),(x).end()
#define SIZE(x)   (int)(x).size()
#define SORT(x) sort(ALL(x))
using namespace std;
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define ISS istringstream
#define OSS ostringstream
typedef long long ll;
// NUNCA DEFINIR int max....

bool visited[41][20010];
long double res[41][20010];
int N, C;
long double COMB[41][41];
long double go(int tengo, int paso)
{
       if( paso > 20010 ) return 0.;
       if( !tengo ) return (long double)paso;
//        printf("HOLANDA\n");
       if( visited[tengo][paso] ) 
       {
	      return res[tengo][paso];
       }
       visited[tengo][paso] = true;
       long double & r = res[tengo][paso];
       r = 0.;
       for( int i = 0; i <= min(tengo, N); i ++ )
       {
	      r += ((COMB[tengo][i] * COMB[C-tengo][N-i]) / COMB[C][N]) * go(tengo-i,paso+1);
       }
       return res[tengo][paso];
}

int main()
{
       int i,j ,k;
       
       int casos; 
       for( i = 0; i < 41; i ++ ) COMB[i][i] = COMB[i][0] = 1.;
       for( i = 1; i < 41; i ++ )
	      for( j = 1; j < i ; j ++ ) COMB[i][j] = COMB[i-1][j-1] + COMB[i-1][j];
       cin >> casos;
//        double a = 1.;
//        for( i = 21; i <= 40 ; i ++ ) a *= (double)i;
//        cout << a << endl;
//        for( i = 1 ; i < 21; i++ ) a /= (double)i;
//        cout << a << endl;
       for( int h = 0 ; h < casos; h ++ )
       {
	      cin >> C >> N;
	      for( i = 0 ; i < 41; i ++ ) memset(visited, false, sizeof(visited));
	      cout << "Case #" << (h+1) << ": " << go(C, 0) << endl;
       }return 0;
}
