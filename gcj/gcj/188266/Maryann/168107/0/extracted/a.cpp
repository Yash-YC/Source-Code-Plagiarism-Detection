#include<stdio.h>
#include<set>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
bool f[11][1000];
int n,ans,a[10];
set<int> s;
int sqr(int x){return x*x;}
int cc(int x,int b)
{
	int r=0;
	while(x)
	{
		r+=sqr(x%b);
		x/=b;
	}
	return r;
}
bool check(int x,int b)
{
	if(x==1)return true;
	if(s.find(x)!=s.end())return false;
	s.insert(x);
	return check(cc(x,b),b);
}
int main()
{
	int i,b,_;
	string ss;
	for(b=2; b<=10; b++)
	for(i=1; i<1000; i++)
	{
		s.clear();
		f[b][i]=(check(i,b));
	}
	cin>>_;getline(cin,ss);
	for(int t=1; t<=_; t++)
	{
		getline(cin,ss);
		istringstream sin(ss);
		for(n=0; sin>>a[n]; )
			if(a[n]!=2 && a[n]!=4)n++;
		bool flag=true;
		for(ans=2; flag; ans++)
		{
			flag=false;
			for(int i=0; i<n && !flag; i++)
				if(!f[a[i]][cc(ans,a[i])])
					flag=true;
		}
		printf("Case #%d: %d\n",t,ans-1);
	}
	return 0;
}
