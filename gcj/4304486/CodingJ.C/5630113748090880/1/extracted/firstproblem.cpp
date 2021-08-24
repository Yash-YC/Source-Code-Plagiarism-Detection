// CodeJamTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class MyInput
{
public:
	MyInput(std::ifstream &file)
	{
		//get firstLine of the testCase
		std::string line;
		std::getline(file, line);
		std::istringstream iss(line);
		iss >> n;
		for (int i = 0; i < 2*n - 1; ++i)
		{
			std::getline(file, line);
			std::istringstream iss2(line);
			for (int j = 0; j < n; ++j)
			{
				int value;
				iss2 >> value;
				auto result = heights.insert(value);
				if (!result.second)
				{
					heights.erase(result.first);
				}
			}
		}
	};
	std::string solve()
	{
		bool isPossible = false; 
		std::stringstream ss;
		for (auto & height : heights)
		{
			ss << ' ' << height;
		}
		return ss.str();
	};

private:
	int n;
	set<int> heights;

};




int main()
{
	std::ifstream file("C:\\Users\\Noob\\Downloads\\B-large.in");
	std::ofstream outputFile("C:\\Users\\Noob\\Downloads\\B-large.out");
	std::string line;
	int nbCases = 0;
	std::getline(file, line);
	std::istringstream iss(line);
	iss >> nbCases;
	for (int i = 0; i < nbCases; ++i)
	{
		MyInput myInput(file);
		outputFile << "Case #" << i+1 << ":"<<myInput.solve() << std::endl;
	}
	file.close();
	outputFile.close();
    return 0;
}

