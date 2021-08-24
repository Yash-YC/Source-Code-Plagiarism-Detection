#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
void GetBaseNumber(int n10Number , int nBase, int * result,int &nPos)
{
	nPos = 0;
//	int * temp = result;
	while(n10Number > 0 )
	{
		result[nPos++] = n10Number % nBase;
		n10Number /= nBase;
	}
}
bool CheckHappy(int nNumber , int nBase)
{
	bool bRes = true;
	int nNumberList[64] = {0};
	int nTempNum = nNumber;
	vector<int> verLastNumber;
	int nPos = 0;
	int i = 0;
	while(true)
	{
		GetBaseNumber(nTempNum,nBase,nNumberList,nPos);
		nTempNum = 0 ;
		for(i = 0 ; i < nPos ; ++i)
		{
			nTempNum += nNumberList[i] * nNumberList[i];
		}		
		if(nTempNum == 1)
		{
			bRes = true;
			break;
		}
		else 
		{
			for(i = 0 ; i < verLastNumber.size(); ++i)		
			{
				if(verLastNumber [i] == nTempNum)
				{
					return false;
				}
			}
		}
		verLastNumber.push_back( nTempNum );
	}
	return bRes;
}
int main(int argc, char ** argv)
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int nBaseList[32] = {0};
	int nt = 1;
	int i = 0 ;
	int j = 0 ;
	int nPos = 0;
	for(nt =1 ; nt <= T ; ++nt)
	{
		nPos = 0;
		while(true)
		{
			scanf("%d",&nBaseList[nPos++]);
			char ch = getchar();
			if(ch == '\n')
				break;
		}
		for( i = 2;true ;++i)
		{
			for( j = 0; j < nPos ; ++j)
			{
				if(false == CheckHappy(i,nBaseList[j]))
				{
					break;
				}
			}
			if(j == nPos)
			{
				break;
			}
		}
		printf("Case #%d: %d\n",nt,i);
	}
	return 0;
}