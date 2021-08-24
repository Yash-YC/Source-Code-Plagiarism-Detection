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

const int NMAX(32);

int S[NMAX][NMAX];
int W[NMAX][NMAX];
int T[NMAX][NMAX];

int N, M;

int dist[NMAX * 2][NMAX * 2];
char flag[NMAX * 2][NMAX * 2];

const int dirx[4] = {0, -1,  0, 1};
const int diry[4] = {1,  0, -1, 0};

int getNextTime(int i, int j, int t, char type)
{
    int tt = (t - T[i][j]) % (S[i][j] + W[i][j]);
    if (type == 0)
    {
        if (tt >= 0 && tt < S[i][j])
        {
            return t;
        }
        else
        {
            return t - tt + S[i][j] + W[i][j];
        }
    }
    if (tt >= S[i][j])
    {
        return t;
    }
    return t - tt + S[i][j];
}

int main()
{
    int numTestCase;
    scanf("%d", &numTestCase);
    for (int tc = 1; tc <= numTestCase; ++tc)
    {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d%d%d", &S[i][j], &W[i][j], &T[i][j]);
                T[i][j] %= (S[i][j] + W[i][j]);
                if (T[i][j] > 0)
                {
                    T[i][j] -= S[i][j] + W[i][j];
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        memset(flag, 0,  sizeof(flag));
        flag[2 * N - 1][0] = 1;
        dist[2 * N - 1][0] = 0;
        int mini = 2 * N - 1, minj = 0;
        while (mini != 0 || minj != 2 * M - 1)
        {
            for (int i = 0; i < 4; ++i)
            {
                int ti = mini + diry[i], tj = minj + dirx[i];
                if (ti <= -1 || tj <= -1 || ti >= 2 * N || tj >= 2 * M)
                {
                    continue;
                }
                int d = dist[mini][minj];
                if (ti /2 != mini / 2 || tj / 2 != minj / 2)
                {
                    d += 2;
                }
                else
                {
                    int ci = mini / 2, cj = minj / 2;
                    if (ti == mini)
                    {
                        d = getNextTime(ci, cj, d, 1) + 1;
                    }
                    else
                    {
                        d = getNextTime(ci, cj, d, 0) + 1;
                    }
                }
                if (dist[ti][tj] > d || dist[ti][tj] == -1)
                {
                    dist[ti][tj] = d;
                }
            }
            mini = -1, minj = -1;
            for (int i = 0; i < 2 * N; i++)
            {
                for (int j = 0; j < 2 * M; j++)
                {
                    if (!flag[i][j] && dist[i][j] != -1 && (mini == -1 || dist[mini][minj] > dist[i][j]))
                    {
                        mini = i;
                        minj = j;
                    }
                }
            }
            flag[mini][minj] = 1;
        }
        printf("Case #%d: %d\n", tc, dist[0][2 * M - 1]);
    }
    return 0;
}
