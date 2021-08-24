#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

inline int todigit(char c) { return c-'0'; }

int go(const char* buf, int base)
{
	int res = 0;
	int len = strlen(buf);
	for ( int i=0 ; i<len ; ++i )
	{
		int d = todigit(buf[i]);
		res += d * d;
	}
	return res;
}

bool happy(int num, int base)
{
	char buf[64];
	set<int> already;
	already.insert(num);
	while ( num > 1 )
	{
		itoa(num, buf, base);
		int next = go(buf, base);
		if ( next == 1 ) return true;
		if ( already.find(next)!=already.end() ) return false;
		already.insert(next);
		num = next;
	}
	return true;
}

int firstHappy(int base)
{
	for ( int i=1 ; ; ++i )
	{
		if ( happy(i, base) ) return i;
	}
}

vector<int> split(string& str)
{
	istringstream sin(str);
	vector<int> res;
	int num;
	while ( sin >> num ) res.push_back(num);
	return res;
}

int solve(vector<int>& base)
{
	int sz = base.size();
	for ( int k=2 ; ; ++k )
	{
		bool ok = true;
		for ( int i=0 ; i<sz ; ++i )
		{
			if ( !happy(k, base[i]) )
			{
				ok = false;
				break;
			}
		}
		if ( ok ) return k;
	}
}

int main()
{
	int T;
	cin >> T;
	cin.ignore(1);
	for ( int _T=1 ; _T<=T ; ++_T )
	{
		string line;
		getline(cin, line);
		vector<int> bases = split(line);

		cout << "Case #" << _T << ": " << solve(bases) << endl;
	}
	return 0;
}
