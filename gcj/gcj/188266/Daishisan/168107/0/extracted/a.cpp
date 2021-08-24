#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int CAP = 5000000;

int convert_base(int n, int base) {
	int answer = 0;
	while (n > 0) {
		answer += (n % base)*(n % base);
		n = n / base;
	}
	return answer;
}

int main() {
	int num_test_cases; cin >> num_test_cases;
	string blah; getline(cin, blah);
	for (int test_case = 1; test_case <= num_test_cases; test_case++) {
		string line; getline(cin, line);
		stringstream str;
		str << line;
		int base;
		vector<int> v;
		while (str >> base) {
			v.push_back(base);
		}
		int answer;
		for (answer = 2; answer < CAP; answer++) {
			int happy;
			for (int i = 0; i < v.size(); i++) {
				base = v[i];
				int a = answer;
				vector<int> so_far;
				happy = 0;
				while (happy == 0) {
					so_far.push_back(a);
					a = convert_base(a, base);
					for (int j = 0; j < so_far.size(); j++) {
						if (so_far[j] == a) {
							if (a == 1)
								happy = 1;
							else
								happy = -1;
							break;
						}
					}
				}
				if (happy == -1)
					break;
			}
			if (happy == 1)
				break;
		}
		// print answer
		cout << "Case #" << test_case << ": " << answer << endl;
	}
}

