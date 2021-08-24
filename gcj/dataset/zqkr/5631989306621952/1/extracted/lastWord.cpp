#pragma region Template
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <algorithm>
#include <set>
#include <stack>
#include <cassert>
#include <cctype>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define SZ(a)        ((int)a.size())
#define LENGTH(a)    ((int)a.length())
#define ALL(a)       a.begin(), a.end()
#define REP(i, n)    for(int i = 0; i < (n); i++)
#define INC(i, a, b) for(int i = (a); i <= (b); i++)
#define DEC(i, a, b) for(int i = (a); i >= (b); i--)
#define CLEAR(a, b)  memset(a, b, sizeof a)
#define X            first
#define Y            second
#define si(a)        scanf("%d", &a)
#define ss(a)        scanf("%s", a)
#define sll(a)       scanf("%lld", &a)

typedef long long int LL;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int    inf = 1000000000;
const LL     INF = ((LL)inf)*inf;
#pragma endregion

#define LIM 4000
char inp[LIM], out[LIM];



int main(void) {
	freopen("input.in", "r", stdin);
//	freopen("output1.txt", "w", stdout);

	int tcase; si(tcase);
	REP(_i, tcase) {
		ss(inp);
		int len = strlen(inp);
		deque<char> ans;
		ans.push_front(inp[0]);
		INC(i, 1, len-1) {
			if(*ans.begin() > inp[i]) ans.push_back(inp[i]);
			else ans.push_front(inp[i]);
		}
		REP(i, len) {
			out[i] = *ans.begin();
			ans.pop_front();
		}
		out[len] = 0;
		printf("Case #%d: %s\n", _i+1, out);
	}
	return 0;
}
