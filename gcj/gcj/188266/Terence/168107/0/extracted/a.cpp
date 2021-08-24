#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30000000
char happy[N][11];
int sqs[N][11];

char find_happy(int n, int b)
{
  if(happy[n][b] == 2) {
    happy[n][b] = 0;
  } else if(happy[n][b] < 0) {
    happy[n][b] = 2;
    happy[n][b] = find_happy(sqs[n][b], b);
  }
  return happy[n][b];
}
/*
char find_sqs(int n, int b)
{
  if(n < 2*b*b)
    return sqs[n][b];
  else
    return find_sqs(n/b,b) + (n%b)*(n%b);
}
*/
int main()
{
  memset(happy, -1, sizeof(happy));
  for(int b = 2; b <= 10; b++) {
    sqs[0][b] = 0;
    sqs[1][b] = 1;
    happy[0][b] = 0;
    happy[1][b] = 1;
  }
  for(int b = 2; b <= 10; b++) {
    for(int n = 2; n < N; n++) {
      sqs[n][b] = sqs[n/b][b]+(n%b)*(n%b);
    }
  }
  for(int b = 2; b <= 10; b++) {
    for(int n = 2; n < 2*b*b; n++)
      find_happy(n, b);
    for(int n = 2*b*b; n < N; n++)
      happy[n][b] = happy[sqs[n][b]][b];
  }
  int res[512];
  memset(res, 0, sizeof(res));
  for(int k = 1; k < 512; k++)
    for(int n = 2; n < N; n++) {
      bool r = true;
      for(int b = 2; b <= 10; b++)
        if((k & (1<<(b-2))) && happy[n][b] == 0) {
          r = false;
          break;
        }
      if(r) {
        res[k] = n;
        break;
      }
    }

  int t, index, b;
  char line[100];
  scanf("%d", &t);
  fgets(line, 100, stdin);
  for(int index = 1; index <= t; index++) {
    fgets(line, 100, stdin);
    char *p = line;
    b = 0;
    while(1) {
      while(*p <= 32 && *p) ++p;
      if(*p==0) break;
      b |= (1 << (atoi(p)-2));
      while(*p>='0' && *p <= '9')++p;
    }
    printf("Case #%d: %d\n", index, res[b]);
  }
  return 0;
}

