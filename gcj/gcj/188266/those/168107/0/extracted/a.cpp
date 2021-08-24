#include<stdio.h>
#include<string.h>

int f(int x, int base){
  int ans=0;
  while (x>0){
    int k=x%base;
    x/=base;
    ans += k*k;
  }
  return ans;
}

const int MAX=100000;
char s[100];
int n, a[100];
bool vis[MAX], happy[100][MAX];

int main(){
  memset(happy,0,sizeof(happy));
  for (int i=2; i<=10; i++){
    happy[i][1]=true;    
    for (int x=2; x<=MAX; x++){
      memset(vis,0,sizeof(vis));
      int k=x;
      while (!happy[i][k] && !vis[k]){
        vis[k]=true;
        k=f(k,i);
      }    
      if (happy[i][k]) happy[i][x]=true;
    }
  }
  
  int ca; scanf("%d",&ca); gets(s);
  for (int tt=1; tt<=ca; tt++){
    gets(s);
    int t=0, k=0, ll=0;
    n=0;
    while (sscanf(s+t,"%d%n",&k,&ll) > 0){
      a[n++]=k;
      t += ll;
    }   
    int ans=0; 
    for (int x=2; true; x++){
      //printf("~~ %d\n",x);
      bool ok=true;
      for (int i=0; i<n && ok; i++){
        int k=x;
        while (k>=MAX) k=f(k,a[i]);        
        if (!happy[a[i]][k]) ok=false;
      }     
      if (ok){
        ans=x;
        break;
      }
    }    
    printf("Case #%d: %d\n",tt,ans);
  }
  return 0;
}
