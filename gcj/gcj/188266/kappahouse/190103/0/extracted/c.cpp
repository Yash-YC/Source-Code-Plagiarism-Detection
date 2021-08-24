#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double CollectingCards(int C, int N)
{
	vector <vector <long long> > cmb(41);
	for (int i = 0; i < cmb.size(); i++) {
		cmb[i].resize(cmb.size(), 0);
		cmb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
		}
	}

	double ret = 0;
	vector <double> prob(C + 1, 0);
	prob[0] = 1;
	for (int n = 1; n < 10000; n++) {
		vector <double> newprob(C + 1, 0);
		for (int i = 0; i <= C; i++) {
			for (int j = 0; j <= i; j++) {
				if (N - j >= 0)  
				newprob[N - j + i] += cmb[i][j] * cmb[C - i][N - j] * prob[i] / cmb[C][N];
			}
		}
		ret += n * newprob[C];
		newprob[C] = 0;
		prob = newprob;
	}

	return ret;
}

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int C, N;
		cin >> C >> N;

		double ret = CollectingCards(C, N);

		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
