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
		int n;
		cin >> n;
		map<int, int> count;
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int inp;
				cin >> inp;
				count[inp] ++;
			}
		}
		vector<int> vec;
		for (int i = 0; i <= 2500; ++i)
		{
			if(count[i] % 2)
				vec.push_back(i);
		}

		cout << "Case #" << test+1 << ":";

		for (int i = 0; i < vec.size(); ++i)
			cout << " " << vec[i];
		cout << endl;
	}

	return 0;
}