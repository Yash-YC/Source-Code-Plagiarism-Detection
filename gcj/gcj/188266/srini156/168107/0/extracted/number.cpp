//Multi-Base
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int convert(int a,int b)
{
int ret=0,si=1;
while(a>0)
{
 ret=(a%b)*si+ret;
 a/=b;
 si*=10;
}
return ret;
}
int sq(int a,int b)
{
 int ret=0;
while(a>0)
{
 ret+=(a%10)*(a%10);
 a/=10;
}
return convert(ret,b);
}
bool isHappy(int a,int b)
{
 int w=a,loops=10;
 while(1)
 {
  w=a;
  for(int q=0;q<loops;q++)
  { 
    a=sq(a,b);
    if(a==w)
    break;
  }
  if(a==w)
  break;
  loops+=10;
 }
 return a==1?true:false;
}
int main()
{
 int t;
 cin>>t;
string s; getline(cin,s);
for(int i=1;i<=t;i++)
{
   getline(cin,s);
    istringstream in(s);
    vector<int>vec; int n;
    while(in>>n)
    vec.push_back(n);
    int q=2;
   while(1)
  {
   bool t=true;
   for(int z=0;z<vec.size();z++)
   t=t&&isHappy(convert(q,vec[z]),vec[z]);
   if(t)
   break;
   q++;
  } 	 
   cout<<"Case #"<<i<<": "<<q<<endl;	
} 
 return 0;
}
