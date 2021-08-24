#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

int depth;

int isHappy(int n, int b)
{
	//printf("%d %d\n", n, b);
	if (depth > 100)
		return 0;
	if (n == 1)
		return 1;
	if (n <= 0) {
		printf("!!!!!\n");
		return 0;
	}
	if (b == 2)
		return 1;
	int sum = 0;
	int n0 = n;
	while (n0) {
		int i = n0 % b;
		sum += i * i;
		n0 /= b;
	}
	bool t;
	if (n == sum) {
		t = false;
	} else {
		++depth;
		t = isHappy(sum, b);
	}
	return t;
}

int main()
{
	int N_;
	scanf("%d\n", &N_);
	string str;
	for (int n_=1; n_<=N_; ++n_) {
		getline(cin, str);
		stringstream ss(str);
		int flag[20];
		memset(flag, 0, sizeof(flag));
		while (!ss.eof()) {
			unsigned int b;
			ss >> b;
			if (b <= 10)
				flag[b] = 1;
		}
		int ans = 2;
		for (;;) {
			bool t = true;
			for (int b=2; b<=10; ++b) {
				if (flag[b]) {
					depth = 0;
					t = isHappy(ans, b);
				}
				if (!t)
					break;
			}
			if (t)
				break;
			else
				++ans;
		}
		printf("Case #%d: %d\n", n_, ans);
	}
	return 0;
}

