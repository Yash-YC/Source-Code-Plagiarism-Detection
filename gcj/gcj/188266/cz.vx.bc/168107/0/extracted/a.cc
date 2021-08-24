#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

int C[20000000][15];


int ishappy_helper(int n, int b) {
  int &N = C[n][b];
  if (N == 2)
    return N = 0;
  if (N != -1)
    return N;
  if (n == 1)
    return N = 1;

  N = 2;

  int m = 0;
  while (n)
    m += (n%b)*(n%b), n/=b;
  
  return N = ishappy_helper(m, b);
}

int ishappy(int n, int b) {
  int m = 0;
  while (n)
    m += (n%b)*(n%b), n/=b;
  return ishappy_helper(m, b);
}

int main() {
  memset(C, -1, sizeof C);
  int nc;
  cin >> nc;


  /*  for (int i = 2; i <= 10000; ++i)
      if (ishappy(i, 3))
    cout << i << endl;
  */
    
  cin.get();
  for (int i = 0; i < nc; ++i) {
    string ln;
    getline(cin, ln);
    istringstream ssin(ln);
    vector<int> bs;
    int b;
    while (ssin >> b)
      bs.push_back(b);

    int best = -1;

    for (int j = 2; j <= 100000000; ++j) {
      bool f = true;
      for (int k = bs.size()-1; k >= 0; --k)
	if (!ishappy_helper(j, bs[k])) {
	  f = false;
	  break;
	}
      if (f) {
	best = j;
	break;
      }
    }

    cout << "Case #" << i+1 << ": " << best << endl;
  }
}
