#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define ROF(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define PER(i,a) ROF(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))
#define st first
#define nd second
#define LL long long

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

struct cross {
	int s,w,t;	
} Cr[25][25];

int N,M;
int R,C;

int main (void) {
	int NC; scanf("%d",&NC);
	int TC=1;
	while(NC--) {
		scanf("%d %d",&N,&M);
		REP(i,N) REP(j,M) {
			scanf("%d %d %d",&Cr[i][j].s,&Cr[i][j].w,&Cr[i][j].t);
			while(Cr[i][j].t>0)
				Cr[i][j].t-=(Cr[i][j].s+Cr[i][j].w);
		}
		
		R=N*2;
		C=M*2;
		
		int res=-1;
		
		int xS=0,yS=R-1,xD=C-1,yD=0;
		int Memo[100][100];
		REP(i,100) REP(j,100) Memo[i][j]=-1;
		Memo[yS][xS]=0;
		
		priority_queue<PIII> PQ;
		PQ.push(PIII(0,PII(xS,yS)));
		while(!PQ.empty()) {
			PIII now=PQ.top(); PQ.pop();
			int time=-now.st;
			int xn=now.nd.st;
			int yn=now.nd.nd;
			
			if(xn==xD&&yn==yD) {
				res=time;
				break;
			}
			
			int ay[]={0,0,1,-1};
			int ax[]={1,-1,0,0};
			
			REP(i,4) {
				int xt=xn+ax[i];
				int yt=yn+ay[i];
				
				if(xt<0||yt<0||xt>=C||yt>=R) continue;
				
				/*ke atas*/
				if(yt<yn) {
					if(yn%2==1&&yt%2==0) {
						int xCr=xn/2;
						int yCr=yn/2;
						
						int ttime=(time-Cr[yCr][xCr].t)/(Cr[yCr][xCr].s+Cr[yCr][xCr].w);
						ttime=Cr[yCr][xCr].t+(ttime*(Cr[yCr][xCr].s+Cr[yCr][xCr].w));
						if(time>=ttime&&time+1<=ttime+Cr[yCr][xCr].s) {
							if(Memo[yt][xt]==-1||Memo[yn][xn]+1<Memo[yt][xt]) {
								Memo[yt][xt]=time+1;
								PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
							}
							
						}
					} else {
						if(Memo[yt][xt]==-1||Memo[yn][xn]+2<Memo[yt][xt]) {
							Memo[yt][xt]=time+2;
							PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
						}
					}
				}
				
				/*ke bawah*/
				if(yt>yn) {
					if(yn%2==0&&yt%2==1) {
						int xCr=xn/2;
						int yCr=yn/2;
						
						int ttime=(time-Cr[yCr][xCr].t)/(Cr[yCr][xCr].s+Cr[yCr][xCr].w);
						ttime=Cr[yCr][xCr].t+(ttime*(Cr[yCr][xCr].s+Cr[yCr][xCr].w));
						if(time>=ttime&&time+1<=ttime+Cr[yCr][xCr].s) {
							if(Memo[yt][xt]==-1||Memo[yn][xn]+1<Memo[yt][xt]) {
								Memo[yt][xt]=time+1;
								PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
							}
						}
					} else {
						if(Memo[yt][xt]==-1||Memo[yn][xn]+2<Memo[yt][xt]) {
							Memo[yt][xt]=time+2;
							PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
						}
					}
				}
				
				/*ke kiri*/
				if(xt<xn) {
					if(xn%2==1&&xt%2==0) {
						int xCr=xn/2;
						int yCr=yn/2;
						
						int ttime=(time-Cr[yCr][xCr].t)/(Cr[yCr][xCr].s+Cr[yCr][xCr].w);
						ttime=Cr[yCr][xCr].t+(ttime*(Cr[yCr][xCr].s+Cr[yCr][xCr].w));
						ttime+=Cr[yCr][xCr].s;
						if(time>=ttime&&time+1<=ttime+Cr[yCr][xCr].w) {
							if(Memo[yt][xt]==-1||Memo[yn][xn]+1<Memo[yt][xt]) {
								Memo[yt][xt]=time+1;
								PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
							}
						}
					} else {
						if(Memo[yt][xt]==-1||Memo[yn][xn]+2<Memo[yt][xt]) {
							Memo[yt][xt]=time+2;
							PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
						}
					}
				}
				
				/*ke kanan*/
				if(xt>xn) {
					if(xn%2==0&&xt%2==1) {
						int xCr=xn/2;
						int yCr=yn/2;
						
						int ttime=(time-Cr[yCr][xCr].t)/(Cr[yCr][xCr].s+Cr[yCr][xCr].w);
						ttime=Cr[yCr][xCr].t+(ttime*(Cr[yCr][xCr].s+Cr[yCr][xCr].w));
						ttime+=Cr[yCr][xCr].s;
						if(time>=ttime&&time+1<=ttime+Cr[yCr][xCr].w) {
							if(Memo[yt][xt]==-1||Memo[yn][xn]+1<Memo[yt][xt]) {
								Memo[yt][xt]=time+1;
								PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
							}
						}
					} else {
						if(Memo[yt][xt]==-1||Memo[yn][xn]+2<Memo[yt][xt]) {
							Memo[yt][xt]=time+2;
							PQ.push(PIII(-Memo[yt][xt],PII(xt,yt)));
						}
					}
				}
			}
			
			int xCr=xn/2;
			int yCr=yn/2;
			int ttime2=(time-Cr[yCr][xCr].t)/(Cr[yCr][xCr].s+Cr[yCr][xCr].w);
			ttime2=Cr[yCr][xCr].t+(ttime2*(Cr[yCr][xCr].s+Cr[yCr][xCr].w));
			if(ttime2+Cr[yCr][xCr].s>time) {
				ttime2+=Cr[yCr][xCr].s;
			} else {
				ttime2+=Cr[yCr][xCr].s+Cr[yCr][xCr].w;
			}
			PQ.push(PIII(-ttime2,PII(xn,yn)));
			
		}
		
		printf("Case #%d: %d\n",TC++,res);
	}
	return 0;
}
