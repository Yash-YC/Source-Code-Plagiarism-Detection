#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int calc(int b,int x)
{
	int ret=0,m;
	while (x)
	{
		m=x%b;
		ret+=m*m;
		x/=b;
	}
	return ret;
}
int isGood(int b,int x)
{
	set<int> last;
	while (x!=1)
	{
		last.insert(x);
		x=calc(b,x);
		if (last.find(x)!=last.end()) return 0;
	}
	return 1;
}
int main()
{
	string str;
	int T;
	while (true)
	{
		getline(cin,str);
		stringstream slo(str);
		if (slo >> T) break;
	}
	for (int Kase=1;Kase<=T;Kase++)
	{
		vector<int> vec;
		getline(cin,str);
		stringstream slo(str);
		int x;
		while (slo >> x) vec.push_back(x);
		for (int q=2;;q++)
		{
			int good=1;
			for (int w=0;w<vec.size();++w)
				if (isGood(vec[w],q) == 0)
				{
					good=0;
					break;
				}
			if (good) 
			{
				cout << "Case #" << Kase << ": " << q << endl;
				break;
			}
		}
	}
	return 0;
}
