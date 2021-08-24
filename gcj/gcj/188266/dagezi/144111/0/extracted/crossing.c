#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>

typedef struct {
  int ns;
  int ew;
  int start;
  long long min;
} crossing_t;

crossing_t town[40][40];
int width, height;

long long 
fastest(long long time, int isns, crossing_t *cr)
{
  int total = cr->ns + cr->ew;
  int t = time % total;
  t -= cr->start;
  if (t < 0) t += total;
  if (isns) {
    return (t < cr->ns) ? time : time + (total - t);
  } 
  return (t < cr->ns) ? (time + (cr->ns - t)) : time;
}

long long
nfastest(int x, int y) 
{
  long long froms = LLONG_MAX, fromw = LLONG_MAX;
  if (x > 0) {
    if (x % 2 == 0) {
      fromw = town[y][x -1].min + 2;
    } else {
      fromw = fastest(town[y][x -1].min, 0, &town[y][x - 1]) + 1;
    }
  }
  if (y > 0) {
    if (y % 2 == 0) {
      froms = town[y - 1][x].min + 2;
    } else {
      froms = fastest(town[y - 1][x].min, 1, &town[y - 1][x]) + 1;
    }
  }
  town[y][x].min = fromw > froms ? froms : fromw;
  return town[y][x].min;
}

void
readtown()
{
  int x, y;
  
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      crossing_t *c = &town[y*2][x*2];
      scanf("%d %d %d", &c->ns, &c->ew, &c->start);
      c->min = 99999999;
      c->start %= (c->ns + c->ew);
      town[y*2][x*2+1] = town[y*2+1][x*2] = town[y*2+1][x*2+1] = *c;
    }
  }
}

int
main()
{
  int i, x, y, j, ncases;
  long long min;
  scanf("%d", &ncases);

  for (j = 1; j <= ncases;j++) {
    scanf("%d %d", &height, &width);
    readtown();

    town[0][0].min = 0;

    for (i = 1; i <= (height * 2 + width * 2 - 2); i++) {
      x = 0; 
      if (i >= height * 2) x = i - height * 2 + 1;
      for (; x < width * 2 && x <= i; x++) {
	y = i - x;
	fprintf(stderr, "%lld ", min = nfastest(x, y));
      }
      fputc('\n', stderr);
    }
    printf("Case #%d: %lld\n", j, min);
  }
  return 0;
}
