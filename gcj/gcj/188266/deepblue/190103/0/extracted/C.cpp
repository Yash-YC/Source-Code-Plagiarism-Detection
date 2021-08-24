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
const int mn = 11;
vector < int > trans;
int seen[1<<mn] , seenid;
double dp[1<<mn];

int oc ( int n )
{
	if ( !n )
		return 0;
	return __builtin_popcount(n);
}

double go ( int mask )
{
	if ( mask == (1<<C) -1  )
		return 0;
	double & res = dp[mask];
	
	if ( seen[mask] == seenid )
		return res;
		
	seen[mask] = seenid;
	res = 0;
	int cnt = 0;
	for ( int i=0;i<trans.size();i++ )
	{
		if ( ( mask | trans[i] ) == mask )
			cnt ++;
		else
			res += go(mask|trans[i]);
	}
	
	
	res = ( 1 + res/trans.size() )/ ( 1 - double(cnt)/trans.size() );

	return res;
}

int main()
{
	int _t;
	cin >> _t;
	
	for ( int kase=1;kase<=_t;kase++ )
	{
		cin >> C >> N;
		
		trans.clear();
		for ( int i=0;i<(1<<C);i++ )
			if ( oc(i) == N )
				trans.push_back(i);
		
		seenid ++;
		printf ( "Case #%d: %.5lf\n" , kase , go(0) );
//		cout <<"Case #" << kase <<": " << go(0) << endl;
	}
	return 0;
}
