#include <iostream>
using namespace std;

int __builtin_popcount(unsigned x){
	int res = 0;
	while(x){
		if(x & 1) ++res;
		x >>= 1;
	}
	return res;
}
const int N = 10;
int mask[1 << N], cnt;
double p[1 << N];
double dp(unsigned m){
	if(p[m] > -1) return p[m];
	double& res = p[m];
	res = 0;
	int repcnt = 0;
	double pacc = 0;
	for(int i = 0; i < cnt; ++i){
		unsigned m2 = m | mask[i];
		if(m2 == m){
			++repcnt;
		}
		else{
			pacc += dp(m2);
		}
	}
	return res = (cnt + pacc) / (cnt - repcnt);
	return res;
}
int main(){
	//freopen("ip.in", "r", stdin);
	//freopen("op.out", "w", stdout);
	int cas, n, c;
	scanf("%d", &cas);
	for(int cs = 1; cs <= cas; ++cs){
		scanf("%d%d", &c, &n);
		cnt = 0;
		for(int i = (1 << c) - 1; i >= 0; --i){
			int bits = __builtin_popcount(i);
			if(bits == n) mask[cnt++] = i;
			p[i] = -2;
		}
		p[(1 << c) - 1] = 0;
		printf("Case #%d: %.7f\n", cs, dp(0));
	}
	return 0;
}