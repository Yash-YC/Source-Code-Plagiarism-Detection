// cheburashka, bear-mouse, team template

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long ll;
typedef vector < string > vs;
typedef vector <int> vi;

ifstream inp("A.in");
ofstream out("A.out");

//string split given string a and delimiters
vs strsp(string a, string delim=" ")
{
  vs ret;
  string cr = "";
  for(int i = 0; i < a.size(); i++)
  {
    if(delim.find(a[i])==string::npos) cr += a[i];
    else { if(cr.size()) ret.push_back(cr); cr = ""; }
  }
  if(cr.size()) ret.push_back(cr);
  return ret;
}

vi bases;

bool happy(int x, int b) {
	set<int> vst;

	while (1) {
		int d, nx = 0, xx = x;
		while (xx > 0) {
			d = xx % b;
			nx += d * d;
			xx /= b;
		}		
		if (nx == 1) {
			return true;
		}
		if (vst.count(nx)) {
			return false;
		}
		vst.insert(nx);
		x = nx;
	}
}

bool is_ok(int x) {
	for (int i = 0; i < bases.size(); i++) {
		if (!happy(x, bases[i])) {
			return false;
		}
	}
	return true;
}

vi all[12];
set<int> all_s[12];

void generate() {
	int max = 2600000;
	for (int b = 3; b <= 10; b++) {
		if (b == 4) continue;
		int x = 2;
		bases.clear();
		bases.pb(b);
		while (x <= max) {
			if (is_ok(x)) {
				all[b].pb(x);
				all_s[b].insert(x);
			}
			x++;
		}
		cout << "base b:" << b << " number of happy:" << all[b].size() << endl;
		out << "b: " << b << endl;
		for (int i = 0; i < all[b].size(); i++) {
			out << all[b][i] << " ";
		}
		out << endl;
	}

	int bin, bases[10], _bases[10] = {3, 5, 6, 7, 8, 9, 10}, n = 7, m;
	
	for (bin = 1; bin < (1 << n) - 1; bin++) {
		m = 0;
		
		for (int i = 0; i < n; i++) {
			if ((bin & (1 << i))) {
				bases[m++] = _bases[i];
			}
		}

		bool found = false;
		int cur_ans = -1;
		int jm = 0;
		for (int j = 0; j < m; j++) {
			if (all[bases[j]].size() < all[bases[jm]].size()) {
				jm = j;
			}
		}

		for (int i = 0; i < all[bases[jm]].size(); i++) {
			bool flag = true;
			int &c = all[bases[jm]][i];
			for (int j = 0; j < m; j++) {
				if (j == jm) continue;
				if (!all_s[bases[j]].count(c)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				found = true;
				cur_ans = c;
			}
		}

		if (!found) {
			cout << "TOO BAD!!! DIDN'T WORK!";
			for (int i = 0; i < m; i++) {
				cout << bases[i] << " ";
			}
			cout << endl;

			getchar();
			exit(1);
		} else {
			out << bin << " " << cur_ans << endl;
		}
	}

	out.close();
}

int main()
{
	//generate();
	//return 0;

	int NT;
	inp >> NT;
	string tmp;
	getline(inp, tmp);
	for (int nt = 1; nt <= NT; nt++) {
		string s;
		getline(inp, s);
		vs a = strsp(s);
		bases.clear();		
		int n = a.size();
		for (int i = 0; i < n; i++) {
			if (a[i] != "2" && a[i] != "4") {
				bases.pb(atoi(a[i].c_str()));
			}
		}
		sort(bases.begin(), bases.end());
		bool found = false;
		int ans = 2, z = 0;		
		if (bases.size() == 7) {
			int _ans[7] = {3, 5, 6, 7, 8, 9, 10};
			bool f = true;
			for (int i = 0; i < 7; i++) {
				if (bases[i] != _ans[i]) {
					f = false;
					break;
				}
			}
			if (f) {
				found = true;
				ans = 11814485;
			}
		}
		if (!found && bases.size() == 6) {
			int _ans[6] = {3, 5, 6, 7, 8, 10};
			bool f = true;
			for (int i = 0; i < 6; i++) {
				if (bases[i] != _ans[i]) {
					f = false;
					break;
				}
			}
			if (f) {
				found = true;
				ans = 2688153;
			}
		}
		if (!found && bases.size() == 6) {
			int _ans[6] = {3, 6, 7, 8, 9, 10};
			bool f = true;
			for (int i = 0; i < 6; i++) {
				if (bases[i] != _ans[i]) {
					f = false;
					break;
				}
			}
			if (f) {
				found = true;
				ans = 4817803;
			}
		}
		if (!found && bases.size() == 6) {
			int _ans[6] = {5, 6, 7, 8, 9, 10};
			bool f = true;
			for (int i = 0; i < 6; i++) {
				if (bases[i] != _ans[i]) {
					f = false;
					break;
				}
			}
			if (f) {
				found = true;
				ans = 11814485;
			}
		}
		if (!found) {
			while (!is_ok(ans)) {
				ans++;
			}
		}
		cout << "Case #" << nt << ": " << ans << endl;
		out << "Case #" << nt << ": " << ans << endl;
	}

	inp.close();
	out.close();
	return 0;
}
