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

using namespace std;

int ds[10002], hs[10002], dfim;
int pd[10002];

int main(){
	int t, n;
	scanf("%d", &t);
	for(int _ = 1; _ <= t; ++_){
		printf("Case #%d: ", _);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &ds[i], &hs[i]);
		}
		scanf("%d", &dfim);
		ds[n] = dfim;
		hs[n] = 0;
		int at = 0, prox = 1;
		int swing = ds[0];
		memset(pd, -1, sizeof pd);
		pd[0] = swing;
		for(int i = 0; i < n; ++i){
			if(pd[i] < 0) continue;
			for(int j = i+1; j <= n; ++j){
				int dist = ds[j]-ds[i];
				if(pd[i] < dist) break;
				int temp = min(dist, hs[j]);
				if(temp > pd[j]){
					pd[j] = temp;
				}
			}
		}
		if(pd[n] < 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}