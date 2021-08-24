#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define sz(c) ((int)c.size())
#define pb push_back

map <int, bool> m[11];
map <int, bool> viz;

int sum(int a, int b) {
	string res = "";
	while (a > 0) {
		res += "0123456789"[a%b];
		a /= b;
	}

	int cnt[10]; memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < sz(res); i++)
		cnt[res[i]-'0']++;
	bool found = 1;
	for (int i = 2; i < 10; i++)
		if (cnt[i] > 0) { found = 0; break; }
	if (cnt[1] != 1) found = 0;
	if (found) return -1;

	int val = 0;
	for (int i = 0; i < sz(res); i++)
		val += (res[i]-'0')*(res[i]-'0');
	return val;
}

bool check(int a, int b) {
	if (m[b].count(a)) return m[b][a];
	if (viz.count(a)) return 0;
	viz[a] = 1;
	int s = sum(a, b);
	if (s == -1) return m[b][a] = 1;
	bool res = check(s, b);
	return m[b][a] = res;
}

int main() {
	ifstream fin("A-small.txt");
	FILE *fout = fopen("A-small.out", "w");
	
	int numtests;
	string dummy;
	fin >> numtests;
	getline(fin, dummy);
	for (int i = 1; i <= numtests; i++) {
		string line;
		getline(fin, line);
		stringstream ss(line);
		int b; vector <int> bases;
		while (ss >> b) bases.pb(b);
		for (int j = 2; 1; j++) {
			bool found = 1;
			for (int k = 0; k < sz(bases); k++) {
				viz.clear();
				if (m[bases[k]].count(j)) {
					found = m[bases[k]][j];
					if (!found) break;
				}
				else {
					found = check(j, bases[k]);
					if (!found) break;
				}
			}
			if (found) {
				fprintf(fout, "Case #%d: %d\n", i, j);
				break;
			}
		}
	}

	fclose(fout);
	return 0;
}


