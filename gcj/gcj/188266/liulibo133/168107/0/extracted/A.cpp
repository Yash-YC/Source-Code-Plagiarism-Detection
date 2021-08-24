#include<iostream>
#include<sstream>

using namespace std;

char str[100];
bool used[1000000];

bool check(int num, int base)
{
	memset(used, 0, sizeof(used));
	int sum;
	while (!used[num])
	{
		used[num] = 1;
		sum = 0;
		while (num != 0)
		{
			sum += (num % base) * (num % base);
			num /= base;
		}
		num = sum;
	}
	if (num == 1) return 1;
	return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	gets(str);
	int caseID = 1;
	while (caseID <= t)
	{
		gets(str);
		string s = string(str);
		bool flag = 0;
		int i;
		for (i = 2; ; i++)
		{
			flag = 1;
			int base;
			stringstream istr(s);
			while (istr >> base)
				if (!check(i, base))
				{
					flag = 0;
					break;
				}
			if (flag) break;
		}
		printf("Case #%d: %d\n", caseID++, i);
	}
	return 0;
}