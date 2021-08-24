#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<bitset>
#include<sstream>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<numeric>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int M = 1000 * 1000;

char happy[11][M+1];

int next(int n, int B) {
  int r = 0;
  while(n)
    {
      int d = n % B;
      r += d*d;
      n /= B;
    }
  return r;
}

int is_happy(int n, int B)
{
  if(n == 1)
    return 1;
  if(happy[B][n])
    return happy[B][n];
  happy[B][n] = -1;
  int m = next(n, B);
  assert(m <= M);
  return (happy[B][n] = is_happy(m, B));
}

int main()
{
  /*
    int kmax = 0;
    for(int b1 = 2; b1 < 11; b1++)
    for(int b2 = 2; b2 < 11; b2++)
    for(int b3 = 2; b3 < 11; b3++)
    for(int k = 2;; k++)
    {
    if(is_happy(k, b1) + is_happy(k, b2) + is_happy(k, b3) == 3)
    {
    kmax = max(k, kmax);
    break;
    }
    }
    printf("%d\n", kmax);
  */

  for(int B = 2; B <= 10; B++)
    for(int k = 2; k < M; k++)
      is_happy(k, B);
  

  int T;
  scanf("%d\n", &T);
  for(int t = 1; t <= T; t++)
    {
      cout << "Case #" << t << ": ";
      vi v;
      string s;
      getline(cin, s);
      stringstream is(s);
      int i;
      while(is >> i)
        v.push_back(i);
      int k = 2;
      for(;; k++)
        {
          int i = 0;
          while(i < int(v.size()) && is_happy(k, v[i]) == 1)
            i++;
          if(i == int(v.size()))
            break;
        }
      cout << k << endl;
    }
}
