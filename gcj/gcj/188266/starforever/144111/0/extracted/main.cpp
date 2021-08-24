#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <ctime>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define min2(a,b) (((a) < (b)) ? (a) : (b))
#define sqr(x) ((x) * (x))
#define debug(x) cout << (#x) << ": " << (x) << endl
#define echo(x) cout << (#x) << endl
#define SZ(x) (int(x.size()))

#define PB push_back
#define MP make_pair
#define FI first
#define SE second

const double eps = 1e-8;
const double pi = acos(-1.0);
const int oo = 0x7f7f7f7f;

typedef long long LL;

int TN, TC;
int X, Y;

struct Edge
{
  int ops;
  int len;
  int next;
  bool cross;
  int green, red, start;
};

int N, S, T;
int adj[1600];

int E;
Edge edge[6400];

bool vis[1600];
int dis[1600];
priority_queue<pair<int, int> > heap;

void addEdge (int a, int b, int len, int green = -1, int red = -1, int start = -1)
{
  edge[E] = (Edge){b, len, adj[a], green != -1, green, red, start};
  adj[a] = E++;
  edge[E] = (Edge){a, len, adj[b], green != -1, green, red, start};
  adj[b] = E++;
}

int waittime (int cur, int green, int red, int start)
{
  int cy = green + red;
  int x = ((cur - start) % cy + cy) % cy;
  return x < green ? 0 : cy - x;
}

int solve ()
{
  memset(vis, false, sizeof(vis));
  memset(dis, oo, sizeof(dis));
  while (!heap.empty())
    heap.pop();
  dis[S] = 0;
  heap.push(MP(0, S));
  while (true)
  {
    while (!heap.empty() && vis[heap.top().SE])
      heap.pop();
    if (heap.empty())
      return -1;
    int ds = -heap.top().FI, p = heap.top().SE;
    heap.pop();
    if (p == T)
      return ds;
    vis[p] = true;
    for (int i = adj[p]; i != -1; i = edge[i].next)
    {
      int ds2 = ds, v = edge[i].ops;
      if (!edge[i].cross)
        ds2 += edge[i].len;
      else
        ds2 += edge[i].len + waittime(ds2, edge[i].green, edge[i].red, edge[i].start);
      if (ds2 < dis[v])
      {
        dis[v] = ds2;
        heap.push(MP(-ds2, v));
      }
    }
  } 
  return -1;
}

int main ()
{
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    scanf("%d%d", &X, &Y);
    N = X * Y * 4;
    E = 0;
    memset(adj, -1, sizeof(adj));
    for (int i = 0; i < X; ++i)
      for (int j = 0; j < Y; ++j)
      {
        int green, red, start;
        int i0 = (i * Y + j) * 4, i1 = i0 + 1, i2 = i0 + 2, i3 = i0 + 3;
        scanf("%d%d%d", &green, &red, &start);
        addEdge(i0, i1, 1, red, green, start + green);
        addEdge(i2, i3, 1, red, green, start + green);
        addEdge(i1, i2, 1, green, red, start);
        addEdge(i0, i3, 1, green, red, start);
      }
    for (int x = 0; x < X; ++x)
      for (int y = 0; y < Y; ++y)
      {
        int b0 = (x * Y + y) * 4, by = (x * Y + y + 1) * 4, bx = ((x + 1) * Y + y) * 4;
        if (y + 1 < Y)
        {
          addEdge(b0 + 1, by + 0, 2);
          addEdge(b0 + 2, by + 3, 2);
        }
        if (x + 1 < X)
        {
          addEdge(b0 + 2, bx + 1, 2);
          addEdge(b0 + 3, bx + 0, 2);
        }
      }
    S = ((X - 1) * Y + 0) * 4 + 3, T = (0 * Y + (Y - 1)) * 4 + 1;
    printf("Case #%d: %d\n", TC, solve());
  }
}
