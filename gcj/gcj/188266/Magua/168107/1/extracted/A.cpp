
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

vector <int> bases;

char buff[1000];


int is_ok(int n, int b)
{
	set<int> s;
	int nxt;

	while(1)
	{
		if( n == 1)
			return 1;
		if( s.count(n) )
			return 0;
		s.insert(n);
		nxt = 0;
		while( n)
		{
			nxt += (n%b) * (n%b) ;
			n = n/b;
		}
		n = nxt;
	}
}

set<int> ans[11];

int main()
{

	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int t;
	
	

	for( int i=2;i<5000000;i++)
	{
	
		for( int j=2;j<=10;j++)
			if(  is_ok(i,j ) )
				ans[j].insert(i);
			
		
	}

		
	
	


	
	
	scanf("%d",&t);
	fgets(buff,1000,stdin);	

	for(int tt=0;tt<t;tt++)
	{
		bases.clear();
		fgets(buff,1000,stdin);
		
		int now;
		for(int i=0; i<strlen(buff);i++)
		{
			if( buff[i] >= '0' && buff[i] <= '9' )
			{
				sscanf(&buff[i],"%d",&now);
				bases.pb(now);
				//fprintf(stderr,"Found %d\n",now);
				while(  ( buff[i] >= '0' && buff[i] <= '9' ) )
					i++;
			} 
		}
		//fprintf(stderr,"\n");

		int found = 0;
		for( sii it = ans[bases[0] ].begin()  ;it != ans[bases[0] ].end();it++)
		{
			int ok = 1;
			for( int j=1;j<bases.size();j++)
				if( ! ans[bases[j] ].count(*it) )
				{
					ok = 0;
					break;
				}
			if( ok)	
			{
				printf("Case #%d: %d\n",tt+1,*it);
				found = 1;
				break;
			}
		}
		if( !found)
			printf("Case #%d: %d\n",tt+1,11814485);
		


	}
	
	return 0;
}
