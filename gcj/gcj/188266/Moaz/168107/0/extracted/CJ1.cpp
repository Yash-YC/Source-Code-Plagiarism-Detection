#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int> base_happy[11];
set<int> base_sad[11];
set<int> inLoop;


bool isHappy(int a, int base)
{
	if(base_happy[base].find ( a) != base_happy[base].end())
	{
		base_happy[base].insert(inLoop.begin(), inLoop.end());
		return true;
	}
	else if(base_sad[base].find ( a) != base_sad[base].end())
	{
		base_sad[base].insert( inLoop.begin(), inLoop.end());
		return false;
	}

	char ac[30];
	itoa(a, ac, base);
	int ac_len = strlen(ac);
	int total_sum = 0;

	for(int i = 0 ; i < ac_len ; i++)
	{
		int num = ac[i] - 48;
		total_sum += num * num;
	}

	if(inLoop.find(total_sum) != inLoop.end())
	{
		base_sad[base].insert(a);
		base_sad[base].insert( inLoop.begin(), inLoop.end());
		return false;
	}
	if( base_happy[base].find (total_sum) != base_happy[base].end())
	{
		base_happy[base].insert(a);
		base_happy[base].insert( inLoop.begin(), inLoop.end());
		return true;
	}
	else if( base_sad[base].find ( total_sum) != base_sad[base].end())
	{
		base_sad[base].insert(a);
		base_sad[base].insert( inLoop.begin(), inLoop.end());
		return false;
	}
	else
	{
		inLoop.insert(total_sum);
		return isHappy(total_sum, base);
	}
}

void main()
{
	ifstream inFile("c:\\CodeJam\\A-small-attempt1.in");
	ofstream outFile("c:\\CodeJam\\out");

	int numberOfCases;
	
	string words[5000];

	inFile >> numberOfCases ;

	char dummy[500];
	inFile.getline(dummy, 500);

	for(int i = 2; i < 11 ; i++)
		base_happy[i].insert(1);
	
	for(int caseNumber = 1; caseNumber <= numberOfCases ; caseNumber++)
	{
		int result = 2;

		list<int> bases;

		inFile.getline(dummy, 500);

		char *number = strtok(dummy, " ");

		while(number != 0)
		{
			bases.push_back(atoi(number));
			number = strtok(NULL, " ");		
		}

		while(true)
		{
			list<int>::iterator it = bases.begin();

			for( ; it != bases.end(); it++)
			{
				inLoop.clear();
				if(isHappy(result, *it) == false)
					break;
			}

			if(it == bases.end())
				break;

			result++;
		}

		outFile << "Case #" << caseNumber << ":" << " " << result << endl;
	}
}

