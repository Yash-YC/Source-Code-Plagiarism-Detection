#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define maxn 300000

int happyn[11][maxn];
int checkn[11][maxn];
int s;

int happy(int n, int base)
{
	if (happyn[base][n]) return happyn[base][n];
	if (checkn[base][n]) return n;

	checkn[base][n]=1;
	s++;

	if (s>10) {
		happyn[base][n]=-1;
		return -1;
	}
	
	int ret;
	int m=n;

	ret=0;
	while (n) {
		ret+=(n%base)*(n%base);
		n/=base;
	}

	if (ret>=maxn) {
		s=0;
		return happyn[base][ret]=-1;
	}

	if (happyn[base][ret]) {
		happyn[base][m]=happyn[base][ret];
		s=0;
		return happyn[base][m];
	}
	else if (checkn[base][ret]) {
		happyn[base][m]=m;
		s=0;
		return m;
	}
	else {
		happyn[base][m]=happy(ret,base);
		s=0;
		return happyn[base][m];
	}
}

int a[100];

int main()
{
	int n;
	int testCases;
	scanf("%d\n",&testCases);
	memset(happyn,0,sizeof(happyn));
	memset(checkn,0,sizeof(checkn));
	for (int caseID=1;caseID<=testCases;caseID++) {
		char buf[100];
		gets(buf);
		n=0;
		char *p=buf;
		int nn;
		while (sscanf(p,"%d%n",&a[n],&nn)==1) {
			n++;
			p+=nn;
		}

		int s=2, i;
		while (1) {
			for(i=0;i<n;i++)
				if (happy(s,a[i])!=1) break;
			if (i==n) break;
			s=s+1;
			if (s>=maxn) break;
		}
		printf("Case #%d: %d\n", caseID, s);
	}

	return 0;
}


