#include <stdio.h>
#include <cstring>
#include <set>

using namespace std;

int MAXN = 18000000;

inline int sqr(int a){
	return a * a;
}

set <int> se;
set <int> :: iterator it;

int can[11][20000000];
int out[1024], ret[1024];

int main(){
	int cur, tmp, last, val;
	
	memset(can, 0xff, sizeof(can));
	for(int base = 3;base <= 10;base++){
		for(int i = 2;i < MAXN;i++) if(can[base][i] < 0){
			se.clear();
			cur = i;
			while(cur != 1 && cur <= MAXN && se.find(cur) == se.end()){
				if(can[base][cur] == 1){
					cur = 1;
					break;
				}
				if(can[base][cur] == 0){
					cur = MAXN + 1;
					break;
				}
				se.insert(cur);
				tmp = 0;
				while(cur){
					tmp += sqr(cur % base);
					cur /= base;
				}
				cur = tmp;
			}
			if(cur == 1)
				val = 1;
			else
				val = 0;
			for(it = se.begin();it != se.end();it++)
				can[base][*it] = val;
		}
	}
	memset(out, 0, sizeof(out));
	for(int i = 2;i < MAXN;i++){
		tmp = 0;
		for(int j = 3;j <= 10;j++)
			tmp = (tmp << 1) | can[j][i];
		if(out[tmp] == 0)
			out[tmp] = i;
	}
	memset(ret, 0, sizeof(ret));
	for(int i = 0;i < 256;i++)
		for(int j = 0;j < 256;j++)
			if((i | j) == i)
				if(out[i]){
					if(out[i] < ret[j] || ret[j] == 0)
						ret[j] = out[i];
				}
	for(int i = 0;i < 256;i++)
		printf("%d, ", ret[i]);
		//printf("%d:%d\n", i, ret[i]);
	return 0;
}
