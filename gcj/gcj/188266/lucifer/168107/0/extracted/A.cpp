#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

char str[100];
int b[10], top;
bool vis[100000];

void init()
{
    gets(str);
    istringstream in(str);

    top = 0;
    int num;
    while(in >> num) b[top++] = num;
}

int check(int n, int b)
{
    memset(vis, 0, sizeof vis);
    while(true)
    {
        if(n == 1) return 1;
        if(vis[n]) return 0;

        vis[n] = 1;

        int sum = 0;
        while(n)
        {
            int tmp = n % b;
            sum += tmp * tmp;
            n /= b;
        }

        n = sum;
    }
}

void solve(int tc)
{
    printf("Case #%d: ", tc);

    for(int i=2; ; ++i)
    {
        int flag = 1;
        for(int j=0; j<top; ++j)
            if(!check(i, b[j])) flag = 0;
        if(flag){ printf("%d\n", i); return; }
    }
}

int main()
{
    int t, tc = 0;
    scanf("%d\n", &t);
    while(t--)
    {
        init();
        solve(++tc);
    }
    return 0;
}

