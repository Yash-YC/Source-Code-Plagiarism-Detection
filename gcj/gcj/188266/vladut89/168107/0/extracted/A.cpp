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
int memo[11][1000000];
//1 happy
//-1 sad
//0 ?
// 2 visited
int go(int num, int b) {
  if (num == 1) return 1;
  if (b >= 1000000) return -1;
  if (memo[b][num] == 2 || memo[b][num] == -1) {return -1;}
  if (memo[b][num] == 1) {return  1;}
  
  memo[b][num] = 2;
  
  int socru = 0;
  int X = num;
  while (X) {socru += (X % b) * (X % b); X/= b;}
 
  return memo[b][num] = go(socru, b);

} 
void go_fish() {
  string line;
  char wa[1024];

  cin.getline(wa, 1024);
  line = wa;

  iss in(line);

  vector<int> B;
  int X;
  while (in >> X) {
    B.PB(X);
  }
  
  for (int ans = 2; ;++ans) {
    int bad = 0;

    for (int i = 0; i < B.size(); ++i) {
    if (go(ans, B[i]) == -1) {bad = 1; break;}
    }
    if (bad == 0) {
      cout << ans << '\n';
      return;
    }
  }
}
