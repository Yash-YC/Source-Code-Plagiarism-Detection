#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int nbC;
int nbN;

double dyn[41][41];

double ncr(int n, int r)
{
	if (r > n)
		return 0;
	if (r == 0)
		return 1;

	if (dyn[n][r] == -1)
		dyn[n][r] = ncr(n-1,r-1) + ncr(n-1,r);

	return dyn[n][r];
}

double dyn2[41];
double expPacks(int n)
{
	if (n >= nbC)
		return 0;

	if (dyn2[n] == -1) {
		double e = 1;
		for (int i = 1; i <= nbN; i++)
			e += (ncr(nbC-n,i)*ncr(n,nbN-i)/ncr(nbC,nbN))*expPacks(n + i);
		double p0 = ncr(n,nbN)/ncr(nbC,nbN);
	
		dyn2[n] = (1./(1-p0))*e;
	}

	return dyn2[n];
}

int main()
{
	for (int j = 0; j <= 40; j++)
		for (int k = 0; k <= 40; k++)
				dyn[j][k] = -1;
	
	FILE *fin = fopen("cl.in", "r");
	FILE *fout = fopen("cl.out","w");
	int nbT;
	fscanf(fin, "%d", &nbT);
	for (int i = 0; i < nbT; i++) {
		
		for (int j = 0; j <= 40; j++)
			dyn2[j] = -1;
		

		fscanf(fin, "%d %d", &nbC, &nbN);
		fprintf(fout, "Case #%d: %lf\n", i+1, expPacks(0));
	}	
	
	fclose(fin);
	fclose(fout);

	return 0;
}
