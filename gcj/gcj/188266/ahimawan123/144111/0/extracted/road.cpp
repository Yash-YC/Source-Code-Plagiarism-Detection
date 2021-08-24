#include<iostream>
#include<queue>
using namespace std;

struct node {
  int y, x, t;
  node(){}
  node(int y2, int x2): y(y2), x(x2) {}
  node(int y2, int x2, int t2): y(y2), x(x2), t(t2) {}
  bool operator<(const node &b) const {
    if (t != b.t) return t > b.t;
    if (y != b.y) return y < b.y;
    return x < b.x;
  }
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int S[30][30], W[30][30], T[30][30];

void validate(int &s, int &w, int &t) { // validate/normalize t
  t %= (s+w);
}

int check(const node &s, int dir) { // assuming dir valid, calculate delay
  //printf("s.t %d\n", s.t);
  int y2 = (s.y-1)/2;
  int x2 = (s.x-1)/2;
  int s2 = S[y2][x2];
  int w2 = W[y2][x2];
  int tot = s2 + w2;
  int tmp = s.t % tot;
  if ( ( (s.y & 1) && dy[dir] == 1) ||
       ( dy[dir] == -1 && (s.y & 1) == 0 ) ) { // vertical
    //printf("vert\n");
    if (tmp < s2) return s.t + 1;
    return s.t + tot - tmp + 1;
  }
  else if ( (dx[dir] == 1 && (s.x & 1) ) ||
	    (dx[dir] == -1 && (s.x & 1) == 0 ) ) { // horizontal
    //printf("hori\n");
    if (tmp >= s2) return s.t + 1;
    //printf("%d %d %d\n", s.t, tmp, s2);
    return s.t + s2-tmp + 1;
  }
  else return s.t + 2; // no delay
}

int infi, ny2, nx2;

node calc(const node &s, int dir) { // check validity and return node
  node ret(s.y+dy[dir], s.x+dx[dir], infi);
  if (ret.y <= 0 || ret.x <= 0 || ret.y > ny2 || ret.x > nx2) return ret;
  ret.t = check(s, dir);
  return ret;
}

int main() {
  int cases, casen, ny, nx, y, x;
  int a[50][50];

  memset(&infi, (1<<7)-1, sizeof(infi));
  infi /= 2;
  //printf("infi %d\n", infi);

  cin >> cases;
  for (casen = 1; casen <= cases; casen++) {
    cin >> ny >> nx;
    ny2 = ny*2;
    nx2 = nx*2;
    for (y = 0; y < ny; y++) {
      for (x = 0; x < nx; x++) {
	cin >> S[y][x] >> W[y][x] >> T[y][x];
	validate(S[y][x], W[y][x], T[y][x]);
      }
    }
    for (y = 0; y <= ny2+1; y++) {
      for (x = 0; x <= nx2+1; x++) {
	a[y][x] = infi;
      }
    }

    int dir;
    node s, t, tmp, tmp2;
    priority_queue<node> q;

    s.y = 2*ny;
    s.x = 1;
    s.t = 0;

    t.y = 1;
    t.x = 2*nx;
    
    a[s.y][s.x] = 0;
    q.push(s);
    while (a[t.y][t.x] >= infi) {
      tmp = q.top();
      q.pop();
      for (dir = 0; dir < 4; dir++) {
	//cout << "test\n";
	tmp2 = calc(tmp, dir);
	if (a[tmp2.y][tmp2.x] > tmp2.t) {
	  a[tmp2.y][tmp2.x] = tmp2.t;
	  //exit(0);
	  q.push(tmp2);
	}
      }
    }
    printf("Case #%d: %d\n", casen, a[t.y][t.x]);
  }
  return 0;
}
