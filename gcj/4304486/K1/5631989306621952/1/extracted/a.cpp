// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define EPS 1e-8
#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 2e5 + 123;


int main()
{
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test)
	{
		string s;
		cin >> s;
		string result;
		result += s[0];
		for (int i = 1; i < s.size(); ++i)
		{
			string beg = s.substr(i, 1) + result;
			string en = result + s.substr(i, 1);
			if(beg > en)
				result = beg;
			else
				result = en;
		}

		printf("Case #%d: %s\n", test+1, result.c_str());
	}

	return 0;
}