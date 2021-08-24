#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;

int a[512];
int r[20000000][11];

int cal(int n,int x) {
	int sum,t=n,tt;

	while(r[n][x]<0) {
		for(tt=n,sum=0;n;n/=x) sum+=(n%x)*(n%x);
		r[tt][x]=sum;
		n=sum;
	}
	for(n=r[n][x],sum=t;sum!=n;) {
		t=r[sum][x];
		r[sum][x]=n;
		sum=t;
	}
	return n==1;
}

int main() {
	int i,j,k,N,cs=0,t;
	char tmp[256];

	memset(r,0xff,sizeof(r));
	a[0]=2;
	for(i=1;i<512;i++) {
		for(j=a[i&(i-1)];;j++) {
			for(k=0;k<9;k++) if (i&(1<<k)) {
				if (!cal(j,k+2)) break;
			}
			if (k>=9) break;
		}
		a[i]=j;
	}

	for(scanf("%d",&N),gets(tmp);N--;) {
		gets(tmp);
		istringstream is(tmp);
		for(t=0;is>>i;) t|=1<<(i-2);
		printf("Case #%d: %d\n",++cs,a[t]);
	}
	return 0;
}
