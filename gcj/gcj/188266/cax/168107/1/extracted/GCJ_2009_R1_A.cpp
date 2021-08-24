#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int N = 100000;
int a[10];
int dp[N][11];
int flag[N][11]; // 1: YES; -1: NO; 0: UNKOWN
int q[N];
const int M = 12000000;
bool visit[M];

int run(int n, int base)
{
	int ret = 0;
	for (; n; n /= base)
	{
		int i = n % base;
		ret += i * i;
	}
	return ret;
}

int check(int n, int base)
{
	visit[n] = true;
	int head, tail;
	q[0] = n;
	for (head = 0, tail = 1; head < tail; ++head)
	{
		int i = q[head];
		if (i < N) i = dp[i][base];
		else i = run(i, base);
		if (i < N && flag[i][base])
		{
			for (head = 0; head < tail; ++head)
				if (q[head] < N)
					flag[q[head]][base] = flag[i][base];
			return flag[i][base];
		}
		assert(i < M);
		if (visit[i]) return -1;
		visit[i] = true;
		q[tail++] = i;
	}
	return -1;
}

int main()
{
	int num, cas;
	int i, j, k;
	for (i = 1; i < N; ++i)
		for (j = 2; j <= 10; ++j)
		{
			int ret = 0;
			for (k = i; k; k /= j)
			{
				int u = k % j;
				ret += u * u;
			}
			dp[i][j] = ret;
		}
	cout << "ok" << endl;
	for (j = 2; j <= 10; ++j)
	{
		memset(visit, 0, sizeof(visit));
		flag[1][j] = 1;
		for (i = 2; i < N; ++i)
		{
			if (flag[i][j]) continue;
			flag[i][j] = check(i, j);
		}
	}
	cout << "ok" << endl;
//	cin >> cas;
//	cin.ignore(INT_MAX, '\n');
//	for (num = 1; num <= cas; ++num)
//	freopen("ans2.txt", "w", stdout);
	for (num = 1; num < 220; ++num)
	{
		/*
		string buf;
		getline(cin, buf);
		stringstream ss(buf);
		int n = 0;
		for (n = 0; ss >> a[n]; ++n);
		sort(a, a + n);
		n = unique(a, a + n) - a;
		*/
		int n = 0;
		for (i = 0; i < 9; ++i)
			if (num & (1 << i))
				a[n++] = i + 2;
		for (i = 2; ; ++i)
		{
			for (j = 0; j < n; ++j)
				if (check(i, a[j]) < 0) break;
			if (j == n) break;
		}
		cout << num << ": " << i << endl;
//		cout << "Case #" << num << ": " << i << endl;
	}
	return 0;
}
