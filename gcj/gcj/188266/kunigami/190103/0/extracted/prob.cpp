#include <stdio.h>
#include <iostream>

using namespace std;

int main (){

    int t, cases = 1, c, n;
    scanf("%d", &t);

    while (t--){
	
	scanf("%d %d", &c, &n);
	printf("Case #%d: %.7lf\n", cases++, (2.0*c - 1)/n);

    }

    return 0;
}
