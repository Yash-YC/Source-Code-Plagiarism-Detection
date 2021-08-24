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

#define T 10000000

map < pii, int > pd;
int pd2[T][10];

set<int> ja;

map< vi, int> megapd;

int converte(int x, int b) {
	int rr = 0;
	int aux;
	while(x != 0) {
		aux = x%b;
		x /= b;
		rr += aux*aux;
	}
	return rr;
}

int calc(int x, int b) {
	if(x < T) {
		if(pd2[x][b-1] != -1)
			return pd2[x][b-1];
	}
	else{
		if( pd.count(pii (x,b)) ) return pd[ pii(x,b) ];
	}


	if(ja.count(x)) {
		if(x < T)
			return pd2[x][b-1] = 0;
		return pd[ pii(x,b) ] = 0;
	}

	ja.insert(x);

	if(x == 1) {
		return pd2[x][b-1] = 1;
		return pd[ pii(x, b) ] = 1;
	}
	int rr = converte(x, b);

	if(x < T)
		return pd2[x][b-1] = calc(rr, b);
	else
		return pd[pii(x,b-1)] = calc(rr, b);
}

int main() {
	int TT;
	scanf("%d\n", &TT);
	pd.clear();
	megapd.clear();
	memset(pd2, -1, sizeof(pd2));
	FOR(t,TT) {
		printf("Case #%d: ", t+1);
		fgets(in, 500, stdin);
		string ent(in);
		stringstream rr(ent);
		bases.clear();
		int x;
		while(rr >> x) bases.pb(x);
		int ini = 1;
//		FOR(i,sz(bases))
//			ini *= bases[i];

		ini = 2;

		if(megapd.count(bases))
			printf("%d\n", megapd[bases]);
		else
			for(int i=ini; ;i++) {
				int ok = 1;

				FOR(j, sz(bases)) {
					if(i < T) {
						if(pd2[i][bases[j]-1] != -1)
							ok = pd2[i][bases[j]-1];
					}
					else {
						if(pd.count( pii( i, bases[j] )))
							ok = pd[ pii(i, bases[j] )];
					}
					if(!ok) break;
				}

				FOR(j, sz(bases)) {
					if(!ok) break;
					ja.clear();
					ok = calc(i, bases[j]);
					if(!ok) break;
				}

				if(ok) {
					megapd[bases] = i;
					printf("%d\n", i);
					break;
				}
			}
	}

	return 0;
}

