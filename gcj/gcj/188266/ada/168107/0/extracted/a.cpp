#include <iostream>
using namespace std;

int n,c;
char f[10][100000];
int b[20];
void init()
{
	memset(f,0,sizeof(f));
	char a[1000];
	cin.getline(a,999);
	int i,j,k;
	j=1;
	i=0;
	k=0;
	while (a[i])
	{
		if (a[i]==' ')
		{
			b[j]=k;
			k=0;
			while (a[i]==' ') i++;
			if (a[i]) j++;
		}
		k=k*10+a[i]-'0';
		i++;
	}
	b[j]=k;
	b[0]=j;
}
int getnum(int k,int j)
{
	int i,t;
	t=0;
	while (k>0)
	{
		i=k%j;
		k=k/j;
		t+=i*i;
	}
	return t;
}

bool search(int i,int j)
{
	if (f[i][j]==-1) return false;
	if (f[i][j]==2) 
	{
		f[i][j]=-1;
		return false;
	}
	if (f[i][j]==1) return true;
	int k;
	f[i][j]=2;
	k=getnum(j,b[i]);
	if (search(i,k)) 
	{
		f[i][j]=1;
		return true;
	}
	else 
	{
		f[i][j]=-1;
		return false;
	}
}

void make()
{
	int i,j,k;
	for (i=1;i<=b[0];i++) f[i][1]=1;
	for (j=2;true;j++)
	{
		for (i=1;i<=b[0];i++) 
		{
			k=getnum(j,b[i]);
			if (f[i][k]==-1) continue;
		}
		if (i>b[0])
		{
			for (i=1;i<=b[0];i++)
			{
				k=getnum(j,b[i]);
				search(i,k);
				if (f[i][k]==-1)break;
			}
			if (i<=b[0]) continue;
		}
		break;
	}
	cout<<j<<endl;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int cs;
	int i;
	cin>>cs;
	cin.get();
	for (i=1;i<=cs;i++)
	{
		init();
		cout<<"Case #"<<i<<": ";
		make();
	}

	return 0;
}