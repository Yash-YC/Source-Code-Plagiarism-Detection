#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

#define TOPE 1<<22

int m[TOPE][16];

vint v;

#define sqr(x) ((x)*(x))

int b;

int auxvar;

bool happy(int n)
{
	if (n < TOPE)
		if (m[n][b] != -1)
			return m[n][b];
	int & res = (n < TOPE)?(m[n][b]):(auxvar);
	res = 0;
	if (n == 1)
		res = 1;
	else
	{
		int suma = 0;
		while (n != 0)
		{
			suma += sqr(n%b);
			n /= b;
		}
		res = happy(suma);
	}
	return res == 1;
}

bool anda(int n)
{
	forall(i,v)
	{
		b = *i;
		if (!happy(n))
			return false;
	}
	return true;
}

bool tantodos()
{
	return true;
}

map<vint,int> computo;

int main()
{
	
	memset(m,0xFF,sizeof(m));
	/*b = 10;
	int m = 0;
	forsn(i,2,100000)
		if (happy(i))
			m++;
	cout << m << endl;
	return 0;*/
	
	/*
	forsn(i,2,11)
	{
		b = i;
		int num = 11814485;
		int sum = 0;
		while (num != 0)
		{
			sum += sqr(num % i);
			num /= i;
		}
		cout << i << " " << happy(sum) << endl;
	}
	* */
	computo.clear();
	freopen("entrada.in","r",stdin);
	freopen("salida.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	string s;
	getline(cin,s);
	forn(caso,totalCasos)
	{
		getline(cin,s);
		istringstream is(s);
		v.clear();
		int num;
		while (is >> num)
		if (num != 2 && num != 4)
			v.push_back(num);
		int res;
		if (v.size() == 7)
			res = 11814485;
		else if (esta(v,computo))
			res = computo[v];
		else
		{
			res = 2;
			while (!anda(res))
			{
				res++;
				//if (res % 1000000 == 0)
				//	cerr << res << endl;
			}
			computo[v] = res;
		}
		cout << "Case #" << caso + 1 << ": " << res << endl;
		//cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}
