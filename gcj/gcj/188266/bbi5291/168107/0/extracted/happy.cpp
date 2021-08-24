#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
bool happy(int x,int b)
{
	set<int> vis;
	for (;;)
	{
		if (x==1) return true;
		if (vis.find(x)!=vis.end()) return false;
		vis.insert(x);
		int y=0;
		while (x)
		{
			y+=(x%b)*(x%b);
			x/=b;
		}
		x=y;
	}
}
int main()
{
	int T,i,j;
	string s;
	cin >> T;
	cin.ignore();
	for (i=1; i<=T; i++)
	{
		getline(cin,s);
		istringstream sin(s);
		vector<int> V;
		for(;;)
		{
			int x;
			sin >> x;
			if (sin.fail()) break;
			V.push_back(x);
		}
		int res;
		bool ok=false;
		for(res=2;;res++)
		{
			ok=true;
			for (j=0; j<V.size(); j++)
				if (!happy(res,V[j]))
				{
					ok=false;
					break;
				}
			if (ok) break;
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}