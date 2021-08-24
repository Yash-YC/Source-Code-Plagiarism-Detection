#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;

string readLine() {
	char sz[10000];
	fgets(sz, 10000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}

int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}

vector<int> itokens(string s, string sep = " \n\r\t") {
	vector<int> res;
	int start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

vector<int> readVILine() {
	string s = readLine();
	return itokens(s);
}

vector<int> first;

int sumsqb(int i, int b) {
	int ss = 0;
	while (i) {
		ss += (i%b)*(i%b);
		i /= b;
	}
	return ss;
}

#define HMX 1000

void prep() {
	first.resize(1024, 0);
	vector<int> happy;
	happy.resize(HMX, 0);
	happy[0] = 0;
	happy[1] = 0x7fffffff;
	for (int b = 2; b <= 10; b++) {
		vector<int> bh(HMX, -1);
		bh[1] = 1;
		for (int i = 2; i < HMX; i++) if (bh[i] < 0) {
			int v = i;
			set<int> seen;
			while (v >= i && seen.find(v) == seen.end()) {
				seen.insert(v);
				v = sumsqb(v, b);
			}
			if (bh[v] == 1) {
				for (set<int>::iterator it = seen.begin(); it != seen.end(); ++it) {
					bh[*it] = 1;
					happy[*it] |= 1<<(b-2);
				}
			} else {
				for (set<int>::iterator it = seen.begin(); it != seen.end(); ++it)
					bh[*it] = 0;
			}
		}
	}
	for (int i = 2; i < HMX; i++) if (first[happy[i]] == 0) {
		for (int j = 0; j < 1023; j++) if (first[happy[i]&j] == 0) first[happy[i]&j] = i;
	}
	int tgtms = (1<<9)-1;
	for (int i = HMX; i < 1000000000; i++) {
		int ms = 0;
		for (int b = 2; b <= 10; b++) if ((happy[sumsqb(i, b)]>>(b-2))&1)
			ms |= 1<<(b-2);
		if (first[ms] == 0)
			for (int j = 0; j < 1023; j++) if (first[ms&j] == 0) first[ms&j] = i;
		if (ms == tgtms) {
			fprintf(stderr, "Done at %d\n", i);
			break;
		}
	}
//	for (int i = 2; i < 20; i++) {
//		for (int b = 2; b <= 10; b++) printf("%d ", (happy[i]>>b)&1);
//		printf("\n");
//	}
}

int solveIt(vector<int> bs) {
	int ms = 0;
	for (int i = 0; i < bs.size(); i++) ms |= 1<<(bs[i]-2);
	return first[ms];
}

int main(int argc, char ** /*argv*/) {
	dbg = argc;
	prep();
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		vector<int> bs = readVILine();
		long long res = solveIt(bs);
		printf("Case #%d: %lld\n", cn, res);
	}
	return 0;
}

