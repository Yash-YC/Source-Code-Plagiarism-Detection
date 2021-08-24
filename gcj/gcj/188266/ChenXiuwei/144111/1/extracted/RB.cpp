#include "iostream"
using namespace std;

typedef long long ll;
const ll inf = 1000000LL * 1000000LL;
const int maxn=24;
int row,col;
ll s[maxn][maxn];
ll w[maxn][maxn];
ll t[maxn][maxn];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct node{
	ll time;
	int addr;
	int flag;
	bool operator < (const node& b){
		return time<b.time;
	}
}a[maxn*maxn*4];
int addr[maxn*maxn*4];

void input()
{
	int i,j;
	scanf("%d%d",&row,&col);
	for(i=0;i<row;++i){
		for(j=0;j<col;++j){
			scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
		}
	}
}

void upsift(int x)
{
	int i,j;
	for(i=x, j=(i-1)/2; i>0;i=j,j=(i-1)/2){
		if(a[addr[i]]<a[addr[j]]){
			swap(addr[i],addr[j]);
			a[addr[i]].addr=i;
			a[addr[j]].addr=j;
		}else break;
	}
}

int getid(int x,int y)
{
	return x*col*2+y;
}

void getid(int id, int& x,int& y)
{
	x=id/(col*2);
	y=id%(col*2);
}

void downsift(int x,int limit)
{
	int i,j;
	for(i=x,j=i+i+1;j<limit;i=j,j=i+i+1){
		if(j+1<limit && a[addr[j+1]] < a[addr[j]]) ++j;
		if(a[addr[j]]<a[addr[i]]){
			swap(addr[i],addr[j]);
			a[addr[i]].addr=i;
			a[addr[j]].addr=j;
		}else break;
	}
}

bool inside(int x,int y)
{
	return (x>=0 && y>=0 && x<row*2 && y<col*2 && a[getid(x,y)].flag==0);
}

bool move(int x,int y,int dir,int ct,int& tx,int& ty,int& ret)
{
	int nextt;
	tx=x+dx[dir];
	ty=y+dy[dir];
	if(!inside(tx,ty)) return false;
	if(dir<2){
		if((x%2==0 && dir == 1) || (x%2==1 && dir==0)){
			ret = ct+2;
		}else{
			nextt=(ct-t[x/2][y/2])%(s[x/2][y/2]+w[x/2][y/2]);
			if(nextt<0)nextt+=(s[x/2][y/2]+w[x/2][y/2]);
			if(nextt<s[x/2][y/2]){
				ret=ct+1;
			}else{
				ret=ct+((s[x/2][y/2]+w[x/2][y/2]) - nextt)+1;
			}
		}
	}else{
		if((y%2==0 && dir==3) || (y%2==1 && dir==2)){
			ret =ct+2;
		}else{
			nextt=(ct-t[x/2][y/2])%(s[x/2][y/2]+w[x/2][y/2]);
			if(nextt<0)nextt+=(s[x/2][y/2]+w[x/2][y/2]);
			if(nextt<s[x/2][y/2]){
				ret=ct+1;
				ret=ct+(s[x/2][y/2] - nextt)+1;
			}else{
				ret=ct+1;
			}
		}
	}
	return true;
}

int solve()
{
	int x,y,ct,nt,tx,ty;
	int i,j,k;
	for(i=0;i<row*col*4;++i){
		a[i].time = inf;
		a[i].addr=i;
		addr[i]=i;
		a[i].flag=0;
	}
	a[(row*2-1)*(col*2)].time=0;
	upsift((row*2-1)*(col*2));
	for(i=0;i<row*col*4;++i){
		k=addr[0];
		//printf("k=%d time=%d\n",k,a[k].time);
		if(k==col*2-1) return a[k].time;
		a[k].flag=1;
		swap(addr[0],addr[row*col*4-i-1]);
		a[addr[0]].addr=0;
		a[addr[row*col*4-i-1]].addr=row*col*4-i-1;
		downsift(0,row*col*4-i-1);
		getid(k,x,y);
		for(j=0;j<4;++j){
			if(move(x,y,j,a[k].time,tx,ty,nt)){
				int id=getid(tx,ty);
				if(a[id].time > nt){
					a[id].time=nt;
					//printf("u id=%d,t=%d\n",id,nt);
					upsift(a[id].addr);
				}
			}
		}
	}
	return -1;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("RB2.out","w",stdout);
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;++i){
		input();
		printf("Case #%d: %d\n",i,solve());
	}
	return 0;
}