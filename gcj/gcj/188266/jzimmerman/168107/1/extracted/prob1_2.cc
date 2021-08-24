#include <iostream>
#include <sstream>
#include <cstdlib>
#include <set>
using namespace std;

const int MAX = 5000;
const int EMAX = 20000000;

bool happy[11][MAX];
bool ehappy[11][EMAX];

typedef long long int64;

inline int64 xform(int64 n, int b) {
  int64 s = 0;
  while (n) {
    int64 q = n % b;
    n /= b;
    s += q * q;
  }
  return s;
}

inline bool h(int b, int64 n) {
  int nn = (int) xform(n, b);
  set<int> pres;
  while (pres.find(nn) == pres.end()) {
    pres.insert(nn);
    nn = (int) xform(nn, b);
  }
  return (nn == 1);
}    

inline bool eh(int b, int64 n) {
  return happy[b][xform(n, b)];
}

int nbases;
int bases[11];

int main() {
  int n = 1;
  for (int b = 2; b <= 10; b++) {
    n = 1;
    for (; n < MAX; n++) {
//      cout << "pregen" << n;
      ehappy[b][n] = happy[b][n] = h(b,n);
//      if (n < 5) cout << "happy " << n << " " << b << " = " << happy[b][n] << endl;
    }
    for (; n < EMAX; n++) {
      ehappy[b][n] = eh(b,n);
//      cerr << " eh " << b << " " << n << " " << " = " << ehappy[b][n] << endl;
    }
  }

  string s;
  getline(cin, s);
  int T = atoi(s.c_str());

  for (int t = 0; t < T; t++) {
//    cerr << " starting t = " << t << endl;
    nbases = 0;
    getline(cin, s);
    istringstream is(s);
    int b;
    while (is >> b) {
      bases[nbases++] = b;
    }
//    cerr << " got " << nbases << endl;

    bool good = false;
    int64 k = 1;
    while (!good) {
//      cerr << "k " << k << endl;
      ++k;
      good = true;
      for (int bn = 0; bn < nbases; bn++) {
      //for (int b = 2; b <= 10; b++) {
        int b = bases[bn];
        //int64 n = xform(k, b);
        if (!ehappy[b][k]) {
        //if (!happy[b][n]) {
          good = false;
          break;
        }
      }
    }
    cout << "Case #" << (t+1) << ": " << k << endl;
  }
  
  return 0;
}
