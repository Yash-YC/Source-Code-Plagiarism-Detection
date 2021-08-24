#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <string>

using namespace std;

#define loop(a, b) for(a = 0; a < b; ++a)

int conv(int num, int base) {
	if (num == 0)
		return 0;
	return 10*conv(num/base, base)+(num%base);
}

set<int> inUse;

bool isHappy(int num, int base) {

	int digit, sum = 0;

	num = conv(num, base);

	while(num > 0) {
		digit = num%10;
		sum += digit*digit;
		num /= 10;
	}

	if (sum == 1)
		return 1;

	if (inUse.find(sum) != inUse.end())
		return 0;

	inUse.insert(sum);

	if (isHappy(sum, base)) {
		inUse.erase(sum);
		return 1;
	} else {
		inUse.erase(sum);
		return 0;
	}
}

int main(){
	char ln[128], *pt;
	int baseCount, bases[29], i, j, tc = 1;
	int ds;
	scanf("%d ", &ds);
	while(ds--) {
		gets(ln);
		pt = strtok(ln, " ");
		baseCount = 0;
		while(pt != NULL) {
			bases[baseCount++] = atoi(pt);
			pt = strtok(NULL, " ");
		}

		for(i = 2;;++i) {
			loop(j, baseCount)
				if (!isHappy(i, bases[j]))
					break;
			if (j == baseCount) {
				printf("Case #%d: %d\n", tc++, i);
				break;
			}
		}
	}
	return 0;
}
