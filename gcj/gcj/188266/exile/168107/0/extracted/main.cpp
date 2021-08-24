#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 100000;

bool checked[SIZE][10];

bool check(long long num, int base, bool init) {
	if (!init) {
		if (num < SIZE)
			return checked[num][base];
	}
	vector<int> digits;
	set<int> values;
	long long value = num;

	while (value != 1 && values.find(value) == values.end()) {
		values.insert(value);
		digits.clear();
		while (value > 0) {
			digits.push_back(value % base);
			value /= base;
		}
		int size = (int) digits.size();
		value = 0;
		for (int i = 0; i < size; i++) {
			value += digits[i] * digits[i];
		}
	}
	if (value == 1)
		return true;
	else
		return false;
}

void init() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 2; j <= 10; j++) {
			checked[i][j] = check(i, j, true);
		}
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	stringstream ss;
	char buf[256];
	init();
	int T;
	fin >> T;
	fin.getline(buf, sizeof(buf));
	for (int cnt = 0; cnt < T; cnt++) {
		fin.getline(buf, sizeof(buf));
		ss.clear();
		ss << buf;
		int temp;
		vector<int> nums;
		while (ss >> temp) {
			nums.push_back(temp);
		}
		long long i = 1;
		bool success = false;
		while (!success) {
			i++;
			success = true;
			for (int j = 0; j < (int)nums.size(); j++) {
				if (!check(i, nums[j], false)) {
					success = false;
					continue;
				}
			}
		}
		fout << "Case #" << cnt + 1 << ": "  << i << endl;
	}
	fout.close();
	return 0;
}
