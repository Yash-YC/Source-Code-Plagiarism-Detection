#include <stdio.h>

const double eps = 1e-14;

int main(){
	int testnum;
	double a, b, ret, cur, c, n;
	
	scanf("%d", &testnum);
	for(int test = 1;test <= testnum;test++){
		scanf("%lf%lf", &c, &n);
		a = ((c - n)) / c;
		b = (n) / c;
		//printf("%lf %lf\n", a, b);
		ret = 0;
		cur = b;
		for(int l = 1;cur * l > eps;l++){
			ret += cur * l;
			cur = cur * a;
		}
		printf("Case #%d: %.10lf\n", test, ret + 1);
	}
	return 0;
}
