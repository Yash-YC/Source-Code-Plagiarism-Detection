#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>

#define UNKNOWN 0
#define GOOD 1
#define BAD 2
#define TRIED 3

long n, base[10], digit[100000], ndigit, occur[11][1000000], toccur[1000000];

long next(long i, long b){

	long sum = 0, j;
	memset(digit, 0, sizeof(digit));
	ndigit = 0;

	while(i){
		digit[ndigit++] = i % b;
		i /= b;
	}

	for(j = 0; j < ndigit; j++)
		sum += (digit[j] * digit[j]);

	return sum;

}

bool valid(long i, long b){

	if(occur[b][i] == GOOD)
		return true;

	if(occur[b][i] == BAD)
		return false;



	long j = i;

	memset(toccur, 0, sizeof(toccur));
	toccur[i] = 1;

	while(j - 1){

		j = next(j, b);

		

		if(occur[b][j] == BAD || toccur[j] == 1){
			occur[b][j] = occur[b][i] = BAD;
			return false;
		}

		toccur[j] = 1;
	}

	occur[b][i] = GOOD;
	return true;

}

using namespace std;

int main()
{
	
	memset(occur, UNKNOWN, sizeof(occur));

	for(int i = 0; i < 11; i++)
		occur[i][1] = GOOD;


	int T, caseidx, i, j;

	string line;

	getline(cin, line);
	stringstream ss(line);

	ss >> T;

	for(caseidx = 1; caseidx <= T; caseidx++){

		getline(cin, line);

		stringstream ss(line);

		n = 0;
		while(ss >> base[n]){
			n++;
		}


		for(i = 2; ; i++){

			for(j = 0; j < n && valid(i, base[j]); j++)
			{
				//cout << "case " << caseidx << " trying " << i << " for " << base[j] << endl;
			}

			if(j >= n){
				printf("Case #%d: %d\n", caseidx, i);

				break;
			}
		}
	}

	return 0;
}

/*
 * vim: ts=2 sw=2
 * Local variables:
 * tab-width: 2
 * End:
 */
