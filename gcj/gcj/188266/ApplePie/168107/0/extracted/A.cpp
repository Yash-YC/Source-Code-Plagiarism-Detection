#define _BACKWARD_BACKWARD_WARNING_H
#include <strstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;

int iBaseCnt;
int baseNum[15];
set<int> iSet;
void Input();
void Work(int iCase);
bool IsHappyNumber(int num,int base);
int F(int num,int base);

int main()
{
	int t,i;
	scanf("%d",&t);
	cin.get();
	for(i=1;i<=t;++i)
	{
		Input();
		Work(i);
	}
}

void Work(int iCase)
{
	int iNum,i;
	bool flag;
	iNum=2;
	flag=true;
	while(flag)
	{
		flag=false;
		for(i=0;i<iBaseCnt;++i)
			if( !IsHappyNumber(iNum, baseNum[i]))
			{
				flag=true;
				break;
			}
		if(flag)
			++iNum;
	}
	printf("Case #%d: %d\n",iCase,iNum);
}

bool IsHappyNumber(int num, int base)
{
	int res;
	iSet.clear();
	set<int>::iterator pos;
	res=F(num,base);
	iSet.insert(res);
	if(res==1) return true;
	while(res!=1)
	{
		res=F(res,base);
		pos=iSet.find(res);
		if(pos==iSet.end())
		{
			iSet.insert(res);
		}
		else
			return false;
	}
	return true;
}

int F(int num,int base)
{
	int res=0,t;
	while(num)
	{
		t=num%base;
		res+=t*t;
		num/=base;
	}
	return res;
}

void Input()
{
	int num;
	iBaseCnt=0;
	char str[100];
	cin.getline(str,100);
	istrstream iss(str,100);
	while(iss >> num)
	{
		baseNum[iBaseCnt++]=num;
	}
	int i;
}
