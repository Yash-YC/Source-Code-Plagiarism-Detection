#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int maxN = 10000;
int p[maxN];
bool help[maxN];
bool hasC[maxN];
char buf[128];

inline int convert(int n, int base) {
	char buf[32];
	itoa(n, buf, base);
	int res = 0;
	for (int i =0; buf[i]; ++i)
		res = res * 10 + buf[i] - '0';
	return res;
}
bool computeN(int n, int base) {
	set<int> temp;
	temp.insert(n);
	n = convert(n, base);
	while(n) {
		int t = 0;
		while(n) {
			t += (n%10) * (n%10);
			n/=10;
		}
		n = t;
		if (n==1) {
			return true;
		//} else if (hasC[n]) {
		//	return help[n];
		} else if (temp.find(n)!=temp.end()) 
			return false;
		temp.insert(n);
		n = convert(n, base);
	}
	return false;
}

//void getBase(int base) {
//	memset(help, 0, sizeof help);
//	memset(hasC, 0, sizeof hasC);
//	for (int i =2; i < maxN; ++i) {
//		if (computeN(i, base)){
//			++p[i];
//			help[i] = true;
//		} else {
//			help[i] = false;
//		}
//		hasC[i] = true;
//	}
//}

int main() {
	freopen("E:\\Ëã·¨\\GCJ\\09R1A\\A-small.in", "r", stdin);
	freopen("E:\\Ëã·¨\\GCJ\\09R1A\\A-small.out", "w", stdout);
	fgets(buf, 128, stdin);
//	gets(buf);
	int k[20];
	int nCase = atoi(buf);
	for (int cnt =1; cnt <= nCase; ++cnt) {
		fgets(buf, 128, stdin);
		memset(p, 0, sizeof p);
		istringstream iss(buf);
		int n = 0, temp;
		//while (iss >> temp) {
		//	getBase(temp);
		//	++n;
		//}	
		//for (int i = 0; i < maxN; ++i) {
		//	if (p[i] == n) {
		//		printf("Case #%d: %d\n", cnt, i);
		//		break;
		//	}
		//}
		while (iss >> temp) k[n++] = temp;
		for (int i = 2, j; ; ++i) {
			for (j =0; j < n; ++j)
				if (!computeN(i, k[j])) break;
			if (j<n) continue;
			printf("Case #%d: %d\n", cnt, i);
			break;
		}
	}
	return 0;
}
