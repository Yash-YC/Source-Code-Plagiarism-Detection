#include <stdafx.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

inline bool judge(int, int);

int main(void)
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int n;
	int t, i, j, k;
	char in[1<<10];

	scanf("%d", &t);
	gets(in);
	while (t--) {
		gets(in);
		k = 0;
		for (i = strlen(in) - 1; i >= 0; --i)
			if (in[i] == ' ') ++k;
		++k;
		vector<int> v;
		for (i = j = 0; i < k; ++i) {
			n = 0;
			while (isdigit(in[j])) {
				n = n * 10 + in[j] - '0';
				++j;
			}
			//printf("n = %d\n", n);
			//system("pause");
			v.push_back(n);
			++j;
		}
		vector<int>::iterator it;
		//printf("v.size = %d\n", v.size());
		//for (it = v.begin(); it != v.end(); ++it) {
		//	printf("%d\n", *it);
		//}
		vector<int>::reverse_iterator rit;
		for (n = 2; true; ++n) {
			bool flag = true;
			for (rit = v.rbegin(); rit != v.rend(); ++rit)
				if (!judge(n, *rit)) {
					flag = false; break;
				}
			if (flag) break;
		}
		static int ca = 0;
		printf("Case #%d: %d\n", ++ca, n);
	}

	return 0;
}

bool judge(int n, int b) {
	//printf("n = %d, b = %d\n", n, b);
	set<int> se;
	se.insert(n);
	while (true) {
		int s = 0, t;
		while (n) {
			t = n % b;
			s += t * t;
			n /= b;
		}
		if (se.count(s)) return false;
		n = s;
		if (n == 1) return true;
		se.insert(n);
		//printf("n = %d\n", n);
		//system("pause");
	}
	return n == 1;
}
