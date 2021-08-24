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

const int MAX_N = 40;

int C, N;
double fact[MAX_N+1];
double T[MAX_N+1];

double binom(int n, int p) {
  if(p < 0 || p > n)
    return 0;
  return fact[n] / fact[p] / fact[n-p];
}

int main()
{
  fact[0] = 1;
  for(int n = 1; n <= MAX_N; n++)
    fact[n] = n*fact[n-1];
  int nb_tests;
  cin >> nb_tests;
  for(int t = 1; t <= nb_tests; t++)
    {
      cin >> N >> C;
      double choices = binom(N, C);
      T[0] = 0;
      for(int d = 1; d <= N; d++)
        {
          double a = binom(N-d, C) / choices, r = 0;
          for(int k = 1; k <= d; k++)
            r += binom(d, k) * binom(N-d, C-k) * T[d-k];
          r /= choices;
          T[d] = (1+r) / (1-a);
        }
      printf("Case #%d: %.8lf\n", t, T[N]);
    }
}
