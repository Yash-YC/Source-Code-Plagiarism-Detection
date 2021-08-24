/*
	A.cpp
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int h[1000000][11];
int c[1000000];

int happy(int n,int b)
{
//	if(n<b) return(n==1)?1:0;
	if(n==1) return 1;

	if(c[n]) return 0;
	
	int m=n;	c[m]=1;
	int next=0;
	while(n)
	{
		int p=n%b; next+=p*p;
		n/=b;
	}
	int ret= happy(next,b);
	c[m]=0;	
	return ret;
}

int main()
{
	memset(h,0,sizeof(h));
	memset(c,0,sizeof(c));
	for(int base=2;base<=10;base++)
	{
		for(int num=2;num<1000000;num++)
			h[num][base]=happy(num,base);
	}
	//cout<<h[91][9]<<" "<<h[91][10]<<"\n";
	//cout<<h[3][2]<<" "<<h[3][3]<<"\n";

	int tc;
	cin>>tc;
	cin.ignore(1,'\n');

	for(int cases=1;cases<=tc;cases++)
	{
		string s; getline(cin,s);// cout<<"s="<<s;
		stringstream ss(s);
		
		int arr[11];
		for(int i=0;i<11;i++) arr[i]=0;
		int n;
		while(ss>>n){ arr[n]=1; }
		
		int ans=-1;
		for(int num=2;num<1000000;num++)
		{
			int base=10;
			for(;base>=2;base--)
				if(arr[base]&&!h[num][base]) break;
			if(base==1){ ans=num; break; }
		}
		printf("Case #%d: %d\n",cases,ans);
		
	}
}
