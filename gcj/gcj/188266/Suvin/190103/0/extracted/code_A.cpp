#include<stdio.h>

int main()
{
	int t, i;
	double n, m;
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		scanf("%lf %lf", &n, &m);
		printf("Case #%d: %.7f\n", i,(n+m)/m);
	}
	
	return 0;
}


