#include <functional> 
#include <algorithm> 
#include <iostream> 
#include <complex> 
#include <cstring> 
#include <numeric> 
#include <sstream> 
#include <fstream>
#include <limits> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <queue> 
#include <map> 
#include <set> 
using namespace std; 

template <class T, bool B> struct cmp_ { inline static bool cmp(T a, T b) { return a < b; } };  
template <class T> struct cmp_<T, false> { inline static bool cmp(T a, T b) { return a != b; } };  
#define FOR(i, b, e) for (typeof(b) i = (b); cmp_< typeof(b), numeric_limits< typeof(b) >::is_specialized >::cmp(i, e); ++i)

map<string, int> ih[11];

bool isHappy(string s, int B) 
{
	map<string, int> m;
	string t;
	int SOS;
	while (m[s] != 1 && ih[B].find(s) == ih[B].end())
	{
		m[s] = 1;
		t = "";
		SOS = 0;
		FOR(i, 0, s.size()) SOS += (s[i] - '0') * (s[i] - '0');
		while (SOS)
		{
			t += '0' + SOS % B;
			SOS /= B;
		}
		s = t;
	}
	if (ih[B].find(s) != ih[B].end())
		return ih[B][s] == 1 ? 1 : 0;
	
	return s == "1";
}

int main()
{
ifstream fin("in.in");
ofstream fout("out.out");
	map<string, int> ih[11];	
	FOR(b, 2, 11) ih[b]["1"] = 1;
	FOR(i, 2, 200) FOR(b, 2, 11)
	{
		string s = "";
		int n = i;
		while (n)
		{
			s += '0' + n % b;
			n /= b;
		}
		ih[b][s] = isHappy(s, b) ? 1 : -1;
	}

int T;
fin >> T;
char cs[100]; fin.getline(cs, 256);
FOR(tc, 0, T)
{
	vector<int> bases;
	fin.getline(cs, 256);
	stringstream ss;
	ss << cs;
	int n;
	while (ss >> n) bases.push_back(n);
	int B = bases.size();
	
	string s;
	long long ret;

	for (long long i = 2;; ++i)
	{
		bool isHappyOverall = true;
		FOR(b, 0, B)
		{
			long long ii = i;
			s = "";
			while (ii)
			{
				s += '0' + ii % bases[b];
				ii /= bases[b];
			}

			if (!isHappy(s, bases[b]))
			{
				isHappyOverall = false;
				break;
			}
		}
		
		if (isHappyOverall)
		{
			ret = i;
			break;
		}
	}

	fout << "Case #" << tc + 1 << ": " << ret << endl;
}
	return 0;
}
