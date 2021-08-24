/*
ID: BigGuava
PROG: A
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
#define ___SMALL

#pragma warning(disable:4996 4101)


void patch(int &a, int b)
{
	if (a<0 || a>b) a=b;
}

int cmp_int(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}


bool happy[11][10000000];

int calc(int c, int base)
{
	int k,d;
	d=0;
	k=0;
	while (c) {
		k=c%base;
		d+=k*k;
		c/=base;
	}
	return d;
}

#define M 3000000
void prepare(int base)
{
	int i,j,k,a,b,c,d,tot;

	for (i=2;i<M;i++) {
		//printf("%d\n",i);
		d=calc(i,base);
		tot=0;
		while (d>i) {
			tot++;
			if (tot>10) break;
			d=calc(d,base);
		}
		happy[base][i]=happy[base][d];
	}
}




int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
#else
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d,e,f;
	char s[1000],t[1000];
	int v[10];

	memset(happy,0,sizeof(happy));
	for (b=2;b<=10;b++) {
		happy[b][1]=true;
		//printf("%d\n",b);
		prepare(b);
	}

	//for (i=2;i<M;i++) {
	//	k=0;
	//	for (b=2;b<=10;b++) if (happy[b][i]) k++;
	//	if (k==9) printf("==%d\n",i);
	//}

	gets(s);
	sscanf(s,"%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		gets(s);
		m=sscanf(s,"%d%d%d%d%d%d%d%d%d%d",v+0,v+1,v+2,v+3,v+4,v+5,v+6,v+7,v+8,v+9);

		for (i=2;i<M;i++) {
			k=0;
			for (b=0;b<m;b++) if (happy[v[b]][i]) k++;
			if (k==m) {
				printf("%d\n",i);
				break;
			}
		}



//		printf("%d\n",d);
	}

	return 0;
}	

/*

*/