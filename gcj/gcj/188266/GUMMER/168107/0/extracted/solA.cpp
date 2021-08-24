#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool lista[20][100000];// si no cubre use map
bool visit[20][100000];
bool bases[20];
void generaF(int b,int i)
{ //cout<<"esta en base"<< b<<endl;
  memset(visit[b-2],0,sizeof(visit[b-2]));
  visit[b-2][1]=1;      
  int aux=i;
    while(aux>=1)
    {int s=0;
     
      if(!(visit[b-2][aux]))
         { visit[b-2][aux]=1; 
    //       cout<<"numero estudiado :"<<aux<<endl;
           while(aux!=0)
           {
           s+=(aux%b)*(aux%b);
           aux/=b;   // cout<<"bucl";   
           }    
           aux=s;   
         }
      else     
        {lista[b-2][i]=lista[b-2][aux];
         
         return;
        }
       
    } 
}
int main()
{
   freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
int T;
string s;
int x;
cin>>T;
memset(lista,0,sizeof(lista));
for(int i=0;i<20;i++)
lista[i][1]=1;
getline(cin,s);
//casos:
for(int c=0;c<T;c++)
{
        getline(cin,s);
   istringstream is(s);
   
     memset(bases,0,sizeof(bases));
     while(is>>x)
     {       
      bases[x-2]=1;   
      
     }  
   int i=2;      
  while(1)
  {   
     bool r=1;
       for(int j=0;j<20;j++)
           if(bases[j])
            {
             generaF(j+2,i);    
             //cout<<lista[j][i]<<"  ";      
             r=r&&lista[j][i];    
            //int j;cin>>j;
            }
            
     if(r)
     {cout<<"Case #"<<(c+1)<<": "<<i<<endl;
      break;
     }
     i++;
  }    
}

return 0;    
}
