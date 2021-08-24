/*
 * A.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Sep 12, 2009
 */

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

const int OO = (int) 1e8; //Small -> WRONG, Large -> OVERFLOW

const double PI = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int main() {


	freopen("a.in", "rt", stdin);
	freopen("a.txt", "wt", stdout);

	int cases;
	cin >> cases;

	string line;
	getline(cin, line);

	int cc = 1;
	while (cases--) {
		getline(cin, line);
		istringstream iss(line);

		vector<ll> v;
		ll a;
		while (iss >> a)
			v.push_back(a);

		for (ll i = 2;; ++i) {
			bool fail = false;
			rep(j, v) {
				ll b = v[j];
				ll temp = i;

				set<int> vis;

				do {
					ll n = 0;

					while (temp) {
						int d = temp % b;
						n += d * d;
						temp /= b;
					}
					temp = n;
					if (vis.count(temp)) {
						fail = 1;
						break;
					}
					vis.insert(temp);

				} while (temp != 1);
			}
			if (!fail) {
				cout << "Case #" << cc++ << ": " << i << "\n";
				break;
			}
		}
	}

	return 0;
}
