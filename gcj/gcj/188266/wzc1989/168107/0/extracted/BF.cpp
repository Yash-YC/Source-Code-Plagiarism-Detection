#include<iostream>
#include<sstream>

using namespace std;

typedef long long ll;

const int MAXN=1000000;


ll mask[50];
int arr[100],parr;
int Occ[MAXN];
ll ans[50000];

bool test(ll num,int base)
{
	ll pre;
	int i;
	int tim=20;
	while (tim--)
	{
		pre=num;
		parr=0;
		while (num)
		{
			arr[parr++]=num%base;
			num/=base;			
		}
		num=0;
		for (i=parr-1;i>=0;i--) num+=arr[i]*arr[i];
		if (num==1) return true;	
		pre=num;
	}
	return false;
}

bool Ok(ll num,ll state)
{
	int i;
	for (i=0;mask[i]<=state;i++)
			if (mask[i]&state && !test(num,i+2))
				return false;
	return true;
}

ll Solve(int state)
{
	ll num;

	for (num=2;;num++)if (Ok(num,state)) break;
	return num;
}


char st[100];

int main()
{
	int i,j;
	int state=0;
	int t,v;

	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);

	mask[0]=1;
	for (i=1;i<50;i++)
		mask[i]=mask[i-1]*2;

	//for (i=1;i<mask[9];i++) ans[i]=Solve(i);

	/*printf("{");
	for (i=1;i<mask[9];i++)
	{
		printf("%lld,",ans[i]);
	}
	printf("};\n");*/


	int cas=0;
	scanf("%d",&t);
	gets(st);
	while (t--)
	{
		cas++;
		gets(st);
		stringstream ssin(st);
		state=0;
		while (ssin>>v)  state|=mask[v-2];	
		printf("Case #%d: %d\n",cas,Solve(state));
	}
	
	return 0;
}