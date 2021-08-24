#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

const int Max = 11;
const int MaxResult = 1000000;
int suc[Max][MaxResult];
int state[Max][MaxResult];//0 for unvisited, 1 for visited, 2 for good
int next(int num,int base)
{
	int result = 0;
	for(;num;num/=base)
	{
		int t = num%base;
		result += t*t;
	}
	return result;
}
void computestate(int num,int base)
{
	if(state[base][num] == 0)
	{
		state[base][num] = 1;
		int t = suc[base][num];
		computestate(t,base);
		if(state[base][t] == 2)
			state[base][num] = 2;
	}
}
int main()
{
	int T;
	scanf("%d\n",&T);
	char line[1000];
	for(int i=2;i<Max;i++)
	{
		state[i][0] = 1;
		state[i][1] = 2;
		for(int j=1;j<MaxResult;j++)
		{
			int t = next(j,i);
			if(t < MaxResult) suc[i][j] = t;
		}
	}
	for(int i=2;i<Max;i++)
		for(int j=1;j<MaxResult;j++)
			computestate(j,i);
	for(int cases=1;cases<=T;cases++)
	{
		gets(line);
		istringstream sin(line);
		int base[Max],bases;
		for(bases=0;sin>>base[bases];bases++);
		bool cont = true;
		int i;
		for(i=2;cont;i++)
		{
			cont = false;
			for(int j=0;j<bases;j++)
				if(state[base[j]][i] != 2)
					cont = true;
		}
		printf("Case #%d: %d\n",cases,--i);
	}
	return 0;
}
