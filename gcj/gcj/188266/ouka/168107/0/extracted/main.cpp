#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int T;
bool mem[1000000];

bool ok(int x, int k)
{
	if (x == 1) return 1;
	memset(mem, 0, sizeof(mem));
	while (1)
	{
		mem[x] = 1;
		int next = 0;
		while (x)
		{
			next += (x % k) * (x % k);
			x /= k;
		}
		if (next == 1) return 1;
		if (mem[next]) return 0;
		x = next;
	}
}

void solve()
{
	vector<int> bases;
	bases.clear();
	string str;
	getline(fin, str);
	istringstream is(str);
	int temp;
	while (is >> temp)
		bases.push_back(temp);
	int ans = 2;
	memset(mem, 0, sizeof(mem));
	while (1)
	{
		bool flag = 1;
		for (int i = 0; i < (int)bases.size(); ++i)
			if (!ok(ans, bases[i]))
			{
				flag = 0; break;
			}
		if (flag) break;
		++ans;
	}
	fout << ans << endl;
	cout << ok(3,3) << endl;
}

int main()
{
	fin >> T;
	string junk;
	getline(fin, junk);
	for (int cas = 1; cas <= T; ++cas)
	{
		fout << "Case #" << cas << ": ";
		solve();
	}
	fin.close();
	fout.close();
	return 0;
}
