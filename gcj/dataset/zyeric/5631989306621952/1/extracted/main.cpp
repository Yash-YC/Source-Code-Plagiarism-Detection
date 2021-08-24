#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <iomanip>
using namespace std;

//#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

const int MAXN = 1111;
char s[MAXN];

void solve() {
    scanf("%s", s);
    int N = (int)strlen(s);
    char head = s[0];
    char tail = s[0];
    string res = "";
    res += s[0];
    for (int i = 1; i < N; ++i) {
        char cur = s[i];
        if (cur >= head)
        {
            head = cur;
            string tmp = "";
            tmp += cur;
            res = tmp + res;
        }
        else
        {
            tail = cur;
            string tmp = "";
            tmp += cur;
            res = res + tmp;
        }
    }
    cout << res << endl;
}

int main() {
    
    //freopen("/Users/zyeric/Desktop/workspace/workspace/in.txt", "r", stdin);
    
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
    
    int T;
    cin >> T;
    
    for (int kase = 1; kase <= T; ++ kase) {
        cout << "Case #" << kase << ": ";
        solve();
        cerr << "solved " << kase << endl;
    }
    
    return 0;
}
