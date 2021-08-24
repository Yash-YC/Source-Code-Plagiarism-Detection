/*###################START INCLUDE-urile#########################/*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

/*###################STOP INCLUDE-urile#########################/*/
using namespace std;
/*######################START PRECODE#############################*/
const long double eps = 1e-7; // marja de eroare
const long double pi=acos(-1.0);//valoarea lui PI
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define PB push_back  //vector<> v.PB(X);
#define NP next_permutation //v.NP()
#define MP make_pair //MP
#define X first //.X 
#define Y second //.Y
#define ALL(a) (a).begin(), (a).end() //sort(ALL(v))
#define RALL(a) (a).rbegin(), (a).rend()//sort(RALL(v)) //sens invers
#define FORIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it) //parcurg cu iteratoru//FORIT(it, V) {cout << *it << '\n';}
#define STERGE(v) memset(v,0,sizeof v) //set 0 on something
#define INF 0x3f3f3f3f
#define STERGEI(v) memset(v,0x3f, sizeof(v)) //set cu infinit
//memcmp
typedef stringstream iss; //iss f(string); f>>X; sau f << X;//sau de output
/*#####################TEMPLATES##################################*/

template<class A, class B> inline A i2s(B x){stringstream s; s<<x; A r; s>>r;return r;} //string x = i2s<string, int>(X);
template<class A> inline A abs(A a) {if (a < 0) return -a; return a;} //
//__gcd(A, B) - euclidu
template<class A> inline A euclid(A a, A b, A &x, A &y) {
               if (!b) {x=1, y = 0; return a;} 
               A ret = euclid(b, a%b, x, y);
               A aux = x; 
               x = y; y = aux - (a/b)*y;
               return ret;
               } ///euclid(556, 21, A, B); si A * 556 + B * 21 = gcd-ul
//de verificad daca e prim
template<class A> inline int isPrime(A X) {
               if (X <= 1 || (X % 2 == 0 && X != 2)) return 0;
               for (A i = 3; i * i <= X; i+=2) if (X % i == 0) return 0;
               return 1;
               } ///isPrime(22531);

/*######################STOP PRECODE#############################*/
void go_fish();
int main() { 
      freopen("0.in", "r", stdin);freopen("0.out", "w", stdout);
//    freopen("0-small.in", "r", stdin);freopen("0-small.out", "w", stdout);
//    freopen("0-large.in", "r", stdin);freopen("0-large.out", "w", stdout);
    int ceamailungavariabila;
    int ceamailungavariabila2 = 1;
    for (scanf("%d\n", &ceamailungavariabila); ceamailungavariabila--;) {
        printf("Case #%d: ", ceamailungavariabila2++);
        go_fish();
        }
    }

double dp[1<<11];
double dp2[1<<11];

void go_fish() {
  int N, C;
  cin >> N >> C;
  
  dp[0] = 1.0;
  vector<int> E;
  for (int i = 0; i < (1 << N); ++i) {
    int sum = 0;
    for (int j = 0; j < N; ++j) if (i & (1 << j)) {
      ++sum;
    }
    if (sum == C) E.PB(i);
  }
  double P = 1.0 / (1.0 * E.size());
  double total = 0.0;
  for (int pas = 1; pas <= 1000; ++pas) {
    memcpy(dp2, dp, sizeof(dp));
    memset(dp, 0, sizeof(dp));

    //combina 2 masti
    for (int i = 0; i + 1 < (1 << N); ++i) if (dp2[i] > 0.0)
    for (int j = 0; j < E.size(); ++j) {
      int mask = i | E[j];
      dp[mask] += dp2[i] * P;
    }
    total += dp[int(1 << N) - 1] * (1.0 * pas);
  }
  cout << total << '\n';
}
