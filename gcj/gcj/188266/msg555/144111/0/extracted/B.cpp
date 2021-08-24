#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int A[20][20];
int B[20][20];
int C[20][20];
int d[20][20][2][2];

int get_next_vert(int r, int c, int t) {
  int n = A[r][c] + B[r][c];
  t -= C[r][c];
  t %= n;
  if(t < 0) t += n;
  if(t < A[r][c]) return 1;
  else return n - t + 1;
}

int get_next_horz(int r, int c, int t) {
  int n = A[r][c] + B[r][c];
  t -= C[r][c];
  t %= n;
  if(t < 0) t += n;
  if(t < A[r][c]) return A[r][c] - t + 1;
  else return 1;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int rows, cols; cin >> rows >> cols;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        cin >> A[i][j] >> B[i][j] >> C[i][j];
      }
    }
    memset(d, -1, sizeof(d));
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, (rows - 1) * cols * 4));
    d[rows - 1][0][0][0] = 0;
    while(true) {
      pair<int, int> v = q.top(); q.pop();
      int dst = -v.first;
      int r = v.second / 4 / cols;
      int c = (v.second / 4) % cols;
      bool top = (v.second / 2) % 2;
      bool right = v.second % 2;   
      if(r == 0 && c == cols - 1 && top && right) break;
      if(dst != d[r][c][top][right]) continue;

      int ndst, nr, nc;
      bool ntop, nright;
      #define TRY(xdst, xr, xc, xtop, xright) { \
        ndst = (xdst); nr = (xr); nc = (xc); ntop = (xtop); nright = (xright); \
        int nv = nr * 4 * cols + 4 * nc + 2 * ntop + nright; \
        int& dd = d[nr][nc][ntop][nright]; \
        if(dd == -1 || dd > ndst) { \
          dd = ndst; q.push(make_pair(-ndst, nv)); \
        } \
      }

      // Try up
      if(top) {
        if(r > 0) {
          TRY(dst + 2, r - 1, c, 0, right);
        }
      } else {
        TRY(dst + get_next_vert(r, c, dst), r, c, 1, right);
      }
      // Try right
      if(right) {
        if(c + 1 < cols) {
          TRY(dst + 2, r, c + 1, top, 0);
        }
      } else {
        TRY(dst + get_next_horz(r, c, dst), r, c, top, 1);
      }
      // Try down
      if(!top) {
        if(r + 1 < rows) {
          TRY(dst + 2, r + 1, c, 1, right);
        }
      } else {
        TRY(dst + get_next_vert(r, c, dst), r, c, 0, right);
      }
      // Try left
      if(!right) {
        if(c > 0) {
          TRY(dst + 2, r, c - 1, top, 1);
        }
      } else {
        TRY(dst + get_next_horz(r, c, dst), r, c, top, 0);
      }
    }

    cout << "Case #" << t << ": " << d[0][cols - 1][1][1] << endl;
  }

  return 0;
}
