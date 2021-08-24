#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int input[100][100];
vector<int> output;
void print(int idx, int n)
{
	printf("Case #%d:", idx);
	for (int i = 0; i < n; i++)
		printf(" %d", output[i]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		memset(input, 0, sizeof(input));
		output.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2 * n - 1; i++) for (int j = 0; j < n; j++) scanf("%d", &input[i][j]);
		map<int, int> cnt;
		for (int i = 0; i < 2 * n - 1; i++) for (int j = 0; j < n; j++) cnt[input[i][j]]++;

		for (pair<int, int> p : cnt)
		{
			if (p.second % 2)
			{
				output.push_back(p.first);
			}
		}
		sort(output.begin(), output.end());

		print(cases, n);
	}
	return 0;
}