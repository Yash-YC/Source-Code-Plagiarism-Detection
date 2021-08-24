#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string.h>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int
main()
{
	int cases, tmp, val, lucky;
	int next, pot;
	string s;
	stringstream sstr;
	vector<int> bases;
	vector<int> seen;

	cin >> cases;
	getline(cin, s);
	for (int cas = 1; cas <= cases; cas++) {
		getline(cin, s);
		sstr << s;
		bases.clear();
		while (sstr >> tmp) {
			bases.push_back(tmp);
		}
		sstr.clear();

		lucky = 2;
		do {
			for (size_t bs = 0; bs < bases.size(); bs++) {
				seen.clear();
				next = lucky;

				do {
					val = next;

					pot = bases[bs];
					while (val / pot != 0)
						pot *= bases[bs];
					pot /= bases[bs];

					next = 0;
					while (pot != 0) {
						int res = val / pot;
						next += res * res;
						val -= res * pot;
						pot /= bases[bs];
					}

					//printf("bs=%zd lucky=%d next=%d\n", bs, lucky, next);
					if (find(seen.begin(), seen.end(), next) != seen.end()) {
						lucky++;
						break;
					}
					seen.push_back(next);
				} while (next != 1);

				if (next != 1)
					break;
			}
		} while (next != 1);

		printf("Case #%d: %d\n", cas, lucky);
	}

	return 0;
}
