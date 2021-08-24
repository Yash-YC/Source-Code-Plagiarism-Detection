#include <iostream>

using namespace std;

const int MaxN=25;

int b[2*MaxN][2*MaxN];
int c,n,m,i,j,s[MaxN][MaxN],w[MaxN][MaxN],t[MaxN][MaxN],q[5000][3],len;

int calc(int now,int s,int w,int t,bool b)
{
    int ans=0;
    if (now<t)
    {
               if (b) ans=t-now;
               else ans=0;
    }
    else
    {
        if ((now-t)%(s+w)<s)
        {
                             if (b) ans=0;
                             else ans=s-(now-t)%(s+w);
        }
        else
        {
                             if (!b) ans=0;
                             else ans=w-(now-t)%(s+w)+s;
        }
    }
    return ans;
}

int main()
{
    freopen("gcj2.in","r",stdin);
    freopen("gcj2.out","w",stdout);
    cin>>c;
    for (int ii=1;ii<=c;ii++)
    {
        cin>>n>>m;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
            {
                cin>>s[i][j]>>w[i][j]>>t[i][j];
                t[i][j]%=(s[i][j]+w[i][j]);
            }
        len=1;
        q[1][0]=0;
        q[1][1]=2*n;
        q[1][2]=1;
        i=1;
        memset(b,0xff,sizeof(b));
        b[2*n][1]=0;
        while (i<=len)
        {
            int xx,yy,temp;
            for (j=1;j<=4;j++)
            {
                if (j==1)
                {
                         xx=q[i][1]-1;
                         yy=q[i][2];
                         if (xx%2) temp=1;
                         else temp=2;
                }
                if (j==2)
                {
                         xx=q[i][1];
                         yy=q[i][2]+1;
                         if (yy%2) temp=2;
                         else temp=1;
                }
                if (j==3)
                {
                         xx=q[i][1]+1;
                         yy=q[i][2];
                         if (xx%2) temp=2;
                         else temp=1;
                }
                if (j==4)
                {
                         xx=q[i][1];
                         yy=q[i][2]-1;
                         if (yy%2) temp=1;
                         else temp=2;
                }
                if (xx>0&&yy>0&&xx<=n*2&&yy<=m*2)
                {
                   if (temp==1) temp+=calc(q[i][0],s[xx/2+xx%2][yy/2+yy%2],w[xx/2+xx%2][yy/2+yy%2],t[xx/2+xx%2][yy/2+yy%2],j%2);
                   temp+=q[i][0];
                   if (temp<b[xx][yy]||b[xx][yy]==-1)
                   {
                      b[xx][yy]=temp;
                      len++;
                      q[len][0]=temp;
                      q[len][1]=xx;
                      q[len][2]=yy;
                   }
                }
            }
            i++;
        }
        cout<<"Case #"<<ii<<": "<<b[1][2*m]<<endl;
        /*if (ii==4)
        {
                  for (i=1;i<=2*n;i++)
                  {
                      for (j=1;j<=2*m;j++)
                          cout<<b[i][j]<<' ';
                      cout<<endl;
                      }
                      }*/
    }
    return 0;
}
