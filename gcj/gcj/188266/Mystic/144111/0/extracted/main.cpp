#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

ifstream fin("B-small-attempt1.in");
ofstream fout("file.out");

#define ASSIGN(a,b) a = (a == 0) || (a > b) ? b : a

inline int timeWait(int S, int W, int T, int curT, bool dir) {  //True = South
  //T -= (T/(S+W))*(S+W);
  T %= S+W;
  curT -= T;
  curT += S+W;
  curT %= S+W;
  if(dir) //North
    return curT >= S ? S+W-curT : 0;
  else
    return curT < S ? S - curT : 0;
}

int main() {
  int C = 0;
  fin >> C;
  for(int c = 0; c < C; c++) {
    int result = 0;
    vector<vector<vector<int> > > streets;
    // 2 3
    // 1 4
    vector<vector<int> > S, W, T;
    int N, M;
    fin >> N >> M;
    streets.clear();
    streets.resize(N, vector<vector<int> >(M, vector<int>(5, 0)));
    S.resize(N, vector<int>(M, 0));
    W = T = S;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        fin >> S[N-1-i][j] >> W[N-1-i][j] >> T[N-1-i][j];
      }
    }
    //Start
    for(int j = 0; j < M; j++) {
      for(int i = 0; i < N; i++) {
        //Up
        if(j != 0) {
          //Left-Up Corner
          ASSIGN(streets[i][j-1][3], 1+streets[i][j-1][4]+timeWait(S[i][j-1], W[i][j-1], T[i][j-1], streets[i][j-1][4], true));
          ASSIGN(streets[i][j][2], 2+streets[i][j-1][3]);
          if(i != N-1) {
            ASSIGN(streets[i+1][j-1][4], 2+streets[i][j-1][3]);
            ASSIGN(streets[i+1][j][1], 4+streets[i][j-1][3]);
          }
        }
        //Right-Up Corner
        ASSIGN(streets[i][j][2], 1+streets[i][j][1]+timeWait(S[i][j], W[i][j], T[i][j], streets[i][j][1], true));
        if(j != 0) {
          ASSIGN(streets[i][j-1][3], 2+streets[i][j][2]);
          if(i != N-1)
            ASSIGN(streets[i+1][j-1][4], 4+streets[i][j][2]);
        }
        if(i != N-1)
          ASSIGN(streets[i+1][j][1], 2+streets[i][j][2]);

        //Right
        if(i != 0) {
          //Right-Down Corner
          ASSIGN(streets[i-1][j][3], 1+streets[i-1][j][2]+timeWait(S[i-1][j], W[i-1][j], T[i-1][j], streets[i-1][j][2], false));
          ASSIGN(streets[i][j][4], 2+streets[i-1][j][3]);
          if(j != M-1) {
            ASSIGN(streets[i-1][j+1][2], 2+streets[i-1][j][3]);
            ASSIGN(streets[i][j+1][1], 4+streets[i-1][j][3]);
          }
        }
        //Right-Up Corner
        ASSIGN(streets[i][j][4], 1+streets[i][j][1]+timeWait(S[i][j], W[i][j], T[i][j], streets[i][j][1], false));
        if(i != 0) {
          ASSIGN(streets[i-1][j][3], 2+streets[i][j][4]);
          if(j != M-1)
            ASSIGN(streets[i-1][j+1][2], 4+streets[i][j][4]);
        }
        if(j != M-1)
          ASSIGN(streets[i][j+1][1], 2+streets[i][j][4]);
      }
    }
    //Top-Right
    for(int j = 0; j < M; j++) {
      ASSIGN(streets[N-1][j][3], 1+streets[N-1][j][2]+timeWait(S[N-1][j], W[N-1][j], T[N-1][j], streets[N-1][j][2], false));
      if(j != M-1)
        ASSIGN(streets[N-1][j+1][2], 2+streets[N-1][j][3]);
    }
    //Right-Top
    for(int i = 0; i < N; i++) {
      ASSIGN(streets[i][M-1][3], 1+streets[i][M-1][4]+timeWait(S[i][M-1], W[i][M-1], T[i][M-1], streets[i][M-1][4], true));
      if(i != N-1)
        ASSIGN(streets[i+1][M-1][4], 2+streets[i][M-1][3]);
    }
    result = streets[N-1][M-1][3];
    fout << "Case #" << c+1 << ": " << result << endl;
  }
}
