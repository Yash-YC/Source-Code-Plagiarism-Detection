#include <cstdio>
#include <cstring>
int power[11][30];
int calc (int i, int j) {
  int ans = 0;
  int k;
  for (int l = 0; ; l ++) {
    k = i % j;
    ans += k * k;
    i /= j;
    if (!i) break;
  }
  return ans;
}
bool happy (int i, int j) {
  int k = i;
  for (int l = 0; l < 500; l ++) {
    k = calc (k, j);
    if (k == 1) break;
  }
  if (k == 1) return true;
  else return false;
}
int main () {
  for (int i = 2; i < 11; i ++) {
    power[i][0] = 1;
    for (int j = 1; j < 30; j ++)
      power[i][j] = power[i][j - 1] * i;
  }
  int t;
  char data[100];
  char* line = data;
  char* head = line;
  int n;
  int base[10];
  int len;
  char* space = NULL;
  int ans;
  scanf ("%d", &t);
  gets(line);
  for (int i = 0; i < t; i ++) {
    n = 0;
    line = head;
    gets (line);
    len = strlen (line);
    space = strstr (line, " ");
    while (space != NULL) {
      if (space == line + 2) {
	base[n] = 10;
	line += 3;
      }
      else {
	base[n] = line[0] - '0';
	line += 2;
      }
      n ++;
      space = strstr (line, " ");
    }
    if (strlen (line) == 2) 
      base[n] = 10;
    else 
      base[n] = line[0] - '0';
    n ++;
    ans = 0;
    for (int j = 2; ; j ++) {
      int k;
      for (k = 0; k < n; k ++) 
	if (!happy (j, base[k])) break;
      if (k == n){
	ans = j;
	break;
      }
    }
    printf ("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
	
	
      