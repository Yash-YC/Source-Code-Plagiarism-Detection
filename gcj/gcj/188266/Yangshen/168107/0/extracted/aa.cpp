#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stdio.h>
using namespace std;
char str[1000];
int b[100],num;
bool used[100001];
bool check(int x,int b)
{
	int tt=0,tp,temp=0;
	memset(used,false,sizeof(used));
	used[x]=true;
	 while(x>1)
	 {
	 	 temp=0;
	     while(x)
	     {
	        temp+=(x%b)*(x%b);
			x/=b;
	     }
	     x=temp;
	     if(used[x])
	        return false;
          used[x]=true;
	 }
	 if(x==1)
	    return true;
     return false;
}
int main()
{
	int tst=0,t,i,j,len;
	freopen("A.in","r",stdin);
	freopen("fuck.out","w",stdout);
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		tst++;
	    gets(str); 
	    num=0;
	    memset(b,0,sizeof(b));
		len=strlen(str);
	    for(i=0;i<len;i++)
	    {
	    	if(str[i]==' ')
	    	  num++;
   	        else if(str[i]>='0'&&str[i]<='9')
   	          b[num]=10*b[num]+str[i]-'0';
	    }
	    num++;
	    for(i=2;;i++)
	    {
	    	for(j=0;j<num;j++)
	    	{
	    		if(!check(i,b[j]))
	    		   break;
	    	}
	    	if(j>=num)
	    	  break;
	    }
	    printf("Case #%d: %d\n",tst,i);
	}
	return 0;
}
