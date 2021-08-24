#include <stdio.h>
#include <map>

using namespace std;

map<int,int> hash;

bool not_happy(int i, int b) {
  int t = 0;

  if (hash.find(i) != hash.end()) return true;
  hash[i] = i;

  while (i) {
    t += (i%b)*(i%b);
    i /= b;
  }

  if (t == 1) return false;
  if (t == 0) return true;
  //printf("%d\n", t); fflush(stdout);
  return not_happy(t, b);
}

int main() {
  int T;
  int b[9], nb;
  char line[1024];

  scanf("%d\n", &T);

  map<int, int> solutions;
  for (int cs=1;cs<=T;cs++) {
    gets(line);
    nb = sscanf(line, "%d %d %d %d %d %d %d %d %d", b, b+1, b+2, b+3, b+4, b+5, b+6, b+7, b+8);
    
    //printf("%d %d %d %d\n", nb, b[0], b[1], b[2]);
    int key=0;
    for (int i=0;i<nb;i++)
      key |= 1<<b[i];
    if (solutions.find(key) == solutions.end()) {
      int i, j;
      for (i=2; ;i++) {
        for (j=0; j<nb; j++) {
          hash.clear();
          if (not_happy(i,b[j])) break;
        }
        if (j == nb) break;
      }
      solutions[key] = i;
    }
    printf("Case #%d: %d\n", cs, solutions[key]);
  }
  return 0;
}
