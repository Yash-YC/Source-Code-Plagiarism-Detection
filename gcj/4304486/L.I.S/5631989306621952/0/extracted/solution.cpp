#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define debug 1

#define cerr if(debug) cerr

#define For(i, a, b) for(int i = a; i < b; i++)
#define sz(a) ((int)a.size())
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define len(a) ((int)(a.size()))

typedef pair<int, int> pii;
typedef long long lint;

const int inf = 0x7fffffff;
const int Size = 1000 * 1000 + 1;
char buffer[Size];

string dp[1001][26][26];

void init() {
}

void clear(int i) {
	For(i, 0, 1000) {
		For(j, 0, 26) {
			For(k, 0, 26) {
				dp[i][j][k] = "";
			}
		}
	}
}

int solution(int nTest) {
	scanf("%s", buffer);
	string s = buffer;
	int a = s[0] - 'A';
	dp[0][a][a] = s.substr(0, 1);
	For(i, 1, len(s)) {
		string m = s.substr(0, i + 1);
		int let = s[i] - 'A';
		string p = m.substr(i, 1);
		For(j, 0, 26) {
			For(k, 0, 26) {
				if (len(dp[i-1][j][k]) == 0) {
					continue;
				}
				if (len(dp[i][let][k]) == 0) {
					dp[i][let][k] = p + dp[i-1][j][k];
				} else {
					dp[i][let][k] = max(dp[i][let][k], 
							p + dp[i-1][j][k]);
				}
				dp[i][j][let] = max(dp[i][j][let], 
						dp[i-1][j][k] + p);
			}
		}
	}
	string res = "";
	For (i, 0, 26) {
		For(j, 0, 26) {
			res = max(res, dp[len(s) - 1][i][j]);
		}
	}
	printf("%s\n", res.c_str());





	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i = 0, n = 999999;
	scanf("%d", &n);
	init();
	For(i, 0, n) {
		printf("Case #%d: ", i + 1);
		clear(i);
		solution(i);
	}

	return 0;
}
	
