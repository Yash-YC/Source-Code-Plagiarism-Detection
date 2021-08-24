/* Multi-base happiness */

#include <stdio.h>
#include <string.h>

double pot[11][21];

int bases, B[10];

char number[21], string[500];

void inicializa ();
int happy(int, int);
void convierte(int, int);

main()
{
  int T, cases=0, k, z, matched, index, longitud;

  char c;

  inicializa();

  scanf("%d\n", &T);

  while (cases++<T)
  {
    bases=0;

    longitud=0;
    while ((c=getchar())!='\n' && c!=EOF)
      string[longitud++] = c;

    index=0;

    string[longitud] = 0;

    int flag = 1;

    while (flag)
    {
      sscanf(string+index, "%d", &k);

      if (k==10)
	index++;

      index+=2;

      B[bases++] = k;

      if (index >= longitud)
	flag = 0;
    }

    flag = 1;

    for (k=2; flag; k++)
    {
      matched = 0;

      for (z=0; z<bases; z++)
	if (happy(k, B[z]))
	  matched++;

      if (matched == bases)
	flag = 0;
    }

    printf("Case #%d: %d\n", cases, k-1);
  }

  return 0;
}

void inicializa ()
{
  int i, j;

  for (i=2; i<=10; i++)
  {
    pot[i][0] = 1;
    for (j=1; j<=20; j++)
      pot[i][j] = pot[i][j-1]*i;
  }
}

happy(int k, int b)
{
  int p=20;

  convierte(k,b);

  int yen[200];

  yen[0] = k;

  int y=0, j=1;

  while (k!=1&&!y)
  {
    unsigned long sum=0;

    convierte(k,b);

    int d=0;

    while (d<=20)
    {
      sum += (number[d])*(number[d]);
      d++;
    }

    k = sum;

    yen[j] = k;

    j++;

    int p=0;

    while (p++<j-1 && !y)
    {
	if (yen[p-1]==k)
	  y=1;
    }
  }

  if (k==1)
	return 1;

  return 0;
}

void convierte (int n, int b)
{
  int p=20;

  while (p>=0)
  {
    number[20-p] = (int)(n / pot[b][p]);
    n %= (long long)pot[b][p];
    p--;
  }
}
