#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int dp[11][1000];

int ishappy(int base, int num)
{
	if (num < 1000 && dp[base][num] >= 0) {
		return dp[base][num];
	}
	if (num < 1000) {
		dp[base][num] = 0;
	}
	int newnum = 0;
	int curnum = num;
	while (curnum > 0) {
		newnum += (curnum % base) * (curnum % base);
		curnum /= base;
	}
	int ret = (newnum == 1) ? 1 : ishappy(base, newnum);
	if (num < 1000) {
		dp[base][num] = ret;
	}
	return ret;
}

int MultibaseHappiness(vector <int> bases)
{
	memset(&(dp[0][0]), -1, sizeof(dp));

	for (int i = 2; ; i++) {
		for (int j = 0; j <= bases.size(); j++) {
			if (j == bases.size()) {
				return i;
			} else if (!ishappy(bases[j], i)) {
				break;
			}
		}
	}

	return 0;
}

int main()
{
	string line;

	int cases;
	cin >> cases;
	getline(cin, line);

	for (int caseno = 1; caseno <= cases; caseno++) {
		getline(cin, line);
		stringstream ss(line);
		vector <int> bases;
		int num;
		while (ss >> num) {
			bases.push_back(num);
		}

		int ret = MultibaseHappiness(bases);

		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
