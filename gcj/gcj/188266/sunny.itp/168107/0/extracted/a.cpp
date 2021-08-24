#include <cstdio>
#include <map>
#include <string.h>
using namespace std;

int ch(int x, int b){
	int r = 0, a[1000], ac;
	memset(a, 0, sizeof(a)); ac = 0;
	while (x>0){
		a[ac++] = x % b;
		x /= b;
	}
	for (int i=ac-1; i>=0; i--) r = r * 10 + a[i];
	return r;
}

bool happy(int x, int b){
	map<int, bool> ma; ma.clear();
	ma.insert( make_pair(x, true));
	while (x != 1){
		int r = 0;
		while (x>0){
			int t = x % 10;
			r += t*t;
			x /= 10;
		}
		x = ch(r, b);
		if (ma.find(x) == ma.end())
			ma.insert( make_pair(x, true));
		else break;
	}
	return x==1;
}

bool findhappy(int x, int b){
	int r = ch(x, b);
	//printf("%d %d %d\n", x, b, r);
	return happy(r, b);
}

int main(){
	int T, ca = 0;
	char s[1000];
	scanf("%d", &T); gets(s);
	while (T--){
		gets(s); int l, ll=0, x, a[15], ac;
		memset(a, 0, sizeof(ac)); ac = 0;
		while (sscanf(s+ll, "%d%n", &x, &l)>0){
			ll += l;
			a[ac++] = x; 
		}

		printf("Case #%d: ", ++ca);
		for (int i=2; i<100000000; i++){
			bool f = true;
			for (int j=0; j<ac; j++)
				if (!findhappy(i, a[j])){
					f = false;
					break;
				}
			if (f) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

