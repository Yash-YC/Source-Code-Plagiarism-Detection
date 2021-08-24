
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>
	using namespace std;

	const int limit = 1000000;
	bool check[15][limit + 5], ok[15][limit + 5], need[15];

	bool ch(int base, int num)
	{
		//printf("%d %d %d\n", base, num, ok[base][num] == true);
		if (check[base][num])
			return ok[base][num];
		check[base][num] = true;
		int tmp = num, result = 0;
		while (tmp > 0)
		{
			result += (tmp % base) * (tmp % base);
			tmp /= base;
		}
		if (result <= limit)
			ok[base][num] = ch(base, result);
		else
			ok[base][num] = false;
		return ok[base][num];
	}

	void init()
	{
		memset(check, false, sizeof(check));
		memset(ok, false, sizeof(ok));
		for (int i = 2; i <= 10; i ++)
			ok[i][1] = true;
		for (int i = 2; i <= 10; i ++)
			check[i][1] = true;
		//ch(2, 3);
		//printf("%d\n", ok[2][3]);
		
		for (int base = 2; base <= 10; base ++)
			for (int i = 2; i <= limit; i ++)
				if (!check[base][i])
					ok[base][i] = ch(base, i);
//		for (int i = 2; i <= 10; i ++)
//			for (int j = 2; j <= limit; j ++)
//				if (ok[i][j] == false)
//					printf("%d %d\n", i, j);
	}

	void find()
	{
		int ans = 2;
		while (ans < limit)
		{
			int flag = 1;
			for (int i = 2; i <= 10; i ++)
				if (need[i] && !ok[i][ans])
					flag = 0;
			if (flag == 1)
				break;
			ans ++;
		}
		printf("%d\n", ans);
	}

	void work()
	{
		memset(need, false, sizeof(need));
		while (true)
		{
			int x;
			scanf("%d", &x);
			need[x] = true;
			char c = getchar();
			if (c == '\n')
				break;
		}
		find();
	}

	int main()
	{
		int T;
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
		init();
		scanf("%d", &T);
		for (int i = 0; i < T; i ++)
		{
			printf("Case #%d: ", i + 1);
			work();
		}
		return 0;
	}
