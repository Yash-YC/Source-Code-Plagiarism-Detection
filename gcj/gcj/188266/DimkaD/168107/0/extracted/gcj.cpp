#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

bool isHappy(int num, int base)
{
	set<int> sums;
	sums.insert(num);
	while (true)
	{
		int sum = 0;
		while (num > 0)
		{
			int digit = num % base;
			sum += digit * digit;
			num /= base;
		}
		if (sum == 1) 
			return true;
		if (sums.find(sum) != sums.end())
			return false;
		sums.insert(sum);
		num =  sum;
	}
}

int main()
{
	ifstream ifstr("a-small.in");

	char buf[1024];
	ifstr.getline(buf, 1024);

	int T = atoi(buf);

	ofstream ofstr("a-small.out");

	for (int i = 0; i < T; ++i)
	{
		ifstr.getline(buf, 1024);
		istringstream istr(buf);
		int base;
		vector<int> bases;
		while (istr >> base)
			bases.push_back(base);
		int happy = 2;
		while (true)
		{
			bool is_happy = true; 
			for (int j = 0; j < (int)bases.size(); ++j)
				is_happy &= isHappy(happy, bases[j]);
			if (is_happy)
				break;
			++happy;
		}
		ofstr << "Case #" << i + 1 << ": " << happy <<  "\n";
	}

	return 0;
}