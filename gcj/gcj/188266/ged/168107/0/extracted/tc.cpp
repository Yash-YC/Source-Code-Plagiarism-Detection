#include <vector>
#include <list>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define FN(i,n) for (int i=0; i<(int)(n); i++)
#define SZ(c) ((int)(c).size())

#define FBE(i,v,T) for (vector<T >::iterator i=(v).begin(); i!=(v).end(); i++)
#define FEB(i,v,T) for (vector<T >::reverse_iterator i=(v).rbegin(); i!=(v).rend(); i++)
#define ABS(a) ((a)<0?-(a):(a))
#define PI     3.14159265358979323846
#define MIN (a,b)  ((a)<(b) ? (a) : (b))
#define MAX (a,b)  ((a)<(b) ? (b) : (a))
#define MAXINT (1<<30)
#define MININT (-MAXINT)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
template<class X,class Y> ostream &operator<<(ostream &s, pair<X,Y> p){s<<p.first<<'@'<<p.second;return s;}
template<class V> ostream &operator<<(ostream &s, list<V> v){char c='{';for (typename list<V >::iterator i=v.begin(); i!=v.end();i++){s<<c<<*i; c=','; }s<<'}';return s;}
template<class A> string printString(A o ) { ostringstream s; (s << o); return s.str(); }
template<class C> void kill(C&c){for(typename C::iterator i=c.begin(); i!=c.end(); i++)kill:for(typename C::iterator j=i+1;j!=c.end();j++)if(*i==*j){*j=c.back();c.pop_back();goto kill;}}
template<class TA, class TV> void feed(vector<TV> &v, TA a[], int n) {  v.clear(); FN(i,n) v.push_back(TV(a[i])); }
#define FEED(vec,arr) feed((vec),(arr),sizeof((arr))/sizeof((arr)[0]))
#define all(a) (a).begin(), (a).end()
vector<string> tokens(const string &str, const string &delims){
	char *buf = strdup(str.c_str()), *token;
	const char *dels = delims.c_str();
	vector<string> v;
	token = strtok( buf, dels );
	while (token) {	v.push_back(token);	token = strtok(NULL, dels);	}
	free(buf);
	return v;
}
#define erase_unique(v)     (v).erase(unique(all(v)),v.end())  
#define erase_remove(v,val) (v).erase(remove(all(v),(val)),v.end()) 

template<class T> ostream &operator<<(ostream &s, vector<T> v){char c='[';for(typename vector<T >::iterator i=v.begin();i!=v.end();i++){s<<c<<*i;c=',';}s<<']';return s;}
// END CUT HERE 

int debug=0;
map<long,bool> mems[11];
map<long,bool> visited;
int ishappy2(int n,int base) {
//	cout<<"f("<<n<<","<<base<<") enter..."<<endl;
	if (mems[base].find(n)!=mems[base].end()) 
		return mems[base][n];
	int k=n,sum=0;
	while (k) {
		int d=k%base;
		sum+=d*d;
		k/=base;
	}
	if (sum==1) return mems[base][n]=true;
	if (visited[sum]) return mems[base][n]=false;
	visited[sum]=true;
	if(debug)cout<<"sum("<<n<<",b"<<base<<")="<<sum<<endl;
	return mems[base][n]=ishappy2(sum,base);
}
int ishappy(int n,int base) {
	visited.clear();
	visited[n]=true;
	return ishappy2(n,base);
}

#include "stdio.h"
int main(int argc, char* argv[])
{
	int CASES;
	cin >> CASES;
	char buf[1000];
	cin.getline(buf,1000);
	for (int test=0; test<CASES; test++) {
		cin.getline(buf,1000);
		vector<int> bases;
		vector<string> sbases=tokens(string(buf)," ");
		FN(i,sbases.size()) {
			bases.push_back(sbases[i]=="10"?10:sbases[i][0]-'0');
		}
		if(debug)cout<<"BASES: "<<bases<<endl;		
		
		int n=2;
		while(true) {
			int happy=true;
			for(int i=0; happy && i<SZ(bases); i++) {
				bool ret = ishappy(n,bases[i]);
				if(debug)cout<<n<<"is happy in base "<<bases[i]<<"? "<<ret<<endl;
				happy = happy&&ret;
			}
			if (happy) break;
			n++;
		}
		cout<<"Case #"<<(test+1)<<": "<<n<<endl;
//		cout<<"exiting!"<<endl;break;
	}
	return 0;
}
// END CUT HERE 
