//Problem 1 -- Google Code Jam -- louis123 
#include<cstdio>
using namespace std;

int btoi(int N, int b)
{
   int t=N, r=0, p=1;
   while(t!=0)
   {
     r+=(t%10)*p;
     t=(int)(t/10);
     p=p*b;
   }
  return r;
}

int itob(int N, int b)
{
   int t=N, r=0, p=1;
   while(t!=0)
   {
     r+=(t%b)*p;
     t=(int)(t/b);
     p=p*10;
   }
  return r;
}

int digsq(int N, int b)
{
  int sum=0, i, j, t=N;
  while(t!=0)
  {
     i=t%10;
     sum+=i*i;
     t=(int)(t/10);
  }
  return itob(sum, b);
}

bool isone(int i, int b)
{  int j, k=i;
   for(j=0;j<1000;j++)
   {
      k=digsq(k,b);
      
      if(k==1)
     {
        return true;

     }
   }
 return false;
}
int main()
{
  int q,k,i,j ,f, ans,l, sqsum,answer[500];
  int t, bs[500][10], num[500];
  char ch;
  scanf("%d", &t);

  for(i=0;i<t;i++)
 {  
   for(j=0;j<11;j++)
   {
     scanf("%d%c", &bs[i][j], &ch);
     if(ch=='\n')
     {
       num[i]=j+1;
       break;
     }
   } 
 }


for(q=0;q<t;q++){f=1;
 for(i=2;f!=0;i++)
 { f=0;
   for(j=0;j<num[q];j++)
   if(isone(itob(i,bs[q][j]),bs[q][j])==false)
   {
     f=1;
   }
 }
 answer[q]=i-1;
}

for(q=0;q<t;q++)
{
 printf("Case #%d: %d\n", q+1, answer[q]);
}

  return 0;
}

