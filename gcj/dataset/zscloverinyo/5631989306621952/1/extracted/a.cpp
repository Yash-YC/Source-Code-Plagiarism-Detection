#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int T;
char s[1005];
string ss;
int len,dq,now;
int ans[1005];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int z=1;z<=T;++z)
	{
		scanf("%s",s+1);
		printf("Case #%d: ",z);
		len=strlen(s+1);
		dq=len;
		while (dq>=1)
		{
			now=dq;
			for (int i=dq;i>=1;--i) if (s[i]>s[now]) now=i;
			for (int i=now+1;i<=dq;++i) ans[i]=2;
			ans[now]=1;
			dq=now-1; 
		}
		ss="";
		ss+=s[1];
		for (int i=2;i<=len;++i)
		{
			if (ans[i]==2) ss=ss+s[i];
			else ss=s[i]+ss;
		}
		cout<<ss<<endl;
	}
	return 0;
}
