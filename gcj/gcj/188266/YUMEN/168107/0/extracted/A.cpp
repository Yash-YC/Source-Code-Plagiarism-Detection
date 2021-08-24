#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
#include <string.h>
using namespace std;

char use[1 << 20];
bool ok[1 << 20];
bool ye[11][1 << 17];
int B;
vector<int> mb;

int check(int n)
{
	int s,t;
	if(use[n] != -1)
		return use[n];
	if(ok[n])
	{
		use[n] = 0;
		return 0;
	}
	ok[n] = true;
	if(n == 1)
		return 1;
	s = n,t = 0;
	while(s)
		t += (s%B)*(s%B),s/=B;
	use[n] = check(t);
	return use[n];
}

int main()
{
	int T,b,i,j,t;
	char str[1 << 10];
	//freopen("A-small-attempt2.in","r",stdin);
	//freopen("A.txt","w",stdout);
	memset(ye,false,sizeof(ye));
	for(B = 2;B <= 10;B++)
	{
		memset(ok,false,sizeof(ok));
		memset(use,-1,sizeof(use));
		use[1] = 1;
		for(i = 1;i <= 100000;i++)
		{
			if(check(i))
				ye[B][i] = true;
		}
	}
	scanf("%d\n",&T);
	for(t = 1;t <= T;t++)
	{
		gets(str);
		//puts(str);
		mb.clear();
		for(i = 0;i < strlen(str);)
		{
			b = 0;
			for(;i < strlen(str) && str[i] != ' ';i++)
				b = b*10 + str[i] - '0';
			mb.push_back(b);
			i++;
		}
		printf("Case #%d: ",t);
		for(i = 2;i <= 100000;i++)
		{
			for(j = 0;j < mb.size();j++)
			{
				if(!ye[mb[j]][i])
					break;
			}
			if(j == mb.size())
			{
				printf("%d\n",i);
				break;
			}
		}
		if(i == 10001)
			printf("NO\n");
	}	
	return 0;
}
	
	
