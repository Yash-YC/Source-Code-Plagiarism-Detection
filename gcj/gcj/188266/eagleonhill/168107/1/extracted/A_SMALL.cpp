#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int getnext(int t, int base)
{
	int ans = 0;
	while (t)
	{
		int x = t % base;
		t /= base;
		ans += x * x;
	}
	return ans;
}

#define MAX 12000000
int happy[11][MAX + 10];
int check(int t, int base)
{
	if (t == 1)
		return 1;
	int &v = happy[base][t];
	if (v == 0 && v == 1)
		return v;
	if (v == 2)
		return v = 0;
	v = 2;

	int n = getnext(t, base);
	return v = check(n, base);
}

int main()
{
	memset(happy, -1, sizeof(happy));
	for (int i = 2; i <= 10; ++i)
		for (int j = 1; j < MAX; ++j)
			happy[i][j] = check(j, i);
	int T;
	scanf("%d", &T);
	char s[300];
	gets(s);
	for (int i = 1; i <= T; ++i)
	{
		gets(s);
		istringstream is(s);
		int bc = 0, tmp;
		int b[15];
		while (is >> tmp)
			b[bc++] = tmp;
		int ok = 0, k;
		for (k = 2; !ok; ++k)
		{
			ok = 1;
			for (int j = 0; j < bc && ok; ++j)
				if (!happy[b[j]][k])
					ok = 0;
		}
		printf("Case #%d: %d\n", i, k - 1);
	}
}
