#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
const int maxn=20000000;
int f[maxn][11];
int a[maxn];
bool h[11];
char ch;
int i,j,k,t;
int solve(int n,int base)
{
	int m=0;
	int i;
	if (n==3&&base==2)
	{
		n=3;
	}
	if (n<=maxn&&f[n][base]!=0) return f[n][base];
	while (n!=0)
	{
		m+=(n%base)*(n%base);
		n/=base;
	}
	if (m==1) return 1;
	for (i=0;i<=t;i++)
		if (a[i]==m) return 2;
	t++;
	a[t]=m;
	return solve(m,base);
}
int main()
{
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	memset(f,0,sizeof(f));
	for (i=2;i<=10;i++)
		for (j=1;j<=maxn;j++)
		{
			t=0;
			a[t]=j;
			f[j][i]=solve(j,i);
		}
	cin>>t;
	getline(cin,s);
	for (i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		getline(cin,s);
		memset(h,0,sizeof(h));
		for (ch='2';ch<='9';ch++)
			if (s.find(ch)!=s.npos) h[(int)(ch-'0')]=true;
		if (s.find("10")!=s.npos) h[10]=true;
		for (j=2;j<=maxn;j++)
		{
			bool flag=true;
			for (k=2;k<=10;k++)
				if (h[k]&&f[j][k]==2) flag=false;
			if (flag)
			{
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
