#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

const int MAX =  11814485 + 100;

vector<int> go[MAX];
int valid[MAX];

char buf[100];

void init() {
	memset(valid, 0, sizeof(valid));
	for (int i = 2; i <= 10; ++i) {
		for (int x = 1; x < MAX; ++x)
			go[x].clear();
		for (int x = 1; x < MAX; ++x) {
			int sum = 0, tmp = x;
			while (tmp > 0) {
				int y = tmp % i;
				sum += y * y;
				tmp /= i;
			}
			go[sum].push_back(x);
		}
		valid[1] |= 1 << i;
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (vector<int>::iterator iter = go[now].begin(); iter != go[now].end(); ++iter)
				if ((valid[*iter] & (1 << i)) == 0) {
					valid[*iter] |= 1 << i;
				
					q.push(*iter);
				}
		}
	}
}

int solve(int mask) {
	for (int i = 2; i < MAX; ++i)
		if ((valid[i] & mask) == mask)
			return i;
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

