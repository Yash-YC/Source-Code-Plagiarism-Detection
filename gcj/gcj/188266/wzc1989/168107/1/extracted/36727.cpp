#include<iostream>
#include<sstream>

using namespace std;

typedef long long ll;

int mask[31];
int arr[100],parr;
int ans[50000];




bool test(int num,int base)
{
	int pre;
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

bool F[200][12];

void BF()
{
	int i,j;
	memset(F,0,sizeof(F));
	for (i=2;i<=10;i++)
		F[1][i]=true;
	for (j=2;j<=10;j++)
		for (i=2;i<200;i++)
		{		
			if (test(i,j))
				F[i][j]=true;
		}
}

bool Ok(int num,int state)
{
	int i,j;
	int base;
	int tmp;
	for (i=0;mask[i]<=state;i++)
		if (mask[i]&state)
		{
			base=i+2;
			parr=0;
			tmp=num;
			while (num)
			{
				arr[parr++]=num%base;
				num/=base;			
			}
			num=0;
			for (j=parr-1;j>=0;j--) num+=arr[j]*arr[j];
			if (!F[num][base]) return false;
			num=tmp;
		}
	return true;
}

int Solve(int state)
{
	if (ans[state]!=-1) return ans[state];
	int num=2;
	for (;;num++) if (Ok(num,state)) break;
	return ans[state]=num;
}



char st[100];

int main()
{
	int i,j;
	int state=0;
	int t,v;

	freopen("in","r",stdin);
	freopen("out","w",stdout);

	mask[0]=1;
	for (i=1;i<31;i++)
		mask[i]=mask[i-1]*2;


	BF();

	memset(ans,-1,sizeof(ans));

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