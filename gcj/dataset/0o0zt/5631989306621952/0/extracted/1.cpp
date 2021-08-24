#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char input[1005];
char output[1005];
char output1[2010];

void print(int idx)
{
	printf("Case #%d: %s\n", idx, output);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		scanf("%s", input);
		int len = strlen(input);
		int left = 1001, right = 1001;
		output1[left] = input[0];
		for (int i = 1; i <= len; i++)
		{
			if (input[i] >= output1[left])
			{
				output1[--left] = input[i];
			}
			else
			{
				output1[++right] = input[i];
			}
		}

		strcpy(output, output1 + left);

		print(cases);
	}
	return 0;
}