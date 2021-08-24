/*
ID: BigGuava
PROG: B
LANG: C++
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//#define LOCAL_JUDGE
//#define ___SMALL

#pragma warning(disable:4996 4101)


void patch(int &a, int b)
{
	if (a<0 || a>b) a=b;
}
int cmp_int(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}


int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
#else
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d,e,f;
	__int64 s[32][32],w[32][32],t[32][32],dt;
#define M 40000000
		int x[M],y[M],z[M];
		__int64 best[32][32][4],r,p,q;

	
	scanf("%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		
		scanf("%d%d",&n,&m);

		for (i=0;i<n;i++) for (j=0;j<m;j++) {
			scanf("%I64d%I64d%I64d",&s[i][j],&w[i][j],&t[i][j]);
			t[i][j]%=(s[i][j]+w[i][j]);
			t[i][j]-=(s[i][j]+w[i][j]);
			t[i][j]-=(s[i][j]+w[i][j]);
		}

		memset(best,200,sizeof(best));

		best[n-1][0][0]=0;
		x[0]=n-1;
		y[0]=0;
		z[0]=0;
		i=0; j=1;
		while (i<j) {
			switch (z[i]) {
				case 0:
					c=x[i]+1;
					d=y[i];
					e=1;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i]-1;
					e=3;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=1;
					r=t[c][d];
					while (r+s[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r>best[x[i]][y[i]][z[i]]) dt=r+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=3;
					r=t[c][d];
					while (r+s[c][d]+w[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r+s[c][d]>best[x[i]][y[i]][z[i]]) dt=r+s[c][d]+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					break;

				case 1:
					c=x[i]-1;
					d=y[i];
					e=0;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i]-1;
					e=2;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=0;
					r=t[c][d];
					while (r+s[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r>best[x[i]][y[i]][z[i]]) dt=r+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=2;
					r=t[c][d];
					while (r+s[c][d]+w[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r+s[c][d]>best[x[i]][y[i]][z[i]]) dt=r+s[c][d]+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					break;

				case 2:
					c=x[i]-1;
					d=y[i];
					e=3;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i]+1;
					e=1;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=3;
					r=t[c][d];
					while (r+s[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r>best[x[i]][y[i]][z[i]]) dt=r+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=1;
					r=t[c][d];
					while (r+s[c][d]+w[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r+s[c][d]>best[x[i]][y[i]][z[i]]) dt=r+s[c][d]+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					break;

				case 3:
					c=x[i]+1;
					d=y[i];
					e=2;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i]+1;
					e=0;
					if (c>=0 && d>=0 && c<n && d<m) if (best[c][d][e]<0 || best[c][d][e]>2+best[x[i]][y[i]][z[i]]) {
						best[c][d][e]=2+best[x[i]][y[i]][z[i]];
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=2;
					r=t[c][d];
					while (r+s[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r>best[x[i]][y[i]][z[i]]) dt=r+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					c=x[i];
					d=y[i];
					e=0;
					r=t[c][d];
					while (r+s[c][d]+w[c][d]<=best[x[i]][y[i]][z[i]]) r+=s[c][d]+w[c][d];
					if (r+s[c][d]>best[x[i]][y[i]][z[i]]) dt=r+s[c][d]+1; else dt=best[x[i]][y[i]][z[i]]+1;
					if (best[c][d][e]<0 || best[c][d][e]>dt) {
						best[c][d][e]=dt;
						x[j]=c;
						y[j]=d;
						z[j]=e;
						j++;
					}
					break;
				}// end switch
				i++;
				if (j>M-1) printf("!!!!\n");
		}




		printf("%I64d\n",best[0][m-1][2]);
	}

	return 0;
}	

/*

*/