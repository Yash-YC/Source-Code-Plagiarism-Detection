#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
#define MAXN 1000000
#define MAX(a,b) ((a)>(b)?(a):(b))

int t;
int n,ans;
int base;
int num[10];
bool hash[11][MAXN] = {0};
int f[11][MAXN] = {0};
bool happy[11][MAXN] = {0};

bool dp(int x)
{
	if(hash[base][x])
		return happy[base][x];
	hash[base][x] = true;
	int tmp = x%base;
	dp(x/base);
	f[base][x] = f[base][x/base]+tmp*tmp;
	return happy[base][x] |= dp(f[base][x]);
}

void pre()
{
	for(int i = 2; i <= 10; i++)
	{
		base = i;
		hash[i][1] = true;
		f[i][1] = 1;
		happy[i][1] = true;
		for(int j = 1; j < MAXN; j++)
			dp(j); 
	}
}

void init()
{
	char s[256];
	int tmp;
	gets(s);
	stringstream ss;
	n = 0;
	ss << s;
	while(ss>>tmp)
		num[n++] = tmp;
} 

void solve()
{
	int i,j;
	for(i = 2; i < MAXN; i++)
	{
		for(j = 0; j < n; j++)
			if(!happy[num[j]][i])
				break;
		if(j==n)
		{
			ans = i;
			break;
		}
	}
}

void print()
{
	printf("Case #%d: %d\n",t+1,ans);
}

int main(void)
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
	pre();
	int T;
	scanf("%d\n",&T);
	for(t = 0; t < T; t++)
	{
		init();
		solve();
		print();
	}
    return 0;
}
