#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


const int N = 100000;
int memo[11][N];

bool check(const int n, const int b)
{
	int val = n;
	bool f[N] = { 0 };
	while (val != 1) {
		if (f[val]) return false;
		f[val] = true;
		if (memo[b][val] != -1) return memo[b][val];
		int t = 0;
		while (val) {
			int x = val % b;
			t += x*x;
			val /= b;
		}
		val = t;
	}
	return true;
}

int main()
{
	fstream fout("out.txt");
	fstream fin("in.txt");

	fill(&memo[0][0], &memo[10][N], -1);


	for (int x=2; x < N; ++x) {
		for (int i=2; i < 10; ++i) {
			memo[i][x] = check(x, i);
		}
	}

	int T;
	fin>>T;

	string buf;
	getline(fin, buf);
	for (int q=0; q < T; ++q) {
		getline(fin, buf);
		istringstream is(buf);
		vector<int> v;
		int t;
		while (is>>t) v.push_back(t);

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int x;
		for (x=2; x < N; ++x) {
			bool isOk = true;
			for (int i=0; i < v.size(); ++i) {
				if (memo[v[i]][x] == 0) {
					isOk = false;
					break;
				}
				if (memo[v[i]][x] == 1) continue;
				memo[v[i]][x] = check(x, v[i]);
				if (memo[v[i]][x]==0) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				break;
			}
		}
		static int counter = 0;
		fout << "Case #" << ++counter << ": " << x << endl;
		cout << "Case #" << counter << ": " << x << endl;
	}

	fout.close();
	fin.close();

	return 0;
}