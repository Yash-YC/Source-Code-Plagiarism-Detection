#include <iostream>
  using namespace std;
  int base[12],t,n,num[50];
  bool hav[50000];
bool happy(int x,int y){
  int i,k,wei=0; 
  memset(hav,false,sizeof(hav));hav[y]=true;
  while(y>0){
    num[++wei]=y % x;
    y=y / x;
    };    
  while(true){
    y=0;
    for(i=1;i<=wei;i++)y=y+num[i]*num[i];
    if(hav[y])break;
    if(y==1)break;
    wei=0;hav[y]=true;
    while(y>0){
      num[++wei]=y % x;
      y=y/x;
      };
    };
  if(y==1)return true;
  else return false;
}
main(){
  freopen("a.in","r",stdin);freopen("a.out","w",stdout);
  int sj,i,j,k;
  scanf("%d\n",&t);
  char ch;
  bool flag;
  for(sj=1;sj<=t;sj++){
    printf("Case #%d: ",sj);
    n=0;
    while(true){
      scanf("%d%c",&k,&ch);
      base[++n]=k;
      if(ch=='\n')break;
      };
   // for(i=1;i<=n;i++)cout<<base[i]<<' ';cout<<endl;
    for(k=2;k<=1000000000;k++){
      flag=true;
      for(i=1;i<=n;i++)if(!happy(base[i],k)){flag=false;break;};
      if(flag)break;
      };
    cout<<k<<endl;
    };
}
      
