#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <memory>
#include <sstream>

using namespace std;

#define TOTAL 50000

short isOk[TOTAL + 1][11];

bool isVisited[TOTAL + 1];

int index[TOTAL + 1];

int digit[100],digitNo,base[10],cnt,cnt2;

bool isHappy(int a)
{
	for(int i = 0;i < cnt;i++)
	{
		if(isOk[a][base[i]] == 0) return false;
	}
	return true;
}

int main()
{
	freopen("D:\\VC project\\ForTest\\Debug\\input.in","r",stdin);
	freopen("D:\\VC project\\ForTest\\Debug\\out.txt","w",stdout);
	memset(isOk,-1,sizeof(isOk));
	int t,i,j,i1,c,cur,ans,last;
	string input;
	cin >> t;
	for(i = 2;i <= 10;i++) isOk[1][i] = isOk[i][i] = 1;
	for(i = 2;i <= 10;i++)
	{
		for(j = 2;j <= TOTAL;j++)
		{
			if(isOk[j][i] != -1) continue;
			memset(isVisited,false,sizeof(isVisited));
			cur = j,isVisited[j] = true,index[0] = cur,cnt2 = 1;
			while(1)
			{
				digitNo = 0,last = cur;
				while(cur != 0)
				{
					digit[digitNo++] = cur % i;
					cur /= i;
				}
				for(i1 = 0;i1 < digitNo;i1++) cur += digit[i1] * digit[i1];
				if(isVisited[cur] || isOk[cur][i] == 0) 
				{
					for(i1 = 0;i1 < cnt2;i1++) isOk[index[i1]][i] = 0;
					break;
				}
				else if(isOk[cur][i] == 1) 
				{
					for(i1 = 0;i1 < cnt2;i1++) isOk[index[i1]][i] = 1;
					break;
				}
				isVisited[cur] = true,index[cnt2++] = cur;
			}
		}
	}
	getchar();
	for(c = 1;c <= t;c++)
	{
		ans = -1;
		getline(cin,input);
		istringstream in(input);
		cnt = 0;
		while(in >> base[cnt++])
		{}
		cnt--;
		for(i = 2;i <= TOTAL;i++)
		{
			if(isHappy(i)) {ans = i;break;}
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}