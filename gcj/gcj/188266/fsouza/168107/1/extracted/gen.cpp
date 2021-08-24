#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv)
{
	int ntest = (1<<9) - 1 - 9;

	printf("%d\n", ntest);

	int st;
	for (st = 0; st < (1<<9); st++) {
		vector <int> bases;

		for (int i = 0; i < 9; i++)
			if (st & (1<<i))
				bases.push_back(i+2);

		if (bases.size() >= 2) {
			for (int j = 0; j < bases.size(); j++)
				printf("%d ", bases[j]);
			printf("\n");
		}
	}

	return 0;
}
