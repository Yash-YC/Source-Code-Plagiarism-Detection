#include<map>
#include<set>
#include<cstdio>
#include<cstdlib>

#define MAXANS 11814486

using namespace std;

map<pair<int,int>, bool> mem;

bool happy(int n, int b) {
//	printf("%d %d\n",n,b);
	set<int> s;
	while(n!=1) {
		if(mem.count(make_pair(n,b)) > 0) return mem[make_pair(n,b)];
		if(s.count(n) > 0) {
			for(set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
				mem[make_pair(*iter,b)]=false;
			}
			return false;
		}
		s.insert(n);
		int nn = 0;
		while(n) {
			nn += (n%b)*(n%b);
			n /= b;
		}
		n = nn;
//		printf("%d\n",n);
	}
	for(set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		mem[make_pair(*iter,b)]=true;
	}
	return true;
}

int bases[11], nb, ans[512];

int main() {
	FILE *fin = fopen("A.in","r");
	FILE *fout = fopen("A.out","w");
	int T;
	fscanf(fin,"%d ",&T);
	for(int i = 0; i<512; i++) ans[i] = 0;
	for(int i = 2; i<MAXANS; i++) {
		int mask = 0;
		for(int b = 0; b<9; b++) {
			if(happy(i,b+2)) {
				mask |= (1<<b);
			}
		}
		if(ans[mask] == 0) {
			ans[mask] = i;
		}
	}
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
		int mask = 0;
		for(int i = 0; i<nb; i++) {
			mask |= (1<<(bases[i]-2));
		}
		int tans = MAXANS;
		for(int i = 0; i<512; i++) {
			if((mask & (~i))==0) {
				if(ans[i] < tans && ans[i] != 0) tans = ans[i];
			}
		}
		fprintf(fout,"Case #%d: %d\n",k,tans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
