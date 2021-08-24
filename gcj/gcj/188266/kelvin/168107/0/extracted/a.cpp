// a

#include <stdio.h>
#include <string.h>
#define MAXBASE 10
#define MAXNUM 1000000

bool happy[MAXBASE+1][MAXNUM]={0};
int mod[MAXBASE+1][MAXNUM];

int flag=1;
int appear[MAXNUM]={0};

int n,rb[MAXBASE+1];
char in[100000];

inline int Result(int x,int b)
{
  int s;
  while(1) {// if(b==3) printf("(%d %d)\n",x,b);
    appear[x]=flag;
    s=0;
    while(x) {
      s+=mod[b][x]*mod[b][x];
      x/=b;
    }
    x=s;
    if(appear[x]==flag) break;
  }
  flag++;
  return x;
}

inline void PreCalc(void)
{
  int i,j;
  for(i=2;i<=MAXBASE;i++)
    for(j=0;j<MAXNUM;j++)
      mod[i][j]=j%i;
  for(i=2;i<=MAXBASE;i++)
    for(j=2;j<MAXNUM;j++)
      happy[i][j]=(Result(j,i)==1?1:0);
}

inline int Solve(void)
{
  int i,j;
  for(i=2;i<MAXNUM;i++) {
    for(j=0;j<n&&happy[rb[j]][i];j++);
    if(j==n) break;
  }
  return i;
}

int main(void)
{
  int t,casenum;
  char *p;
  PreCalc();
  gets(in);
  sscanf(in,"%d",&t);
  for(casenum=1;casenum<=t;casenum++) {
    gets(in);
    p=strtok(in," ");
    n=0;
    while(p) {
      sscanf(p,"%d",rb+n);
      n++;
      p=strtok(NULL," ");
    }
    printf("Case #%d: %d\n",casenum,Solve());
  }
  return 0;
}
