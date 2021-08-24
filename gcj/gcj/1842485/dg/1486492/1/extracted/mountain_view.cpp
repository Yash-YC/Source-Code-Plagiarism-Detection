// vim:set ts=8 sw=4 et smarttab:
// Round 2 2012

#include <cstdio>
#include <cstring>
#include <cassert>

int n, x[2000], y[2000];

int check(int i)
{
    int maxj = i + 1;
    for (int j = i + 2; j < n; ++j)
    {
        if ((x[j] - x[i]) * (maxj - i) > (x[maxj] - x[i]) * (j - i))
        {
            maxj = j;
        }
    }
    return maxj;
}

bool increase(int i, int maxj)
{
    if (y[i] < maxj)
    {
        int j = y[i];
        while ((x[j] - x[i]) * (maxj - i) < (x[maxj] - x[i]) * (j - i))
        {
            if (x[j] == 1000000000)
            {
                return false;
            }
            ++x[j];
        }
    }
    else
    {
        int j = y[i];
        while ((x[j] - x[i]) * (maxj - i) <= (x[maxj] - x[i]) * (j - i))
        {
            if (x[j] == 1000000000)
            {
                return false;
            }
            ++x[j];
        }
    }
    return true;
}

const int sucess = 0;
const int retry = 1;
const int failed = 2;

bool run()
{
    for (int i = n - 2; i >= 0; --i)
    {
        int maxj = check(i);
        if (y[i] != maxj)
        {
            if (!increase(i, maxj))
            {
                return failed;
            }
            return retry;
        }
    }
    return sucess;
}

bool solve()
{
    for (int i = 0; i < n; ++i)
    {
        x[i] = 0;
    }
    for (int i = 0; i < 10 * n; ++i)
    {
        int temp = run();
        if (temp == sucess)
        {
            return true;
        }
        if (temp == failed)
        {
            return false;
        }
    }
    return false;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int tc = 1; tc <= ntc; ++tc)
    {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d", &y[i]);
            --y[i];
        }
        if (solve())
        {
            printf("Case #%d:", tc);
            for (int i = 0; i < n; ++i)
            {
                printf(" %d", x[i]);
            }
            printf("\n");
        }
        else
        {
            printf("Case #%d: Impossible\n", tc);
        }
    }
}
