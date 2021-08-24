#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int C, N, M;
int S[20][20], W[20][20], T[20][20];
int dist[20][20][4];
bool done[20][20][4];

int westgreen(int i, int j, int d)
{
  if (d < T[i][j])
    if (d >= T[i][j] - W[i][j])
      return d;
    else
      return T[i][j] - W[i][j];
  else
    {
      int cd = (d - T[i][j]) % (S[i][j] + W[i][j]);
      if (cd >= S[i][j]) 
	return d;
      else
	return d + (S[i][j] - cd);
    }
}

int northgreen(int i, int j, int d)
{
  if (d < T[i][j])
    if (d >= T[i][j] - W[i][j])
      return T[i][j];
    else
      return d;
  else
    {
      int cd = (d - T[i][j]) % (S[i][j] + W[i][j]);
      if (cd >= S[i][j])
	return d + (S[i][j] + W[i][j] - cd);
      else
	return d;
    }
}

int update(int i, int j, int k, int d)
{
  if (i >= 0 && i < N && j >= 0 && j < M && d < dist[i][j][k])
    {
      dist[i][j][k] = d;
      if (done[i][j][k]) cout << "ERROR EROEUREOUR" << endl;
    }
}

int solve()
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      {
	cin >> S[i][j] >> W[i][j] >> T[i][j];
	T[i][j] %= (S[i][j] + W[i][j]);
      }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      for (int k = 0; k < 4; k++)
	{
	  dist[i][j][k] = (int)1e9;
	  done[i][j][k] = false;
	}
  dist[N-1][0][0] = 0;

  while (!done[0][M-1][2])
    {
      int ci = -1;
      int cj, ck;
      for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
	  for (int k = 0; k < 4; k++)
	    if (!done[i][j][k] && (ci < 0 || dist[i][j][k] < dist[ci][cj][ck]))
	      {
		ci = i;
		cj = j;
		ck = k;
	      }
      done[ci][cj][ck] = true;

      int d = dist[ci][cj][ck];
      //cout << "getting (ci, cj, ck) " << ci << " " << cj << " " << ck << " distance = " << d << endl;

      if (ck == 0)
	{
	  update(ci, cj-1, 3, d+2);
	  update(ci+1, cj, 1, d+2);
	  update(ci, cj, 3, westgreen(ci, cj, d) + 1);
	  update(ci, cj, 1, northgreen(ci, cj, d) + 1);
	}
      else if (ck == 1)
	{
	  update(ci-1, cj, 0, d+2);
	  update(ci, cj-1, 2, d+2);
	  update(ci, cj, 2, westgreen(ci, cj, d) + 1);
	  update(ci, cj, 0, northgreen(ci, cj, d) + 1);
	}
      else if (ck == 2)
	{
	  update(ci-1, cj, 3, d+2);
	  update(ci, cj+1, 1, d+2);
	  update(ci, cj, 1, westgreen(ci, cj, d) + 1);
	  update(ci, cj, 3, northgreen(ci, cj, d) + 1);
	}
      else
	{
	  update(ci+1, cj, 2, d+2);
	  update(ci, cj+1, 0, d+2);
	  update(ci, cj, 0, westgreen(ci, cj, d) + 1);
	  update(ci, cj, 2, northgreen(ci, cj, d) + 1);
	}
    }

  return dist[0][M-1][2];
}

int main()
{
  cin >> C;
  for (int i = 0; i < C; i++)
    {
      cout << "Case #" << i+1 << ": " << solve() << endl;
    }
  return 0;
}
