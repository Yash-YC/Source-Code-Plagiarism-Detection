#include<bits/stdc++.h>
using namespace std;
const int maxn=2500+5;
int n, a[maxn];
void run()
{
	memset(a,0,sizeof a);
	scanf("%d",&n);
	for(int i=0;i<2*n-1;i++)
		for(int j=0, x;j<n;j++)
		{
			scanf("%d",&x);
			a[x]++;
		}
	for(int i=1;i<maxn;i++) if(a[i]&1) printf(" %d",i);
}
int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d:",++cas);
		run();
		puts("");
	}
	return 0;
}

