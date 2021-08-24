#include<iostream>
#include<sstream>
using namespace std;

int base[11];
int blen;
int dp[10000000][11];//1 true; 2 false

bool checkb(int re,int bas)
{
	if(re>=10000000)
	{
		printf("check");
		return false;
	}
	if(dp[re][bas]!=0)
	{
		if(dp[re][bas]==1)return true;
		else return false;
	}
	int sum=0,reb=re;
	while(reb>0)
	{
		sum+=(reb%bas)*(reb%bas);
		reb/=bas;
	}
	dp[re][bas]=2;
	if(sum==1||checkb(sum,bas))
	{
		dp[re][bas]=1;
		return true;
	}
	return false;	
}
bool check(int re)
{
	int i,j;
	for(i=blen-1;i>=0;i--)
		if(!checkb(re,base[i]))
			break;
	if(i>=0)
		return false;
	return true;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int cas=1;
	int t,i,j,k;
	scanf("%d",&t);
	string b;
	char c[50];
	gets(c);
	memset(dp,0,sizeof(dp));
	while(t--)
	{
		printf("Case #%d: ",cas);
		cas++;
		gets(c);
		b=c;
		istringstream a(b);
		blen=0;
		while(a>>base[blen])
			blen++;
		int res=2;
		while(!check(res))
			res++;
		printf("%d\n",res);
	}
	return 0;
}
