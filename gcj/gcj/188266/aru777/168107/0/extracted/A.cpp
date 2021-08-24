#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define GI ({int t;scanf(" %d",&t);t;})
#define GC(x) scanf(" %c",&x)
#define sz size()
#define rz resize
#define inf 1e9
#define pb push_back

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef double D;
typedef long long LL;


VI ip;

int tobase(int a, int n) {
	VI temp;
	temp.clear();
	while(a!=0) {
		temp.pb(a%n);
		a/=n;
	}
	a=0;
	for(int i=temp.sz-1;i>=0;i--) a=a*10+temp[i];
	return a;
}

int frombase(int a, int n) {
	VI temp;
	temp.clear();
	while(a!=0) {
		temp.pb(a%10);
		a/=10;
	}
	a=0;
	for(int i=temp.sz-1;i>=0;i--) a=a*n+temp[i];
	return a;
}

int go(int a) {
	int n=0;
	while(a!=0) {
		n+=(a%10)*(a%10);
		a/=10;
	}
	return n;
}

int ishappy(int a, int n) {
	VI temp;
	temp.clear();
	set <int> Q;
	int h,k=tobase(a,n);
	while(1) {
		h=go(k);
//		cout<<h<<" ";
		h=tobase(h,n);
//		cout<<h<<endl;
		if(Q.find(h)!=Q.end()) return 0;
		Q.insert(h);
		k=h;
		if(k==1) break;
	}
	return 1;
}

int main() {
//	cout<<ishappy(91,9)<<endl;
	string test;
	int a,k=0,ind,_,yo=1;
	_=GI;
	getchar();
	while(_--) {
		getline(cin,test,'\n');
		istringstream sin(test);
		ip.clear();
		while(sin>>a) {
			if(a!=2 || a!=4) ip.pb(a);
		}
		ind=2;
		while(1) {
			k=0;
			REP (i,ip.sz) {
				if(ishappy(ind,ip[i]) == 0) {k=1; break; }
			}
			if(k==0) break;
			ind++;
		}
//		cout<<ind<<endl;
		cout<<"Case #"<<yo<<": "<<ind<<endl;
		yo++;
	}
	return 0;
}

