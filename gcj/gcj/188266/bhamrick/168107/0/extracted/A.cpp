#include<set>
#include<cstdio>
#include<cstdlib>

using namespace std;

bool happy(int n, int b) {
//	printf("%d %d\n",n,b);
	set<int> s;
	while(n!=1) {
		if(s.count(n) > 0) return false;
		s.insert(n);
		int nn = 0;
		while(n) {
			nn += (n%b)*(n%b);
			n /= b;
		}
		n = nn;
//		printf("%d\n",n);
	}
	return true;
}

int bases[11], nb;

int main() {
	FILE *fin = fopen("A.in","r");
	FILE *fout = fopen("A.out","w");
	int T;
	fscanf(fin,"%d ",&T);
	for(int k = 1; k<=T; k++) {
		nb = 0;
		char c = 0;
		int base = 0;
		fscanf(fin,"%c",&c);
		while(c != 10) {
			if(c == ' ') {
				bases[nb] = base;
				nb++;
				base = 0;
			} else {
				base = base * 10 + (c-'0');
			}
			fscanf(fin,"%c",&c);
//			printf("%d\n",c);
		}
		bases[nb] = base;
		nb++;
//		printf("nb = %d\n");
//		for(int i = 0; i<nb; i++) {
//			printf("%d ",bases[i]);
//		}
//		printf("\n");
		for(int i = 2; ; i++) {
			bool flag = true;
			for(int b = 0; b<nb; b++) {
				if(!happy(i,bases[b])) {
					flag = false;
					break;
				}
			}
			if(flag) {
				fprintf(fout,"Case #%d: %d\n",k,i);
				break;
			}
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
