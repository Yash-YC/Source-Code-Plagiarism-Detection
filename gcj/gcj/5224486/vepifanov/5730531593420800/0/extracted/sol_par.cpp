#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
string s, p;

int stoi (string s) {
	int x = 0;
	for (int i = 0; i < sz (s); i++) x = x * 10 + s[i] - '0';
	re x;
}

int get (string p) {
	int x = 0;
	for (int i = 0; i < sz (p); i++)
		if (p[i] != '.')
			x = x * 10 + p[i] - '0';
	re x;
}

int main (int argc, char **argv) {
	int NUM = stoi (string (argv[1]));
	int CNT = stoi (string (argv[2]));
	freopen (argv[3], "r", stdin);
	string output = "output." + string (argv[1]);
	freopen (output.c_str (), "w", stdout);
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> p >> s;
		if ((it - 1) % CNT != NUM) continue;
		int P = get (p);
		pair<ii, int> best (mp (1e9, 1), 0);
		for (int i = 0; i < n; i++) {
			int one = 0;
			for (int j = i; j < n; j++) {
				one += int (s[j] == '1');
				int len = j - i + 1;
				ii cur (abs (P * len - one * 1000000), 1000000 * len);
//				printf ("%d %d = %.10f\n", i, j, (cur.fi + 0.0) / cur.se);
				if ((ll)cur.fi * best.fi.se < (ll)cur.se * best.fi.fi) best = mp (cur, i);
			}
		}
		cout << "Case #" << it << ": " << best.se << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
