#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <ctype.h>
using namespace std;

#define ENDVAL 2000000000
#define BUFSIZE 501

int transform(int val,int base)
{
	int ret = 0;

	if (val == 0)
	{
		return 0;
	}
	else
	{
		while (val > 0)
		{
			ret += (val % base) * (val % base);
			val /= base;
		}
	}

	return ret;
}

bool happy(int val,int base)
{
	set<int> met_list;

	int ret = val;
	while (ret != 1 && met_list.find(ret) == met_list.end())
	{
		met_list.insert(ret);
		ret = transform(ret,base);
	}

	if (ret == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int solve(const vector<int>& base_list)
{
	for (int i = 2; i <= ENDVAL ;i++)
	{
		int j = 0;
		for (; j != base_list.size(); j++)
		{
			if (!happy(i,base_list[j]))
			{
				break;
			}
		}
		if (j == base_list.size())
		{
			return i;
		}
	}
	return 1;
}

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int n;
	fin >> n;
	fin.get();

	for (int ni = 1; ni <= n; ni++)
	{
		char temp[BUFSIZE];

		fin.getline(temp,BUFSIZE);
		vector<int> base_list;

		for (int i = 0; temp[i] != '\0'; )
		{
			while ((!(temp[i] >= '0' && temp[i] <= '9')) && temp[i] != '\0')
			{
				i++;
			}

			int val = 0;
			while (temp[i] >= '0' && temp[i] <= '9' && temp[i] != '\0')
			{
				val = val * 10 + (temp[i++] - '0');
			}

			base_list.push_back(val);
		}

		int res = solve(base_list);

		fout << "Case #" << ni << ": " << res << endl;
	}

	fout.close();
	fin.close();

	return 0;
}