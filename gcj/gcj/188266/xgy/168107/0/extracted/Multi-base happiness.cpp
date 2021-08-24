#include <string>
#include <cstdio>
#include <sstream>
using namespace std;

int mem[100000][11];

int happy(int n, int base) {
	if (n == 1)
		return 1;
	if (mem[n][base])
		return mem[n][base];
	mem[n][base] = -1;
	int tmp = n;
	int m = 0;
	while (n > 0) {
		int t = n % base;
		m += t * t;
		n = n / base;
	}
	return mem[tmp][base] = happy(m, base);
}

int main() {
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T;
	char buf[100];
	scanf("%d", &T);
	gets(buf);
	memset(mem, 0, sizeof(mem));
	for (int t = 1; t <= T; ++t) {
		gets(buf);
		stringstream ss(buf);
		int a[20];
		int n = 0;
		int x;
		while (ss >> x) {
			a[n++] = x;
		}
		int i;
		for (i = 2; ; ++i) {
			bool flag = true;
			for (int j = 0; j < n && flag; ++j)
				if (happy(i, a[j]) == -1)
					flag = false;
			if (flag)
				break;
		}
		printf("Case #%d: %d\n", t , i);
		fflush(stdout);
	}
}
