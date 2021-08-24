#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char buf[1000];
const int BC = 11;
int base[BC], basecnt;
const int N = 1000000;
int flag[BC][N];

int dp(int b, int n){
	int& res = flag[b][n];
	if(res >= 0) return res;
	if(n == 1) return res = 1;
	if(res == -2) return res = 0;
	res = -2;
	int m = n, sum = 0;
	while(m){
		int digit = m % b;
		sum += digit * digit;
		m /= b;
	}
	return res = sum >= N ? 0 : dp(b, sum);
}

int main(){
	//freopen("ip.in", "r", stdin);
	//freopen("op.out", "w", stdout);
	memset(flag, -1, sizeof(flag));
	for(int b = 2; b < BC; ++b){
		for(int n = 1; n < N; ++n)
			dp(b, n);
	}
	int cas;
	scanf("%d", &cas);
	gets(buf);
	for(int cs = 1; cs <= cas; ++cs){
		gets(buf);
		string str(buf);
		istringstream iss(str);
		basecnt = 0;
		while(iss >> base[basecnt]){
			++basecnt;
		}
		int res = 2;
		while(1){
			bool yes = true;
			for(int i = 0; i < basecnt && yes; ++i){
				if(flag[base[i]][res] != 1)
					yes = false;
			}
			if(yes) break;
			++res;
		}
		printf("Case #%d: %d\n", cs, res);
	}
	return 0;
}