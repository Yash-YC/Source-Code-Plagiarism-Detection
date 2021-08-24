
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//

int main(void)
{
	int a, b;
	int nc, ca;

	scanf("%d", &nc);
	for(ca=1; ca<=nc; ca++)
	{
		scanf("%d %d", &a, &b);
		double d = 1 + double(a)/b;
		printf("Case #%d: %.7lf\n", ca, d);
	}

	return 0;
}
