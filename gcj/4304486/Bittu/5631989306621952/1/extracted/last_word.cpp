#include<bits/stdc++.h>
using namespace std;

int main()
 {

   freopen("A-large.in","r",stdin);
     freopen("output6.txt","w",stdout);
   int t;
   cin>>t;


   int p1;
   for(p1=1;p1<=t;p1++)
     {

       string s1;
       cin>>s1;

       string ans="";
       int l=s1.size();
       int i;

       char ch;
       for(i=0;i<l;i++)
        {
           ch=s1[i];
           if(ans=="")
             ans+=ch;
           else if(ans[0]>ch)
               ans=ans+ch;
               else
               ans=ch+ans;
        }
        cout<<"Case #"<<p1<<": "<<ans<<endl;
    }
 }
