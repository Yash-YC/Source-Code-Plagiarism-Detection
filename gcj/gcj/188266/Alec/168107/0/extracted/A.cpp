#include <cstdio>
#include <cstring>
#define MAXM 100000
#define MAXN 200000

using namespace std;

char save[MAXN][11];
char visit[MAXN];

void convert(int k,int b,char *num){
  char tmp[100];
  int i;
  i=0;
  while (k>0){
    tmp[i]=k%b;
    k=k/b;
    i++;
  }
  i--;
  while (i>=0){
    (*num)=tmp[i];
    num++;
    i--;
  }
  (*num)=-1;
}

int getSum(char *num){
  int res=0;
  int i;
  while ((*num)!=-1){
    res=res+(*num)*(*num);
    num++;
  }
  return res;
}

void init(){
  memset(save,-1,sizeof(save));
  
  memset(visit,0,sizeof(visit));
}

int solve(int k,int b){
  char num[100];
  int s;
  
  visit[k]=1;
  if (save[k][b]!=-1) return save[k][b];
  convert(k,b,num);
  s=getSum(num);
  //printf("s=%d k=%d\n",s,k);
  if (visit[s]==1){
    save[k][b]=0;
    return 0;
  }
  if (s==1){
    save[k][b]=1;
    return 1;
  }
  save[k][b]=solve(s,b);
  return save[k][b];
}

int main(){
  int i,j,k=0;
  
  init();
  memset(visit,0,sizeof(visit));
      
  for (i=2;i<MAXN;i++){
    k=0;
    for (j=2;j<=10;j++){
      //printf("i=%d j=%d\n",i,j);
      memset(visit,0,sizeof(visit));
      solve(i,j);
      if (save[i][j]==0) k=1;
      //printf("i=%d j=%d save[i][j]=%d\n",i,j,save[i][j]);
    }
    if (k==0){
      printf("i=%d\n",i);
      break;
    }
  }
  
  int t,m,cc=0;
  int list[20];
  char ch;
  scanf("%d",&t);
  while (t--){
    k=0;
    cc++;
    printf("Case #%d: ",cc);
    while (1){
      scanf("%d%c",&list[k],&ch);
      //printf("%d ",list[k]);
      k++;
      if (ch=='\n') break;
    }
    for (i=2;i<MAXN;i++){
      m=0;
      for (j=0;j<k;j++){
        if (save[i][list[j]]==0) m=1;
      }
      if (m==0){
        printf("%d\n",i);
        break;
      }
    }
  }
  return 0;
}

