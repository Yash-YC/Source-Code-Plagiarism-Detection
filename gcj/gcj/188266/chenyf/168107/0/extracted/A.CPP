#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int hash[10001];
int chash[10001];
int r[11][10001];
int num[100];
int basev[10];
bool dfs(int value, int base)
{
	if(hash[value])
		return true;
	int tmp = value;
	int cnt = 0;
	int nexttmp = 0;
	while(1)
	{
		num[cnt++] = tmp % base;
		nexttmp += (num[cnt-1] * num[cnt-1]);
		tmp /= base;
		if (tmp == 0 )
			break;
	}
	if( !chash[nexttmp] )
	{
		chash[nexttmp] = 1;
		hash[value] = dfs(nexttmp, base);
		return hash[value];
	}
	else 
	{
		return false;
	}
}
char str[100];
int main()
{
	freopen("A-small-attempt1.in","r", stdin);
	freopen("out.txt","w", stdout);
	int i, j;
	memset(r, 0, sizeof(r));
	for(i = 2; i <= 10; i ++)
	{
		memset(hash, 0, sizeof(hash));
		hash[1] = 1;
		int cnt = 0, tmp;
		for(j = 2;  j <= 10000;  j ++)
		{
			memset(chash, 0, sizeof(chash));
			chash[j] = 1;
			if(dfs(j, i))
			{
				r[i][j] = 1;
			}
		}
	}
	int t;
	scanf("%d", &t);
	getchar();
	char tmp[2];
	int caseno = 0;
	for(i = 2;  i <= 10; i ++)
		r[i][1] = 1;
	while(t--)
	{
		gets(str);
		int basenum = 0;
		for(i = 0; str[i] != '\0'; i ++)
		{
			if(str[i] == ' ')
				continue;
			if( str[i]  != ' ' && (str[i + 1] == ' ' || str[i+1] == '\0') )
			{
				basev[basenum++] = str[i] - '0';
			}
			else 
			{
				basev[basenum++] = 10;
				i ++ ;
			}
		}

		for(i = 2; ; i ++ )
		{
			for(j = 0; j < basenum; j ++ )
			{
				int nexttmp = 0, cnt = 0;
				int tmp = i;
				while(1)
				{
					num[cnt++] = tmp % basev[j];
					nexttmp += (num[cnt - 1] *  num[cnt-1]);
					tmp = tmp / basev[j];
					if( tmp == 0 )
						break;
				}
				if(! r[basev[j]][nexttmp])
					break;
			}
			if( j == basenum)
			{
				printf("Case #%d: %d\n", caseno + 1,i );
				caseno ++;
				break;
			}
		}
	}
	
}