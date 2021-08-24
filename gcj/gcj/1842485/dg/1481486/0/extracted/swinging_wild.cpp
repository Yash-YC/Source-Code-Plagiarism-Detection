// vim:set ts=8 sw=4 et smarttab:
// Round 2 2012

#include <cstdio>
#include <cstring>
#include <algorithm>

int n, d, dist[10000], length[10000];
int max_reach[10000];

bool solve()
{
    std::fill(max_reach, max_reach + n, 0);
    max_reach[0] = dist[0];
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] + max_reach[i] >= d)
        {
            return true;
        }
        for (int j = i + 1; j < n && dist[j] <= dist[i] + max_reach[i]; ++j)
        {
            int temp = std::min(dist[j] - dist[i], length[j]);
            if (temp > max_reach[j])
            {
                max_reach[j] = temp;
            }
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
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &dist[i], &length[i]);
        }
        scanf("%d", &d);
        if (solve())
        {
            printf("Case #%d: YES\n", tc);
        }
        else
        {
            printf("Case #%d: NO\n", tc);
        }
    }
}
