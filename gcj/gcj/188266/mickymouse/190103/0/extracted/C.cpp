#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);
	int test, c, n, cases = 1;
	scanf("%d", &test);
	while(test --)
	{
		scanf("%d %d", &c, &n);
		double ans;
		ans = (c + n) * 1.0 / n;
		printf("Case #%d: %.7lf\n", cases ++, ans);
	}
	return 0;
}