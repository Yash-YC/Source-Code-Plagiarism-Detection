#include <iostream>
using namespace std;
int n,m;
int vis[1610],res[1610],d[1610],ns[30][30],ew[30][30],wa[30][30];
const int PI=99999999;
int dir[4][4]={-2,PI,PI,0,-2,PI,0,PI,PI,2,PI,0,PI,2,0,PI};
void renew(int now){
    int t=now%4,i,j;
    int ii,jj;
    ii=now/4/m;
    jj=now/4%m;
    int round=ew[ii][jj]+ns[ii][jj];
    for(i=0;i<4;i++){
        if(i==0&&jj==0)continue;
        if(i==1&&jj==m-1)continue;
        if(i==2&&ii==n-1)continue;
        if(i==3&&ii==0)continue;
        if(now+dir[t][i]>=0&&now+dir[t][i]<n*m*4){
            if(vis[now+dir[t][i]]==0&&d[now+dir[t][i]]>d[now]+2){
                d[now+dir[t][i]]=d[now]+2;
                renew(now+dir[t][i]);
            }
        }
    }
    int plus;
    
    int le=wa[ii][jj]%round;
    int nowtime=d[now]%round-le;
    if(nowtime<0)nowtime+=round;
    if(t==0){
        if(nowtime>=ns[ii][jj])plus=round-nowtime;
        else plus=0;
        if(d[now+1]>d[now]+plus+1){
            d[now+1]=d[now]+plus+1;
            renew(now+1);
        }
        if(nowtime<ns[ii][jj])plus=ns[ii][jj]-nowtime;
        else plus=0;
        if(d[now+2]>d[now]+plus+1){
            d[now+2]=d[now]+plus+1;
            renew(now+2);
        }
    }
    else if(t==1){
        if(nowtime>=ns[ii][jj])plus=round-nowtime;
        else plus=0;
        if(d[now-1]>d[now]+plus+1){
            d[now-1]=d[now]+plus+1;
            renew(now-1);
        }
        if(nowtime<ns[ii][jj])plus=ns[ii][jj]-nowtime;
        else plus=0;
        if(d[now+2]>d[now]+plus+1){
            d[now+2]=d[now]+plus+1;
            renew(now+2);
        }
    }
    else if(t==2){
        if(nowtime>=ns[ii][jj])plus=round-nowtime;
        else plus=0;
        if(d[now+1]>d[now]+plus+1){
            d[now+1]=d[now]+plus+1;
            renew(now+1);
        }
        if(nowtime<ns[ii][jj])plus=ns[ii][jj]-nowtime;
        else plus=0;
        if(d[now-2]>d[now]+plus+1){
            d[now-2]=d[now]+plus+1;
            renew(now-2);
        }
    }
    else if(t==3){
        if(nowtime>=ns[ii][jj])plus=round-nowtime;
        else plus=0;
        if(d[now-1]>d[now]+plus+1){
            d[now-1]=d[now]+plus+1;
            renew(now-1);
        }
        if(nowtime<ns[ii][jj])plus=ns[ii][jj]-nowtime;
        else plus=0;
        if(d[now-2]>d[now]+plus+1){
            d[now-2]=d[now]+plus+1;
            renew(now-2);
        }
    }
}
int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int cas,ca=1,i,j,id;
    cin>>cas;
    while(cas--){
        cin>>n>>m;
        dir[1][2]=dir[3][2]=4*m-1;
        dir[0][3]=dir[2][3]=1-4*m;
        for(i=n-1;i>=0;i--){
            for(j=0;j<m;j++){
                cin>>ns[i][j]>>ew[i][j]>>wa[i][j];
            }
        }
        //memset(vis,0,sizeof(vis));
        for(i=0;i<n*m*4;i++){
            d[i]=0x0fffffff;
            vis[i]=0;
        }
        d[0]=0;
        int mini,miniid;
        while(1){
            mini=0x3fffffff;
            for(i=0;i<n*m*4;i++){
                if(d[i]<mini&&vis[i]==0){
                    mini=d[i];
                    id=i;
                }
            }
            res[id]=d[id];
            if(id==n*m*4-1)break;
            vis[id]=1;
            renew(id);
        }
        printf("Case #%d: %d\n",ca++,res[n*m*4-1]);
    }
    return 0;
}
                
