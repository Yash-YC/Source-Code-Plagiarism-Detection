#include <vector>
#include <string>
#include <list>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>
#include <sstream>
#include<iostream>
using namespace std;
long long squresum(int num,int dec)
{
	long long res = 0;
	while(num != 0)
	{
		long long tmp = (long long)(num % dec);
		res += tmp * tmp;
		num /= dec;
	}
	return res;
}

int T;
char s[501];
vector <int> decV;
map <int,int> IsFound;
int main()
{
	freopen("..\\A-small-attempt0.in","r",stdin);
	freopen("..\\A-small-attempt0.out","w",stdout);
	char qqq;
	scanf("%d%c",&T,&qqq);
	for(int i = 1;i <= T;i++)
	{
		cin.getline(s,501);
		stringstream stream(s);
		int atmp;
		decV.clear();
		while(stream>>atmp)
		{
			decV.push_back(atmp);
		}
		for(int j = 2;;j++)
		{
			int flag2 = false;
			for(int k = 0;k < decV.size();k++)
			{
				long long btmp = squresum(j,decV[k]);
				IsFound.clear();
				bool flag = true;
				while(btmp != 1)
				{
					btmp = squresum(btmp,decV[k]);
					if(IsFound.find(btmp) != IsFound.end()) {flag = false;break;}
					else IsFound[btmp] = 1;
				}
				if(!(flag && btmp == 1)) flag2 = true;
			}
			if(!flag2)
			{
				printf("Case #%d: %d\n",i,j);
				break;
			}
		}
	}
	return 0;
}