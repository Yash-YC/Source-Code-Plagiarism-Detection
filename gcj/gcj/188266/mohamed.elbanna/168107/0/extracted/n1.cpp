#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<int>v;
map<long long,bool>m;
int tobase(int x,int b)
{
int p=1,y,num=0;
while(x!=0)
{    
y=x%b;
num+=(y*p);
x/=b;
p*=10;
}    
return num;
}
int getn(int x)
{
int sum=0;
while(x!=0)
{
sum+=((x%10)*(x%10));
x/=10;
}
return sum;
}
bool checkh(int x,int b)
{
x=getn(tobase(x,b));
while(m[x]==false)
{
m[x]=true;
if(x==1)
{return true;}
x=getn(tobase(x,b));
}
return false;
}
int main()
{
freopen("n1.in","r",stdin);
freopen("n1.out","w",stdout);
int c,base=0,temp,ans[504];
string z;
cin>>c;
for(int k=0;k<c;k++)
{
m.clear();
v.clear();
cin>>temp;
v.push_back(temp);
getline(cin,z);        
for(int i=0;i<z.size();i++)
{
if(z[i]==' '||z[i]=='0')
{continue;}
else
{
temp=z[i]-'0';
if(temp==1)
{temp=10;}
v.push_back(temp);
}
}
int i=2;
while(i>1)           
{               
for(int j=0;j<v.size();j++)
{
m.clear();
if(checkh(i,v[j])==false)
{break;}
if(j==v.size()-1)
{ans[k]=i;i=-1;}

}
i++;
}
cout<<"Case #"<<k+1<<": "<<ans[k]<<endl;
}   
return 0;    
}
