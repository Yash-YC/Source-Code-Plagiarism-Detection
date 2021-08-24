#include "iostream"
#include "sstream"
using namespace std;

const int maxn=2000;
int n;
int a[11];
int r[11][maxn];


int dfs(int x,int y)
{
	int ret;
	if(y<maxn){
		if(r[x][y]>=0) return r[x][y];
		else r[x][y]=0;
	}
	int ty=y;
	int sum=0;
	while(ty>0){
		sum+=(ty%x)*(ty%x);
		ty/=x;
	}
	ret=dfs(x,sum);
	if(y<maxn){
		r[x][y]=ret;
	}
	return ret;
}

int solve()
{
	int i,j;
	for(i=2;;++i){
		for(j=0;j<n;++j){
			if(dfs(a[j],i)!=1){
				break;
			}
		}
		if(j==n) return i;
	}
	return -1;
}


void init()
{
	int i,j;
	memset(r,-1,sizeof(r));
	for(i=2;i<=10;++i){
		r[i][1]=1;
		for(j=2;j<maxn;++j){
			if(r[i][j]<0){
				r[i][j] = dfs(i,j);
			}
		}
	}
}

void check()
{
	int t[1024],tn=0;
	memset(t,-1,sizeof(t));
	int i,j,k;
	for(i=2;;++i){
		k=0;
		for(j=2;j<=10;++j){
			k=k+k+dfs(j,i);
		}
		if(t[k]<0){
			t[k]=i;
			tn++;
			printf("%d %d\n",i, tn);
			if(tn==1024)break;
		}
	}
	printf("YES\n");
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("ra1.out","w",stdout);
	int i, T;
	char str[1000];
	init();
	//check();
	scanf("%d",&T);
	gets(str);
	for(i=1;i<=T;++i){
		gets(str);
		istringstream sin(str);
		n=0;
		while(sin>>a[n]) n++;
		printf("Case #%d: %d\n",i,solve());
	}
	return 0;
}