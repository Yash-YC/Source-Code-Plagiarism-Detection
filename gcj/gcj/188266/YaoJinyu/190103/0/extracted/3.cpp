#include <iostream>

using namespace std;

const int MAXN = 50;

int c, n;
double f[MAXN];
double cc[MAXN][MAXN];

double calc1(int i, int j)
{
       return cc[j][n-i+j]/cc[c][n]*cc[c-j][i-j];
}

double calc2(int i)
{
      if (i<n) return 0; else  
      return cc[i][n]/cc[c][n];        
}

void work()
{
     int i, j;
     double s;
     
     f[n] = 1;
     for (i=n+1; i<c; i++){
         f[i] = 0;
         j=n;
         if (j<i-n) j=i-n;
         for (; j<=i-1; j++)
             f[i] += cc[i][j]*(f[j]/(1-calc2(j))+1)*calc1(i, j);
         s = calc2(i);
         f[i] = (f[i]+s)/(1-s);        
     }           
     j=n;
     if (j<c-n) j=c-n;
     f[c] = 0;
     for (;j<=c-1; j++)
         f[c]+=cc[c][j]*(f[j]/(1-calc2(j))+1)*calc1(c, j);
     printf("%.8lf\n", f[c]);
}
     
void prepare()
{
     int i, j;
     memset(cc, 0, sizeof(cc));
     for (i=1; i<=40; i++)
         for (j=0; j<=i; j++)
             if (j==0 || j==i) cc[i][j]=1;
             else
                 cc[i][j] = cc[i-1][j]+cc[i-1][j-1];
}
     
int main()
{
    prepare();
    int t, i = 0;
    scanf("%d", &t);
    while (t--){
          i++;
          printf("Case #%d: ", i);
          scanf("%d%d", &c, &n);
          work();
    }  
    return 0;
}
