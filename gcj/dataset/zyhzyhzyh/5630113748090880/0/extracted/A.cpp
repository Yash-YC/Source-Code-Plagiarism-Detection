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
char s[1010];
bool vis[1010];
int T,l;
char fi;
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
		printf("Case #%d: ",_);
		scanf("%s",s);
		l=strlen(s);
		for(int i=0;i<l;i++) vis[i]=0;
		for(;!vis[0];)
		{
			char Max=s[0];int num=0;
			for(int j=1;j<l&&!vis[j];j++)
			{
				if (s[j]>=Max) 
				{
					Max=s[j];num=j;
				}
			}
			vis[num]=1;printf("%c",Max);
		}
		for(int i=0;i<l;i++) if (!vis[i]) printf("%c",s[i]);
		printf("\n");
	}
}
