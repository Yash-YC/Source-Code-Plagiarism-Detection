#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define INF LL(1e18)

typedef long long LL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int mn=4;
LL dist[mn][mn][4];				//0-SW 1-SE 2-NW 3-NE
int burn[mn][mn][4];					
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};	//0-S 1-E 2-N 3-W
int m,n;
LL s[mn][mn],w[mn][mn],t[mn][mn];

struct pt{
	int x,y,dir;	
};
pt src,dest;

#define ok(x,y)	(x>=0 && x<m && y>=0 && y<n)

LL fn(LL curtime,int t,int cycle,int s,bool mode){
	LL r=(curtime-t)%cycle;
	if(mode==0){		//going south
		if(r<s)	return curtime+1;
		else		return curtime+(cycle-r)+1;
	}
	else{
		if(r<s)	return curtime+(s-r)+1;
		else		return curtime+1;	
	}
}

LL dijkstra(){
	while(!burn[dest.x][dest.y][dest.dir]){
		LL mi=INF;
		pt dummy;
		REP(i,m)	REP(j,n)	REP(k,4)	if(!burn[i][j][k] && dist[i][j][k]<mi){
			mi=dist[i][j][k];
			dummy.x=i;dummy.y=j;dummy.dir=k;	
		}
		burn[dummy.x][dummy.y][dummy.dir]=1;
		LL curtime=mi;
		if(dummy.dir==0){
			if(ok(dummy.x,dummy.y-1))	dist[dummy.x][dummy.y-1][1]<?=curtime+2;
			if(ok(dummy.x+1,dummy.y))	dist[dummy.x+1][dummy.y][2]<?=curtime+2;
			dist[dummy.x][dummy.y][2]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],0);
			dist[dummy.x][dummy.y][1]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],1);
		}
		if(dummy.dir==1){
			if(ok(dummy.x,dummy.y+1))	dist[dummy.x][dummy.y+1][0]<?=curtime+2;
			if(ok(dummy.x+1,dummy.y))	dist[dummy.x+1][dummy.y][3]<?=curtime+2;
			dist[dummy.x][dummy.y][3]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],0);
			dist[dummy.x][dummy.y][0]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],1);
		}
		if(dummy.dir==2){
			if(ok(dummy.x,dummy.y-1))	dist[dummy.x][dummy.y-1][3]<?=curtime+2;
			if(ok(dummy.x-1,dummy.y))	dist[dummy.x-1][dummy.y][0]<?=curtime+2;
			dist[dummy.x][dummy.y][0]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],0);
			dist[dummy.x][dummy.y][3]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],1);
		}
		if(dummy.dir==3){
			if(ok(dummy.x,dummy.y+1))	dist[dummy.x][dummy.y+1][2]<?=curtime+2;
			if(ok(dummy.x-1,dummy.y))	dist[dummy.x-1][dummy.y][1]<?=curtime+2;
			dist[dummy.x][dummy.y][1]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],0);
			dist[dummy.x][dummy.y][2]<?=fn(curtime,t[dummy.x][dummy.y],s[dummy.x][dummy.y]
				+w[dummy.x][dummy.y],s[dummy.x][dummy.y],1);
		}
	}
	return dist[dest.x][dest.y][dest.dir];
}

int main(){
	
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Kase=GI;
	FOR(kase,1,Kase+1){
		m=GI,n=GI;
		REP(i,mn)	REP(j,mn)	s[i][j]=t[i][j]=w[i][j]=0;
		REP(i,m)	REP(j,n)	scanf("%Ld%Ld%Ld",&s[i][j],&w[i][j],&t[i][j]);	
		REP(i,m)	REP(j,n)	t[i][j]%=(s[i][j]+w[i][j]),t[i][j]-=(s[i][j]+w[i][j]);
		REP(i,mn)	REP(j,mn)	REP(k,4)	dist[i][j][k]=INF,burn[i][j][k]=0;
		dist[m-1][0][0]=0;
		src.x=m-1;src.y=src.dir=0;
		dest.x=0;dest.y=n-1;dest.dir=3;
		printf("Case #%d: %d\n",kase,dijkstra());
	}
	
	return 0;
}
