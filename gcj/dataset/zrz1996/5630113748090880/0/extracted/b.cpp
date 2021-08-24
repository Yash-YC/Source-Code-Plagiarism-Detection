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
map<int, int> M;
void solve(int task)
{
	printf("Case #%d: ", task);
	M.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			M[x] ^= 1;
		}
	for (auto i : M)
		if (i.second)
			printf("%d ", i.first);
	puts("");
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
