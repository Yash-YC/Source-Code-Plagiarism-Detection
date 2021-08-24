#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
char temp[1024];
int base[25];
int T;
int convert(int n, int b){
	int res = 0;
	while( n > 0){
		int r = n % b;
		n /= b;
		res += r * r;
	}
	return res;
}

bool isHappy(int n, int b){
	set<int> all;
	all.insert(n);
	
	while(1){
		if( n == 1)
			return true;
		n = convert(n, b);
		if( all.count(n) != 0)
			return false;
		all.insert(n);
	}
	return false;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	gets(temp);
	sscanf(temp, "%d", &T);
	for(int t = 1; t <= T; t++){
		gets(temp);
		istringstream inp(temp);
		int id = 0;
		while( inp>>base[id]){
			id++;
		}
		for(int n = 2; ; n++){
			bool fine = true;
			for(int i = 0; i < id; i++){
				if( !isHappy(n, base[i])){
					fine = false;
					break;
				}
			}
			if( fine){
				printf("Case #%d: %d\n", t, n);
				break;
			}

		}
	}
}