
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int gcd(int a, int b) { int t; while ( b > 0 ) { a %= b; t = a; a = b; b = t; } return a; }
long long big_ncr(int n, int r) { int up, down, u, d, i, t; up = down = 1; if ( r > (n >> 1) ) r = n - r; for ( i = r; i >= 1; --i ) { u = n-r+i; d = i; t = gcd(u,d); u /= t; d /= t; t = gcd(up,d); up /= t; d /= t; t = gcd(down,u); down /= t; u /= t; up *= u; down *= d; } return (up / down); }


int main()
{
/*
	double ans = 0;

	long long b = 4;
	for(int i = 2; i < 60 ; i++ )
	{
		ans += (double)i * 1.0/(double)b;
		b *=2LL;
	}

	printf("%lf\n" , ans *2);
	*/

	int cases, Case = 0;
	scanf("%d" , &cases);
int n ,c;
	while(cases--)
	{
		scanf("%d%d" , &n,&c);

		double ans = 0;
		long long b = big_ncr(n,c);
		int i  = n/c;
		if( n % c) i++;

		long long aaa = b;
		for(int j=0;j<i-1;j++)
			b *= aaa;

		for(; i < 64 && b > 0 ; i++ )
		{
			ans += (double)i * 1.0/(double)b;
			b *= (long long)n;
		}


		printf("Case #%d: " , ++Case);
		printf("%.8lf\n" , ans *c*n);
	}



	return 0;
}