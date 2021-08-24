#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <map>
#include <sstream>
using namespace std;

//BEGIN_CODETEMPLATE
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin() ; it!=(v).end() ; it++)
//END_CODETEMPLATE

int sum(int n, int base)
{
	int s = 0;

	while(n)
	{
		int d = n % base;
		s += d*d;
		n /= base;
	}

	return s;
}

bool check(int n, int base)
{
	for(int i=0 ; i<10000 ; i++)
	{
		n = sum(n, base);
		if(n == 1) return true;
	}

	return false;
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();

	for(int t=1 ; t<=T ; t++)
	{
		char str[100];
		cin.getline(str, 100);
		istringstream in(str);

		vector<int> bases;
		int b;
		while(in >> b) bases.push_back(b);

		for(int i=2 ; true ; i++)
		{
			bool good = true;
			FOREACH(it, bases)
				if(!check(i, *it))
				{
					good = false;
					break;
				}

			if(good)
			{
				cout << "Case #" << t << ": " << i << endl;
				break;
			}
		}
	}

	return 0;
}
