#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

long long choose(int n, int k) {
  if (n < k) return 0;
  long long res = 1;
  vector<long long> vals;
  for (int i = 0; i < k; i++) vals.push_back(n - i);

  vector<long long> left;
  for (int i = 2; i <= k; i++) {
    bool done = false;
    for (int j = 0; j < k; j++) {
      if (vals[j] % i == 0) {
        vals[j] /= i;
        done = true;
        break;
      }
    }
    if (!done) left.push_back(i);
  }

  for (int i = 0; i < k; i++) res *= vals[i];
  for (int i = 0; i < left.size(); i++) res /= left[i];
  return res;
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    double prob[64][64];
    double expv[64], p[64];
    memset(prob, 0, sizeof(prob));
    memset(expv, 0, sizeof(expv));
    memset(p, 0, sizeof(p));

    int C, N; cin >> C >> N;
    for (int i = 0; i <= C; i++)
      for (int j = 0; j <= C - i && j <= N; j++)
        prob[i][j] = (1.0 * choose(C-i, j) * choose(i, N-j)) / choose(C, N);

    /* for (int i = 0; i <= C; i++) {
      for (int j = 0; j <= C - i; j++)
        cout << prob[i][j] << " ";
      cout << endl;
    } */

    expv[N] = 1; p[N] = 1;
    for (int i = N; i < C; i++) {
      for (int j = 1; j <= C - i && j <= N; j++) {
        expv[i+j] += p[i] * prob[i][j] / (1 - prob[i][0]) * (expv[i] + (prob[i][j] + prob[i][0]) / prob[i][j]);
        p[i+j] += p[i] * prob[i][j] / (1 - prob[i][0]);
      }
    }

    cout.setf(ios::fixed);
    cout << setprecision(6) << "Case #" << c << ": " << expv[C] / p[C] << endl;
  }
  return 0;
}
