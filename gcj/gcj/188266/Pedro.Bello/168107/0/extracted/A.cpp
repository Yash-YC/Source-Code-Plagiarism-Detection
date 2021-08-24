#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

char text[500];
int nb;
int bases[20];
map<int, int> memo[11];

bool read(){
	gets(text);
	istringstream s(text);
	nb = 0;
	while(s >> bases[nb]){
		nb++;
	} 
	return true;
}

int square(int n, int b){
	int resp = 0;
	while(n){
		resp += (n%b)*(n%b);
		n /= b;
	}
	return resp;
}
bool happy(int n, int b){
	
	if(memo[b].find(n) != memo[b].end()){
		if(memo[b][n] == 2){
			return false;
		}else{
			return (memo[b][n] == 1) ? true : false;
		}
	}else if(n == 1){
		return true;
	}else{
		memo[b][n] = 2;
		bool val = happy(square(n,b), b);
		if(val){
			memo[b][n] = 1;
		}else{
			memo[b][n] = 0;
		}
		return val;
	}
}

int caso = 1;

void process(){
	bool off;
	printf("Case #%d: ", caso++);
	
	for(int i = 2; ; i++){
		off = false;
		for(int j = 0; j < nb; j++){
			if(!happy(i,bases[j])){
				off = true;
				break;
			}	
		}
		if(!off){
			printf("%d\n", i);
			return;
		}
	}
}

int main(){
	int casos;
	
	freopen("data.in","r", stdin);
	freopen("data.out","w", stdout);
	
	scanf("%d", &casos);
	for(int i = 0; i <= 10; i++)
		memo[i].clear();
	gets(text);
	
	while(casos--){
		read();
		process();
	}
	
	return 0;
}
