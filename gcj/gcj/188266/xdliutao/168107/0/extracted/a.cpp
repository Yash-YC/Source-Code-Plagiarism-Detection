#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MAX = 12;
bool visit[999999];

int GetNum(int num, int base)
{
	int ans, n;
	ans = 0;
	while(num)
	{
		n = num%base;
		ans += n*n;
		num /= base;
	}
	return ans;
}

bool Happy(int n, int b)
{
	int i = GetNum(n, b);
	if(i == 1)
		return true;
	else if(visit[i])
		return false;
	else 
	{
		visit[i] = 1;
		if(Happy(i, b))
			return true;
		else
			return false;
	}
}

int main()
{
	int i, t, j, cases, l, cnt, ret;
 	freopen("ain.txt","r",stdin);
 	freopen("aout.txt","w",stdout);
	scanf("%d",&t);
	cases = 0;
	char str[MAX*MAX];
	int bas[MAX];
	getchar();
	while(t--)
	{
		gets(str);
		l = strlen(str);
		cnt = 0;
		for (i = 0; i < l;)
		{
			if(i == l-1 || str[i+1] == ' ')
			{
				bas[cnt++] = str[i]-'0';
				i = i+2;
			}
			else
			{
				bas[cnt++] = 10;
				i = i+3;
			}
		}
		for (i = 2; ;i++)
		{
			for (j = 0; j < cnt; j++)
			{
				memset(visit, 0, sizeof(visit));
				if(!Happy(i, bas[j]))
					break;
			}
			if(j == cnt)
			{
				ret = i;
				break;
			}
		}
		printf("Case #%d: %d\n",++cases, ret);
	}
	return 0;
}