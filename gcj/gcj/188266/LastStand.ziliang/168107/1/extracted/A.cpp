#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

//bool user[15000000];
//
//bool test(int n, int b)
//{
//	memset(used,0,sizeof(used));
//	while(true)
//	{
//		if(used[n]==1)return 0;
//
//		used[n]=1;
//		int nn=0;
//		while(n)
//		{
//			nn += (n%b)*(n%b);
//			n/=b;
//		}
//
//		n=nn;
//
//		if(n==1)return 1;
//	}
//}

int main()
{
	freopen("ans.txt","r",stdin);
	int ans[1200];
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		ans[a]=b;
	}

	freopen("a2in.txt","r",stdin);
	freopen("a2out.txt","w",stdout);


	int T;
	cin>>T;
	char str[10000];
	gets(str);
	for(int t=1;t<=T;t++)
	{
		gets(str);
		stringstream ss(str);

		int bt=0;
		int in;
		while(ss>>in)
		{
			bt |= (1<<(in-2));
		}

		cout<<"Case #" << t <<": " << ans[bt] <<endl;
	}
}
