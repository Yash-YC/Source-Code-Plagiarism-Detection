#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

#define sz(A) (int)(A).size()
#define vs vector<string>
#define vi vector<int>
#define ll long long
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define pb push_back
#define pii pair<int,int>
#define inf (1<<25)
#define infL 10000000000000000LL
#define F first
#define S second
#define all(x) x.begin() , x.end()

char in[1000];
vi bases;
set<int> ja;

map < pii, int > pd;

string converte(int x, int b) {
	string s = "";
	int aux;
	while(x != 0) {
		aux = x%b;
		x /= b;
		s += " ";
		s[ sz(s) - 1 ] = aux + '0';
	}
	return s;
}

int calc(int x, int b) {
	if( pd.count(pii (x,b)) ) return pd[ pii(x,b) ];
	if(ja.count(x)) return pd[ pii(x,b) ] = 0;
	ja.insert(x);

	if(x == 1) return pd[ pii(x, b) ] = 1;
	string s = converte(x, b);
	int rr = 0;
	FOR(i, sz(s))
		rr += (s[i]-'0')*(s[i]-'0');
	return calc(rr, b);
}

int main() {
	int T;
	scanf("%d\n", &T);
	pd.clear();
	FOR(t,T) {
		printf("Case #%d: ", t+1);
		fgets(in, 500, stdin);
		string ent(in);
		stringstream rr(ent);
		bases.clear();
		int x;
		while(rr >> x) bases.pb(x);

		for(int i=2; ;i++) {
			int ok = 1;
			FOR(j, sz(bases)) {
				if(pd.count( pii( i, bases[j] )))
					ok = pd[ pii(i, bases[j] )];
				if(!ok) break;
			}
			FOR(j, sz(bases)) {
				if(!ok) break;
				ja.clear();
				ok = calc(i, bases[j]);
				if(!ok) break;
			}
			if(ok) {
				printf("%d\n", i);
				break;
			}
		}
	}

    return 0;
}

