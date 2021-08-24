#include <cstdio>
int cs,n,m,a[25][25],b[25][25],c[25][25],x,y,z,t,A,B,u[25][25][4],v[25][25][4];
int qx[1000000],qy[1000000],qz[1000000],hd,tl;


void relax(int x,int y,int z,int t){
	if (!x||!y||x>n||y>m) return;
	if (v[x][y][z]>t||v[x][y][z]==-1){
	v[x][y][z]=t;
		if (!u[x][y][z]){
		u[x][y][z]=1;
		tl++;
		qx[tl]=x;
		qy[tl]=y;
		qz[tl]=z;
		}
	}
}

int f(int a,int b,int c,int t){
	int x;
	if (c>t){
	x=(c-t-1)/(a+b)+1;
	c-=x*(a+b);
	}
	if (c+a+b<=t){
	x=(t-c)/(a+b);
	c+=x*(a+b);
	}
	if (t<c+a) return t;
	else return c+a+b;
}

int main(){
	scanf("%d",&cs);
	for (int ce=1;ce<=cs;ce++){
	scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
			scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
				for (int k=0;k<4;k++) v[i][j][k]=-1,u[i][j][k]=0;
			}
	v[n][1][0]=0;
	qx[0]=n;
	qy[0]=1;
	qz[0]=0;
		for (hd=0,tl=0;tl>=hd;hd++){
		x=qx[hd];
		y=qy[hd];
		z=qz[hd];
		u[x][y][z]=0;
		t=v[x][y][z];		
			if (z==1||z==3) relax(x-1,y,z-1,t+2);
			if (z==3||z==2) relax(x,y+1,z-2,t+2);
			if (z==0||z==2) relax(x+1,y,z+1,t+2);
			if (z==0||z==1) relax(x,y-1,z+2,t+2);
		A=f(a[x][y],b[x][y],c[x][y],t);
			if (z==0) relax(x,y,1,A+1);
			if (z==1) relax(x,y,0,A+1);
			if (z==2) relax(x,y,3,A+1);
			if (z==3) relax(x,y,2,A+1);			
		B=f(b[x][y],a[x][y],c[x][y]+a[x][y],t);
		relax(x,y,(z+2)%4,B+1);
		}
	printf("Case #%d: %d\n",ce,v[1][m][3]);
	}
	return 0;
}

