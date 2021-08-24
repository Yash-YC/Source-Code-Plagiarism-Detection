
//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
int n;
int a[110][55];
int b[55][55], mi;
bool filled[110];
int maybe[110];
void solve(int i, int j)
{
    int x = maybe[i], y = maybe[i + n];
    if(a[x][j] == b[i][j])
    {
        filled[i] = true;
        if(y != -1) filled[i + n] = true;
        for(j = 1; j <= n; ++j)
        {
            b[i][j] = a[x][j];
            if(y != -1)
            {
                b[j][i] = a[y][j];
            }
        }
    }
    else
    {
        filled[i + n] = true;
        if(y != -1) filled[i] = true;
        for(j = 1; j <= n; ++j)
        {
            b[j][i] = a[x][j];
            if(y != -1)
            {
                b[i][j] = a[y][j];
            }
        }
    }
    if(y == -1) return ;
    for(j = 1; j <= n; ++j)
    {
        if(!filled[j] && !filled[j + n] && b[i][j] != b[j][i])
        {
            solve(j, i);
        }
    }
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:", cas);
        scanf("%d", &n);
        mi = INF;
        for(int i = 1; i < n + n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                scanf("%d", &a[i][j]);
                mi = min(mi, a[i][j]);
            }
        }
        memset(filled, 0, sizeof(filled));
        for(int i = 1; i < n + n; ++i)
        {
            if(a[i][1] != mi) continue;
            if(!filled[1])
            {
                filled[1] = true;
                for(int j = 1; j <= n; ++j)
                {
                    b[1][j] = a[i][j];
                }
            }
            else
            {
                filled[n + 1] = true;
                for(int j = 1; j <= n; ++j)
                {
                    b[j][1] = a[i][j];
                }
            }
        }
        for(int i = 2; i <= n; ++i)
        {
            maybe[i] = -1, maybe[i + n] = -1;
            for(int j = 1; j < n + n; ++j)
            {
                if(a[j][1] == b[1][i])
                {
                    b[i][i] = a[j][i];
                    maybe[i] = j;
                    break;
                }
            }
            for(int j = 1; j < n + n; ++j)
            {
                if(a[j][i] == b[i][i] && maybe[i] != j)
                {
                    maybe[i + n] = j;
                    break;
                }
            }
        }
        if(!filled[n + 1])
        {
            for(int i = 2; i <= n; ++i)
            {
                b[i][1] = a[maybe[i + n]][1];
            }
            for(int i = 1; i <= n; ++i) printf(" %d", b[i][1]);
            puts("");
            continue;
        }
        for(int i = 2; i <= n; ++i)
        {
            if(b[1][i] != b[i][1])
            {
                solve(i, 1);
            }
        }
        for(int i = 2; i <= n; ++i)
        {
            if(filled[i] || filled[i + n]) continue;
            int x = maybe[i], y = maybe[i + n];
            filled[i] = true;
            if(y != -1) filled[i + n] = true;
            for(int j = 1; j <= n; ++j)
            {
                b[i][j] = a[x][j];
                if(y != -1) b[j][i] = a[y][j];
            }
            if(y == -1) continue;
            for(int j = 1; j <= n; ++j)
            {
                if(!filled[j] && !filled[j + n] && b[i][j] != b[j][i])
                {
                    solve(j, i);
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!filled[i])
            {
                for(int j = 1; j <= n; ++j)
                    printf(" %d", b[i][j]);
                break;
            }
            if(!filled[i + n])
            {
                for(int j = 1; j <= n; ++j)
                    printf(" %d", b[j][i]);
                break;
            }
        }
        puts("");
    }
    return 0;
}
