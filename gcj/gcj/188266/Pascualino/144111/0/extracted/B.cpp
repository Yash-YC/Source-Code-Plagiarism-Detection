#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;
#define t first
#define ew second.first
#define ns second.second
#define n second.first
#define m second.second.first
#define dir second.second.second
#define INF 2000000000

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<int,PIII> PIIII;

vector<vector<vector<int> > > memo;

int cruzans(int time, PIII i){
    time = time-i.t +i.ns+i.ew;
    if(time %(i.ns+i.ew) < i.ns) return time+i.t+1-i.ns-i.ew;
    else return time+i.t+1+i.ns+i.ew-time %(i.ns+i.ew)-i.ns-i.ew;
}
int cruzaew(int time, PIII i){
    time = time-i.t +i.ns+i.ew;
    if(time %(i.ns+i.ew) >= i.ns) return time+i.t+1-i.ns-i.ew;
    else return time+i.t+1+i.ns-time%(i.ns+i.ew)-i.ns-i.ew;
}
void p(PIIII a,priority_queue<PIIII> &pq){
     if(memo[a.n][a.m][a.dir]==-1){ a.t = -a.t; pq.push(a); }
}

int main(){
	int T;
	cin >> T;
	for(int tt=1;tt<=T;tt++){
            int N,M;
            cin >> N >> M;
            vector<vector<PIII> > inter(N,vector<PIII>(M));
            memo = vector<vector<vector<int> > > (N,vector<vector<int> > (M,vector<int>(5,-1)));
            
            for(int i=0;i<N;i++) for(int j=0;j<M;j++){
                    cin >> inter[i][j].ns >> inter[i][j].ew >> inter[i][j].t;
                    inter[i][j].t %= (inter[i][j].ns + inter[i][j].ew);
            }
            
            priority_queue<PIIII> pq;
            pq.push(PIIII(0,PIII(N-1,PII(0,4))));
            PIIII a;
            for(;!pq.empty();){
                    a = pq.top();
                    a.t = -a.t;
                    pq.pop();
                    if(memo[a.n][a.m][a.dir]!=-1) continue;
                    memo[a.n][a.m][a.dir]= a.t;
                    if(a.dir==1){
                                 if(a.n-1 >= 0) p(PIIII(a.t+2,PIII(a.n-1,PII(a.m,4))),pq);
                                 if(a.m-1 >= 0) p(PIIII(a.t+2,PIII(a.n,PII(a.m-1,2))),pq);
                    }
                    else if(a.dir==2){
                                 if(a.n-1 >= 0) p(PIIII(a.t+2,PIII(a.n-1,PII(a.m,3))),pq);
                                 if(a.m+1 < M) p(PIIII(a.t+2,PIII(a.n,PII(a.m+1,1))),pq);
                    }
                    else if(a.dir==3){
                                 if(a.n+1 < N) p(PIIII(a.t+2,PIII(a.n+1,PII(a.m,2))),pq);
                                 if(a.m+1 < M) p(PIIII(a.t+2,PIII(a.n,PII(a.m+1,4))),pq);
                    }
                    else if(a.dir==4){
                                 if(a.n+1 < N) p(PIIII(a.t+2,PIII(a.n+1,PII(a.m,1))),pq);
                                 if(a.m-1 >= 0) p(PIIII(a.t+2,PIII(a.n,PII(a.m-1,3))),pq);
                    }
                    
                    
                    if(a.dir==1){
                                 p(PIIII(cruzans(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,4))),pq);
                                 p(PIIII(cruzaew(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,2))),pq);
                    }
                    else if(a.dir==2){
                                 p(PIIII(cruzans(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,3))),pq);
                                 p(PIIII(cruzaew(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,1))),pq);
                    }
                    else if(a.dir==3){
                                 p(PIIII(cruzans(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,2))),pq);
                                 p(PIIII(cruzaew(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,4))),pq);
                    }
                    else if(a.dir==4){
                                 p(PIIII(cruzans(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,1))),pq);
                                 p(PIIII(cruzaew(a.t,inter[a.n][a.m]),PIII(a.n,PII(a.m,3))),pq);
                    }
            }
            cout << "Case #" << tt << ": " << memo[0][M-1][2] << endl;
            
 
}
}




















