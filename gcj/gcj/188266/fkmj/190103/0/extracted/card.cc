#include <cstdio>

#define MAX_C   41

typedef long double DOUBLE;

long long ch[MAX_C][MAX_C];
int n,c;

void build_tab()
{
  for(int i=0; i<=c; i++) {
    ch[i][0] = 1;
    ch[0][i] = 0;
  }
  ch[0][0] = 1;

  for(int i=1; i<=c; i++)
    for(int j=1; j<=c; j++)
      if(j<=i)
	ch[i][j] = ch[i-1][j] + ch[i-1][j-1];
      else
	ch[i][j] = 0;
}

void show_tab()
{
  for(int i=0; i<=c; i++) {
    for(int j=0; j<=c; j++)
      printf("%lld ",ch[i][j]);
    printf("\n");
  }
}

DOUBLE X(int m, int k)  // already has m, get new k
{
  return ((DOUBLE)(ch[c-m][k]*ch[m][n-k]))/ch[c][n];
}

DOUBLE exp[MAX_C];
DOUBLE fr[MAX_C];

main()
{
  int t,T;
  scanf("%d",&T);
  for(int t=0; t<T; t++) {
    scanf("%d %d",&c,&n);
    build_tab();
    //show_tab();
    // rational check
    /*
      DOUBLE p = 0;
      for(int i=0; i<=n; i++) {
      DOUBLE q = X(25,i);
      printf("%Lf\n",q);
      p += q;
      }
      printf("%Lf\n",p);
    */
    
    // init
    for(int i=0; i<n; i++)
      exp[i] = 0;
    exp[n] = 1;
    // calculate
    for(int i=n+1; i<=c; i++) {
      DOUBLE t = 0;
      for(int j=1; j<=n; j++) {
	if(i-j>=n)
	  fr[i-j] = X(i-j,j);
	else
	  fr[i-j] = 0;
	t += fr[i-j];
	//printf("%Lf ", fr[i-j]);
      }
      
      exp[i] = 0;
      for(int j=1; j<=n; j++)
	if(i-j>=n)
	  exp[i] += (fr[i-j]/t)*(exp[i-j]+1/(1-X(i-j,0)));
      //printf("%d - %Lf\n",i,exp[i]);
    }
    printf("Case #%d: %Lf\n",t+1,exp[c]);
  }
}
