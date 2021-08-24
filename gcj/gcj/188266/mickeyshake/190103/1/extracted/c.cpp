#include <stdio.h>

long long T[51][51];

double D[2][41];

#define P(j, q) (double)T[(q)][N-((j)-(q))]/T[C][N]*T[C-(q)][(j)-(q)]

int C,N;
int main() {
  T[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    T[i][0] = T[i][i] = 1;
    for (int j = 1; j < i; j++) {
      T[i][j] = T[i-1][j-1] + T[i-1][j];
    }
  }

  int TT;
  scanf("%d", &TT);
  for (int Tc = 1; Tc <= TT; Tc++) {
    scanf("%d%d", &C, &N);

    for (int i = 0; i < 2; i++) for (int j = 0; j <= C; j++) D[i][j]=0;
    D[0][0] = 1;
    double R = 0;
    for (int i = 1; i <= 10000000; i++) {
      bool cs = i % 2;
      for (int j = 0; j <= C; j++) {
        double r = 0;
        for (int k = 0; k <= j; k++) if (k != C && k >= (N-(j-k)) && j <= N+k && j >= N) {
          r += P(j, k) * D[!cs][k];
        }
        D[cs][j] = r;
      }
      R += D[cs][C] * i;
      if (i > 10000 && D[cs][C] * i < 1e-10) break;
    }

    printf("Case #%d: %.10lf\n", Tc, R);
  }
  return 0;
}
