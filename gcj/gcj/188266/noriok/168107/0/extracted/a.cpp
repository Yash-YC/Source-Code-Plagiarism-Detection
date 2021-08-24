#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;

void ln() {
  putchar('\n');
}

template <class T>
T sq(T n) {
  return n*n;
}

map<int, int> tab[11];
map<int, int> used[11];

bool is_happy(int n, int base) {
//  printf("%d %d\n", n, base);

  if (used[base][n]) return tab[base][n];

  int sum = 0;
  int x = n;
  vi v;
  while (x > 0) {
    v.push_back(x % base);
    x /= base;
    sum += sq(v.back());
  }

  used[base][n] = true;
  if (sum == 1)
    return tab[base][n] = true;


  return tab[base][n] = is_happy(sum, base);
}

int main() {
  char s[1000];
  gets(s);
  int ncases = atoi(s);
  for (int cc = 0; cc < ncases; cc++) {
    gets(s);
    stringstream ss(s);

    int x;
    vi v;
    while (ss >> x)
      v.push_back(x);

    for (int i = 2; /* */; i++) {
      bool match = true;
      for (int j = 0; j < (int)v.size(); j++) {
        if (!is_happy(i, v[j])) {
          match = false;
          break;
        }
      }
      if (match) {
        printf("Case #%d: %d\n", cc+1, i);
        break;
      }
    }
  }
}
