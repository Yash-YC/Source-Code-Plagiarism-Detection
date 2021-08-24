// vim:set ts=8 sw=4 et smarttab:
// Round 2 2012

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

int n, w, l, r[1000], x[1000], y[1000], idx[1000];

struct comp
{
    bool operator() (const int &lhs, const int &rhs) const
    {
        return r[lhs] < r[rhs];
    }
};

void place(int i, int xx, int yy)
{
    x[i] = xx;
    y[i] = yy;
}

int findy(int n, int xx, int rr)
{
    int ret = rr;
    for (int i = 0; i < n; ++i)
    {
        if (abs(x[idx[i]] - xx) < rr + r[idx[i]])
        {
            int temp = y[idx[i]] + r[idx[i]] + rr;
            if (temp > ret)
            {
                ret = temp;
            }
        }
    }
    return ret;
}

int findx(int n, int yy, int rr)
{
    int ret = rr;
    for (int i = 0; i < n; ++i)
    {
        if (abs(y[idx[i]] - yy) < rr + r[idx[i]])
        {
            int temp = x[idx[i]] + r[idx[i]] + rr;
            if (temp > ret)
            {
                ret = temp;
            }
        }
    }
    return ret;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int tc = 1; tc <= ntc; ++tc)
    {
        scanf("%d%d%d", &n, &w, &l);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &r[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            idx[i] = i;
        }
        std::sort(idx, idx + n, comp());
        place(idx[0], 0, 0);
        for (int i = 1; i < n; ++i)
        {
            int xx = x[idx[i - 1]];
            int yy = findy(i, xx, r[idx[i]]);
            if (yy > l)
            {
                yy = 0;
                xx = findx(i, yy, r[idx[i]]);
            }
            place(idx[i], xx, yy);
        }
        printf("Case #%d:", tc);
        for (int i = 0; i < n; ++i)
        {
            printf(" %d %d", x[i], y[i]);
        }
        printf("\n");
    }
}
