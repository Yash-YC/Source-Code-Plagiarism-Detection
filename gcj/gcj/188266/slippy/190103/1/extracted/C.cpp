#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double COMB[50][50];

double comb(int n, int k)
{
	
	if(k == 0 || k == n) return 1;
	if(k < 0 || k > n) return 0;
	
	if(COMB[n][k] > 0) return COMB[n][k];
	
	double ans = 1;
	int x = min(k, n-k);
	for(int t = 0; t < x; t++)
	{
		ans *= (n-t);
		ans /= (t+1);
	}
	return COMB[n][k] = ans;
}

double answer[50];

double calc(int C, int N, int k)
{
	if(k >= C) return 0.0;
	if(answer[k] > 0) return answer[k];
	
	double denom = 1.0 - comb(k,N)/comb(C,N);
	double num = 1.0;
	for(int t = 1; t <= N; t++)
		num += (comb(C-k,t)*comb(k,N-t)/comb(C,N))*calc(C,N,k+t);
	return answer[k] = num/denom;
}

int main()
{
	FILE * pFile;
   pFile = fopen("C-large.out","w");

	
	
	ifstream fin("C-large.in");
	
	int T;
	fin >> T;
	
	for(int t = 0; t < 50; t++)
	for(int u = 0; u < 50; u++)
		COMB[t][u] = -1;
	
	for(int tt = 0; tt < T; tt++)
	{
		int N,C;
		fin >> C >> N;
		
		for(int u = 0; u < 50; u++)
			answer[u] = -1;
		
		double ANS = 1.0 + calc(C,N,N);
      fprintf (pFile, "Case #%d: %.7lf\n",tt+1,ANS);

	}
	
	
	return 0;
}
		
