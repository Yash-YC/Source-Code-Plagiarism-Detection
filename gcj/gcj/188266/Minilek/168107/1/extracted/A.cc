#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <assert.h>
#include <sstream>
using namespace std;
vector<int> bases;
int n;
char seen[12000000][11];
char ans[12000000][11];
bool happy(int x, int b) {
  //  cout << x << " " << b << endl;
  if (x == 1)
    return 1;
  if (ans[x][b] != -1)
    return ans[x][b];
  if (seen[x][b])
    return ans[x][b] = 0;
  seen[x][b] = 1;
  int ret = 0, y = x;
  while (x) {
    ret += (x%b)*(x%b);
    x /= b;
  }
  return ans[y][b] = happy(ret, b);
}
bool good(int x) {
  for (int i = 0; i < bases.size(); ++i)
    if (!happy(x, bases[i]))
      return false;
  return true;
}
int main(int argc, char* argv[]) {
  /*  int QQ = atoi(argv[1]);
  cout << QQ << endl << "-----" << endl;
  for (int i = 2; ; ++i)
    if (happy(i, QQ))
    cout << i << endl;*/
  int nocases;
  memset(seen, 0, sizeof(seen));
  memset(ans, -1, sizeof(ans));
  cin >> nocases;
  getc(stdin);
  int precalc[11] = {0, 0, 11814485, 11814485, 11814485, 4817803, 346719, 
		     28099, 711725, 2688153, 569669};

  for (int rr = 1; rr <= nocases; ++rr) {
    int missing[11];
    memset(missing, 1, sizeof(missing));
    bases = vector<int>();
    string s, t;
    getline(cin, s);
    istringstream p(s);
    while (p >> t) {
      bases.push_back(atoi(t.c_str()));
      missing[bases[bases.size()-1]] = 0;
    }
    n = bases.size();
    if (n == 9)
      printf("Case #%d: 11814485\n", rr);
    else if (n == 8) {
      int d;
      for (int i = 2; i <= 10; ++i)
	if (missing[i])
	  d = i;
      printf("Case #%d: %d\n", rr, precalc[d]);
    } 
    else if (n == 7 && missing[2] && missing[3])
      printf("Case #%d: 11814485\n", rr);
    else {
      long long K = 2;
      while (!good(K))
	K++;
      printf("Case #%d: %lld\n", rr, K);
    }
  }
  return 0;
}
