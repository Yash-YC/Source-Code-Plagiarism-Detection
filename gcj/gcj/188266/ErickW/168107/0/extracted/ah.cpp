#include <iostream>
using namespace std;

char hap[11][1000];

int dig(int n, int b){int t=0;while(n){int d=n%b;t+=d*d;n/=b;}return t;}
inline int mx(int b){return b*b*b; }
inline bool happy(int n, int b)
{
  int m=mx(b); while(n>=m) n=dig(n,b); return (hap[b][n]>0);
}

int bh(int n, int b)
{
  int h=hap[b][n];
  if (abs(h)==1) return h;
  else 
  {
    if (h==2) { hap[b][n]=h=-1; return h; }
    else { hap[b][n]=2; h=bh(dig(n,b), b); hap[b][n]=h; return h; }
  }
}

main(int argc, char *argv[])
{
  int b=atoi(argv[1]); if (!b) b=10;

  for(int b=2;b<=10;b++) {memset(hap[b],0,sizeof(hap[b])); hap[b][1]=1;
       for(int i=2;i<mx(b);i++)bh(i,b);}
  for(int i=2;i<30000000;i++) if(happy(i,b)) printf("%08d\n",i);
}
