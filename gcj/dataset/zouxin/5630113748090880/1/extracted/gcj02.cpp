#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))

int M[2505], ans[55];

int main(){
	int t, _case = 1;
	int n, num;
	scanf("%d", &t);
	while(t--){
		mem0(M);
		scanf("%d", &n);
		int top = 2*n-1;
		for(int i = 0; i < top; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &num);
				M[num]++;	
			}
		}	
		int len = 0;
		for(int i = 0; i < 2505 && len < n; i++){
			if(M[i]&1){
				ans[len++] = i;
			}
		}
		printf("Case #%d: ", _case++);	
		for(int i = 0; i < len-1; i++){
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[len-1]);
	}
}
