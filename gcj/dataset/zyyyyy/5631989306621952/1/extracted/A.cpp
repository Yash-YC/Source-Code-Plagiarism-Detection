#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,t,i,j;
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		char s[1010],ss[1010];
		scanf("%s",s);
		int l=strlen(s);
		bool ins[l];
		for (i=0;i<l;i++) ins[i]=1;
		int k=0;
		ss[0]=s[0];
		ins[0]=0;
		for (i=1;s[i];i++)
			if (s[i]>=ss[k]) ss[++k]=s[i],ins[i]=0;
		printf("Case #%d: ",t);
		for (i=k;i>=0;i--) putchar(ss[i]);
		for (i=0;i<l;i++)
			if (ins[i]) putchar(s[i]);
		puts("");
	}
	return 0;
}
