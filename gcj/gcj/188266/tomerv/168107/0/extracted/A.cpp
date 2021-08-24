#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using std::string;
using std::vector;
using std::map;
using std::queue;



vector<int> split(string strNumbers) {
	
	vector<int> result;
	int pos;
	while((pos = strNumbers.find_first_of(' ')) != string::npos) {
		string strNum = strNumbers.substr(0, pos+1);
		std::istringstream iss(strNum, std::istringstream::in);
		int num;
		iss >> num;
		if (num != 0) {
			result.push_back(num);
		}
		strNumbers = strNumbers.substr(pos+1);
	}
	std::istringstream iss(strNumbers, std::istringstream::in);
	int num;
	iss >> num;
	if (num != 0) {
		result.push_back(num);
	}
	
	return result;
}


int happyStep(int num, int base) {
	
	int result = 0;
	while (num != 0) {
		int digit = num  % base;
		result += digit*digit;
		num -= digit;
		num /= base;
	}
	
	return result;
}


bool isHappy(int num, int base) {
	
	vector<bool> visited(2000000, false);
	visited[num] = true;
	while (num != 1) {
		num = happyStep(num, base);
		if (visited[num]) {
			return false;
		}
		visited[num] = true;
	}
	return true;
}


int minimalHappy(vector<int> bases) {
	
	int n = 1;
	bool found = false;
	do {
		n++;
		found = true;
		for (int i = 0; i < bases.size(); i++) {
			if (!isHappy(n, bases[i])) {
				found = false;
			}
		}
	} while (!found);
	
	return n;
}


int main()  {
	
	int t;
	std::cin >> t;
	string garbage;
	std::getline(std::cin, garbage);
	for (int i = 0; i < t; i++) {
		string strBases;
		std::getline(std::cin, strBases);
		vector<int> bases = split(strBases);
		try {
			std::cout << "Case #" << i+1 << ": " << minimalHappy(bases) << std::endl;
		} catch (string& str) {
			std::cout << str << std::endl;
		}

	}			
		
	return 0;
}

