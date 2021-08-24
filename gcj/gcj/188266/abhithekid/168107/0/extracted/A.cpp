#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <limits>
#include <iterator>
#include <sstream>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i != _b; ++i)
#define REP(i, N) FOR(i, 0, N)
#define REPK(K) REP(_crazyName, K)

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

template<typename CType, typename VType>
inline void REMOVE(CType &container, const VType &value) {
	container.erase(remove(ALL(container), value), container.end());
}

#define sz() size()
#define len() length()
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef long long LL;

int calc(vector< vector<int> > &isHappy, int num, int base) {
	if (num > isHappy[base].size())
		return 0;

	// cycle
	if (isHappy[base][num] == -2)
		return isHappy[base][num] = 0;

	if (isHappy[base][num] != -1)
		return isHappy[base][num];

	int next = 0, numbak = num;
	while (num) {
		int dig = num % base;
		dig *= dig;
		num /= base;
		next += dig;
	}

	if (next == numbak)
		return isHappy[base][numbak] = 0;


// cout << numbak << ' ' << next << endl;

	isHappy[base][numbak] = -2;

	return isHappy[base][numbak] = (next == 1 ? 1 : calc(isHappy, next, base));
}

inline int countOnes(int num) {
	int ret = 0;
	while (num) {
		num &= num - 1;
		++ret;
	}
	return ret;
}

int main() {
	vector< vector<int> > isHappy(11, vector<int>(100000, -1));


	for (int i = 2; i <= 10; ++i)
		for (int j = 0; j < isHappy[i].size() / 2; ++j)
			calc(isHappy, j, i);

	int T;
	cin >> T;

	REP (kase, T) {
		string str;
		getline(cin, str);

		if (str.length() == 0) {
			--kase;
			continue;
		}

		istringstream iss(str);
		vector<int> bases;
		int baseVal;
		while (iss >> baseVal)
			bases.pb(baseVal);

		if (bases.sz() == 0) {
			--kase;
			continue;
		}

		FOR (i, 2, isHappy.front().sz()) {
			bool ok = true;
			REP (j, bases.sz()) {
				if (isHappy[bases[j]][i] != 1) {
					ok = false;
					break;
				}
			}

			if (ok) {
				cout << "Case #" << (kase + 1) << ": " << i << endl;
				break;
			}
		}
	}
}
