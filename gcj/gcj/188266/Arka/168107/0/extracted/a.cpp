#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long base(int a,int b)
{  long long s=0ll; long long c=1;int d;
   while(a)
  { d=a%b;
    s=s+d*c; c=c*10;
    a=a/b; }
  return s;
}
long long abase(int a,int b)
{  long long s=0ll; long long c=1;int d;
   while(a)
  { d=a%b;
    s=s+d*c; c=c*b;
    a=a/10; }
  return s;
}
long long result(long long a,int b)
{   long long s=0ll;
    int d;
    while(a)
    { d=a%10;
      s+=d*d; 
      a=a/10;}
    s=base(s,b);
    return s;
}

void inp(int A[],int &count)
{  char s[10000],c; int len=0,x;
   scanf("%c",&c);
   while(c!='\n')
   {  s[len++]=c;
      scanf("%c",&c);  }
   s[len]='\0';
   for(x=0;x<len;x++)
   {  if(s[x]!=' ')
      { if(s[x]=='1' && s[x+1]=='0')
           { A[count++]=10; x++; }
        else A[count++]=s[x]-'0';
      }
   }
} 
int happy(long long a,int b)
{   int n,c,x,f=0,len=1;
    long long A[1000];
    A[0]=a;
    while(1)
    {  for(x=0;x<len;x++) 
       c=0;  
       n=a;
       a=result(n,b);
       for(x=0;x<len;x++) 
         if(a==A[x]) { c=1; break;}
       if(c==1) break;
       else A[len++]=a;
        
       if(a==1)
       { f=1; break;}
     }
     return f;
}
int main()
{
    int x,T,B[10],f,count; char c;
    long long y,z,b;
    scanf("%d",&T);scanf("%c",&c);
    for(x=1;x<=T;x++) 
    {  
       count=0;
       inp(B,count); 
       printf("Case #%d: ",x);
       for(y=2;;y++)
       {  f=1;
          for(z=0;z<count;z++)
          { b=base(y,B[z]); 
            if(!happy(b,B[z]))
            {f=0; break;}
          }
         
          if(f==1)
          { cout<<y<<endl; break;}
       }
    }  
    return 0;
}
