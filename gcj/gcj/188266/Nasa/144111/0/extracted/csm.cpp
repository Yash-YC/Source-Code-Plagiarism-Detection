#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;


#define MAX 100
#define INF 10000000000000LL

long long visited[MAX][MAX];
long long s[MAX][MAX],w[MAX][MAX],t[MAX][MAX];
priority_queue<pair<long long,pair<int,int> > > q;

int n,m;

void update(long long d, int r, int c){
	//printf("=>%d %d  %d\n",r,c,d);
	if (visited[r][c]>d){
		q.push(make_pair(d,make_pair(r,c)));
		visited[r][c]=d;
	}
}

long long getd1(long long tt, long long ss, long long ww, long long d){
	long long d1,d2;
			d2=d;
			if (d2<tt-ww) d1=d;
			else{
				if (d2<tt) d2=tt;
				d2-=tt;
				long long ita=d2/(ss+ww);
				d2%=(ss+ww);
				if (d2>=ss) d2=ss+ww;
				d1=tt+ita*(ss+ww)+d2;
			}
			return d1;
}

void bfs(){
	int r,c,tt,rr,ss,ww;
	long long d,d1,d2;
	while(!q.empty()){
		pair<long long,pair<int,int> > x=q.top(); q.pop();
		r=x.second.first;
		c=x.second.second;
		d=x.first;
	//	printf("%d %d  %d\n",r,c,d);
		if (d>visited[r][c]) continue;
		if (r%2==1 && r<2*n-1) update(d+2,r+1,c);
		if (r%2==0 && r>0) update(d+2,r-1,c);
		if (r%2==0){
 			tt=t[r/2][c/2];
			ss=s[r/2][c/2];
			ww=w[r/2][c/2];
			update(getd1(tt,ss,ww,d)+1,r+1,c);
		}
		if (r%1==0){
 			tt=t[r/2][c/2];
			ss=s[r/2][c/2];
			ww=w[r/2][c/2];
			update(getd1(tt,ss,ww,d)+1,r-1,c);
		}
		if (c%2==1 && c<2*m-1) update(d+2,r,c+1);
		if (c%2==0 && c>0) update(d+2,r,c-1);
		if (c%2==0){
 			tt=t[r/2][c/2]-w[r/2][c/2];
			ww=s[r/2][c/2];
			ss=w[r/2][c/2];
			update(getd1(tt,ss,ww,d)+1,r,c+1);
		}
		if (c%2==1){
 			tt=t[r/2][c/2]-w[r/2][c/2];
			ww=s[r/2][c/2];
			ss=w[r/2][c/2];
			update(getd1(tt,ss,ww,d)+1,r,c-1);
		}
	}
}

int main(){
	int tt,u,i,j;
	scanf("%d",&tt);
	for (u=0; u<tt; u++){
		scanf("%d%d",&n,&m);
		for (i=n-1; i>=0; i--){
			for (j=0; j<m; j++){
				scanf("%lld%lld%lld",&s[i][j],&w[i][j],&t[i][j]);
				t[i][j]%=(s[i][j]+w[i][j]);
				t[i][j]+=(s[i][j]+w[i][j]);
				t[i][j]%=(s[i][j]+w[i][j]);
		//		printf("%lld %lld %lld\n",s[i][j],w[i][j],t[i][j]);
			}
		}
		for (i=0; i<2*n; i++) for (j=0; j<2*m; j++) visited[i][j]=INF;
		update(0,0,0);
		bfs();
		printf("Case #%d: %lld\n",u+1,visited[2*n-1][2*m-1]);
	}
	return 0;
}

