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

bool tb[11][1000001];

bool is(int a[20],int base,int index,int shu)
{
	int i,tmp = 1;
	
	int t=100;
	while(t--)
	{
		tmp = 0;
		for(i=index;i>=0;i--)
		{
			tmp+=a[i]*a[i];
		}
		
		if(tmp == 1)return true;
		if(tmp<=shu)return tb[base][tmp];
		index=0;
		while(tmp)
		{
			a[index++]=tmp%base;
			tmp/=base;
		}
		//if(a[index-1]==0)a[index]=1;
		index--;
	}
	return false;
}
void solve(int i,int j)
{
	int a[20]={0};
	int tmp=i;
	int index=0;
	while(tmp)
	{
		a[index++]=tmp%j;
		tmp/=j;
	}
	index--;
	if(is(a,j,index,i))
		tb[j][i]=true;
	return ;
}
int main()
{
	freopen("ain.txt","r",stdin);
	freopen("aout.txt","w",stdout);
	memset(tb,0,sizeof(tb));
	int i,j;
	for(i=2;i<1000001;i++)
	{
		for(j=2;j<=10;j++)
			solve(i,j);
	}
	int T;
	scanf("%d",&T);
	getchar();
	char buffer[1024];
	for(i=1;i<=T;i++)
	{
		gets(buffer);
		stringstream ss(buffer);
		vector<int>vi;
		int a=0;
		while(ss>>a)
			vi.push_back(a);
		for(j=2;j<1000001;j++)
		{
			int k;
			for(k=0;k<vi.size();k++)
				if(!tb[vi[k]][j])break;
			if(k<vi.size()) continue;
			else
			{
				printf("Case #%d: %d\n",i,j);
				goto x;
			}
		}
		printf("no\n");
		x:;
	}
}