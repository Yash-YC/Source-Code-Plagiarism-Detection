
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int N, M;

struct intersection { int s, w, t; };

intersection m[100][100];
bool visited[100][100];

struct node {
  int i, j, t;
  node(int _i, int _j, int _t) {i=_i;j=_j;t=_t;}
  bool operator<(const node & n) const { return n.t < t; }
};

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j)
{
  return i >= 0 && j >= 0 && i < N*2 && j < M*2;
}

void solve(int C)
{
  cin >> N >> M;
  memset(visited, false, sizeof visited);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      cin >> m[i][j].s >> m[i][j].w >> m[i][j].t;
      m[i][j].t %= (m[i][j].s + m[i][j].w);
      m[i][j].t -= (m[i][j].s + m[i][j].w);
    }

  node start(2*N-1, 0, 0);

  priority_queue<node> pq;
  pq.push(start);

  while (!pq.empty())
  {
    node n = pq.top(); pq.pop();
    if (visited[n.i][n.j])
      continue;

    //printf("visiting %d %d at %d\n", n.i, n.j, n.t);
    visited[n.i][n.j] = true;
    if (n.i == 0 && n.j == M*2-1)
    {
      printf("Case #%d: %d\n", C, n.t);
      return;
    }

    for (int k = 0; k < 4; k++)
    {
      int ni = n.i + d[k][0];
      int nj = n.j + d[k][1];
      if (valid(ni, nj) && !visited[ni][nj])
      {
        int nt = n.t;
        if (n.i/2 != ni/2 || n.j/2 != nj/2)
          nt += 2; // two minutes to walk along a road
        else
        {
          int ii = n.i/2;
          int ij = n.j/2;

          int cycle_time = m[ii][ij].s + m[ii][ij].w;

          // NS turns green at:
          int start = (m[ii][ij].t - n.t) % (cycle_time) + n.t;
          // EW turns green at:
          int end_ns = start + m[ii][ij].s;
          int end_ew = end_ns + m[ii][ij].w;

          if (k < 2) // VERTICAL, necessita NS verde.
          {
            if (n.t + 1 > end_ns) // we don't have time.
              nt = start + cycle_time; // we have to wait for the end of the cycle.
            // else, just cross it.
          }
          else // HORIZONTAL, necessita EW verde.
          {
            if (n.t <= end_ns) // just wait for the change and cross it
              nt = end_ns;
            else if (n.t + 1 > end_ew) // we don't have time
              nt = end_ns + cycle_time;
          }

          nt += 1; // crossing time
        }

        pq.push(node(ni, nj, nt));
      }
    }
  }
}


int main()
{
  int C;
  cin >> C;
  for (int i = 1; i <= C; i++)
    solve(i);
  return 0;
}
