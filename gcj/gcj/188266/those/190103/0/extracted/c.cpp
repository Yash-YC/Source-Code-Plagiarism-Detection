#include<stdio.h>
#include<string.h>

double ans[100],ans2[100];
int c,n;

double C(int x,int y);

int main(){
  int ca; scanf("%d",&ca);
  for (int tt=1; tt<=ca; tt++){
    scanf("%d%d",&c,&n);
    printf("Case #%d: ",tt);  
    memset(ans,0,sizeof(ans));
    ans[0]=1;
    double xx = 0;
    for (int k=1; k<100000; k++){
      for (int i=0; i<=c; i++) ans2[i]=0;
      for (int i=0; i<c; i++){
        for (int j=0; j<=n; j++){
          if (i+j <= c){
            double pp=( C(i,n-j)*C(c-i,j)/C(c,n));
            /*
            if (i==2 && j==1){
            printf(">> %lf %lf %lf\n",C(i,n-j),C(c-i,j),C(c,n));
            printf(">> %lf\n",pp);
            }*/
          
            ans2[i+j] += ans[i]*pp;
          }
        }
      }
      memcpy(ans,ans2,sizeof(ans2));
      //for (int i=0; i<=c; i++) printf("%f ",ans[i]); printf("\n");
      xx += ans[c]*k;
    }
    printf("%lf\n",xx);
  }

  return 0;
}

double C(int x,int y){
  if (x<y) return 0;
  if (y>x/2) y=x-y;
  double k=1;
  for (int i=1; i<=y; i++) k = k*(x-i+1)/i;
  return k;
}
/*
int main(){
  int ca; scanf("%d",&ca);
  for (int tt=1; tt<=ca; tt++){
    scanf("%d%d",&c,&n);
    printf("Case #%d: ",tt);
    
    if (n>=c){ printf("1.00000\n"); continue; }
    
    for (int i=0; i<=c; i++) ans[i]=0;
    ans[n]=1;
    for (int i=n; i<c; i++){
      //ans[i] += 1;
      ans[i] /= 1-C(i,n)/C(c,n);    
      for (int j=1; j<=n; j++){
        if (c-i>=n-j)
          ans[i+j] += (ans[i]+1)*( C(i,j)*C(c-i,n-j)/C(c,n));
      }
    }
    for (int i=0; i<=c; i++) printf("%f ",ans[i]); printf("\n");
    printf("%lf\n",ans[c]);
  }
  return 0;
}
*/
