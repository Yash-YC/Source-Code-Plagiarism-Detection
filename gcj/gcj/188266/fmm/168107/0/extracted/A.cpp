#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

map<int,int> mark;
int base, val;

int v[100], q;

bool ok(int n) {
	mark.clear();
	while(!mark[n]++) {
		val = 0;
		while(n) {
			val += (n%base)*(n%base);
			n /= base;
		}
		n = val;
	}
	return (n == 1);
}

char linha[1000];

int main() {

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	gets(linha);
	sscanf(linha,"%d",&t);
	
	for(int k = 1; k <= t; k++) {
		gets(linha);
		istringstream str(linha);
		q = 0;
		while(str >> v[q]) {
			q++;
		}
			
		for(int i = 2; ; i++) {
			for(int j = 0; j < q; j++) {
				base = v[j];
				if(!ok(i)) goto end;
			}
			printf("Case #%d: %d\n",k,i);break;
			end: base = 0;
		}
	}
	
	return 0;
	
}
