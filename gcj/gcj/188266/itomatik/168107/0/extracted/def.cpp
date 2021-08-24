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

int main()
{
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
			bases.pb(atoi(a[i].c_str()));
		}

		int ans = 2;
		while (!is_ok(ans)) {
			ans++;
		}
		cout << "Case #" << nt << ": " << ans << endl;
		out << "Case #" << nt << ": " << ans << endl;
	}

	inp.close();
	out.close();
	return 0;
}
