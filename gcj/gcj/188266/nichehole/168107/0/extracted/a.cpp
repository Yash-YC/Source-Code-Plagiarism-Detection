#include <cstdio>
#include <cstring>


int Q[100000], b[20], bn;
bool v[1000000];

bool check(int n, int base) {
	memset(v, 0, sizeof(v));
	int sum=n, h=0;
	while (sum!=1) {
		//printf("%d\n", sum);
		//Q[h++] = sum;
		if (v[sum]) return 0; v[sum]=1;
		n=sum; sum=0; 
		while (n) {
			sum += (n%base)*(n%base);
			n /= base;
		}
	}
	return 1;
}

int go() {
	bool f=0;
	for (int i=2;!f;i++) {
		//printf("trying %d\n", i);
		for (int j=0;j<bn;j++) {
			f = check(i, b[j]);
			if (!f) break;
		}
		if (f) return i;
	}
}

int main() {
	char s[10000];
	int T; scanf("%d", &T); gets(s);
	for (int cas=0; cas<T;cas++) {
		int sp=0, spn; bn=0;
		gets(s);
		while (sscanf(s+sp, "%d%n", &b[bn], &spn)>0) {
			bn++;
			sp+=spn;
		}
		//for (int i=0;i<bn;i++) printf("%d ", b[i]); puts("");
		int ret = go();
		printf("Case #%d: %d\n", cas+1, ret);
	}
	return 0;
}
