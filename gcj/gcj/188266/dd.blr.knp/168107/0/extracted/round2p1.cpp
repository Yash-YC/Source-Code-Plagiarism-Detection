// round2p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "stdafx.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <strstream>
#include <map>

using namespace std;

string n2s(long num,int b)
{
	return "";
}

long s2n(string s, int b)
{

	return 0;
}

int sumsquares(long num,int b)
{
	int digit;
	int sumsq = 0;
	while (num > 0)
	{
		digit = num % b;
		num = num/b;
		sumsq += digit * digit;
	}
	return sumsq;
}

bool ishappy(long num, int b)
{
	set<int> already;
	bool looped = false;
	bool ishappy= false;
	while (looped == false)
	{
		int temp = sumsquares(num,b);
		num = temp;
		if (already.find(temp)!=already.end()) looped = true;
		if (temp == 1) {
			ishappy = true;
			break;
		}
		already.insert(temp);

	}
	return ishappy;

}





long getgch(vector<int> bases)
{
	long i = 1;
	bool found = false;
	while (!found)
	{
		i++;
		bool fullloop = false;
		int index = 0;
		for (index=0;index<bases.size();++index)
		{
			int tb = bases[index];
			if (!ishappy(i,tb)) break;
		}
		if (index == bases.size()) {
			found = true;
			return i;
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream fin("input.txt");
	FILE *f2 = fopen("output.txt","w");
	int numCases;
	char temp[2000];
	fin >> numCases;
	vector <string> cases;
	fin.getline(temp,2000);
	for (int i=0;i<numCases;++i)
	{
		fin.getline(temp,2000);
		strstream ss;
		ss << temp;
		int tbase;
		vector<int> bases;
		while (!ss.eof())
		{
			ss >> tbase;
			bases.push_back(tbase);
		}
		fprintf(f2,"Case #%d: %d\n",i+1,getgch(bases));
	
	}
	
}



