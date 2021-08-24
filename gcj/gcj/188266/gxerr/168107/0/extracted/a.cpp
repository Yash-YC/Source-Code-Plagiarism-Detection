// a.cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

char line[30];
bool bases[11];

set<int> calculated;

bool accept_base(int n, int base) {
	if(calculated.find(n) != calculated.end()) {
		return false;
	}
	if(n == 1) {
		return true;
	}
	calculated.insert(n);
	int nn = 0;
	while(n) {
		nn += (n % base) * (n % base);
		n /= base;
	}
	
	return accept_base(nn, base);
}


bool accept(int n) {
	for(int i = 2; i <= 10; i++) {
		calculated.clear();
		if(bases[i] && !accept_base(n, i)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	gets(line);
	for(int casa = 1; casa <= n; casa++) {
		gets(line);
	//	printf("%s\n", line);
		for(int i = 1; i < 11; i++) {
			bases[i] = false;
		}
		for(int i = 0; line[i] != '\0'; i++) {
			if(line[i] != ' ') {
				if(line[i] == '1' && line[i] != '\0') {
					bases[10] = true;
					i ++;
				} else {
					bases[line[i] - '0'] = true;
				}
			}
		}
	/*	for(int i = 1; i < 11; i++) {
			if(bases[i]) {
				printf("%d\n", i);
			}
		}*/
		for(int i = 2; ; i++) {
			if(accept(i)) {
				printf("Case #%d: %d\n", casa, i);
				break;
			}
		}
	}
}
