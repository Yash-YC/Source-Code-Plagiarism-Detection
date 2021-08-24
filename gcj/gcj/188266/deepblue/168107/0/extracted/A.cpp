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
#include <set>
#include <sstream>
using namespace std;
typedef long long LL;
vector < int > bases;

bool ishappy ( int a , int b )
{
	LL res = a;
	set < int > S;
	while ( res != 1 )
	{
		LL ta = res;
		res = 0;
		while ( ta )
		{
			res += LL(ta%b) * (ta%b) , ta/=b;
		}
		if ( S.count(res) )
			break;
		S.insert(res);
		
	}
	return res == 1;
}
int go()
{
	for ( int i=2;;i++ )
	{
		for ( int j=0;j<bases.size();j++ ) if ( ishappy(i,bases[j]) );
		else goto next;
		return i;
		next:;;
	}	
}

int main()
{
	int _t;
	cin >> _t;
	while ( cin.peek() == '\n' )
		cin.get();
	for ( int kase=1;kase<=_t;kase++ )
	{
		bases.clear();
		string s;
		while ( cin.peek() == '\n' )
			cin.get();
		getline ( cin , s );
		
		istringstream iss ( s );
		int a;		
		while ( iss >> a )
			bases.push_back(a);
		cout <<"Case #" << kase <<": " << go() << endl;
	}
	return 0;
}
