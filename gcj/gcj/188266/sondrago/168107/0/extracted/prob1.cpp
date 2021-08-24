#include<iostream>
#include<vector>
using namespace std;
int Z[1000000][11]={0};
int dp(int a,int b)
{
     if(a==1)return Z[a][b]=1;
     if(Z[a][b]==1||Z[a][b]==-1)return Z[a][b];
     if(Z[a][b]==2)return Z[a][b]=-1;
     Z[a][b]=2;
     int s=0;
     int A=a;
     while(a>0)
     {
         int x=a%b;
         s+=x*x;
         a/=b;          
     }
     return Z[A][b]=dp(s,b);    
}
int main()
{
    for(int i=1;i<1000000;i++)for(int j=2;j<=10;j++)
    {
            Z[i][j]=dp(i,j);
    }
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    scanf("%d\n",&N);
    char x=0;
    for(int caso=1;caso<=N;caso++)
    {
           int n=0;
           vector<int>num;
           scanf("%c",&x);
           n=x-'0';
           while(x!='\n')
           {
                   scanf("%c",&x); 
                   if(x=='\n'||x==' ')
                   {
                          num.push_back(n);
                          n=0;
                          continue;                 
                   }      
                   n=10*n+x-'0';
           }
           int s=2;
           for(s=2;s<=1000000;s++)
           {
               int k;                   
               for(k=0;k<num.size();k++)
               if(Z[s][num[k]]!=1)break;
               if(k==num.size())break;                       
           }
           cout<<"Case #"<<caso<<": "<<s<<endl;         
    }
   
    return 0;    
}
