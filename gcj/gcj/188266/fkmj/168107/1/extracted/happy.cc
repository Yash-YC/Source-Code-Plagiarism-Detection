#include <cstdio>

//#define MAX_T  1000
#define MAX_T  12000000

bool h[9][MAX_T];

int found[MAX_T];

int next(int x, int b)
{
  int t = 0;
  while(x>0) {
    int a = x%b;
    t += a*a;
    x /= b;
  }
  return t;
}

int is_happy(int x, int b)
{
  found[x] = x;
  int c = next(x,b);
  while((c!=1) && (found[c]!=x)) {
    found[c] = x;
    c = next(c,b);
  }
  return c==1;
}

void compute_tab()
{
  for(int k=0; k<=8; k++) {
    int b = k+2;
    
    //printf("base: %d\n",b);
    for(int i=0; i<MAX_T; i++) {
      h[k][i] = false;
      found[i] = -1;
    }
    h[k][1] = true;
    for(int j=2; j<MAX_T; j++) {
      //h[k][j] = is_happy(j,b);
      
      int nn = next(j,b);
      if(nn>j) {
	//printf("bad at %d\n",j);
	h[k][j] = is_happy(j,b);
      } else
	h[k][j] = h[k][nn];
      
      /*
	if(h[k][j])
	printf("%d\n",j);
      */
    }
  } 
}

int bases[10];

main()
{
  compute_tab();
  char line[1000];
  fgets(line,1000,stdin);
  int T;
  sscanf(line,"%d",&T);

  for(int t=0; t<T; t++) {
    int b,c,count;
    fgets(line,1000,stdin);
    char *p = line;
    count = 0;
    while(sscanf(p,"%d%n",&b,&c)>0) {
      p+=c;
      bases[count] = b;
      count++;
    }
    for(int i=2; i<MAX_T; i++) {
      int k;
      for(k=0; k<count; k++)
	if(!h[bases[k]-2][i])
	  break;
      if(k==count) {
	printf("Case #%d: %d\n",t+1,i);
	break;
      }
    }
  }
}
