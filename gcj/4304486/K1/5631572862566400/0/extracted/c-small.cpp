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

vector<int> vec[200];
bool mark[200];
int parrent[200];

int dfs(int i, vector<int> & order){
	if(mark[i] && i == order[0])
		return 1; 				// complete
	if(mark[i] && order[order.size()-2] == i)
		return 2;
	if(mark[i])
		return 3;
	mark[i] = true;
	order.push_back(i);
	int next = vec[i][0];
	parrent[next] = i;
	return dfs(next, order);
}

int main()
{
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test)
	{
		cerr << "Calculating Test " << test << endl;
		for (int i = 0; i < 200; ++i)
			vec[i].clear();
		fill(mark, mark+200, false);
		fill(parrent, parrent+200, -1);


		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int inp;
			cin >> inp;
			vec[i].push_back(inp-1);
		}

		int result = 0;
		vector<int> numbers;
		for (int i = 0; i < n; ++i)
			numbers.push_back(i);

		do{

			int sz = 1;
			//while(((numbers[(sz+1) % sz] == next || numbers[(i-1 + sz) % sz] == next)))
			for (int sz = n; sz > 1; --sz)
			{
				bool flag = true;
				for (int i = 0; i < sz; ++i)
				{
					int next = vec[numbers[i]][0];
					if(!(numbers[(i+1) % sz] == next || numbers[(i-1 + sz) % sz] == next)){
						flag = false;
						break;
					}
				}
				if (flag)
				{
					result = max(result, sz);
					break;
				}
			}

		}while(next_permutation(numbers.begin(), numbers.end()));

		printf("Case #%d: %d\n", test+1,result);
	}

	return 0;
}