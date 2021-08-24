//Code by Patcas Csaba
//Time complexity:
//Space complexity:
//Method:
//Implementation time: 

#include <vector>
#include <string> 
#include <set> 
#include <map> 
#include <queue> 
#include <bitset> 

#include <numeric> 
#include <algorithm> 

#include <cstdio>
#include <fstream>
#include <iostream> 
#include <sstream> 

#include <cctype>
#include <cmath> 
#include <ctime>
#include <cassert>

using namespace std;

#define VI vector <int>
#define VB vector <bool>
#define PII pair <int, int>
#define LL long long

#define FORN(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define repeat do{ 
#define until(x) }while(!(x)); 

#define SZ size()
#define BG begin() 
#define EN end() 
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x. end()

#define in_file "c.in"
#define out_file "c.out"
ifstream fin(in_file);
ofstream fout(out_file);

int c, n;
vector <double> memo;

double Solve(int state);

void Solve2(int sp, int state, int &all, int &k, VI &ss)
{
	if (sp == n + 1)
	{
		++all;
		int newState = 0;
		FOR(j, 1, n) newState |= 1 << (ss[j] - 1);
		if ((state | newState) == state) ++k;
		else memo[state] += Solve(state | newState);
		return;
	}
	FOR(i, ss[sp - 1] + 1, c)
	{
		ss[sp] = i;
		Solve2(sp + 1, state, all, k, ss);
	}
}

double Solve(int state)
{
	double &ref = memo[state];
	if (ref != -1) return ref;
	if (state == ((1 << c) - 1)) return ref = 0;
	ref = 0;
	VI ss;
	ss.clear();
	ss.RS(n + 1);
	int all = 0,	k = 0;
	Solve2(1, state, all, k, ss);
	ref = (ref + all) / (all - k);
	return ref;
}

int main()
{
	//Read data
	int test;
	fin >> test;
	FORN(t, test)
	{
		fin >> c >> n;
		memo.clear();
		memo.RS((1 << c), -1);
		fout << "Case " << t + 1 << ": " << Solve(0) << endl;
	}
	fin.close();

	//Solve

	//Write data
	fout.close();

	return 0;
}