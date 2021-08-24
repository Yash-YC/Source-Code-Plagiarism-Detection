#include <cstdio>
using namespace std;

int main() {
	int t, n, m;

	scanf("%d", &t);
	for (int ti = 0; ti < t; ti++) {
		scanf("%d %d", &n, &m);
		printf("Case #%d: %.5lf\n", ti+1, ((double)n+m)/m);
	}
}
