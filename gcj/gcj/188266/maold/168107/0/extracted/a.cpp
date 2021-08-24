#include <iostream>
using namespace std;

const int cb=600000;
int t,p,i,j,k,m,n;
char c;
bool f[11][cb];
int d[11];
int a[50];
bool b[cb],ok;

void dfs(int j)
{
	int m=j,k=0,n;
	
	if (f[i][j]) {ok=true; return;}
	if (b[j]) return;
	
	b[j]=true;

	while (m>0)
	{
		k++;
		a[k]=m % i;
		m/=i;
	}
	n=0;
	for (m=1; m<=k; m++)
		n+=a[m]*a[m];

		
	if (f[i][n]) {ok=true; f[i][j]=true; return;}	
	
	if (!b[n])
	{
		dfs(n);
		if (ok) {f[i][j]=true; }
	}
	
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	memset(f,false,sizeof(f));
	
	for (i=2; i<=10; i++)
	{
		f[i][1]=true;
		memset(b,false,sizeof(b));
		b[1]=true;
		for (j=2; j<=cb; j++)
		{
			if (f[i][j]) {continue;}
			ok=false;
			dfs(j);
		}
	}
	
//	for (i=1; i<=100; i++)
//		if (f[10][i]) cout << i << endl;
	
	scanf("%d",&t);
	for (p=1; p<=t; p++)
	{
		k=0;
		while (1)
		{
			k++;
			scanf("%d",&d[k]);
			scanf("%c",&c);
			if (c!=' ') break;
		}
		for (j=2; ; j++)
		{
			ok=true;
			for (i=1; i<=k; i++)
				if (!f[d[i]][j]) {ok=false; break;}
			if (ok) {printf("Case #%d: %d\n",p,j); break;}
		}
		
		
	}

//	system("pause");
	return 0;
}
