#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <assert.h>

using namespace std;

typedef unsigned int Uint;

struct NumIdent
{
	NumIdent() : num(0), base(1)
	{
	}

	NumIdent(Uint num, Uint base) : num(num), base(base)
	{
	}

	bool operator<(const NumIdent &rhs) const
	{
		if (rhs.num == num)
		{
			return base < rhs.base;
		}
		return num < rhs.num;
	}

	Uint num;
	Uint base;
};

enum Happy
{
	UNHAPPY,
	HAPPY,
	LOOPED
};
map<NumIdent, Happy> testedNums;
vector<Uint> numToBase(Uint n, Uint base)
{
	int power;
	

	for (power = 0; pow((double)base, (double)power) <= n; power++);
	power--;
	vector<Uint> digits(power + 1, 0);
	while (power >= 0)
	{
		digits[power] = (n / (Uint)pow((double)base, (double)power));
		n -= digits[power] * (Uint)pow((double)base, (double)power);
		power--;
	}
	
	for (int i = 0; i < (int)digits.size(); i++)
	{
		swap(digits[i], digits[digits.size() - 1 - i]);
	}

	return digits;
}

Uint baseToNum(const vector<Uint> &num, Uint base)
{
	Uint total = 0;
	Uint bMul = 1;
	for (int i = 0; i < (int)num.size(); i++)
	{
		std::cout << i << ". " << num[i] << " * " << bMul << " -> " << total << std::endl;
		total += num[i] * bMul;
		bMul *= base;
	}
	return total;
}
Happy isHappy(Uint n, Uint base)
{
	NumIdent t(n, base);
	if (testedNums.find(t) == testedNums.end())
	{
		Uint nextNum = 0;
		vector<Uint> d = numToBase(n, base);
		for (int i = 0; i < (int)d.size(); i++)
		{
			nextNum += d[i] * d[i];
		}
		if (nextNum == 1)
		{
			testedNums[t] = HAPPY;
		}
		else
		{
			testedNums[t] = LOOPED;
			testedNums[t] = isHappy(nextNum, base);
		}
	}
	if (testedNums[t] == LOOPED)
	{
		testedNums[t] = UNHAPPY;
		return UNHAPPY;
	}
	else if (testedNums[t] == HAPPY)
	{
		return HAPPY;
	}

	return UNHAPPY;
}

int main()
{
	//const string FILENAME = "C:\\CodeJam\\Happy\\A-large.in";
	//const string FILENAME = "C:\\CodeJam\\Happy\\test-in.txt";
	const string FILENAME = "C:\\CodeJam\\Happy\\a-small-1.in";
	ifstream inFile(FILENAME.c_str());
	ofstream outFile((FILENAME + ".out.txt").c_str());

	int t;
	inFile >> t;
	inFile.ignore();

	for (int caseId = 0; caseId < t; caseId++)
	{
		string l;
		getline(inFile, l);
		stringstream ls;
		ls << l;
		
		Uint base;
		vector<Uint> bases;
		while (ls >> base)
		{
			bases.push_back(base);
		}

		bool satisfied = false;
		Uint n = 0;
		for (Uint i = 2; !satisfied; i++)
		{
			satisfied = true;
			n = i;
			for (Uint j = 0; satisfied && j < bases.size(); j++)
			{
				if (isHappy(i, bases[j]) != HAPPY)
				{
					satisfied = false;
				}
			}
		}
		outFile << "Case #" << (caseId + 1) << ": " << n << endl;
	}

	return 0;
}