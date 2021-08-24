#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int _a;

#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOT(i , a , b) for(int i = a ; i < b ; i++)
#define GETINT (scanf("%d" , &_a) , _a)
#define pb push_back
#define mp make_pair
#define s(a) (int(a.size()))
#define PRINT(a) cerr << #a << " = " << a << endl

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int , int> PII;


int main() {
  ld C[50][50];
  FOR(i, 50) FOR(j, 50) C[i][j] = 0;

  FOR(i, 50) C[i][0] = 1;
  for(int n = 1; n < 50; n++)
    for(int c = 1; c <= n; c++)
      C[n][c] = C[n-1][c-1] + C[n-1][c];

  int tests = GETINT;
  FOT(t, 1, tests+1) {
    int c, n;
    c = GETINT;
    n = GETINT;
    ld ans[c+1];
    ans[c] = 0;
    for(int i = c - 1; i >= 0; i--) {

      ld nonew = 0.00;
      if(n <= i) {
        nonew = C[i][n]/C[c][n];
      }
      ans[i] = 0;
      for(int same = max(0, i + n - c); same <= max(min(n-1, i-1),0); same++) {
        ans[i] += ((1.00 + ans[i+n-same])*C[i][same]*C[c-i][n-same]/C[c][n]);

      }
        
      ans[i] = (ans[i] + nonew) / (1.000 - nonew);

    }
    cout << "Case #" << t << ": " << ans[0] << endl;
  }
  
  return 0;
}
