/*#include<stdio.h>
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
int con[7]={3,5,6,7,8,9,10};
int main()
{
	int i,b,_,j;
	string ss;
	for(b=2; b<=10; b++)
	for(i=1; i<1000; i++)
	{
		s.clear();
		f[b][i]=(check(i,b));
	}
	for(i=0; i<128; i++)
	{
		n=0;
		for(j=0; j<7; j++)
			if(i&(1<<j))
				a[n++]=con[j];
		bool flag=true;
		for(ans=2; flag; ans++)
		{
			flag=false;
			for(int i=0; i<n && !flag; i++)
				if(!f[a[i]][cc(ans,a[i])])
					flag=true;
		}
		printf("%d,",ans-1);
		for(j=0; j<n; j++)
			fprintf(stderr,"%d ",a[j]);
		fprintf(stderr,":%d\n",ans-1);
	}
	return 0;
}*/
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
const int a[128]={2,3,5,23,6,79,49,79,7,143,7,143,49,2207,49,2207,8,27,27,27,216,3879,1975,3879,1001,5719,1001,5719,47089,47089,48769,58775,3,3,27,27,415,707,415,1695,125,143,125,143,2753,37131,37131,37131,27,27,27,27,4977,10089,4977,23117,6393,35785,6393,128821,569669,569669,569669,569669,7,13,7,23,44,79,49,79,7,167,7,7895,49,6307,49,7895,97,219,219,219,608,3879,3879,3879,34527,48041,34527,120407,245035,697563,245035,2688153,91,91,91,91,1033,6073,4577,6073,1337,1337,29913,120149,71735,613479,218301,711725,1177,1177,1177,1177,9867,28099,28099,28099,48041,48041,246297,346719,2662657,4817803,11814485,11814485};
const int b[11]={-1,-1,-1,0,-1,1,2,3,4,5,6};
int main()
{
	int _,t,x,ans;
	string s;
	cin>>_;
	getline(cin,s);
	for(t=1; t<=_; t++)
	{
		getline(cin,s);
		istringstream sin(s);
		ans=0;
		while(sin>>x)
			if(b[x]>=0)
				ans+=(1<<b[x]);
		printf("Case #%d: %d\n",t,a[ans]);
	}
	return 0;
}
