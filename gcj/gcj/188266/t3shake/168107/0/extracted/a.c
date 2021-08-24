#include <stdio.h>

#define ML 4096
static char buf[ML];
static int t[11][1000];
static int bases[10];

int main()
{
  int num, base;
  int i, n, h;
  int c, b, s, r, m, p, tp;
  int bp, nb;
  char *cur;

  fgets(buf, ML, stdin);
  sscanf(buf, "%d", &num);

  for (n = 0; n < num; n++) {
    fgets(buf, ML, stdin);
    cur = &buf[0];
    for (nb = 0; ; ) {
      sscanf(cur, "%d", &bases[nb++]);
      while (*cur != ' ' && *cur != '\n') cur++;
      if (*cur == '\n') break;
      cur++;
    }

    for (i = 2; ; i++) {
      h = 0;
      for (bp = 0; bp < nb; bp++) {
	base = bases[bp];

	c = i;
	b = 0;
	while (1) {
	  if (c < 1000) {
	    if (b == 0)
	      t[base][c] = -2;
	    b = c;
	  }
	  s = c;
	  r = 0;
	  while (s > 0) {
	    m = s % base;
	    r += m * m;
	    s /= base;
	  }
	  c = r;
	  if (r < 1000) {
	    if (r == 1 || t[base][r] == -1) {
	      for (p = b; p > 0; p = tp) {
		tp = t[base][p];
		t[base][p] = -1;
	      }
	      h = 1;
	      break;
	    } else if (t[base][r] == 0) {
	      t[base][r] = b;
	    } else {
	      h = 0;
	      break;
	    }
	  }
	}
	if (h == 0) break;
      }
      if (h == 1) {
	printf("Case #%d: %d\n", n+1, i);
	break;
      }
    }
  }

  return 0;
}
