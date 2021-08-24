#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
std::vector<int> va;
std::map<int,int> tt;
bool check(int num,int base)
{
     
     if(num==1) return true;
     
     int sum = 0;
     while( num>0 )
     {
            int t = num%base;
            sum += t*t;
            num /= base;       
     }  
     std::map<int,int>::iterator it=tt.find(sum);
     
     if( it!=tt.end() ) return false;   
     tt[sum] = 1;
     return check(sum,base);
}

int solve()
{
       int i=3;
       
       while(1){
//               printf("solving..%d",i);
//                         system("pause");
               bool flag = true;
               for(int j=va.size()-1;j>=0;j--)
               {
                      tt.clear();
                      if(check(i,va[j])==false)  {flag = false; break;}      
               }        
               if(flag==true) return i;
               i++;
       }    
}

int main(int argc, char *argv[])
{
    freopen("A-small-attempt0.in","r",stdin);
  //  freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
      
    int N;
    char c;
    scanf("%d%c",&N,&c);
    char buf[30];
    int CASE = 1;
    while(N--)
    {
          memset(buf,'\0',sizeof(buf));
          va.clear();
          gets(buf);
          int t = 0;
          for(int i=0; ;i++)
          {
                  if(buf[i]==' ')
                  {
                        va.push_back(t);       
                        t = 0;
                  }
                  else if(buf[i]=='\0')
                  {
                       va.push_back(t);
                       break;     
                  }
                  else
                  {
                      t = 10*t + buf[i]-'0';    
                  }
                          
          }    
//          for(int i=0;i<va.size();i++)
 //         { printf("%d ",va[i]);}
 //        system("pause");
          int res = solve();
          printf("Case #%d: %d\n",CASE,res);
          
                 
          CASE++;     
    }

    return 0;
}
