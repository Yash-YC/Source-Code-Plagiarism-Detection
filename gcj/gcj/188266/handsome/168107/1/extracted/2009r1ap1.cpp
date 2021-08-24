#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define PI 3.14159265358979323846264338327950288


#define N 1000
#define INF 99999999999

char happy[12][99999999] = {0};
int stack[1000];
int top = 0;

bool check(int num, int base)
{
	int sum;
	int pre = 1;
	top = 0;
	while(happy[base][num]==0)
	{
		happy[base][num] = 2;
		stack[top++] = num;
		sum = 0;
		while(num)
		{
			int t = num % base;
			sum += t*t;
			num /= base;
		}
		num = sum;
	}
	if(num == 1)
	{
		while(top)
		{
			happy[base][stack[--top]] = 1;
		}
		return true;
	}
	if(happy[base][num] == 2)
	{

		while(top)
		{
			happy[base][stack[--top]] = -1;
		}
		return false;
	}
	while(top)
	{
		happy[base][stack[--top]] = happy[base][num];
	}
	if(happy[base][num] == 1)
		return true;
	else return false;
}


int main()
{

//	freopen("in.txt", "r", stdin);

	int n, count=1;
	scanf("%d", &n);
	char buf[500];
	fgets(buf, 500, stdin);
	while(n--)
	{
		
		fgets(buf, 500, stdin);
		int l=0;
		int c=0;
		int vec[11];
		while(sscanf(buf + l, "%d ", &vec[c++])!=EOF)
		{
			l += 2;
		}
		--c;
		int co = 2;
		while(1)
		{
			int i;
			for(i=0;i<c;++i)
			{
				if(!check(co, vec[i])) break;
			}
//			printf("%d %d\n", co, vec[i]);
			if(i==c) break;
			++co;
		}
		printf("Case #%d: %d\n", count++, co);
	}

	return 0;
}
