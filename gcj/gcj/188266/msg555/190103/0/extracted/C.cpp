#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

long long ncr[42][42];
double prob[42];
double tt[42];

int main() {
  memset(ncr, 0, sizeof(ncr));
  for(int i = ncr[0][0] = 1; i <= 40; i++) {
    for(int j = ncr[i][0] = ncr[i][i] = 1; j < i; j++) {
      ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
  }
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N, C; cin >> C >> N;
    tt[C] = 0;
    for(int i = C - 1; i >= 0; i--) {
      memset(prob, 0, sizeof(prob));
      for(int j = max(N - i, 0); i + j <= C && j <= N; j++) {
        prob[i + j] = 1.0 * ncr[C - i][j] / ncr[C][N] * ncr[i][N - j];
      }
      tt[i] = 1;
      for(int j = i + 1; j <= C; j++) tt[i] += prob[j] * tt[j];
      tt[i] /= 1 - prob[i];
    }
    cout << "Case #" << t << ": " << fixed << setprecision(9) << tt[0] << endl;
  }
  
  return 0;
}

