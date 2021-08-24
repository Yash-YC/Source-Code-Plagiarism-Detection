#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void) {
	int T;

	ifstream fin("A-small-attempt0 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		string ret, S;
		fin >> S;
		ret = S[0];
		FOR(i, 1, S.size() - 1) {
			if (S[i] >= ret[0]) {
				ret = S[i] + ret;
			} else {
				ret += S[i];
			}
		}

		fout << "Case #" << t + 1 << ": " << ret << endl;
	}
	return 0;
}
