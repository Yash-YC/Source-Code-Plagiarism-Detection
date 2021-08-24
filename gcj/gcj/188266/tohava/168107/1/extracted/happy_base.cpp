#include <iostream>
#include <sstream>
#include <vector>
#include <set>
typedef unsigned int U32; // not always true, but usually is

#define LIM 1048576

std::vector<int> flags(LIM, 0);

bool Happy(const int n, int nBase) {
	std::vector<int> vec;
	std::set<int> set;
	std::vector<ptrdiff_t> flagsChanged;
	const bool bUseFlags = n < LIM;
	int nDivided;
	nDivided = n;
	while (bUseFlags ? flags[nDivided] == 0 : set.find(nDivided) == set.end())
	{
		if (bUseFlags) {
			flags[nDivided] = 1;
			flagsChanged.push_back(nDivided);
		} else set.insert(nDivided);
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
	std::vector<ptrdiff_t>::iterator itFlagsChanged = flagsChanged.begin();
	for (; itFlagsChanged != flagsChanged.end(); ++itFlagsChanged)
		flags[*itFlagsChanged] = 0;
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
