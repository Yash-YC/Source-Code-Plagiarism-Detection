#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;

vector<int> dig;
vector<int> num;
bool com(int n,int k)
{
	int i,j;
	num.resize(0);
	num.push_back(n);
   while(1)
   {
	   dig.resize(0);
	 while(n>0)
	 {
		 dig.push_back(n%k);
		 n/=k;
	 }
	 if(dig.size()==1&&dig[0]==1)
		 return true;
		n=0;
		for(i=dig.size()-1;i>=0;i--) n+=dig[i]*dig[i];
		for(j=0;j<num.size();j++)
		{
	//		printf(" %d\n",num[j]);
			if(n==num[j])
		{
	//		printf("%d\n",n);
			return false;
		}
		}
		num.push_back(n);
   }
}

int main()
{
   int t,i,j,k;
   int b[20];
   char a[100];
freopen("A-small-attempt0.in","r",stdin);
freopen("1.out","w",stdout);
   scanf("%d",&t);
   getchar();
   for(i=1;i<=t;i++)
   {
	   gets(a);
	   int l=0,r=0,x;
	   while(r<strlen(a))
	   {
		   sscanf(a+r,"%d%n",&b[l++],&x);
	   r+=x;
	   }
	//   printf("%d\n",l);
	//   for(i=0;i<l;i++) printf("%d ",b[i]);
	//   printf("\n");
	   for(j=2;;j++)
	   {
		   bool f=true;
		   for(k=0;k<l;k++) f=f&&com(j,b[k]);
		   if(f) break;
	//	   printf("%d\n",j);
	   }
	   printf("Case #%d: %d\n",i,j);
   }
   return 0;
}
	  
  