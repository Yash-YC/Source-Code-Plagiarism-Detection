/*
 * A.cpp
 *
 *  Created on: Sep 11, 2009
 *      Author: bernberg11
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

string int_to_base(int num, int base)
{
	string ret;
	char tmp;
	if (num == 0){
		ret.push_back('0');
		return ret;
	}

	while (num)
	{
		tmp = (num%base)+'0';
		ret.push_back(tmp);
		num = num/base;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}


bool is_happy(string num, int base)
{
	int ones_count = 0;
	int next_num;
	static set<string> nums_seen;

	if (nums_seen.find(num) != nums_seen.end()) { nums_seen.clear(); return false; }


	nums_seen.insert(num);

	next_num = 0;
	// check if happy
	for (string::iterator it = num.begin(); it != num.end(); it++)
	{
		if (*it == '1')
			ones_count++;
		else if (*it != 0)
			ones_count = 2;
		// calc next num
		next_num += (*it-'0') * (*it -'0');
	}
	if (ones_count == 1){ nums_seen.clear(); return true; }

	// calc next num

	return (is_happy(int_to_base(next_num, base), base));
}


int main(int argc, char * argv[])
{
	int num_cases;
	ifstream infile;
	string line;
	string temp;
	int base;
	vector<int> bases;

	infile.open(argv[1]);
	if (!infile)
	{
	   cout << "Invalid file name" << endl;
	   exit(1);
	}
	infile >> num_cases;
	infile.get();

	for (int i=0; i < num_cases; i++)
	{
		getline(infile, line);
		istringstream stream(line);
		while (stream >> base) bases.push_back(base);

		int j = 2;
		while (1)
		{
			bool result = true;
			for(vector<int>::iterator it = bases.begin(); it != bases.end(); it++)
			{
				if (!is_happy(int_to_base(j, *it), *it))
				{
					result = false;
					break;
				}
			}
			if (result) break;
			j++;
		}
		cout << "Case #" << i+1 << ": " << j << endl;
		bases.clear();
	}
	return 0;
}
