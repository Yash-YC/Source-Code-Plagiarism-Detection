#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <iterator> 
#include <iostream> 
#include <functional> 
#include <sstream> 
#include <numeric>

using namespace std;

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) ) 
#define EPS 1e-9

FILE *in=fopen("B.in","r");
FILE *out=fopen("B.out","w");

int spath[25][25][5],vis[25][25][5];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int start[25][25],S[25][25],W[25][25];

int n,m;

int ftime(int x,int y,int v,int t)
{
	int on=0;
	int ori=t;
	if(t<start[x][y]){
		int XX=(start[x][y]-t)/(S[x][y]+W[x][y]);
		t+=(XX+4)*(S[x][y]+W[x][y]);
	}
	t-=start[x][y];
	t%=(S[x][y]+W[x][y]);
	if(t<S[x][y])on=1;
	if(on && !v)return ori;
	if(!on && v)return ori;
	if(v)return S[x][y]-t+ori;
	return S[x][y]+W[x][y]-t+ori;
}
void update(int x,int y,int z,int t)
{
	if(t<spath[x][y][z] || spath[x][y][z]==-1){
		spath[x][y][z]=t;
	}
}
int main()
{
	int i,j,k,T,ret;
	fscanf(in,"%d",&T);
	for(int test=1;test<=T;test++){
		fscanf(in,"%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				fscanf(in,"%d%d%d",&S[i][j],&W[i][j],&start[i][j]);
		CLR(spath,-1);
		CLR(vis,0);
		int x=0,y=0,z=2;
		spath[x][y][z]=0;
		int fx=n,fy=m,fz=0;
		while(1){
			int minn=1<<30;
			for(i=0;i<=n;i++){
				for(j=0;j<=m;j++){
					for(k=0;k<4;k++){
						if(spath[i][j][k]==-1)continue;
						if(spath[i][j][k]<minn && !vis[i][j][k]){
							minn=spath[i][j][k];
							x=i;
							y=j;
							z=k;
						}
					}
				}
			}
			if(minn==1<<30)break;
			vis[x][y][z]=1;
			int t=spath[x][y][z];
			update(x,y,(z+1)%4,t+2);
			update(x,y,(z+3)%4,t+2);
			int ix=x,iy=y;
			if(z==0)ix--,iy--;
			if(z==1)ix--;
			if(z==3)iy--;
			if(ix<0 || iy<0 || ix>=n || iy>=m)continue;
			for(i=0;i<2;i++){
				int nt=ftime(ix,iy,i,t);
				if(z==0 || z==2)j=!i;
				else j=i;
				int nx=x+dx[(z+j)%4];
				int ny=y+dy[(z+j)%4];
				int nz;
				if(!i){
					if(z==0 || z==2)nz=(z+3)%4;
					else nz=(z+1)%4;
				}
				else {
					if(z==0 || z==2)nz=(z+1)%4;
					else nz=(z+3)%4;
				}
				if(nx<0 || ny<0 || nx>n || ny>m)continue;
				update(nx,ny,nz,nt+1);
			}
		}
		ret=spath[fx][fy][fz];
		fprintf(out,"Case #%d: %d\n",test,ret);
	}
	return 0;
}
