#include <stdio.h>
#include <string>

const int MaxN = 10000000;

char s[100];
int T, C, i, j, k, t;
int a[MaxN], c[11][MaxN];

int get()
{
	int k;
	
    k = 0;
    while ('0'<=s[t] && s[t]<='9') { k = k * 10 + s[t] - '0'; t ++; }
    while (s[t]!='\0' && (s[t]>'9' || s[t]<'0')) t ++;
    return k;
}

void go(int x, int y)
{
    int s, p;
    
    if (x==1) c[y][x] = 1;
    if (c[y][x]) return;
    c[y][x] = 3;
    s = 0; p = x;
    while (p) { s += (p % y) * (p % y); p /= y; }
    go(s, y);
    if (c[y][s]==1) c[y][x] = 1; else c[y][x] = 2;
}

int check(int x)
{
    int ans, i, j, k;
    
    ans = 0;
    for (i=2; i<11; i++)
    {
        /*k = x; b[0] = 0;
        while (k) { b[0] ++; b[b[0]] = k % i; k /= i; }*/
        go(x, i);
        if (c[i][x]==1) ans += 1 << (i - 2);
    }
    return ans;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d ", &T);
    for (i=0; i<MaxN; i++) a[i] = -1;
    memset(c, 0, sizeof(c));
    for (C=1; C<=T; C++)
    {
        gets(s); t = 0; k = 0;
        while (s[t]!='\0' && (s[t]>'9' || s[t]<'0')) t ++;
        while (s[t]!='\0') k |= 1 << (get() - 2);
        for (i=2; a[i]<0 || (a[i]&k)!=k; i++)
        {
            if (a[i]<0) a[i] = check(i);
            if ((a[i]&k)==k) break;
            if (i%1000000==0) printf("%d\n", i);
            if (i>MaxN) break;
        }
        printf("Case #%d: %d\n", C, i);
    }
}

