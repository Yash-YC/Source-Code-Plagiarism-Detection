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

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

long nextgreen(long time, int g, int r, long t0) {
	int k=g+r;
	if (t0>time) {
		t0 -= (((t0-time-1)/k)+1)*k;
	} else {
		t0 += ((time-t0)/k)*k;	
	}
	if ((time-t0)<g)
		return time;// is green
	else
		return t0+k;
}


vector<vector<int> > Ss,Ws,Ts;
int N,M;


long getsem(int r, int c, long time, bool north) {
	int s = Ss[r][c];
	int w = Ws[r][c];
	int t0 = Ts[r][c];
	if (!north) {
		t0 += s;
		swap(s,w);
	}
	return nextgreen(time, s/*green=north*/, w, t0);
}
bool debug=false;
vector<vector<long> > times;
int solve() {
	times = vector<vector<long> >(N*2, vector<long>(M*2, -1));
	times[0][0]=0;
	priority_queue<long> q;
	q.push(0);
	while (q.size()) {
		long pos=-q.top();
		q.pop();
		long curt = pos / 10000;
		int curr = pos % 100;
		int curc = (pos / 100 ) % 100;
		if (curr==N*2-1 && curc==M*2-1) {
			return curt;
		}
		if (times[curr][curc]>0) 
			continue;
		if(debug)cout<<"in (r"<<curr<<",c"<<curc<<") at "<<curt<<endl;
		times[curr][curc] = curt;
		FN(i,4) {
			int nextr = curr+dr[i];		
			int nextc = curc+dc[i];		
			if (nextr>=0 && nextc>=0 && nextr<2*N && nextc<2*M && times[nextr][nextc]<0) {
				int nextt = -1;
				if ((curr>>1)!=(nextr>>1) || (curc>>1)!=(nextc>>1)) { // cuadra
					nextt = curt+2;
				} else { //semaforo
					nextt = getsem(curr>>1,curc>>1,curt,nextr!=curr)+1;
				}			
				long pp = nextt*10000+nextc*100+nextr;
				if(debug)cout<<"queued (r"<<nextr<<",c"<<nextc<<") at"<<nextt<<endl;
				q.push(-pp);
			}			
		}
		
	}
	return 123;
}

#include "stdio.h"
int main(int argc, char* argv[])
{
	int CASES;
	cin >> CASES;
	for (int test=0; test<CASES; test++) {
		cin>>N>>M; //nrows m cols
		Ws=Ss=Ts=vector<vector<int> >(N, vector<int>(M, -1));
		FN(r,N) {
			FN(c,M) {
				cin>>Ss[r][c]>>Ws[r][c]>>Ts[r][c];
			}
		}
		if(debug){cout<<"S:"<<Ss<<endl;		
			cout<<"W:"<<Ws<<endl;		
			cout<<"T:"<<Ts<<endl;	}	
		long sol = solve();
		cout<<"Case #"<<(test+1)<<": "<<sol<<endl;
	}
	return 0;
}
// END CUT HERE 
