#include<iostream>
using namespace std;
int ans[50][50];
int b[25][25][3];
int n,m;
const int fx[4][2]={-1,0,1,0,0,-1,0,1};
void dpf(const int i0,const int j0,const int ans0)
{
    ans[i0][j0]=ans0;
    for(int z=0;z<4;z++){
        int i1=i0+fx[z][0],j1=j0+fx[z][1];
        if(i1<0||i1>=2*n||j1<0||j1>=2*m)
            continue;
        int ans1;
        if(i0==i1&&((j0/2)!=(j1/2))||j0==j1&&((i0/2)!=(i1/2)))
            ans1=ans0+2;
        else{
            int i2=i0/2;
            int j2=j0/2;
            int t=ans0-b[i2][j2][2];
            while(t<0)
                t+=b[i2][j2][0]+b[i2][j2][1];
            while(t>b[i2][j2][0]+b[i2][j2][1])
                t-=b[i2][j2][0]+b[i2][j2][1];
            if(i0==i1){
                if(t>=b[i2][j2][0])
                    ans1=ans0+1;
                else
                    ans1=ans0+1+b[i2][j2][0]-t;
            }
            else{
                if(t<b[i2][j2][0])
                    ans1=ans0+1;
                else
                    ans1=ans0+1+b[i2][j2][0]+b[i2][j2][1]-t;
            }        
        }    
        if(ans[i1][j1]==-1 || ans[i1][j1]>ans1)
            dpf(i1,j1,ans1);
    }    
}    
int main(void)
{
    FILE *fin = fopen("B-small-attempt0.in","r");
    FILE *fout = fopen("B-small-attempt0.out","w");
    int num;
    fscanf(fin,"%d",&num);
    for(int cas=1;cas<=num;cas++){
        memset(ans,-1,sizeof(ans));
        fscanf(fin,"%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<3;k++)
                    fscanf(fin,"%d",&b[i][j][k]);
        dpf(n*2-1,0,0);
        fprintf(fout,"Case #%d: %d\n",cas,ans[0][m*2-1]);
    }    
    system("pause");
    return 0;
}    
