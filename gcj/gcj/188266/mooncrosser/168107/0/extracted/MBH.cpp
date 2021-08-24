#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;
set <int> st;
bool check_in_base(int b,int t)
{
  int sz=st.size();
  st.insert(t);
  if(st.size()==sz)return 0;
  //cout<<t<<endl;
  int k=0;
  while(t!=0)
   {
             k+=(t%b)*(t%b);
             t/=b;
   }
  if(k==1)
  return 1;
  else return check_in_base(b,k);
}

int solve(int x)
{
    string s;
    getline(cin,s);
    //cout<<s<<endl;
    stringstream ss;
    ss<<s;
    int bases[512],p=0;
    while(ss.good())
    {ss>>bases[p];
     p++;
    }
    int z=2;
    while(true)
    {
       bool b=1;
       for(int i=0;i<p&&b==1;i++)
        {      st.clear();
               b=check_in_base(bases[i],z);
        }
       if(b==1){printf("Case #%d: %d\n",x,z);return z;}
       z++;
    }
    

}
int main()
{
    int T;
    scanf("%d",&T);
    cin.ignore(256,'\n');
    for(int i=0;i<T;i++)
     solve(i+1);
     
    return 0;
}
