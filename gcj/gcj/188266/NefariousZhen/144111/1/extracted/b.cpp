#include <stdio.h>
#include <queue>

using namespace std;

#define S 0
#define W 1
#define T 2

class pos {
public:
  pos() {}
  pos(int c, int a, int b) { cost=c; i=a; j=b; }

  int cost;
  int i, j;

  bool operator<(const pos &p) const { return cost > p.cost; }
};

int main() {
  int C, N, M, l[20][20][3];
  
  scanf("%d", &C);
  for (int cs=1; cs<=C; cs++) {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++)
      for (int j=0; j<M; j++)
        scanf("%d %d %d", l[i][j], l[i][j]+1, l[i][j]+2);

    //priority_queue<int, vector<int>, less<int>> q;
    priority_queue<pos> q;
    q.push(pos(0,2*N-1, 0));
    
    pos curr;
    int v[40][40];
    memset(v, -1, sizeof(v));
    while(!q.empty()) {
      curr = q.top(); q.pop();
      //printf("visiting %d %d c %d\n", curr.i, curr.j, curr.cost);

      if (curr.i >= 2*N) continue;
      if (curr.j >= 2*M) continue;
      if (curr.i < 0) continue;
      if (curr.j < 0) continue;

      if (v[curr.i][curr.j] >= 0) continue;
      v[curr.i][curr.j] = curr.cost;
      
      if (curr.i == 0 && curr.j == 2*M-1) break;
      {
        int a = curr.i/2;
        int b = curr.j/2;
        int c = l[a][b][S] + l[a][b][W];
        int s = l[a][b][T]%c;
        int t = (c-s+curr.cost)%c;
        int nc = (l[a][b][S] > t ? 1 : (c-t+1));
        if (curr.i % 2 == 0) {
          q.push(pos(curr.cost+2,curr.i-1,curr.j));
          q.push(pos(curr.cost+nc,curr.i+1,curr.j));
        }
        else {
          q.push(pos(curr.cost+nc,curr.i-1,curr.j));
          q.push(pos(curr.cost+2,curr.i+1,curr.j));
          //printf("push %d %d c %d\n", curr.i-1, curr.j, curr.cost+nc);
        }
      }
      {
        int a = curr.i/2;
        int b = curr.j/2;
        int c = l[a][b][S] + l[a][b][W];
        int s = (l[a][b][T]+l[a][b][S])%c;
        int t = (c-s+curr.cost)%c;
        int nc = (l[a][b][W] > t ? 1 : (c-t+1));
        if (curr.j % 2 == 1){
          q.push(pos(curr.cost+nc,curr.i,curr.j-1));
          q.push(pos(curr.cost+2,curr.i,curr.j+1));
          //printf("push %d %d c %d\n", curr.i, curr.j+1, curr.cost+2);
        }
        else {
          q.push(pos(curr.cost+nc,curr.i,curr.j+1));
          q.push(pos(curr.cost+2,curr.i,curr.j-1));
          //printf("push %d %d c %d\n", curr.i, curr.j+1, curr.cost+nc);
        }
      }
    }

    printf("Case #%d: %d\n", cs, v[0][2*M-1]);
  }

  return 0;
}
