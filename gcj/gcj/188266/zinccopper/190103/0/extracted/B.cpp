#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int dblcmp(double x)
{
    if (fabs(x)<1E-7) return 0;
       else return 1;
}
int N,C;
double P[41];
double JIE(int x)
{
       double ans=1;
       for (int i=1;i<=x;i++)
           ans=ans*i;
       return ans;
}
double F[41];
double p[41];
int main()
{
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++)
    {
        memset(P,0,sizeof(P));
        scanf("%d%d",&C,&N);
        for (int i=N;i<=C;i++)
        {
            P[i]=(C-i)/(double)C;
            for (int j=1;j<N;j++)
                P[i]+=(1-P[i])*(C-i)/double(C-j);
        }        
        memset(F,0,sizeof(F));
        F[N]=1;
        for (int i=N+1;i<=C;i++)
        {
            memset(p,0,sizeof(p));
            for (int j=1;j<=C-(i-1);j++)
                p[j]=1;
            int t=0;
            while (true)
            {
                  t++;
                  double last=F[i];
                  for (int j=1;j<=C-(i-1);j++)
                  {
                      F[i]+=(F[i-j]+t)*P[i-j]*p[j];
                      p[j]=p[j]*(1-P[i-j]);
                  }
                  if (dblcmp(last-F[i])==0) break;
            }
        }
        printf("Case #%d: %lf\n",Case,F[C]);
    }
    return 0;
}
 
