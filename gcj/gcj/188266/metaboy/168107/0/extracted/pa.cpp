#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include<cstdlib>
#include<cstring>
#include<string>


using namespace std;

#define pb push_back
#define sz size
#define all(a)  a.begin(),a.end()
#define SZ(v) ((int)(v).size())
#define gcj_print(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}


typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<string> vs;
typedef long long  ll;

vi ans;

//vector<int> 
void f(int a, int b)
{
   //int r=0;
   //vi ans;
   ans.clear();
   while(a>0)
   {
      //n=n*b+a%b;
      ans.pb(a%b);
      a/=b;
   }
   /*while(n>1)
   {
      r=r*b+n%b;
      n/=b;
   }
  return r;*/
  reverse(all(ans));
  //return ans;
}         

int ok(int b)
{
   //int r=12;
   int len=SZ(ans),c=0;
   while(c++ < 100)
   {
      int p=0,i=0;
      //vi ans1;
      while(i<len){p+=(ans[i])*(ans[i]);i++;}
      f(p,b);
      len=SZ(ans);
      if(len==1 && ans[0]==1){c=0;break;}
   }
   //for(int i=0;i<len;i++)cout<<ans[i]<<' ';cout<<"ans"<<endl;
   return (!c) ;
}      

int main()
{
   //cout<<f(91,9)<<endl;
   //vi temp=f(91,9);
   //for(int i=0;i<SZ(temp);i++)cout<<temp[i]<<' ';
   //cout<<endl<<ok(temp,9)<<endl;
   
   
   
   int t,test=0;
   //scanf("%d",&t);
   cin>>t;
   char st[1000];
   char ch;cin.get(ch);
   while(t--)
   {
      
      vector<int> bases;
      cin.getline(st,1000);
      //scanf("%s",st);
     //cout<<st<<endl;
      
      for(int i=0;st[i]!='\0';i++)
      {
         if(st[i]==' ')continue;
         if(st[i]=='1'){bases.push_back(10);break;}
         else bases.pb(st[i]-'0');
      }   
      int len=SZ(bases),flag=0;
      //cout<<len<<endl;
      
      for(int i=2;;i++)
      {
         flag=0;
         for(int j=0;j<len;j++)
         {
            //vector<int> ans1=
            f(i,bases[j]);
            if(!ok(bases[j]))flag=1;
         }
         if(!flag){cout << "Case #" << ((test)+1) << ": " << (i) << endl;break;}   
      }
      test++;
   }         
   return 0;
}   
