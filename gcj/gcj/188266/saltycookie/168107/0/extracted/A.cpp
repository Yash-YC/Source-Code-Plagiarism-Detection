#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <iterator>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <cctype>

using namespace std;

int visit[1000000];
int stamp;

int reduce(int n, int base)
{
    int ret = 0;
    while (n)
    {
        int digit = n % base;
        ret += digit * digit;
        n /= base;
    }
    return ret;
}

bool isHappy(int n, int base)
{
    if (n == 1)
    {
        return true;
    }
    if (visit[n] == stamp)
    {
        return false;
    }
    visit[n] = stamp;
    return isHappy(reduce(n, base), base);
}

int main()
{
    int numTestCase;
    scanf("%d", &numTestCase);
    char buff[1024];
    int bases[16];
    int numBases;
    fgets(buff, 1023, stdin);
    for (int tc = 1; tc <= numTestCase; ++tc)
    {
        fgets(buff, 1023, stdin);
        int pos = 0, scan;
        numBases = 0;
        while (sscanf(buff + pos, "%d%n", &bases[numBases], &scan) == 1)
        {
            numBases++;
            pos += scan;
        }
        int ans = -1;
        for (int i = 2; ; ++i)
        {
            char allHappy = 1;
            for (int j = 0; j < numBases; ++j)
            {
                stamp++;
                if (!isHappy(i, bases[j]))
                {
                    allHappy = 0;
                    break;
                }
            }
            if (allHappy)
            {
                ans = i;
                printf("Case #%d: %d\n", tc, ans);
                break;
            }
        }
    }
    return 0;
}
