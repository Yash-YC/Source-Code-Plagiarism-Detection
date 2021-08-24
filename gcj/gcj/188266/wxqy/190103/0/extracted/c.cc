#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

double p[50][50][100];

void prepare()
{
	int c, n, l,k;
	double s;

	memset(p,0,sizeof(p));
	
	p[1][1][1]=1;
	
	for (c=2;c<=40;c++) {
		s=1;
		for (l=1;l<=c;l++) s*=(c-1)*1.0/c;
		for (l=c;l<=99;l++) {
			for (k=1;k<l;k++) {
				p[c][1][l]+=c*p[c-1][1][k]*s;
			}
			s=s*(c-1)/c;
		}
	}

	for (c=2;c<=40;c++)
		for (n=2;n<=40;n++) {
			s=1.0*n/c;
			for (l=1;l<=99;l++)
				for (k=l-1;k>=1;k--) {
					p[c][n][l]+=n*p[c-1][n-1][k]*s;
					s*=1.0*n/c;
				}
		}
}			

int main()
{
	int testCases;
	scanf("%d",&testCases);

	// prepare();
	int c,n;
	double s;
	
	for (int caseID=1;caseID<=testCases;caseID++) {
		scanf("%d%d",&c,&n);
		// s=0;
		// for (int l=1;l<=40;l++)
		// 	s+=l*p[c][n][l];
		printf("Case #%d: %.7lf\n",caseID,(c+n)*1.0/n);
	}

	return 0;
}
