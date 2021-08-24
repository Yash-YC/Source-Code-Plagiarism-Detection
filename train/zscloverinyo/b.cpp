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

int T,n;
int x,num[2505];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for (int i=1;i<=2*n-1;++i)
		{
			for (int j=1;j<=n;++j) 
			{
				scanf("%d",&x);
				num[x]++;
			}
		}
		printf("Case #%d:",z);
		for (int i=1;i<=2500;++i) if (num[i]%2==1) printf(" %d",i);
		printf("\n");
	}
	return 0;
}
