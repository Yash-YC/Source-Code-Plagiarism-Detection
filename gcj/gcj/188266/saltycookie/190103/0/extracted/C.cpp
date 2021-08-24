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

typedef long long int64;

using namespace std;

const int NMAX(64);

double prob[2][NMAX];

int64 comb[NMAX][NMAX];

void combination()
{
    for (int i = 0; i <= 40; i++)
    {
        comb[i][i] = 1;
        comb[i][0] = 1;
    }
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

int main()
{
    combination();
    int numTestCase;
    scanf("%d", &numTestCase);
    for (int tc = 1; tc <= numTestCase; ++tc)
    {
        int N, C;
        scanf("%d%d", &C, &N);
        memset(prob, 0, sizeof(prob));
        prob[0][0] = 1;
        double exp = 0;
        int s = 0, t = 1;
        for (int num = 1; 1.0 - prob[s][C] > 1E-8; num++)
        {
            memset(prob[t], 0, sizeof(prob[0]));
            for (int i = 0; i <= C; ++i)
            {
                for (int j = i; j <= C && j <= N + i; j++)
                {
                    prob[t][j] += prob[s][i] * comb[i][N - j + i] / comb[C][N] * comb[C - i][j - i];
                }
            }
            exp += (prob[t][C] - prob[s][C]) * num;
            s ^= 1, t ^= 1;
        }
        printf("Case #%d: %lf\n", tc, exp);
    }
    return 0;
}
