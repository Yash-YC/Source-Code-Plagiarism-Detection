#include <iostream>
#include <set>
#include <sstream>
using namespace std;
set<pair<int,int> > s;
set<pair<int,int> > us;
int test(int x,int base)
{
	int in = x;
	if(s.find(make_pair(x,base))!=s.end()) return 1;
	if(us.find(make_pair(x,base))!=us.end()) return 0;
	us.insert(make_pair(x,base));
	int sum=0;
	while(x)
	{
		int t=x%base;
		x=x/base;
		sum += t*t;
	}
	if(sum==1)
	{
		us.erase(make_pair(in,base));
		s.insert(make_pair(in,base));
		return 1;
	}
	else
	{
		int r= test(sum,base);
		if(r==1)
		{
			us.erase(make_pair(in,base));
			s.insert(make_pair(in,base));
		}
		return r;
	}

}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int Ti=1;Ti<=T;Ti++)
	{
		set<int>bases;
		char in[1000];
		gets(in);
		stringstream t;
		t<<in;
		int basein;
		while(t>>basein)
		{
			bases.insert(basein);
		}
		for(int i=2;;i++)
		{
			int flag=1;

			for(set<int>::iterator it=bases.begin(); it!=bases.end() ;it++)
			{
				flag = flag && test(i,*it);
				if(!flag) break;
			}
			if(flag)
			{
				printf("Case #%d: %d\n",Ti,i);
				break;

			}
		}

	}
}