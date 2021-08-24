#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <set>
using namespace std;
int T;
char S[1000];
vector<int> base;


bool able(int x, int b)
{
	set<int> v;
	while (true)
	{
		vector<int> num;
		for (; x; x /= b)
			num.push_back(x%b);
		x = 0;
		for (unsigned i = 0; i < num.size(); i++)
			x += num[i]*num[i];
		if (x == 1)
			return true;
		else if (v.count(x))
			return false;
		v.insert(x);
	}

}

bool succeed(int x)
{
	for (unsigned i = 0; i < base.size(); i++)
		if (!able(x, base[i]))
			return false;
	return true;
}

int main()
{
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++)
	{
		base.clear();
		gets(S);
		stringstream in;
		in << string(S);
		int x;
		
		while (in >> x)
			base.push_back(x);
		for (int i = 2;; i++)
			if (succeed(i))
			{
				printf("Case #%d: %d\n", t, i);
				break;
			}
	}
}
