
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define vii vector<int> :: iterator
#define si set <int>
#define sii set <int> :: iterator
#define is insert
#define vpi vector <pair<int,int> >
#define vpii vector <pair <int,int> > :: iterator
#define spi set <pair<int,int> >
#define spii set <pair <int,int> > :: iterator
#define for_each(tip,it,multime) for( tip it = multime.begin();it!=multime.end();++it)

using namespace std;

double comb [50][50];

double e[50];

int N,C;

double combi(int n,int k){


	if( k == 0)
		return 1;

	
	if( n == 0 )
		return 0;

	if( n < k ) 
		return 0; 
	if( comb[n][k] >= 0 ) 
		return comb[n][k];
	
	return comb[n][k] = (combi(n-1,k-1)+combi(n-1,k));
}

double match( int i, int rem)
{
	return combi(rem,i) * combi (C-rem,N-i) / combi(C,N);
}

double exp(int i)
{
	if( i<= 0)
		return 0;

	if( e[i] >= 0 ) 
		return e[i];

	double rez = 1;
	for( int j=1; j <= min(i,N); j++)
	{
		rez +=  match ( j,i ) * exp( i-j );
	}

	e[i] = rez / ( 1 - match(0,i) );

	return e[i];

}

int main()
{

	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	int t;
	
	scanf("%d",&t);

	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++)
	{
		comb[i][j] = -1;
	}

	
	for(int tt=0;tt<t;tt++)
	{
		scanf("%d",&C);
		scanf("%d",&N);

		for(int i=0;i<50;i++)
			e[i] = -1;

		exp(C);

		/*
		for(int j=0;j<=C;j++)
			fprintf(stderr,"%d=%lf\n",j,e[j]);

		fprintf(stderr,"%lf\n",match(1,2) );

		fprintf(stderr,"\n");
		*/

		printf("Case #%d: %lf\n",tt+1,e[C]);
	}
	
	return 0;
}
