#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

template <class A, class B> void CONV(A& x, B& y) { stringstream s; s << x; s >> y; }
typedef long long LL;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORE(i, v) FOR(i, 0, v.size())
#define FORU(i, a) for (int i = a; ; ++i)
#define SORT(v) sort(v.begin(), v.end())
#define SET(a, n) memset(a, n, sizeof a)

void sum(string& a, const string& b, int base) {
	if (a.size() < b.size()) a.insert(0, string(b.size()-a.size(), '0'));
	int i = a.size()-1, j = b.size()-1;
	for (; j >= 0; --i, --j) {
		a[i] += b[j]-'0';
		if (a[i] > (base-1)+'0') {
			a[i] -= base;
			if (i == 0) {
				a.insert(a.begin(), '1');
				return;
			}
			++a[i-1];
		}
    }
    for (; a[i] > (base-1)+'0'; --i) {
		a[i] -= base;
		if (i == 0) {
			a.insert(a.begin(), '1');
			return;
		}
		++a[i-1];
	}
}

void mul(const string& a, const string& b, string& res, int base) {
	//vector<int> temp(a.size()*b.size()+1, 0);
	vector<int> temp(50, 0);
	for (int i = a.size()-1; i >= 0; --i)
		for (int j = b.size()-1, k = temp.size()-(a.size()-i); j >= 0; --j, --k)
			temp[k] += (a[i]-'0')*(b[j]-'0');
	for (int i = temp.size()-1; i > 0; --i) {
		temp[i-1] += temp[i]/base;
		temp[i] %= base;
	}
	for (int i = 0; ; ++i) {
        if (i == temp.size()-1 || temp[i] != 0) {
            res = string(temp.size()-i, '0');
            for (int j = 0; j < res.size(); ++j) res[j] += temp[i+j];
            return;
        }
    }
}

void getn(string& s, int base) {
	LL temp;
	CONV(s, temp);
	s = "";
	while (temp > 0) {
		s += (temp%base)+'0';
		temp /= base;
	}
	reverse(s.begin(), s.end());
}
	

	/*
	for (int i = s.size()-1; i >= 0; --i) {
		int cur = s[i]-'0';
		int div = cur/base;
		if (div >= 1) {
			s[i] = (cur%base)+'0';
			if (i == 0) {
				s = string(1, div+'0')+s;
   */
				

void getnext(string& s, int base) {
	string res = "0";
	FORE(i, s) {
		string a = string(1, s[i]), b = string(1, s[i]), temp;
		mul(a, b, temp, base);
		sum(res, temp, base);
	}
	s = res;
}

bool check(string& cur, int base, int k) {
	map<string, bool> vis;
	for(;;) {
		//cout << cur << endl;
		if (cur == "1") return true;
		if (vis.count(cur)) return false;
		vis[cur] = true;
 		getnext(cur, base);
	}
}

int main() {
	int t;
	cin >> t;
	cin.get();
	FOR(i, 0, t) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		vector<int> v;
		int temp;
		while (ss >> temp) v.push_back(temp);
		string res = "2", one = "1";
		for(;;) {
			//cout << res << ":\n";
			FORU(k, 0) {
				//cout << "--" << v[k] << endl;
				if (k == v.size()) {
					cout << "Case #" << i+1 << ": " << res << endl;
					goto out;
				}
				string cur = res;
				getn(cur, v[k]);
				//if (res == "8" && v[k] == 2) cout << cur << endl;
				if (!check(cur, v[k], k)) break;
			}
			sum(res, one, 10);
		}
		out: {}
	}
}
