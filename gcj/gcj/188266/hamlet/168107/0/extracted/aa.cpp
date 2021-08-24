#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<map>
#include<set>
#include<queue>
#define all(v) (v).begin(),(v).end()
using namespace std ;
long long toint(string s){istringstream is(s);long long t;is>>t;return t;}
string tos(long long t){stringstream st;st<<t;return st.str();}
bool visited[100000][11];
int base(int n, int b)
{
    if (n==0) return 0;
    return (n%b + 10*base(n/b, b));    
}
int decimal(int n, int b)
{
    if (n==0) return 0;
    return (n%10 + b*decimal(n/10, b));
}
bool dfs(int num,int b)
{
 //   cout<<num<<endl;
    if(num==1)return 1;
    visited[decimal(num,b)][b]=1;
    int x=num;
    int sum=0;
    while(x!=0){sum+=(x%10)*(x%10);x=x/10;}
    x=base(sum,b);
    if(visited[decimal(x,b)][b])return 0;
    return dfs(x,b);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    string aux;
    getline(cin,aux);
    for(int ana=0;ana<n;ana++)
    {
        vector<int>v;
        int t;
        getline(cin,aux);
        istringstream is(aux);
        while(is>>t)v.push_back(t);
        
        int dev=2;
        for(int i=2; ;i++)
        {
            bool ok=1;
            memset(visited,0,sizeof(visited));
            for(int j=0;j<v.size();j++)    
            {
                ok=dfs(base(i,v[j]),v[j]);
                if(!ok)break;
            }
            if(ok){dev=i;break;}
        }
        cout<<"Case #"<<ana+1<<": "<<dev<<endl;    
    }
    
  //  system("pause");
    return 0;
}


