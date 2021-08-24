#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000000;

vector<int> go[MAX][11];
bool valid[MAX][11];

char buf[100];

void init() {
	for (int x = 1; x < MAX; ++x)
		for (int i = 2; i <= 10; ++i) {
			int sum = 0, tmp = x;
			while (tmp > 0) {
				sum += (tmp % i) * (tmp % i);
				tmp /= i;
			}
			go[sum][i].push_back(x);
		}
	memset(valid, 0, sizeof(valid));
	for (int i = 2; i <= 10; ++i) {
		valid[1][i] = true;
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (vector<int>::iterator iter = go[now][i].begin(); iter != go[now][i].end(); ++iter)
				if (!valid[*iter][i]) {
					valid[*iter][i] = true;
					q.push(*iter);
				}
		}
	}
}

int solve(int mask) {
//	printf("f[7][3] = %d + %d\n", valid[7][3], valid[7][2]);

//	7 = 111 -> 3 -> 11 -> 2 -> 10 -> 1
  //           21 -> 5 -> 12 -> 5
	for (int i = 2; i < MAX; ++i) {
		bool succ = true;
		for (int j = 1; j <= 10 && succ; ++j)
			if ((1 << j) & mask)
				succ = valid[i][j];
		if (succ)
			return i;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	gets(buf);
	init();
	for (int tId = 1; tId <= T; ++tId) {
		gets(buf);
		istringstream iss(buf);
		int t, num = 0;
		while (iss >> t)
			num |= 1 << t;
		printf("Case #%d: %d\n", tId, solve(num));
	}
	return 0;
}


