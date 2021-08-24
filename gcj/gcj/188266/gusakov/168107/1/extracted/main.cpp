#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker,"/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

template<class T>T abs(T x) { return (x>0) ? x : -x; }
template<class T>T sqr(T x) { return x*x;            }

const int MAX=1000*1000;
const int MAX2=100*1000*1000;

char ans[11][MAX];

bool good(int base, int n) {
	if (n==1) return true;
	char tmp=-1;
	char &res=n<MAX ? ans[base][n] : tmp;
	if (res!=-1) return res;
	res=0;
	int nn=0;
	while (n) {
		nn+=sqr(n%base);
		n/=base;
	}
	res=good(base,nn);
	return res;
}

map<vi,int> mans;

int solve(vi v) {
	for (int i=0; i<sz(v); i++) cerr<<v[i]<<" "; cerr<<endl;
	if (mans.count(v)) return mans[v];
	for (int ans=2; ans<MAX2; ans++) {
		bool ok=true;
		for (int i=0; i<sz(v); i++)
			if (!good(v[i],ans)) {
				ok=false;
				break;
			}
		if (ok) return mans[v]=ans;				
	}
	return -1;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	memset(ans,-1,sizeof(ans));
	int tn;
	scanf("%d\n",&tn);
	for (int tst=1; tst<=tn; tst++) {
		cerr<<tst<<endl;
		printf("Case #%d: ",tst);
		char buf[100];
		gets(buf);
		string str=buf;
		istringstream in(str);
		vi v;
		int tmp;
		while (in>>tmp)
			v.pb(tmp);
		cout<<solve(v)<<endl;
	}

	return 0;
}
