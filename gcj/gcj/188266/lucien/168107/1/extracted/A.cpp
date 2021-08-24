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

const int M = 12000000;

char happy[11][M+1];
int happy_mask[M+1];

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
  if(n < M && happy[B][n])
    return happy[B][n];
  if(n < M)
    happy[B][n] = -1;
  int m = next(n, B);
  int r = is_happy(m, B);
  if(n < M)
    happy[B][n] = r;
  return r;
}

int main()
{
  for(int B = 2; B <= 10; B++)
    for(int k = 2; k < M; k++)
      if(is_happy(k, B) == 1)
        happy_mask[k] |= 1 << B;
  
  /*
    vi v;
    for(int i = 2; i < 11; i++)
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
  */
  

  int T;
  scanf("%d\n", &T);
  for(int t = 1; t <= T; t++)
    {
      cout << "Case #" << t << ": ";
      int m = 0;
      string s;
      getline(cin, s);
      stringstream is(s);
      int i;
      while(is >> i)
        m |= 1 << i;
      int k = 2;

      for(;; k++)
        if((happy_mask[k] & m) == m)
          break;

      cout << k << endl;
    }
}

