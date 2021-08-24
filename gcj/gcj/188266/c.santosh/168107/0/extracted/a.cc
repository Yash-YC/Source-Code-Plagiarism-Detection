#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>

#if defined (__GNUC__) && (__GNUC__ <= 2)
#include <hash_map>
#include <hash_set>
#else
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
#endif
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <boost/regex.hpp>



#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

LL s2i(string s) { istringstream i(s); LL x; i>>x; return x; }
template<class T> string i2s(T x) { ostringstream o; o << x; return o.str(); }

#define pi acos(-1.)
#define eps 1e-7
#define inf 1e17

bool happy (int n, int b);
bool found(VI x, int a);

#define MAX (20)

char *known_bad[MAX] = {NULL};
int known_badSize[MAX] = {0};

void alloc(int bb)
{
	char *tmp1 = new char[known_badSize[bb]*2];
	memcpy(tmp1, known_bad[bb], sizeof(char)*known_badSize[bb]);
	delete[] known_bad[bb];
	known_bad[bb] = tmp1;

	for(int i=known_badSize[bb]; i<2*known_badSize[bb]; i++)
		known_bad[bb][i]=-1;
	known_badSize[bb]=2*known_badSize[bb];
}


int main()
{
	int i,j,k,l,m,n;
	int testId, nTests;

	cin >> nTests;
	char temp[1024];
	fgets(temp, 1000, stdin);


	for(i=0; i<MAX; i++)
	{
		//known_badSize[i]=10000;
		known_badSize[i]=1000000;
		known_bad[i]=new char[known_badSize[i]];
	}

	for(j=0; j<MAX; j++)
	for(i=0; i<known_badSize[j]; i++)
		known_bad[j][i]=-1; // uninitialized

	for(testId=1;testId<=nTests;testId++)
	{
		int num;
		char str[1001];
		int bases[50];
		int numBases=0;
		fgets(str, 1000, stdin);
		char *p;
		p=strtok(str," ");
		do
		{
			bases[numBases++]=atoi(p);
		} while(p=strtok(NULL, " "));

		//XXX  -- Read input --  XXX
		#if 0
		printf("numBases: %d\n", numBases);
		for(i=0; i<numBases; i++)
		{
			cout << bases[i] << " ";
		}
		cout <<endl;
		#endif

		//XXX  -- Process input --  XXX

		for(i=2;;i++)
		{
			for(j=0; j< numBases; j++)
			{
				int bb=bases[j];
				if (i >= known_badSize[bb])
				{
					alloc(bb);
				}

				if (known_bad[bb][i] == 1)
					break;
				if (known_bad[bb][i] == 0)
					continue;

				#ifdef DBG0
				cout << i << " " <<  bb << endl;
				#endif
				if(!happy(i, bb))
					break;
			}
			if(j==numBases)
			{
				break;
			}
		}

		//XXX  -- Print output --  XXX
		printf("Case #%d: %d\n", testId, i);
	}

	return 0;
}

bool found(VI x, int a)
{
	for (VI::iterator iter=x.begin(); iter!=x.end(); iter++)
	{
		if (a == *iter) return true;
	}
	return false;
}
bool happy (int n, int b)
{
VI temp;
char *known = known_bad[b];

#ifdef DBG1
cout << "in happy" << endl;
#endif

int sum=-1;
int k=n;

map<int, bool> t;
bool ret;

	if (n >= known_badSize[b])
	{
		alloc(b);
		known = known_bad[b];
	}

	if (known[n] == 1)
		return false;
	if (known[n] == 0)
		return true;

while(1)
{
#ifdef DBG2
cout << "eval " << k << endl;
#endif
	
	//if (found(known, k))
	//	return false;

	temp.pb(k);
	t[k]=true;
	sum=0;
	while(k)
	{
		sum+=(k%b)*(k%b);
		k/=b;
	}
	if (sum == 1)
		return true;
	
	k=sum;

	if (k >= known_badSize[b])
	{
		alloc(b);
	}

	if (known[k] == 0)
	{
		for (VI::iterator iter=temp.begin(); iter!=temp.end(); iter++)
		{
			//cout << "setting known-false " << *iter << endl; 
			known[*iter]=0;
		}
		return true;
	}
	//else if (k == n || known[k] == 1 || found(temp, k)) //in loop
	else if (k == n || known[k] == 1 || (t.find(k)!=t.end())) //in loop
	{
		for (VI::iterator iter=temp.begin(); iter!=temp.end(); iter++)
		{
			//cout << "setting known-true " << *iter << endl; 
			known[*iter]=1;
		}
		return false;
	}

	//if ((!found(temp, k)) && t.find(k) != t.end())
	//assert(0);

} //end of while(1)

return true;
}
