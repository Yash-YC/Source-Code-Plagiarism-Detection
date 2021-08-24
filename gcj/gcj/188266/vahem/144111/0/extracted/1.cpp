#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

string inp = "B-small-attempt1.in";
string outp = "B-small-attempt1.out";

typedef long long lint;

struct pel
{
  lint dist;
  int i;
  int j;
  int di;
  int dj;
};

struct cmp
{
  bool operator()(const pel& a, const pel& b)
{
  return a.dist > b.dist;
}
};
const int NMAX = 22;

lint dst[NMAX][NMAX][2][2];
lint S[NMAX][NMAX], W[NMAX][NMAX], T[NMAX][NMAX];
bool vis[NMAX][NMAX][2][2];

typedef priority_queue<pel, vector<pel>, cmp> pq;
void mypush(pq &P, int i, int j, int di, int dj)
{
  pel a;
  a.i = i;
  a.j = j;
  a.di = di;
  a.dj = dj;
  a.dist = dst[i][j][di][dj];
  P.push(a);
}

int main()
{
  freopen(inp.c_str(), "r", stdin);
  freopen(outp.c_str(), "w", stdout);
  int C;
  cin >> C;
  for (int it = 0; it < C; it++)
  {
    cerr << it;
    int i, j, n, m;
    pq P;
    cin >> n >> m;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        cin >> S[i][j] >> W[i][j] >> T[i][j];
    memset(dst, 64, sizeof(dst));
    memset(vis, 0, sizeof(vis));
    dst[n-1][0][1][0] = 0;
    pel start;
    start.dist = 0;
    start.i = n - 1;
    start.j  = 0;
    start.di = 1;
    start.dj = 0;
    P.push(start);
    while (vis[0][m-1][0][1] == 0)
    {
      pel v = P.top();
      P.pop();
      if (vis[v.i][v.j][v.di][v.dj])
        continue;
      else
        vis[v.i][v.j][v.di][v.dj] = true;
      int i = v.i, j = v.j, di = v.di, dj = v.dj;
      int ni = i + 2 * di - 1;
      if (ni >= 0 && ni < n && ~vis[ni][j][1-di][dj])
        if (dst[ni][j][1-di][dj] > dst[i][j][di][dj] + 2)
        {
          dst[ni][j][1-di][dj] = dst[i][j][di][dj] + 2;
          mypush(P, ni, j, 1-di, dj);
        }
      int nj = j + 2 * dj - 1;
      if (nj >= 0 && nj < m && ~vis[i][nj][di][1-dj])
        if (dst[i][nj][di][1-dj] > dst[i][j][di][dj] + 2)
        {
          dst[i][nj][di][1-dj] = dst[i][j][di][dj] + 2;
          mypush(P, i, nj, di, 1-dj);
        }

      lint dur = S[i][j] + W[i][j];
      lint tc = ((v.dist - T[i][j])  % dur + dur) % dur;
      lint ts, tw;
      if (tc < S[i][j])
      {
        ts = 0;
        tw = S[i][j] - tc;
      }
      else
      {
        ts = dur - tc;
        tw = 0;
      }
      if (~vis[i][j][1-di][dj])
        if (dst[i][j][1-di][dj] > dst[i][j][di][dj] + ts + 1)
        {
          dst[i][j][1-di][dj] = dst[i][j][di][dj] + ts + 1;
          mypush(P, i, j, 1-di, dj);
        }
      if (~vis[i][j][di][1-dj])
        if (dst[i][j][di][1-dj] > dst[i][j][di][dj] + tw + 1)
        {
          dst[i][j][di][1-dj] = dst[i][j][di][dj] + tw + 1;
          mypush(P, i, j, di, 1-dj);
        }
    }
    cout << "Case #" << it + 1 << ": " << dst[0][m-1][0][1] << endl;
  }
  return 0;
}
