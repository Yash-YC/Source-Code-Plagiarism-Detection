#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <set>
using namespace std;

set<int> chain;

//	b: base
char isHappy (int n , int b)
{
	if (b == 2 || b == 4) return 1;
	if (n == 1) return 1;
	int next = 0;

	while (n) {
		next += (n % b) * (n % b);
		n /= b;
	}

	if (next == 1) return 1;
	if (chain.find (next) != chain.end()) return 0;
	chain.insert (next);

	return isHappy (next, b);
}

char line [1024];

int bases [10];
int main()
{
	int kase, serial=0,
		nBase, soln,
		b;
	char *token;
	bool allHappy;

	gets (line);
	kase = atoi (line);
	while (kase--)
	{
		//	start a test case

		//	input
		gets (line);
		nBase = 0;
		token = strtok (line, " ");
		do
		{
			b = atoi (token);
			if (b != 2 && b != 4)
				bases [nBase++] = b;
		}
		while (token = strtok (NULL, " "));

		if (nBase == 0) {
			// input contains 2 or 4 or both only
			printf ("Case #%d: 2\n", ++serial);
			continue;
		}

		//	brute force
		for (int i=2, k; ; ++i) { // brute force check
			allHappy = true;
			for (k=0; k<nBase; ++k) { // for all base
				chain.clear(); // clear chain
				if (! isHappy (i, bases [k])) {
					allHappy = false;
					break;
				}
			}
			if (allHappy) {
				soln = i;
				break;
			}
		}

		printf ("Case #%d: %d\n", ++serial, soln);

		//	start a test case
	}
	return 0;
}

