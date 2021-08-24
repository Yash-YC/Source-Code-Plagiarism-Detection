#include <iostream>
#include <vector>
#include <cstring>

#define POW 1024
#define MAXD 128

using namespace std;

int c, n;
vector <int> masks;
int memoset[POW][MAXD];
double memo[POW][MAXD];
int mindepthto[POW];

double solve(int state, int depth)
{
	double ret = 0;

	if (state == ((1<<c)-1))
		return 0;

	if (depth >= MAXD) {
		double guess;
		int manylack = c;

		for (int j = 0; j < c; j++)
			if (state & (1<<j))
				manylack --;

		guess = manylack * (double)c / (double)n;

		return guess;
	}

	if (memoset[state][depth])
		return memo[state][depth];

	for (int i = 0; i < masks.size(); i++)
		ret += solve(state | masks[i], depth + 1);
	ret += masks.size();
	ret /= masks.size();

	memoset[state][depth] = 1;
	return memo[state][depth] = ret;
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);

	for (int t = 0; t < ntest; t++) {
		scanf(" %d %d", &c, &n);

		masks.clear();
		for (int i = 0; i < (1<<c); i++) {
			int many = 0;

			for (int j = 0; j < c; j++)
				if (i & (1<<j))
					many ++;

			if (many == n)
				masks.push_back(i);
		}

		memset(memoset, 0, sizeof(memoset));
		printf("Case #%d: %lf\n", t+1, solve(0, 0));
	}

	return 0;
}
