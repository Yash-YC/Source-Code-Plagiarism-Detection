#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <queue>
#include <time.h>

using namespace std;

int ds[10002], hs[10002];

int main(){
	int t, n;
	scanf("%d", &t);
	srand ( time (NULL));
	//printf("%lf %lf %lf %lf\n", atan2(1,0), atan2(1,1), atan2(0,1), atan2(-1,1));
	//return 0;
	for(int _ = 1; _ <= t; ++_){
		printf("Case #%d:", _);
		scanf("%d", &n);
		for(int i = 1; i < n; ++i){
			scanf("%d", &ds[i-1]);
			ds[i-1]--;
		}
		int ct = 0;
		while(++ct < 7000000){
			for(int i = 0; i < n; ++i) hs[i] = rand()&0xF;//0X1FFFFFFF;
			for(int i = 0; i < n-1; ++i){
				double maior = -5.0;
				int ind = 0;
				for(int j = i+1; j < n; ++j){
					int vetx = j-i;
					int vety = hs[j]-hs[i];
					double temp = atan2(vety, vetx);
					if(temp > maior+1e-11){
						maior = temp;
						ind = j;
					}
				}
				if(ind != ds[i]) goto sai;
			}
			for(int i = 0; i < n; ++i){
				printf(" %d", hs[i]);
			}
			printf("\n");
			break;
			sai:;
		}
		if(ct >= 7000000) printf(" Impossible\n");
	}
	return 0;
}