/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define ALL(s) (s).begin(),(s).end()
#define R(i,m,n)	for(int i=m;i>=n;i--)
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define VI vector<int>
#define PB push_back
#define CLR(s,v) memset(s,v,sizeof(s))
string to_str(LL x){ ostringstream o;o<<x;return o.str();}
LL to_int(string s){ istringstream st(s); LL i;	st>>i;return i;}
#define FR(it,t) for(typeof(t.begin()) it=t.begin(); it!=t.end(); ++it)
typedef pair<int,int> PI;
#define MP(x,y) make_pair(x,y)
#define f first
#define s second
#define VP vector<PI>
#define S(t)	scanf("%d",&t)

int _tobase(int n,int b){
	int tn=1,ret=0;
	while(n){
		ret+=tn*(n%b);
		n/=b;
		tn*=10;
	}
	return ret;
}

map<int,int> mp;
bool fn(int k,int b){
	if(mp[k])	return false;
	if(k==1)	return true;
	mp[k]=1;
	int sm=0;
	while(k){
		sm+=(k%10)*(k%10);
		k/=10;
	}
	k=sm;
	k=_tobase(k,b);
	return fn(k,b);
}

int main(){
	int t;
	string s;
	cin>>t;
	getline(cin,s);
	FF(cas,1,t+1){
		getline(cin,s);
		stringstream sm(s);
		VI v;
		int k;
		while(sm>>k)	v.PB(k);
		int i=2;
		while(true){
			int jj=1;
			F(j,v.size()){
				k=_tobase(i,v[j]);
				mp.clear();
				if(fn(k,v[j]))	continue;
				else{	jj=0;break;}
			}
			if(jj)	break;
			i++;
		}
		cout<<"Case #"<<cas<<": "<<i<<endl;
	}
	return 0;
}
