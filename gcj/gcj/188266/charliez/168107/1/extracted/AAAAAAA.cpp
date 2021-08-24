#include <iostream>
#include<cstring>
using namespace std;

char str[2000];
int b[10], N;
int dp[12000000][11];


int F(int n, int base)
{
	
	int &ret = dp[n][base];
	
	if(n == 1)
		return ret = 1;
	if(ret == 0 || ret == 1)
		return ret;
	if(ret == 2)
		return ret = 0;
		
	ret = 2;
	int tr = 0;
	int tn = n, c;
	while(n)
	{
		c = n % base;
		n /= base;
		tr += c * c;
	}
	return ret = F(tr, base);
}
int main()
{
	freopen("A_Large.in", "r", stdin);
	freopen("A_Large.out", "w", stdout);
int Case, Case_Num;
	int t;
	int i, j, k;
	char*tmp;
	memset(dp, -1, sizeof(dp));
	for(i = 2; i < 12000000; i++)
		for(j = 2; j < 11; j++)
			F(i, j);
			
    scanf("%d", &Case_Num); getchar();
    
    for(Case = 1; Case <= Case_Num; ++Case)
	{

		gets(str);
		N = 0;
		for(tmp = strtok(str, " "); tmp; tmp = strtok(NULL, " "))b[N++] = atoi(tmp);

		for(i = 2; ; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(!dp[i][ b[j] ])
					break;
			}
			if(j >= N) break;
		}
		printf("Case #%d: %d\n", Case, i);
	}

}
