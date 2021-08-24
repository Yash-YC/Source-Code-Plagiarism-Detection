#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int T, N, C;

const double ZERO = 1e-7;

long long choose[41][41];

double solve()
{
  cin >> C >> N;

  double ratio[41];
  for (int i = 0; i <= C; i++) ratio[i] = (double)choose[C-i][N]/(double)choose[C][N];

  double ans = 0;
  for (int i = 1; i <= C; i++)
    {
      double sum = (ratio[i])/(1-ratio[i]);
      if (i % 2 == 0)
	ans -= choose[C][i] * sum;
      else
	ans += choose[C][i] * sum;
    }

  return ans + 1;
}

int main()
{
  for (int i = 0; i <= 40; i++)
    for (int j = 0; j <= 40; j++)
      choose[i][j] = 0;

  choose[0][0] = 1;
  for (int i = 1; i <= 40; i++)
    {
      choose[i][0] = 1;
      choose[i][i] = 1;
      for (int j = 1; j < i; j++) choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
    }

  cin >> T;
  for (int i = 0; i < T; i++)
    {
      cout << "Case #" << i+1 << ": " << setprecision(9) << solve() << endl;
    }

  return 0;
}
