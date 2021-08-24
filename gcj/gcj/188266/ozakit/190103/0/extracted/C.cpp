#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <limits>

using namespace std;

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
		int C, N;
		ifs >> C >> N;
		getline(ifs, dummy);

		int packs = 0;
		double prob = N / (double)C;
		double last = C;
		while (last * (1.0 - numeric_limits<double>::epsilon()) > prob) {
			last -= last * prob;
			++packs;
		}

		// output
		cout << "Case #" << testCase + 1 << ": " << fixed << setprecision(7) << packs + last / prob << endl;
	}

	return 0;
}
