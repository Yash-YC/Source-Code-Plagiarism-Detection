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

unsigned int snoob(unsigned int x) { // Returns next value with same number of 1s
	unsigned smallest, ripple, ones;
                                     // x = xxx0 1111 0000
	smallest = x & -x;           //     0000 0001 0000
	ripple = x + smallest;       //     xxx1 0000 0000
	ones = x ^ ripple;           //     0001 1111 0000
	ones = (ones >> 2)/smallest; //     0000 0000 0111
	return ripple | ones;        //     xxx1 0000 0111
}

map<long,double> dp;
int C,N;

double f(long mask) {
	if (mask==(1<<C)-1) return 0;
	if (dp.find(mask)!=dp.end()) return dp[mask];
//	cout<<"enter: "<<mask<<endl;
	
	long deck=(1<<N)-1, max=1<<C;
	int fail=0,count=0;
	double pp=0;
	while (deck<max) {
//		cout<<"test:"<<deck<<endl;
		long m2=deck|mask;
		if (m2==mask) 
			fail++;
		else
			pp += f(m2)+1;
		count++;
		deck = snoob(deck);
	}
	double ret = (pp+fail)/(count-fail);
//	cout<<"f("<<mask<<")="<<ret<<endl;
	dp[mask]=ret;
	return ret;
}
#include "stdio.h"
int main(int argc, char* argv[])
{
	int CASES;
	cin >> CASES;
	for (int test=0; test<CASES; test++) {
		cin>>C>>N;
		dp = map<long,double>();
		double res = f(0);
		printf("Case #%d: %0.6f\n", test+1, res);
//		cout<<"exiting!"<<endl;break;
	}
	return 0;
}
// END CUT HERE 
