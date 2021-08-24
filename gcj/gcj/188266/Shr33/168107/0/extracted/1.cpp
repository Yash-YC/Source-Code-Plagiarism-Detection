#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#define pb push_back
using namespace std;

int todec(int n, int b)
{
   int result=0;
   int multiplier=1;
      
   while(n>0)
   {
      result+=n%b*multiplier;
      multiplier*=10;
      n/=b;
   }
      
   return result;
}

int happy(int n,int bb)
 {   
  
 int sum=0;int cc=1;
 map<int,int>mm;
 
  while(1)
   {
    sum=0;
	n=todec(n,bb);
	//cout<<n<<endl;
	if(n==0)return 0;
	if(n==1)return 1;
	//cout<<"  :P "<<endl;
    if(mm.count(n)==0)
    {
	//cout<<"  in  "<<n<<endl;
	 mm[n]=cc;
	 cc++;
	 }
	 else if(mm.count(n)>0)break;
	
    while(n>0)
	 {
	   int k=n%10;
	   sum+=k*k;
	   n=n/10;
	 }
	 n=sum;
	 //cout<<n<<endl;
	 
}
	 
	 return 0;
	}
	   
int main()
{
int pp=1;
string s;
int t;
cin>>t;

 getline(cin,s);
while(t--)
		{
		 vector<int>v;
		 
			getline(cin,s);
           	
			stringstream st(s);
			   
			   int k;
			   while(st >> k )
			    { 
				 v.pb(k);
				}
				
				 
				int j=2;
				//int kk=happy(3,2);
				//cout<<kk<<endl;
				//cout<<"  aSAbsam dbas da dba "<<endl; 
				while(1)
				 {
				 
				  int ct=0;
				for(int i=0;i<v.size();i++)
				 {
				  
				 
				 
				  if(happy(j,v[i])==1)ct++;
				  }
				
				  if(ct==v.size()) {cout<<"Case #"<<pp<<": "<<j<<endl;break;}
				  j++;
				  }
				  pp++;
				 
		}
				 
		

return 0;
}
