#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1 << 25;
const int b[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

vector <int> v[9];
int happy[inf + 10];
bool vi[inf + 10];
int g[inf + 10];
int ans[260];

int changebase(int num, int base)
{
    int res = 0;
    int nowbase = 1;
    while (num) {
        res += num % base * nowbase;
        num /= base;
        nowbase *= 10;
    }
    return res;
}

int happyval(int num)
{
    int res = 0;
    while (num) {
        int t = num % 10;
        res += t * t;
        num /= 10;
    }
    return res;
}

int cal(int num, int base)
{
    if (happy[num] != -1)
        return happy[num];
    if (vi[num])
        return num;
    vi[num] = true;
    int t = changebase(num, base);
    happy[num] = cal(happyval(t), base);
    if (happy[num] == 1) {
        g[num] |= (1 << (base - 2));
        v[base - 2].push_back(num);
    }
    return happy[num];
}

void create()
{
    memset (g, 0, sizeof(g));
    for (int j = 0; j < 9; ++j) {
        int base = b[j];
        memset (happy, -1, sizeof(happy));
        memset (vi, false, sizeof(vi));
        happy[1] = 1;
        for (int i = 2; i <= inf; ++i) {
            if (happy[i] == -1) {
                cal(i, base);
            }
        }
        sort(v[j].begin(), v[j].end());
    }
    /* for (int i = 0; i < v[6].size(); ++i)
        printf ("%d ", v[6][i]);
    printf ("\n");
    for (int i = 0; i < v[7].size(); ++i)
        printf ("%d ", v[7][i]);
    printf ("\n");
    for (int i = 0; i < v[8].size(); ++i)
        printf ("%d ", v[8][i]);
    printf ("\n"); */
}


int getans(int k)
{
    for (int i = 2; i <= inf; ++i) {
        if ((g[i] & k) == k)
            return i;
    }
    return -1;
}

void make()
{
    int goal = (1 << 9) - 1;
    for (int k = 1; k <= goal; ++k) {
        ans[k] = getans(k);
        printf ("%d, ", ans[k]);
    }
}

int main()
{
    freopen ("out.txt", "w", stdout);
    
    create();
    make();
    
    //freopen ("A-small-attempt0.in", "r", stdin);
    
    
    /*int t, Case = 1;
    scanf ("%d", &t);
    getchar();
    
    while (t--) {
        int now = 0, num = 0;
        for (char ch = getchar(); ch != '\n'; ch = getchar()) {
            if (ch == ' ') {
                printf ("%d ", num);
                now |= (1 << (num - 2));
                num = 0;
            }
            else 
                num = num * 10 + ch - '0';
        }
        printf ("%d ", num);
        now |= (1 << (num - 2));
        printf ("Case #%d: %d\n", Case++, ans[now]);
    } */
    
    return 0;
}
