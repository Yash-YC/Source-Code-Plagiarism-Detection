#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
int cal[11][500000];
int a[11][500000];
bool used[11][500000];
//int base;
//a*base^2 + b*base+ c
//a*a%base + a*a/base
int check (int bs, int p)
{
	if (used[bs][p]) return 0;
	if (cal [bs][p]!= -1) return a[bs][p];
	if (p == 1) return 1;
		used[bs][p] = 1;
		
	int q = 0, st = 0; int p2 = p;
	while (p)
	{
		st = p%bs;
		p/=bs;
		st*=st;
		q += st;
	}
	
	cal[bs][p2] = 1;
	return a[bs][p2] = check (bs, q);
	
}
int solve(vector <int> base)
{
	
	//scanf ("%d", &base);
	//base = o;
	int i, j;
	memset (cal, -1, sizeof (cal));	
	for (i = 2; i < 500000; i++)
	{
		int ok = 1;
		for (j = 0; j < base.size (); j ++)
		{
		memset (used, 0, sizeof (used));
		if (!check (base[j], i)){ok = 0;break;}
		}
		if (ok) {cout << i << endl; break;}
	}
	
	return 0;
}
string input;
//char rrr[100];
int main ()
{
	int n;
	scanf ("%d", &n); getline (cin, input); 
	int i;
	vector <int> op; int temp ;
	
	for (i = 1; i <= n; i++)
	{	
		op.clear();
		printf ("Case #%d:", i);
		getline (cin, input);
		istringstream in (input);
		while (in >> temp) op.push_back (temp);
		solve (op);
		
	}
		
	return 0;
}