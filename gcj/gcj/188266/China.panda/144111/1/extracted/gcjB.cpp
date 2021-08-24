#include<stdio.h>
const int infi=2100000000;
int dis[30][30][10],n,m;
int s[30][30],w[30][30],t[30][30];
bool visit[30][30][10];
int calc(int time,int x,int y,int dir)
{
    int mod=s[x][y]+w[x][y];
    int cur=((time-t[x][y])%mod+mod)%mod;
    if(dir==0)
    {
        if(cur>=s[x][y]) return 0;
        else return s[x][y]-cur;
    }
    else
    {
        if(cur<s[x][y]) return 0;
        else return mod-cur;
    }
}
void release(int x,int y,int k)
{
    if(k==0)
    {
        if(dis[x-1][y][3]>dis[x][y][k]+2) dis[x-1][y][3]=dis[x][y][k]+2;
        if(dis[x][y-1][1]>dis[x][y][k]+2) dis[x][y-1][1]=dis[x][y][k]+2;
        if(dis[x][y][3]>dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1)dis[x][y][3]=dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1;
        if(dis[x][y][1]>dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1)dis[x][y][1]=dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1;
    }
    if(k==1)
    {
        if(dis[x-1][y][2]>dis[x][y][k]+2) dis[x-1][y][2]=dis[x][y][k]+2;
        if(dis[x][y+1][0]>dis[x][y][k]+2) dis[x][y+1][0]=dis[x][y][k]+2;
        if(dis[x][y][2]>dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1)dis[x][y][2]=dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1;
        if(dis[x][y][0]>dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1)dis[x][y][1]=dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1;
    }
    if(k==2)
    {
        if(dis[x+1][y][1]>dis[x][y][k]+2) dis[x+1][y][1]=dis[x][y][k]+2;
        if(dis[x][y+1][3]>dis[x][y][k]+2) dis[x][y+1][3]=dis[x][y][k]+2;
        if(dis[x][y][1]>dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1)dis[x][y][3]=dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1;
        if(dis[x][y][3]>dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1)dis[x][y][1]=dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1;
    }
    if(k==3)
    {
        if(dis[x+1][y][0]>dis[x][y][k]+2) dis[x+1][y][0]=dis[x][y][k]+2;
        if(dis[x][y-1][2]>dis[x][y][k]+2) dis[x][y-1][2]=dis[x][y][k]+2;
        if(dis[x][y][0]>dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1)dis[x][y][0]=dis[x][y][k]+calc(dis[x][y][k],x,y,1)+1;
        if(dis[x][y][2]>dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1)dis[x][y][2]=dis[x][y][k]+calc(dis[x][y][k],x,y,0)+1;
    }
}
int main()
{
    int ncase,nc,i,j,k,best,tagi,tagj,tagk;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&ncase);
    for(nc=1;nc<=ncase;nc++)
    {
       scanf("%d%d",&n,&m); 
       for(i=n;i>=1;i--)
          for(j=1;j<=m;j++)
              scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
       for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
               for(k=0;k<4;k++)
               {
                   dis[i][j][k]=infi;
                   visit[i][j][k]=false;
               }
        dis[1][1][0]=0;
        while(!visit[n][m][2])
        {
            best=infi;
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    for(k=0;k<4;k++)
                        if(!visit[i][j][k]&&dis[i][j][k]<best)
                        {
                            best=dis[i][j][k];
                            tagi=i;
                            tagj=j;
                            tagk=k;
                        }
            visit[tagi][tagj][tagk]=true;
            release(tagi,tagj,tagk);
        }
        printf("Case #%d: %d\n",nc,dis[n][m][2]);
    }
    return 0;
}