#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define N 11814490

bool h[11][N];
int p[N];

int next(int n, int b){
	int ret = 0;
	while (n){
		int rem = n%b;
		n = n/b;
		ret += rem*rem;
	}
	return ret;
}

int find(int x){if (x==p[x]) return x; return p[x]=find(p[x]);}
void uni(int x, int y){x=find(x), y=find(y), p[x]=y;}

void precal(){
	for (int b=2;b<=10;++b){
		for (int i=1;i<N;++i)
			p[i] = i;
		h[b][1] = true;
		for (int i=2;i<N;++i)
			uni(i,next(i,b));
		find(1);
		for (int i=2;i<N;++i)
			h[b][i] = find(i)==p[1];
		printf("%d done\n", b);
	}
}

bool happy(int k, int b){
	while (k>=N) k = next(k,b);
	return h[b][k];
	
}

int main(){
	precal();
	int zz;
	string s;
	cin >> zz;
	getline(cin,s);
	for (int z=1;z<=zz;++z){
		getline(cin,s);
		istringstream sin(s);
		vector<int> a;
		int u;
		while (sin>>u)
			a.push_back(u);
		int ans=2;
		while (1){
			bool gd = true;
			for (int i=0;i<a.size();++i)
				if (!h[a[i]][ans]) gd=false;
//				if (!happy(ans,a[i])) gd=false;
			if (gd) break;
			++ans;
		}

		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
