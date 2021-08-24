#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

double res[50];
int N, C;

double CNM(int a, int b)
{
	if(a == 0 && b == 0)
		return 1.0;
	if(a == 0)
		return 0;
	double res = 1;
	int i;
	for(i = b+1; i <=a; ++i)
		res *= i;
	for(i = 2; i <= a-b; ++i)
		res /= i;
	return res;
}

double prob(int x, int y)
{
	int nsx = N-x;
	int csy = C-y;
	double res;
	res = CNM(nsx, csy) * CNM(x, y);
	res /= CNM(N, C);
	return res;
}

int main()
{
	ifstream ifs("C-small-attempt0.in");
	ofstream ofs("C-small-attempt0.out");

	int T;
	ifs >> T;
	for(int caseNo = 1; caseNo <= T; ++caseNo)
	{
		ifs >> N >> C;
		if(N == C)
		{
			ofs << "Case #" << caseNo << ": " << 1.00000 << endl;
			continue;
		}
		res[0] = 0.0;
		res[1] = (double)N/C;
		for(int i = 2; i <= N; ++i)
		{
			double tmp = 0;
			for(int k = 1; k < i; ++k)
			{
				tmp += res[k] * prob(i, i-k);
			}
			double coff = prob(i, 0);
			res[i] = 1.0 + tmp/(1.0 - coff);
		}
		ofs << "Case #" << caseNo << ": " << res[N] << endl;
	}

	ifs.close();
	ofs.close();
	
	return 0;
}