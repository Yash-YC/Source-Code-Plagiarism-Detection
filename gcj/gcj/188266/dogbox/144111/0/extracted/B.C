#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX 21
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
int rd[]={1,-1,0,0};
int cd[]={0,0,-1,1};

int R,C;
int d[MAX<<1][MAX<<1];
int v[MAX][MAX],h[MAX][MAX],t[MAX][MAX];

bool ok(int r,int c){
    return r>=0 && r<=R && c>=0 && c<=C;
}
piii mp(int a,int b,int c){return piii(a,pii(b,c));}
int toint(int r,int c){
    return r*C+c;
}
pii topair(int x){
    return pii(x/C,x%C);
}

int on(int r,int c,int dist,int vertical){

    r/=2;
    c/=2;

    int V=v[r][c],H=h[r][c],T=t[r][c];
    int dur=V+H;

    if(vertical){
	if(V==0) return -1;
	if(dist<=T)
	    T-=ceil(double(T-dist)/dur)*dur;

	// where we are right now
	// with respect to cycle
	int diff=(dist-T)%dur;
	if(diff<V){
	    return dist;
	}
	else{
	    return dist+dur-diff;
	}
    }
    else{
	if(H==0) return -1;
	T+=V;
	if(dist<=T)
	    T-=ceil(double(T-dist)/dur)*dur;
	int diff=(dist-T)%dur;

	if(diff<H){
	    return dist;
	}
	else{
	    return dist+dur-diff;
	}
    }
}


main(){

    int T; scanf("%d",&T); for(int test=1;test<=T;test++){

	memset(d,63,sizeof(d));

	printf("Case #%d: ",test);

	scanf("%d %d",&R,&C);

	for(int i=0;i<R;i++)
	    for(int j=0;j<C;j++)
		scanf("%d %d %d",&v[i][j],&h[i][j],&t[i][j]);

	R<<=1;
	C<<=1;

	priority_queue<pii,vector<pii>, greater<pii> > q;
	q.push(pii(0,0));

	while(!q.empty()){

	    pii p=q.top(); q.pop();
	    int dist=p.first;
	    pii pp=topair(p.second);
	    int r=pp.first;
	    int c=pp.second;

//	    cout<<r<<' '<<c<<' '<<dist<<endl;

	    if(r==R-1 && c==C-1){
		printf("%d\n",dist);
		break;
	    }

	    if(d[r][c]<1e9) continue;
	    d[r][c]=dist;

	    // go vertical
	    for(int i=0;i<2;i++){

		int nr=r+rd[i];
		int nc=c+cd[i];

		if(!ok(nr,nc)) continue;

		// cross street
		if(r%2==0){ 
		    // next time it's on >= dist
		    int nt=on(r,c,dist,1);
		    if(nt!=-1)
			q.push(pii(nt+1,toint(nr,nc)));
		}
		// cross block
		else{
		    q.push(pii(dist+2,toint(nr,nc)));
		}
	    }

	    // go horizontal
	    for(int i=2;i<4;i++){

		int nr=r+rd[i];
		int nc=c+cd[i];

		if(!ok(nr,nc)) continue;

		// cross street
		if(c%2==0){ 
		    // next time it's on >= dist
		    int nt=on(r,c,dist,0);
		    if(nt!=-1)
			q.push(pii(nt+1,toint(nr,nc)));
		}
		// cross block
		else{
		    q.push(pii(dist+2,toint(nr,nc)));
		}
	    }
	}
    }
}
