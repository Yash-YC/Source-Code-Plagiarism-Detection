#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,a) for (int i = 0; i < a; i++)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 1010;
char c[maxn];

void solve(int task)
{
	printf("Case #%d: ", task);
	scanf("%s", c);
	int n = strlen(c);
	string ans = "";
	ans += c[0];
	for (int i = 1; i < n; i++)
	{
		string t1 = c[i] + ans;
		string t2 = ans + c[i];
		if (t1 < t2)
			ans = t2;
		else
			ans = t1;
	}
	cout << ans << endl;
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
