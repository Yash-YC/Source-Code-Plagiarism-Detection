#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_H 2505
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	int N;
	int temp;
	int high[max_H];

	for(int i=0; i<T; i++){
		scanf("%d", &N);

		for(int j=0; j<max_H; j++) high[j] = 0;

		for(int j=0; j< N*(2*N-1); j++){
				scanf("%d", &temp);
				if(high[temp] == 0) high[temp] = 1;
				else high[temp] = 0;
		}

		printf("Case #%d: ", i+1);

		for(int j=0; j<max_H; j++) if(high[j] == 1) printf("%d ", j);
		printf("\n");
	}

	return 0;
}
