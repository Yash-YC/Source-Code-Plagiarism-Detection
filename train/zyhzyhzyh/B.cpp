#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int T,n,cnt[2510],x,ans[51];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d:",_);
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		int tot=0;
		for(int i=1;i<n*2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&x);
				cnt[x]++;
			}
		}

		for(int i=1;i<=2500;i++)
			if (cnt[i]&1) ans[++tot]=i;
		sort(ans+1,ans+n+1);
		for(int i=1;i<=n;i++) printf(" %d",ans[i]);
		printf("\n");
	}
}

