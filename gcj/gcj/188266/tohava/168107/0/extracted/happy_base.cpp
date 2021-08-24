#include <iostream>
#include <sstream>
#include <vector>
#include <set>
typedef unsigned int U32; // not always true, but usually is

bool Happy(const int n, int nBase) {
	std::vector<int> vec;
	std::set<int> set;
	int nDivided;
	nDivided = n;
	while (set.find(nDivided) == set.end()) {
		set.insert(nDivided);
		while (nDivided > 0) {
			vec.push_back(nDivided % nBase);
			nDivided /= nBase;
		}
		nDivided = 0; std::vector<int>::const_iterator it;
		for (it = vec.begin(); it != vec.end(); ++it) {
			nDivided += *it * *it;
		}
		vec.clear();
	}
	return nDivided == 1;
}

int main() {
	int nTestCases;
	std::cin >> nTestCases;
	char buf[65536];
	for (U32 i = 0; i < nTestCases; ++i) {
		do { std::cin.getline(buf, 65536); } while (*buf == '\0');
		std::stringstream ss(buf);
		int nBase;
		std::vector<int> vecBases;
		while (!ss.eof()) {
			ss >> nBase;
			vecBases.push_back(nBase);
		}
		for (U32 j = 2; j < 0xFFFFFFFF; ++j) {
			std::vector<int>::iterator itBases;
			for (itBases = vecBases.begin(); itBases != vecBases.end();
			     ++itBases)
			{
				if (!Happy(j, *itBases))
					break;
			}
			if (itBases == vecBases.end()) {
				std::cout << "Case #" << (i + 1) << ": " << j << std::endl;
				break;
			}
		}
	}
}
