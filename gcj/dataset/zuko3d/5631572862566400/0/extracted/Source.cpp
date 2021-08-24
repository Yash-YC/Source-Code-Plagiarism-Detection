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

vector<int> bff;

int traverse(int start, vector<bool> done, int begin, int prev) {
	int cur = -1, best = -1;
	done[start] = true;
	while(!done[bff[start]])
	{
		done[bff[start]] = true;
		prev = start;
		start = bff[start];
	}
	if (bff[start] == begin) {
		best = 0;
		REP(i, done.size()) if (done[i]) best++;
		return best;
	}
	if (bff[start] != prev) return -1;
	best = 0;
	REP(i, done.size()) if (done[i]) best++;
	
	
	REP(i, done.size()) {
		if (!done[i]) {
			cur = traverse(i, done, begin, start);
			if (cur > best) best = cur;
		}
	}
	return best;
}

int main(void) {
	int T;

	ifstream fin("C-small-attempt1 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		int best = -1, cur;
		int n;
		fin >> n;
		bff.resize(n);

		REP(i, n) {
			fin >> bff[i];
			bff[i]--;
		}

		vector<bool> done;
		done.resize(n);
		REP(q, n) done[q] = false;
		REP(i, n) {
			cur = traverse(i, done, i, -2);
			if (cur > best) best = cur;
		}

		fout << "Case #" << t + 1 << ": " << best << endl;
	}
	return 0;
}
