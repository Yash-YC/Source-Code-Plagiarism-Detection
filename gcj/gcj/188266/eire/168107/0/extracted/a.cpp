#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int flag[11];


int next(int n, int base)
{
	int res=0;
	while (n)
	{
		int t = n % base;
		res += t*t;
		n /= base;
	}
	return res;
}

int ishappy(int n, int base)
{
	map< int , int > database;
	while (database[n]==0)
	{
		if (n==1) return 1;
		database[n]=1;
		n=next(n,base);
	}
	return 0;
}

int main()
{
	int t,_t;
	char buf[1024];
	cin.getline(buf,sizeof(buf));
	sscanf(buf,"%d",&_t);
	for (t=1;t<=_t;t++)
	{
		memset(buf,0,sizeof(buf));
		cin.getline(buf,sizeof(buf));
		////////////////////////////
	//	cout<<"haha: "<<buf<<endl;
		////////////////////////////
		memset(flag,0,sizeof(flag));
		int temp;
		char *p=buf;
		while (sscanf(p,"%d",&temp)==1)
		{
			flag[temp]=1;
			p+=2;
		}
		int res=2;
		//////////////////////////
	//	for (int l=2;l<=10;l++) if (flag[l]) cout<<l<<' '; cout<<endl; continue;
		//////////////////////////
	//	if (ishappy(3,2)) cout<<"happ"<<endl;
	//	cout<<"3,9 = "; if (ishappy(3,9)) cout<<"h"<<endl; else cout<<endl;
	//	cout<<"3,10 = "; if (ishappy(3,10)) cout<<"h"<<endl; else cout<<endl;
	//	cout<<"3,4 = "; if (ishappy(3,4)) cout<<"h"<<endl; else cout<<endl;

		while (1)
		{
			int succ=1;
			for (int i=2;i<=10;i++)
			{
				if (!flag[i]) continue;
				if (ishappy(res,i)) continue;
				succ=0;
				res++;
				break;
			}
			if (succ)
			{
				cout<<"Case #"<<t<<": "<<res<<endl;
				break;
			}
		}
	}
	return 0;
}
