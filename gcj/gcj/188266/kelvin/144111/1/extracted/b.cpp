// b

#include <stdio.h>
#define MAXNUM 25
#define MAXNODE (MAXNUM*MAXNUM*4)
#define INF 1200000000

class Heap {
  public:
    int n;
    int h[MAXNODE],pos[MAXNODE];
    int *cost;
    void Init(int *cp) {
      n=0;
      cost=cp;
    }
    void Swap(int i,int j) {
      int temp;
      temp=h[i];
      h[i]=h[j];
      h[j]=temp;
      temp=pos[h[i]];
      pos[h[i]]=pos[h[j]];
      pos[h[j]]=temp;
    }
    void Up(int x) {
      while(x>1&&cost[h[x]]<cost[h[x/2]]) {
	Swap(x,x/2);
	x/=2;
      }
    }
    void Down(int x) {
      int l,r,min;
      while(1) {
	l=x*2;
	r=x*2+1;
	if(l<=n&&cost[h[l]]<cost[h[x]]) min=l;
	else min=x;
	if(r<=n&&cost[h[r]]<cost[h[min]]) min=r;
	if(min==x) return;
	Swap(x,min);
	x=min;
      }
    }
    int Extract_Min(void) {
      int min=h[1];
      Swap(1,n--);
      Down(1);
      return min;
    }
    void Insert(int val) {
      h[++n]=val;
      pos[val]=n;
      Up(n);
    }
};

const int roadseg=1,pedseg=2;

int rn,cn;
int ver[MAXNUM][MAXNUM],hor[MAXNUM][MAXNUM],per[MAXNUM][MAXNUM],t0[MAXNUM][MAXNUM];

Heap hp;
int time[MAXNODE];

inline int Pid(int i,int j) { return i*cn*2+j; }

inline int Row(int id) { return id/(cn*2); }

inline int Col(int id) { return id%(cn*2); }

inline int Ver_Cross(int r,int c,int t)
{
  if(r&1) return t+pedseg;
  r/=2;
  c/=2;
  if((t-t0[r][c])%per[r][c]<=ver[r][c]-roadseg) return t+roadseg;
  else return t+per[r][c]-(t-t0[r][c])%per[r][c]+roadseg;
}

inline int Hor_Cross(int r,int c,int t)
{
  if(c&1) return t+pedseg;
  r/=2;
  c/=2;
  if((t-t0[r][c]+hor[r][c])%per[r][c]<=hor[r][c]-roadseg) return t+roadseg;
  else return t+per[r][c]-(t-t0[r][c]+hor[r][c])%per[r][c]+roadseg;
}

//bool xx[MAXNODE];

inline void Update(int v,int val)
{
  if(val<time[v]) {
    time[v]=val;
    hp.Up(hp.pos[v]);
  }
}

inline int Solve(void)
{
  int i,j,v;
  hp.Init(time);
  for(i=0;i<rn*2;i++) {
    for(j=0;j<cn*2;j++) {
      time[Pid(i,j)]=(Pid(i,j)==0?0:INF);
      hp.Insert(Pid(i,j));
    }
  }
  while(hp.n) {
    v=hp.Extract_Min();//printf("[%d %d]\n",v,time[v]);
    i=Row(v);
    j=Col(v);
    if(i<rn*2-1) Update(Pid(i+1,j),Ver_Cross(i,j,time[v]));
    if(i>0) Update(Pid(i-1,j),Ver_Cross(i-1,j,time[v]));
    if(j<cn*2-1) Update(Pid(i,j+1),Hor_Cross(i,j,time[v]));
    if(j>0) Update(Pid(i,j-1),Hor_Cross(i,j-1,time[v]));
  }
  return time[Pid(rn*2-1,cn*2-1)];
}

int main(void)
{
  int t,casenum=1;
  int i,j;
  scanf("%d",&t);
  while(t--) {
    scanf("%d %d",&rn,&cn);
    for(i=rn-1;i>=0;i--) {
      for(j=0;j<cn;j++) {
	scanf("%d %d %d",&ver[i][j],&hor[i][j],&t0[i][j]);
	per[i][j]=hor[i][j]+ver[i][j];
	t0[i][j]=t0[i][j]%per[i][j]-per[i][j];
      }
    }
    printf("Case #%d: %d\n",casenum++,Solve());
  }
  return 0;
}
