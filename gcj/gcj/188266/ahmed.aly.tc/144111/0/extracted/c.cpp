#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define rep2(i,x,m) for(int i=x;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo = (int) 1e9;
int N,I,J;
int s[20][20];
int w[20][20];
int t[20][20];

struct st{
	int i,j,cr,c;
	st(){}
	st(int ii,int jj,int rr,int cc){
		i=ii;
		j=jj;
		cr=rr;
		c=cc;
	}
	bool operator <(const st &s2)const{
		return mp(mp(c,cr),mp(i,j))<mp(mp(s2.c,s2.cr),mp(s2.i,s2.j));
	}
};
set<st> q;
bool south(int i,int j,int ti){
	if(ti<t[i][j]){
		int d=t[i][j]-ti;
		d/=s[i][j]+w[i][j];
		d+=5;
		ti+=d*(s[i][j]+w[i][j]);
	}
	ti-=t[i][j];
	ti%=s[i][j]+w[i][j];
	if(ti<s[i][j])
		return 1;
	return 0;
}
int bfs(){
	q.clear();
	q.insert(st(I,0,1,0));
	while(!q.empty()){
		st t=*q.begin();
		q.erase(q.begin());
		if(t.i==0 && t.j==J && t.cr==2)
			return t.c;
		if(t.i==0 && (t.cr==0 || t.cr==1))
			continue;
		if(t.i==I && (t.cr==2 || t.cr==3))
			continue;
		if(t.j==0 && (t.cr==0 || t.cr==2))
			continue;
		if(t.j==J && (t.cr==1 || t.cr==3))
			continue;
		q.insert(st(t.i,t.j,t.cr,t.c+1));
		if(t.cr==0){
			q.insert(st(t.i,t.j,1,t.c+2));
			q.insert(st(t.i,t.j,2,t.c+2));
			int ii=t.i-1;
			int jj=t.j-1;
			if(south(ii,jj,t.c))
				q.insert(st(t.i-1,t.j,2,t.c+1));
			else
				q.insert(st(t.i,t.j-1,1,t.c+1));
		}else if(t.cr==1){
			q.insert(st(t.i,t.j,0,t.c+2));
			q.insert(st(t.i,t.j,3,t.c+2));
			int ii=t.i-1;
			int jj=t.j;
			if(south(ii,jj,t.c))
				q.insert(st(t.i-1,t.j,3,t.c+1));
			else
				q.insert(st(t.i,t.j+1,0,t.c+1));
		}else if(t.cr==2){
			q.insert(st(t.i,t.j,0,t.c+2));
			q.insert(st(t.i,t.j,3,t.c+2));
			int ii=t.i;
			int jj=t.j-1;
			if(south(ii,jj,t.c))
				q.insert(st(t.i+1,t.j,0,t.c+1));
			else
				q.insert(st(t.i,t.j-1,3,t.c+1));
		}else if(t.cr==3){
			q.insert(st(t.i,t.j,1,t.c+2));
			q.insert(st(t.i,t.j,2,t.c+2));
			int ii=t.i;
			int jj=t.j;
			if(south(ii,jj,t.c))
				q.insert(st(t.i+1,t.j,1,t.c+1));
			else
				q.insert(st(t.i,t.j+1,2,t.c+1));
		}
	}
	return -1;
}
int main() {
//#define SAMPLE
#ifndef SAMPLE
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small-attempt0.out","wt",stdout);
#endif
#ifdef SAMPLE
	freopen("a.txt", "rt", stdin);
#endif
	cin>>N;
	rep(nn,N){
		cin>>I>>J;
		rep(i,I)
			rep(j,J)
				cin>>s[i][j]>>w[i][j]>>t[i][j];
		printf("Case #%d: %d\n",nn+1,bfs());
	}
	return 0;
}
