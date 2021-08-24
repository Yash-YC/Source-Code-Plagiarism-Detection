#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

vector<string> tokenize(const string& str,const string& delimiters) {
  vector<string> tokens;
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  string::size_type pos = str.find_first_of(delimiters, lastPos);
  while (string::npos != pos || string::npos != lastPos) {
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    lastPos = str.find_first_not_of(delimiters, pos);
    pos = str.find_first_of(delimiters, lastPos);
  }

  return tokens;
}

inline int gg(int N, int B) {
  int R = 0;
  while (N) {
    int A = N % B;
    R += A*A;
    N /= B;
  }
  return R;
}

#define L 10000000
int A[9][L+2];

#define H    1
int S[1000000];
int sp;

int B[10];
int BN;

int main() {
  memset(A, 0, sizeof(A));
  for (int i = 2; i <= 10; i++) {
    A[i-2][1] = H;
    for (int j = 2; j <= L; j++) if (!A[i-2][j]) {
      bool Q = (j <= 100);

      int a = j;
      sp = 3;
      while (true) {
        if (i == 10 && a == 82) Q = true;
        if (A[i-2][a] == H) {
          for (int k = 3; k < sp; k++) A[i-2][S[k]] = H;
          break;
        } else if (A[i-2][a] != 0) {
          break;
        }

        A[i-2][a] = sp;
        S[sp++] = a;
        a = gg(a, i);
      }
    }
  }

  char buf[1000];
  int T;
  fgets(buf, 1000, stdin);
  sscanf(buf, "%d", &T);
  for (int Tc = 1; Tc <= T; Tc++) {
    fgets(buf, 1000, stdin);
    vector<string> V = tokenize(buf, " \n\r");
    BN = V.size();
    for (int i = 0; i < BN; i++) B[i] = atoi(V[i].c_str());
    bool found = false;
    for (int j = 2; j <= L; j++) {
      bool flag = true;
      for (int i = 0; i < BN; i++) {
        if (A[B[i]-2][j] != H) { flag = false; break; }
      }
      if (flag) {
        printf("Case #%d: %d\n", Tc, j);
        found = true;
        break;
      }
    }
    if (!found) printf("NOT FOUND!\n");
  }
  return 0;
}
