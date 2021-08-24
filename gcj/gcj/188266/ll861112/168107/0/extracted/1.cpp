#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<functional>
using namespace std;

int main()
{
	int t,cs,n,i,j,m,sum;
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	//freopen("l.in","r",stdin);
	//freopen("l.out","w",stdout);
	scanf("%d",&t);
	getchar();
	for(cs=1;cs<=t;cs++)
	{
		char s[10000];
		gets(s);
		istringstream ss(s);
		vector<int> v;
		while(ss>>n)
			v.push_back(n);
		for(i=2;;i++)
		{
			for(j=0;j<v.size();j++)
			{
				m=i;
				bool f[100000]={0};
				while(!f[m])
				{
					f[m]=1;
					sum=0;
					while(m>0)
					{
						sum+=(m%v[j])*(m%v[j]);
						m/=v[j];
					}
					if(sum==1)
						break;
					m=sum;
				}
				if(sum!=1)
					break;
			}
			if(j==v.size())
				break;
		}
		printf("Case #%d: %d\n",cs,i);
	}
}