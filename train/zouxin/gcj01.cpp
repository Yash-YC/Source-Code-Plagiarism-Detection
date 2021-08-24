#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))

char str[1005], now[3005];

int main(){
	int t, _case = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		int len = strlen(str);
		int s, e;
		s = 1005, e = 1006;
		now[s] = str[0];
		for(int i = 1; i < len; i++){
			if(str[i]<now[s]) {
				now[e] = str[i];
				e++;
			}
			else{
				now[--s] = str[i]; 
			}
		} 
		now[e] = 0;
		printf("Case #%d: %s\n", _case++, now+s);
	}
} 
