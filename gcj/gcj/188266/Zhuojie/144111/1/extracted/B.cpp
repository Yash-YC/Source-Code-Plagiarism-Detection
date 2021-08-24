#include<cstdio>
#include<iostream>
#include<cstring>
#define L 50

using namespace std;

typedef long long ll;

const int fx[4]={1,-1,0,0};
const int fy[4]={0,0,1,-1};
const int maxQ=100000;

class P{
public:
	int x,y;
	P(){}
	P(int x,int y):x(x),y(y){}
};

int T,n,m,i,j;
int s[L][L],w[L][L],t[L][L];

ll calc(int x,int y,int d,ll T){
	int t=::t[x/2][y/2];
	int s=::s[x/2][y/2];
	int w=::w[x/2][y/2];
	int tmp;
	if (d<2){
		if ((x^d)&1) return T+2;
		else{
			tmp=((T-t)%(s+w)+(s+w))%(s+w);
			if (tmp<s) return T+1;
			else return T+(s+w-tmp)+1;
		}
	}
	else{
		if ((y^d)&1) return T+2;
		else{
			tmp=((T-t)%(s+w)+(s+w))%(s+w);
			if (tmp<s) return T+(s-tmp)+1;
			else return T+1;
		}
	}
}

int l,r,x,y,nx,ny,I=0;
bool bt[L][L];
ll opt[L][L],tmp;
P Q[maxQ];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i)
		    for (j=0;j<m;++j)
				scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
		memset(opt,-1,sizeof opt);
		opt[2*n-1][0]=0;
		l=r=0;
		Q[r++]=P(2*n-1,0);
		while (l<r){
			x=Q[l%maxQ].x;
			y=Q[l++%maxQ].y;
			bt[x][y]=0;
			for (i=0;i<4;++i){
				nx=x+fx[i];
				ny=y+fy[i];
				if (nx<0 || nx>=2*n || ny<0 || ny>=2*m) continue;
				tmp=calc(x,y,i,opt[x][y]);
				if (opt[nx][ny]==-1 || tmp<opt[nx][ny]) {
					opt[nx][ny]=tmp;
					if (!bt[nx][ny]){
						bt[nx][ny]=1;
						Q[r++%maxQ]=P(nx,ny);
					}
				}
			}
		}
		cout << "Case #" << ++I << ": " <<opt[0][2*m-1] << endl;
	}
}
