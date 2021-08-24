// By John Dydo (john@dydo.name)

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;


bool isHappy(int value, int base, set<int> *done)
{
	if (value == 1)
		return true;

	if (done->find(value) != done->end())
		return false;
	done->insert(value);

	int sum = 0;
	int part = value;
	while (part)
	{
		int digit = part % base;
		sum += (digit * digit);
		part /= base;
	}

	return isHappy(sum, base, done);
}

int main()
{
	int cases;
	cin >> cases;
	string empty;
	getline(cin, empty);

	for(int i=0; i < cases; i++)
	{
		string line;
		getline(cin, line);
		stringstream parts(line);

		vector<int> bases;
		while(parts)
		{
			int base;
			parts >> base;
			if (parts)
				bases.push_back(base);
		}

		int x;
		for(x = 2; true; x++)
		{
			bool good = true;
			for(vector<int>::iterator it = bases.begin(); it < bases.end(); ++it)
			{
				set<int> done;
				if (!isHappy(x, *it, &done))
				{
					good = false;
					break;
				}
			}
			if (good)
				break;
		}
		cout << "Case #" << (i+1) << ": " << x << endl;
	}
}

