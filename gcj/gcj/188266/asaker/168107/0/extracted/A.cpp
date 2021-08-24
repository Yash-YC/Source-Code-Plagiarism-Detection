#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
int base[10];
map<int,bool> mp;
ifstream fin("As.in");
ofstream fout("As.out");

bool check(int number,int b)
{
     if(number==1)return true;
     if(mp[number])return false;
     mp[number]=1;
     int next=0;
     while(number)
     {
        next+=(number%10)*(number%10);
        number/=10;
     }
     int cur=next;
     next=0;
     for(int j=1;cur;j*=10)
     {
          next+=(cur%b)*j;
          cur/=b;
     }
     return check(next,b);
}
int main()
{
   int T,N;
   string s;
   fin>>T;
   getline(fin,s);
   for(int k=0;k<T;k++)
   {
      stringstream ss;  
      getline(fin,s);
      ss<<s;
      N=0;
      while(ss)
      {
         ss>>base[N++];
      }
      N--;
      for(int nm=2;nm<100000000;nm++)
      {
          bool flag=1;
          for(int i=0;i<N;i++)
          {
              mp.clear();
              int num=0,cur=nm,b=base[i];
              for(int j=1;cur;j*=10)
              {
                  num+=(cur%b)*j;
                  cur/=b;
              }
              if(!check(num,b)){flag=0;break;}
          }
          if(flag){fout<<"Case #"<<k+1<<": "<<nm<<endl;break;}
      }
   }
   return 0;
}
