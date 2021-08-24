#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define ROF(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define PER(i,a) ROF(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))
#define st first
#define nd second
#define LL long long
#define MAXV 100000
#define MAXDIGIT 100

typedef pair<int,int> PII;

int v2[]={0,1,4,9,16,25,36,49,64,81};
char fmemo[11][MAXV];

void toBase(char sv[100],int &lensv,int v,int b) {
	int idx=0;
	char stemp[100];
	while(v>=b) {
		stemp[idx++]=v%b;
		v/=b;
	}
	if(v) stemp[idx++]=v;

	int idxsv=0;
	PER(i,idx) sv[idxsv++]=stemp[i];
	sv[idxsv]=0;
	lensv=idxsv;
}

void fill(int v,int b) {
	if(fmemo[b][v]==0) {
		char sv[100];
		int lensv;
		toBase(sv,lensv,v,b);
		int sum=0;
		REP(i,lensv)
			sum+=v2[sv[i]];
		
		if(fmemo[b][sum]==0) {
			fmemo[b][v]=-1;
			fill(sum,b);
		}
		
		fmemo[b][v]=fmemo[b][sum];
	} else
		return;
}

void init(void) {
	FOR(i,2,10) {
		fmemo[i][1]=1;
		FOR(j,2,MAXV-1) fill(j,i);
	}
}

int main (void) {
	init();
		
	int NC; scanf("%d\n",&NC);
	int TC=1;
	while(NC--) {
		char sin[100]; gets(sin);
		char *p=strtok(sin," ");
		int nB=0,B[10];
		do {
			B[nB++]=atoi(p);
		} while((p=strtok(0," ")));
		
		char fres[MAXV]; _m(fres,0);
		REP(i,nB) REP(j,MAXV) {
			if(fmemo[B[i]][j]==1)
				fres[j]++;
		}
		
		int res=-1;
		FOR(i,2,MAXV-1)
			if(fres[i]==nB) {
				res=i;
				break;
			}
		
		printf("Case #%d: %d\n",TC++,res);
	}
	return 0;
}
