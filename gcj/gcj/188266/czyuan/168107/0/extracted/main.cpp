#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

typedef long long int64; // 2 ^ 63 - 1 = 9223372036854775807.
typedef unsigned long long uint64; // 2 ^ 64 - 1 = 18446744073709551615.
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INT_INF = INT_MAX / 2;
const int64 INT64_INF = 1LL << 61;
#define mem(a, b) memset(a, b, sizeof(a))
#define Sqr(x) ((x) * (x))
template <class T> inline T Max(T a, T b) { if (a < b) a = b; return a; }
template <class T> inline T Min(T a, T b) { if (a > b) a = b; return a; }
template <class T> inline void Swap(T & a, T & b) { T t = a; a = b; b = t; }
inline int64 mod(int64 x, int64 y) { return x - floor(1.0 * x / y + EPS) * y; }

template <class T> void out(T x, int n) { for(int i = 0; i < n; ++i) cout << x[i] << " "; cout << endl; }
template <class T> void out(T x, int n, int m) {  for(int i = 0; i < n; ++i) out(x[i], m); cout << endl; }
#define Out(x) (cout << #x << " = " << x << endl)

const int maxn = 15;
const int maxm = 1 << 12;

int n, m;
int a[maxn];
map <string, int> Map;
int64 ans;

void Debug(void)
{
    int i, j;
}

void Read(void)
{
    int i, j;
    char st[5];
    int num(0);
    n = 0;
    while (1)
    {
        scanf("%s", st);
        for (i = num = 0; st[i]; i++) num = num * 10 + st[i] - '0';
        a[n++] = num;
        if (getchar() == '\n') break;
    }
//    out(a, n);
}

void Init(void)
{
    int i, j;
    ans = 0;
}

string ToBase(int num, int base)
{
    int i, j;
    string st = "";
    string res = "";
    while (num)
    {
        st += char(num % base + '0');
        num /= base;
    }
    for (i = st.length() - 1; i >= 0; i--) res += st[i];
    return res;
}

string HappyValue(string st, int base)
{
    int i, j;
    int num(0);
    for (i = 0; st[i]; i++)
    {
        num += Sqr(st[i] - '0');
    }
    return ToBase(num, base);
}

int Solve(void)
{
    int i, j, k;
    string st;
    for (i = 2; ; i++)
    {
        for (j = 0; j < n; j++)
        {
            Map.clear(); st = ToBase(i, a[j]);
            while (1)
            {
                if (st == "1") break;
                if (Map[st] > 0) break;
                Map[st] = 1;
                st = HappyValue(st, a[j]);
            }
            if (st != "1") break;
        }
        if (j == n) return i;
    }
}

int main(void)
{
    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
    int i, j;
    int cases;
    int case_num(0);
    char ch;
    scanf("%d", &cases); getchar();
    while (cases--)
    {
        Read();
        Init();
        printf("Case #%d: %d\n", ++case_num, Solve());
//        Debug();
    }
    return 0;
}
