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

string line;
int B;
int base[9];

char ishappy[11814486][9];

bool happy (int x, int b)
{
  if (x == 1)
    return true;
  if (ishappy[x][b - 2] != '?')
    return ishappy[x][b - 2] == 'Y';
  ishappy[x][b - 2] = 'N';
  int t = x, r = 0;
  while (t)
  {
    int d = t % b;
    r += sqr(d);
    t /= b;
  }
  ishappy[x][b - 2] = happy(r, b) ? 'Y' : 'N';
  return ishappy[x][b - 2] == 'Y';
}

bool happy (int x)
{
  for (int i = 0; i < B; ++i)
    if (!happy(x, base[i]))
      return false;
  return true;
}

int solve ()
{
  int ret = 2;
  while (!happy(ret))
    ++ret;
  return ret;
}

int main ()
{
  memset(ishappy, '?', sizeof(ishappy));
  scanf("%d ", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    getline(cin, line);
    istringstream ins(line);
    int x;
    B = 0;
    while (ins >> x)
      base[B++] = x;
    printf("Case #%d: %d\n", TC, solve());
  }
}
