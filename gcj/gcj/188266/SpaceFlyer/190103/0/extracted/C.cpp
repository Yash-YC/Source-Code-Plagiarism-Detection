#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 40;
const int MAXC = 40;

double binom[MAXC+1][MAXN+1];
double A[MAXC+1];
int C, N;

void makeBinom()
{
	memset(binom, 0, sizeof(binom));
	binom[0][0] = 1;
	for(int c=1; c<=MAXC; c++)
	{
		binom[c][0] = 1;
		for(int n=1; n<=MAXN; n++)
			binom[c][n] = binom[c-1][n-1]+binom[c-1][n];
	}
}

int main(int argc, char* args[]){
	if (argc < 3){
		cout << "lack of args" << endl;
		return 0;
	}
	freopen(args[1], "r", stdin);
	freopen(args[2], "w", stdout);
	makeBinom();
	int T;
	cin >> T;
	for(int ic=0; ic<T; ic++)
	{
		cin >> C >> N;
		memset(A, 0, sizeof(A));
		A[C] = 0;
		for(int M=C-1; M>=N; M--)
		{
			double left = (1-binom[M][N]/binom[C][N]);
			double right = 1;
			for(int d=1; d<=min(N, C-M); d++)
				right += binom[M][N-d]*binom[C-M][d]/binom[C][N]*A[M+d];
			A[M] = right/left;
		}
		printf("Case #%d: %lf\n", ic+1, A[N]+1);
	}
}

