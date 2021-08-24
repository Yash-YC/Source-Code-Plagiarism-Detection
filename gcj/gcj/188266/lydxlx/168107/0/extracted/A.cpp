#include <iostream>
using namespace std;
#define tiao system("pause")

const int MAX = 100000;
int is[11][MAX+1];
int n;
int t;
int base[11];
int lenBase;
bool used[MAX+1];
int nowBase;
int cnmb = false;

bool dfs(int i)
{
//	if (nowBase == 10)
//	{
//		cout << i; tiao;
//	}
	if (i == 1) return true;
	if (used[i]) 
	{
		if (is[nowBase][i] == 1) return true;
		else return false;
	}
	
	used[i] = true;
	int sum(0),j = i;
	while(j > 0)
	{
		sum += (j % nowBase) * (j % nowBase);
		j /= nowBase;
	}
//	if (nowBase == 10) { cout << i << ' ' << sum; tiao; }
		
	if (dfs(sum)) 
	{
		is[nowBase][i] = 1;
		return true;
	}
	else
	{
		is[nowBase][i] = 0;
		return false;
	}
}

void init(void)
{
	int i,j,k,ci,cici,cicici;
	
	memset(is,-1,sizeof(is));
	
	for (i=2; i<=10; i++)
	{
		nowBase = i;
		memset(used,0,sizeof(used));
		for (j=2; j<=MAX; j++)
		{
			if (is[i][j] != -1) continue;
			dfs(j);
		}
	}	
}
int main(void)
{
	int i,j,k,ci,cici,cicici;
	bool isOK;
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	init();
	
//	for (i=1; i<=100; i++)
//	{
//		if (is[10][i] == 1) cout << i << endl;
//	}
	
	scanf("%d",&t);
	for (int wb=1; wb<=t; wb++)
	{
		lenBase = 0;
		while(scanf("%d",&ci))
		{
			base[++lenBase] = ci;
			if (getchar() != ' ') break;
		}		
		
		for (i=2; i<=MAX; i++)
		{
			isOK = true;
			for (j=1; j<=lenBase; j++)
				if (is[base[j]][i] != 1)
				{
					isOK = false;
					break;
				}
			if (isOK)
			{
				printf("Case #%d: %d\n",wb,i);
				break;
			}
		}		
	}
//	tiao;
	return 0;
}
