#include<algorithm> 
#include<cmath> 
#include<iostream> 
#include<list> 
#include<cstring>
#include<map> 
#include<queue> 
#include<set> 
#include<sstream> 
#include<vector> 
#define for_(i, a, b) for(int i=(a);i<(b);++i) 
#define set_(a, n) memset(a, n, sizeof a) 
using namespace std;

typedef unsigned int uint; 
typedef unsigned long long int ullong; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef list<int> li;
typedef pair<int,int> pii;

int n, c;
double dp[100];
bool used[100];

double p(int x, int y) {
  double a = 1.0;
  for_(i, 0, y) a *= n - i;
  for_(i, 0, x) a /= c - i;
  for_(i, 0, x-y) a *= c - n - i;
  return a;
}

double e(int rem) {
  if (used[rem]) return dp[rem];
  if (rem == 0) return 0;
  
  double f = 0.0, p0 = p(rem, 0);
  
  for_(i, 1, min(rem,n)+1)
    f += p(rem, i) * (1 + e(rem-i));
  
  double res = (f + p0) / (1 - p0);
  
  used[rem] = true;
  return dp[rem] = res;
}

int main(void) {
  int t; cin >> t;
  
  for_(k, 1, t+1) {
    cin >> c >> n;
    
    set_(used, false);
    cout << "Case #" << k << ": " << 1+e(c-n) << endl;
  }
  
  return 0;
}
