#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

#define MAXN 1123123

int vis[MAXN][20];

int sum(int n, int b){
    int sum = 0;
    if (n == 0) return 0;
    while(n){
	sum = sum + (n % b)*(n % b);
	n /= b;
    } 
    return sum;
}


int is_happy(int n, int b){
    if (n == 1) return 1;
    if (vis[n][b] != -1) return vis[n][b];
    vis[n][b] = 0;
    vis[n][b] = is_happy(sum(n, b), b);   
    return vis[n][b];
}

vector<int> split(string line, char ch){
    vector<int> r;
    string t;
    for (int i = 0; i < line.length(); i++){
	if (line[i] == ch && !t.empty()){
	    r.push_back(atoi(t.c_str()));
	    t = "";
	}
	else 
	    t.push_back(line[i]);
    }
    r.push_back(atoi(t.c_str()));
    return r;	
}
int main (){ 

    int t, cases = 1;
    string str;

    scanf("%d\n", &t);

    
    while (t--){

	getline(cin, str, '\n');
	vector<int> r = split(str, ' ');

	memset(vis, -1, sizeof(vis));
	for (int i = 2; i < 100000; i++){    
	    int ok = 1;
	    for (int j = 0; j < r.size(); j++){
		int b = r[j];
		//cout << b << endl;
		if (is_happy(i, b) != 1){
		    ok = 0;
		    break;
		}
	    }
	    if (ok){
		cout << "Case #" << cases++ << ": " << i << endl;
		break;
	    }
	}

    }    
    return 0;
}
