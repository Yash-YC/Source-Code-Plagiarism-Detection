#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

char s[1005];

void solve() {
    scanf("%s", s);
    string ans = "";
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (ans.empty()) ans = c;
        else {
            string tmp = ans;
            if (c >= ans[0]) { ans = c; ans += tmp; }
            else ans = tmp + c;
        }
    }
    printf("%s\n", ans.c_str());
}

int main() {
    int case_n;
    scanf("%d", &case_n);
    for (int case_i = 1; case_i <= case_n; ++case_i) {
        printf("Case #%d: ", case_i);
        solve();
    }
    return 0;
}

