#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fcntl.h>

using namespace std;

const int M = 1<<9;
static int res[M];

bool testHappiness(long long n, int b) {
	set<long long> v;
	while (v.find(n) == v.end()) {
		v.insert(n);
		long long newN = 0;
		while (n) {
			newN += (n%b)*(n%b);
			n /= b;
		}
		n = newN;
	}
	return n==1;
}

void init() {
	for (int i=2; !res[M-1]; ++i) {
		int k=0;
		for (int j=2; j<=10; ++j) {
			if (testHappiness(i,j)) 
				k |= 1<<(j-2);
		}
		if (res[k] == 0) res[k] = i;
	}
	for (int i=M-1; i>0; --i) {
		if (res[i] == 0) {
			res[i] = res[M-1];
		}

			for (int k=2; k<=10; ++k) {
				int j = i | (1<<(k-2)) ;
				if (j!=i) res[i] = min(res[i],res[j]);
			}
	}
}

void precomp() {
	FILE *f = fopen("precomp.txt","w");
	init();
	for (int i=0; i<M; ++i) fprintf(f,"%d\n",res[i]);
	fclose(f);
}

void readres() {
	FILE *f = fopen("precomp.txt","r");
	for (int i=0; i<M; ++i) fscanf(f,"%d\n",res+i);
}

int main(int argc,char**argv) {
	if (argc>1) {
		precomp();
		return 0;
	}
	readres();
	int c;
	char buffer[100];
	scanf("%d\n",&c);
	for (int ic=1; ic<=c; ++ic) {
		fgets(buffer,100,stdin);
		int k=0;
		int t;
		istringstream in(buffer);
		while (!in.eof()) {
			in >> t;
			if (in.eof()) break;
			k |= 1<<(t-2);
		}
		printf("Case #%d: %d\n",ic,res[k] );
	}
	return 0;
}
