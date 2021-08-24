#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int ishappy(int n, int base)
{
	set <int> seen;
	
	while (seen.find(n) == seen.end()) {
		if (n == 1)
			return 1;
		seen.insert(n);

		int sum = 0;

		while (n) {
			sum += (n%base)*(n%base);
			n /= base;
		}

		n = sum;
	}
	
	return 0;
}

int main(int argc, char ** argv)
{
	int ntest;
	char line[128];

	scanf("%d", &ntest);
	fgets(line, 128, stdin);

	for (int t = 0; t < ntest; t++) {
		vector <int> bases;
		
		fgets(line, 128, stdin);

		stringstream ss(line);
		int x;

		while (ss >> x)
			bases.push_back(x);
		
		int n;
		for (n = 2;; n++) {
			int ok = 1;

			for (int b = 0; b < bases.size(); b++)
				if (!ishappy(n, bases[b])) {
					ok = 0;
					break;
				}

			if (ok)
				break;
		}

		printf("Case #%d: %d\n", t+1, n);
	}

	return 0;
}
