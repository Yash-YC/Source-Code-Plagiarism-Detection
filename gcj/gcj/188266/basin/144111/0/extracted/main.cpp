#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1000000000;
typedef struct Node
{
    int s;
    int w;
    int t;
    } Node;
Node vec_node[20][20]={0};
int n_time[40][40]={0};
int add_x[]={1,0,-1,0};
int add_y[]={0,1,0,-1};
int n=0,m=0;
bool myCheck(int x,int y)
{
    return x>=0&&x<=(2*m-1)&&y>=0&&y<=(2*n-1);
}
int mydealtime(int x,int y,int t,int north)
{
    int n_circle =vec_node[y/2][x/2].s+vec_node[y/2][x/2].w;
    int s=vec_node[y/2][x/2].s;
    int w=vec_node[y/2][x/2].w;
    int temp=(t-vec_node[y/2][x/2].t)%n_circle;
    if(temp<0)
        temp+=n_circle;

    if(north==1)
    {
        if(temp<s)
            return t+1;
        else
            return t+1+n_circle-temp;
    }
    else{
        if(temp<s)
            return t+1+s-temp;
        else
            return t+1;
        }
}
void mySearch(int x,int y)
{

    for(int i=0;i<4;i++)
        {
               int t=n_time[y][x];
            int n_x=x+add_x[i];
            int n_y=y+add_y[i];
            if(myCheck(n_x,n_y))
            {
                if(0==i)
                {
                    if(x%2==1)
                            t+=2;
                    else
                        t=mydealtime(x,y,t,0);
                    }
                else if(1==i)
                {
                    if(y%2==1)
                        t+=2;
                    else
                        t=mydealtime(x,y,t,1);
                    }
                else if(2==i)
                {
                    if(x%2==0)
                        t+=2;
                    else
                        t=t=mydealtime(x,y,t,0);
                    }
                else if(3==i)
                {
                    if(y%2==0)
                        t+=2;
                    else
                        t=mydealtime(x,y,t,1);
                    }

                if(t<n_time[n_y][n_x])
                    {
   // cout<<t<<" :" <<i<<"  "<<n_y<<"  "<<n_x<<endl;
                        n_time[n_y][n_x]=t;
                        mySearch(n_x,n_y);
                        }

            }
        }
}
int main()
{
    ifstream in("a.in");
    ofstream out("a.out");
    int c=0;
    in>>c;
    for(int i=1;i<=c;i++)
    {
        memset(vec_node,0,sizeof(vec_node));
         for(int j=0;j<40;j++)
         for(int k=0;k<40;k++)
            n_time[j][k]=100000000;
        n=0,m=0;
        in>>n>>m;
     //   cout<<n<<m<<n_time[0][0];
        for(int j=1;j<=n;j++)
         for(int k=0;k<m;k++)
            in>>vec_node[n-j][k].s>>vec_node[n-j][k].w>>vec_node[n-j][k].t;

        n_time[0][0]=0;
        mySearch(0,0);
        out<<"Case #"<<i<<": "<<n_time[2*n-1][2*m-1]<<endl;



        }
    return 0;
}
