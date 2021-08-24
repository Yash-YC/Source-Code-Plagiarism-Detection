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

#define in_file "a.in"
#define out_file "a.out"
ifstream fin(in_file);
ofstream fout(out_file);

#define nStates (1<<9)

VI solution(nStates, -1);
set<int> was;

bool Happy(int x, int base)
{
	//cout << x << " " << base << endl;
	if (x == 1) return true;
	if (was.count(x)) return false;
	was.insert(x);
	VI digits;
	while (x)
	{
		digits.PB(x % base);
		x /= base;
	}
	int sum = 0;
	FORN(i, digits.SZ) sum = (sum + digits[i] * digits[i]);
	
	return Happy(sum, base);
}

int Solve(int state)
{
	if (solution[state] != -1) return solution[state];
	int ans = 2;
	FORN(i, 9)
		if (state & (1 << i)) ans = max(ans, Solve(state - (1 << i)));
	while (1)
	{
		bool ok = true;
		FORN(i, 9)
		{
			was.clear();
			if ((state & (1 << i)) && !Happy(ans, i + 2))
			{
				ok = false;
				break;
			}
		}
		if (ok) break;
		++ans;
	}
	return solution[state] = ans;
}

int main()
{
	//Precompute
	//FORN(i, nStates)
	//{
	//	cout << i << " ";
	//	solution[i] = Solve(i);
	//	fout << solution[i] << " ";
	//}

	ifstream fsol("sols.in");
	FORN(i, nStates) fsol >> solution[i];

	//Read data
	int test;
	string s;
	fin >> test;
	getline(fin, s);
	FORN(t, test)
	{
		cout << t << endl;
		getline(fin, s);
		VI bases;
		stringstream ss(s);
		int aux;
		while(ss >> aux) bases.PB(aux);
		int state = 0;
		FORN(i, bases.SZ) state |= 1 << (bases[i] - 2);
		/*int i = 1;
		while (1)
		{
			++i;
			bool ok = true;
			FORN(j, bases.SZ)
			{
				was.clear();
				if (!Happy(i, bases[j]))
				{
					ok = false;
					break;
				}
			}
			if (ok) break;
		}*/
		fout << "Case #" << t + 1 << ": " << solution[state] << endl;
	}
	fin.close();

	//Solve

	//Write data
	fout.close();

	return 0;
}