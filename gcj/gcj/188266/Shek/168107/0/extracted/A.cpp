#pragma warning(disable : 4786)

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a[15];
int n;
char st[1000];
set<int> vis;
vector<int> vv;

void init(){
	gets(st);
	n = 0;
	for (int i = 0; i < (int)strlen(st); i++){
		if (i == 0 || st[i - 1] == ' '){
			sscanf(&st[i], "%d", &a[n]);
			n++;
		}
	}
}

bool _check(int m, int b){
	if (b == 2) return(true);

	vis.clear();
	vis.insert(m);

	while (true){
		vv.clear();

		// jinzhizhuanhuan
		while (m){
			vv.push_back(m % b);
			m /= b;
		}

		// qiuxinshuzi
		m = 0;
		for (int i = 0; i < (int)vv.size(); i++){
			m += (vv[i] * vv[i]);
		}

		if (m == 1) return(true);
		if (vis.find(m) != vis.end()) return(false);
		vis.insert(m);
	}
}

bool check(int m){
	for (int i = 0; i < n; i++){
		if (!_check(m, a[i])) return(false);
	}
	return(true);
}

void calc(int T){
	for (int i = 2; ; i++){
		if (check(i)) break;
	}
	printf("Case #%d: %d\n", T, i);
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, i;
	
	scanf("%d\n", &T);
	for (i = 1; i <= T; i++){
		init();
		calc(i);
	}
	return 0;
}
