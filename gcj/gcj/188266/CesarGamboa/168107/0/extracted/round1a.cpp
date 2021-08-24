#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 5000000

using namespace std;

int pd[MAX][11];
int viz[MAX][11];

int eFeliz(int n, int b){
  //printf("%d %d\n", n, b);
  if (n == 1 || b == 2) return 1;

  if (pd[n][b] == -1){
    if (viz[n][b]) return 0;
    int x = 0;
    int m = n;
    viz[n][b] = 1;

    while (m >= b){
      x += (m%b) * (m%b);
      m /= b;
    }
    x += m*m;

    pd[n][b] = eFeliz(x, b);
  }
  return pd[n][b];
}

int main(){
  int ka;
  int base, bases[10];

  scanf("%d", &ka);
  
  memset(pd, -1, MAX*11*sizeof(int));
  memset(viz, 0, MAX*11*sizeof(int));

  /*for (int b = 2; b <= 10; b++){
    int x = 0;
    for (int i = 1; i < 1000; i++){
      if (eFeliz(i, b)){
	printf("%d ", i);
	x++;
      }
    }
    printf("\n\n");
  }
  printf("\n");*/

  for (int caso = 1; caso <= ka; caso++){
    scanf("%d", &base);
    int i = 0;
    bases[i] = base;
    char c = getchar();
    i++;
    while (c != '\n'){
      scanf("%d", &base);
      c = getchar();
      bases[i] = base;
      i++;
    }
    
    int x;
    for (x = 2; x < MAX; x++){
      bool ok = true;
      for (int b = 0; b < i; b++){
	if (!eFeliz(x, bases[b])){
	  ok = false;
	  break;
	}
      }
      if (ok){
	break;
      }
    }
    printf("Case #%d: %d\n", caso, x);
  }

  return 0;
}
