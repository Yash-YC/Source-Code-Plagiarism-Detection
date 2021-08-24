#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <sstream>

using namespace std;

int FindNextHappyNum(int from, int base) {
	for (int i = from; ; ++i) {
		vector<int> used;
		int val = i;
		for (;;) {
			used.push_back(val);
			int next = 0;
			do {
				int digit = val % base;
				next += digit * digit;
				val /= base;
			} while (val > 0);

			if (next == 1)
				return i;
			if (find(used.begin(), used.end(), next) != used.end())
				break;
			val = next;
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return 1;

	ifstream ifs(argv[1]);
	string dummy;

	int T;
	ifs >> T;
	getline(ifs, dummy);

	for (int testCase = 0; testCase < T; ++testCase) {
		string line;
		getline(ifs, line);
		stringstream sstr(line);
		vector<int> bases;
		int base;
		while (sstr >> base)
			bases.push_back(base);

		vector<int> smallests;
		for (size_t i = 0; i < bases.size(); ++i) {
			smallests.push_back(FindNextHappyNum(2, bases[i]));
		}

		for (;;) {
			int minPos = (int)distance(smallests.begin(), min_element(smallests.begin(), smallests.end()));
			int maxPos = (int)distance(smallests.begin(), max_element(smallests.begin(), smallests.end()));
			if (minPos == maxPos)
				break;
			smallests[minPos] = FindNextHappyNum(smallests[minPos] + 1, bases[minPos]);
		}

		// output
		cout << "Case #" << testCase + 1 << ": " << smallests[0] << endl;
	}

	return 0;
}
