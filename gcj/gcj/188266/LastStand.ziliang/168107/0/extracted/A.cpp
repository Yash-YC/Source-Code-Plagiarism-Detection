#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

bool test(int n, int b)
{
	set<int> ss;
	while(true)
	{
		if(ss.find(n)!=ss.end())return 0;

		ss.insert(n);
		int nn=0;
		while(n)
		{
			nn += (n%b)*(n%b);
			n/=b;
		}

		n=nn;

		if(n==1)return 1;
	}
}

int main()
{
	freopen("a1in.txt","r",stdin);
	freopen("a1out.txt","w",stdout);


	int T;
	cin>>T;
	char str[10000];
	gets(str);
	for(int t=1;t<=T;t++)
	{
		gets(str);
		stringstream ss(str);
		vector<int> vi;
		int in;
		while(ss>>in)
			vi.push_back(in);


		int ans=2;
		while(true)
		{
			bool ok=true;
			for(int i=0;i<vi.size();i++)
			{
				if(test(ans, vi[i]) == false)
				{
					ok=false;
					break;
				}
			}

			if(ok==true)break;

			ans++;
		}

		cout<<"Case #" << t <<": " << ans <<endl;
	}
}