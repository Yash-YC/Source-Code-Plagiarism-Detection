#include <iostream>
  using namespace std;
  int sj,t,n,cards,all,tot;
  double f[20][1024];bool hav[20][1024],used[1024];
  int p[1024];
double dp(int x,int zt){
  if(x>19)return 0;
  if(zt==all)return 0;
  if(hav[x][zt])return f[x][zt];
  hav[x][zt]=true;
  int i,j;
  double w=0.0;
  for(i=1;i<=tot;i++){
    j=zt|p[i];
    if(j==zt)w=w+dp(x+1,zt)+1.0;
    else w=w+dp(1,j)+1.0;
    };
    w=w/tot;
  f[x][zt]=w;
 // if(zt==3)printf("0.7f\n",w);
  return w;
}
main(){
  freopen("c.in","r",stdin);freopen("c.out","w",stdout);
  scanf("%d\n",&t);
  double ans;
  int i,j,k,x;
  for(sj=1;sj<=t;sj++){
    printf("Case #%d: ",sj);
    scanf("%d%d\n",&n,&cards);
    all=(1<<n)-1;
    tot=0;
    memset(hav,0,sizeof(hav));
    for(k=1;k<=all;k++){
      j=0;
      for(i=1;i<=n;i++){
        x=1<<(i-1);
        if((k&x) >0)j++;
        }                        
      if(j==cards)p[++tot]=k;
      };
    ans=dp(1,0);
    printf("%0.7f\n",ans);
    };
}
    
  
  
