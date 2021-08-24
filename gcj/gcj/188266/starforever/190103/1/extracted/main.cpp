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
int C, N;

LL comb[41][41];
double add[41][41];
double ept[41];

void init ()
{
  comb[0][0] = 1;
  for (int i = 1; i <= 40; ++i)
  {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j)
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }
}

double solve ()
{
  for (int i = 0; i <= C; ++i)
    for (int j = 0 >? N - i; j <= C - i <? N; ++j)
      add[i][j] = double(comb[C - i][j]) / comb[C][N] * comb[i][N - j];
  ept[C] = 0.0;
  for (int i = C - 1; i >= 0; --i)
  {
    ept[i] = 1.0;
    for (int j = 1 >? N - i; j <= C - i <? N; ++j)
      ept[i] += add[i][j] * ept[i + j];
    ept[i] /= 1.0 - add[i][0];
  }
  return ept[0];
}

int main ()
{
  init();
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    scanf("%d%d", &C, &N);
    printf("Case #%d: %.7lf\n", TC, solve());
  }
}
