#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

const int maxn = 60000;

map<int,int> happy[15];
int a[20];
map<int, bool> p;

bool can(int x, int base)
{
	if (happy[base][x]!=0) return happy[base][x]==1;
	if (p[x]) return false;
	p[x]=true;
	int num=x, y=0;
	while (x>0)
	{
		y+=(x%base)*(x%base);
		x/=base;
	}
	if (can(y, base))
	{
		happy[base][num]=1;
		return true;
	}
	else 
	{
		happy[base][num]=-1;
		return false;
	}
}

int main()
{
	int i, j, T, n, cas=0;
	char str[100];
	
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	for (j=2; j<=10; j++)
	{
	  happy[j].clear();		
	  happy[j][1]=1;
	}
	for (i=2; i<maxn; i++)
	{
//		printf("%d\n", i);
		for (j=2; j<=10; j++)
		{
		  if (happy[j][i]!=0) continue;
		  p.clear();
		  can(i, j);
		}
	}
//	printf("OK\n");
	scanf("%d\n", &T);
while (T--)
{
	gets(str);
	i=0;
	n=0;
	memset(a,0, sizeof(a));
	while (true)	
	{
		if (str[i]=='\0' || str[i]==' ') n++;
		else a[n]=a[n]*10+str[i]-'0';
		if (str[i]=='\0') break;
		i++;
	}
	for (i=2; i<maxn; i++)
	{
	  for (j=0; j<n; j++)
	    if (happy[a[j]][i]<=0) break;
	  if (j==n) break;   
	}
	printf("Case #%d: ", ++cas);
	if (i==maxn) printf("can't find!\n");
	else printf("%d\n", i);
}
	return 0;
}
/*
2
9
2 3 4 5 6 7 8 9 10

*/
