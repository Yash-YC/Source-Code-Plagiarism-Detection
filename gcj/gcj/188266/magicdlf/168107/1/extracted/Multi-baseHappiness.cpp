// Multi-baseHappiness.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "sstream"
using namespace std;

#define N 50000
char g[11][N] = {};


int toBase(int num, int base)
{
	vector<int> ans;
	if(num==0) return 0;
	while(num>0)
	{
		int k=num%base;
		num/=base;
		ans.push_back(k);
	}
	int ret=0;
	for(int i=ans.size()-1;i>=0;i--)
	{
		ret=ret*10;
		ret+=ans[i];
	}
	return ret;
}

int isHappy(int n, int base)
{
	int ret=0;
	if(n<N && g[base][n]!=0) return g[base][n];
	int cur=toBase(n,base);
	while(cur>0)
	{
		int k=cur%10;
		cur=cur/10;
		ret=ret+k*k;
	}
	if(ret==1) return 2;
	g[base][n]=1;
	int r= isHappy(ret,base);
	g[base][n]=r;
	return r;
}

int find(vector<int> base)
{
	int cur=2;
	while(1)
	{
		cur++;
		int found = 1;
		for(int i=0;i<base.size();i++)
		{
			if(isHappy(cur,base[i])!=2) 
				found=0;
		}
		if(found)
			return cur;
	}
}

int main()
{
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<11;j++)
			g[j][i]=0;
	}
	int T;
	cin>>T;
	char buf[256];
	cin.getline(buf,256);
	for(int i=0;i<T;i++)
	{
		cin.getline(buf,256);
		string str(buf);
		stringstream ss(str);
		int n;
		vector<int> base;
		while(ss>>n)
		{
			base.push_back(n);
		}
		int ret=find(base);
		cout<<"Case #"<<i+1<<": "<<ret<<endl;
	}
}