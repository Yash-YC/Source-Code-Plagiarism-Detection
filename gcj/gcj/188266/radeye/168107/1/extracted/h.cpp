#include <iostream>
#include <cstdio>
using namespace std ;
int hap[10000] ;
int p[11][10000] ;
int res[65536] ;
int nxt(long long t, int b) {
  int s = 0 ;
  while (t) {
    int d = t % b ;
    s += d * d ;
    t /= b ;
  }
  return s ;
}
int main(int argc, char *argv[]) {
  char lin[1000] ;
  hap[1] = -1 ;
  for (int b=2; b<11; b++)
    for (int i=1; i<10000; i++) {
      p[b][i] = nxt(i, b) ;
    }
  for (int b=2; b<11; b++)
    for (int i=2; i<10000; i++) {
      int p1 = i ;
      int p2 = p[b][i] ;
      while (p1 != p2 && p2 != 1 && p1 != 1) {
        p1 = p[b][p1] ;
        p2 = p[b][p[b][p2]] ;
      }
      if (p1 == 1 || p2 == 1)
        hap[i] |= (1 << b) ;
    }
  fgets(lin, 1000, stdin) ;
  int t = atol(lin) ;
  for (int c=1; c<=t; c++) {
    fgets(lin, 1000, stdin) ;
    char *pp = lin ;
    int m = 0 ;
    while (*pp) {
      while (*pp && *pp <= ' ')
        pp++ ;
      int v = 0 ;
      if (*pp == 0)
        break ;
      while (*pp > ' ') {
        v = v * 10 + *pp - '0' ;
        pp++ ;
      }
      m |= 1<<v ;
    }
    if (res[m] == 0) {
      for (int i=2; ; i++) {
        int ok = 1 ;
        for (int b=2; ok && b<11; b++)
          if (((m >> b) & 1) == 1 && ((hap[nxt(i, b)] >> b) & 1) == 0)
            ok = 0 ;
        if (ok) {
          res[m] = i ;
          break ;
        }
      }
    }
    cout << "Case #" << c << ": " << res[m] << endl ;
  }
}
