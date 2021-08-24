// CodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <set>
#include <map>

/////////////////////////
///@author: sakar2003 ///
///@lang: C++         ///
/////////////////////////

using namespace std;

const int MAXN = 1 << 20;

int T;
string s;
int base[10],N;
int m[MAXN][11];

void preprocess(string &s){
	int idx = 0;
	memset(base, 0, sizeof(base));
	for(int i = 0;  i < s.size(); ++i){
		if(s[i] == ' '){
			++idx;
		}
		else{
			base[idx] = base[idx] * 10 + s[i] - '0';
		}
	}
	N = idx + 1;
}

bool match(int v, int b){	
	set<int> si;
	while(si.find(v) == si.end() && m[v][b] < 0){
		si.insert(v);
		int vv = 0;
		while(v){
			int x = v % b;
			vv += x * x;
			v /= b;
		}
		v = vv;
	}
	if(m[v][b] >= 0){
		for(set<int>::iterator it = si.begin(); it != si.end(); ++it) if(*it < MAXN){
			m[*it][b] = m[v][b];
		}		
	}
	else {
		for(set<int>::iterator it = si.begin(); it != si.end(); ++it) if(*it < MAXN){
			m[*it][b] = 0;
		}
	}
	return m[v][b];
}

int solve(){
	memset(m, -1, sizeof(m));
	for(int i = 0; i < 11; ++i) m[1][i] = 1;
	for(int i = 2; ; ++i){		
		bool f = true;
		for(int j = 0; f && j < N; ++j){
			if(m[i][base[j]] == 0) f = false;
		}
		if(!f) continue;
		for(int j = 0; f && j < N; ++j){
			if(m[i][base[j]] != 1) f = false;
		}
		if(f) return i;
		f = true;
		for(int j = 0; f && j < N; ++j){
			if(!match(i, base[j])){
				f = false;
			}
		}
		if(f) return i;
	}
	return 0;
}

int main()
{
	freopen("A-large.in.txt", "r", stdin);
	freopen("Alarge.txt", "w", stdout);
	scanf("%d", &T);
	getline(cin, s);
	for(int tt = 1; tt <= T; ++tt)
	{
		getline(cin, s);
		preprocess(s);
		int ans = solve();
		printf("Case #%d: %d\n", tt, ans);
	}

	return 0;
}
