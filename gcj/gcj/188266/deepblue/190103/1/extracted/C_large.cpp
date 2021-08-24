#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <list>
#include <string.h>
using namespace std;
typedef long long LL;

int C,N;
const int mn = 64;
int seen[mn] , seenid;
double dp[mn];

int oc ( int n )
{
	if ( !n )
		return 0;
	return __builtin_popcount(n);
}

double Comb ( int r , int c )
{
	if ( c > r ) 	return 0;
	double res = 1;
	for ( int i=r;i>=r-c+1;i-- )
		res *= i;
	for ( int i=c;i>0;i-- )
		res /= i;
//	cout <<"C " << r <<" " << c << " = " << res << endl;
	return res;
}

double go ( int have )
{
	if ( have >= C )
		return 0;
	double &res = dp[have];
	if ( seen[have] == seenid )
		return res;
	seen[have] = seenid;
	res = 0;
	double prob = Comb(have,N);
	double den = Comb(C,N);
	prob /= den;
	for ( int i=0;i<N;i++ )
	{
		// i from have
		if ( i > have ) continue;
		double pprob = ( Comb(have,i) * Comb(C-have,N-i) ) / den;
		res += pprob * go(have + N-i);// N to N + have
	}
	res = (1 + res)/(1-prob);
	return res;
}

int main()
{
	int _t;
	cin >> _t;
	for ( int kase=1;kase<=_t;kase++ )
	{
		cin >> C >> N;		
		seenid ++;
		printf ( "Case #%d: %.5lf\n" , kase , go(0) );
	}
	return 0;
}
