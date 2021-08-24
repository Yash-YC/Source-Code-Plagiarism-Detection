#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class UF{
	public : 
	vector<int> parent;
	UF(int n) {
		parent.resize(n);
		for(int i=0; i<n; i++) parent[i] = i;
	}
	int find(int v) {
		if(v == parent[v]) return  v;
		return parent[v] = find(parent[v]);
	}
	bool uni(int v, int u) {
		v = find(v);
		u = find(u);
		if(v == u) return false;
		parent[v]  = u;
		return true;
	}
	
};

void check(vector<int> &parent, vector<int> &height, int cur) {
	if(height[cur] == -1) {
		check(parent, height, parent[cur]);
		height[cur] = height[parent[cur]] + 1;
	}
}

int solve() {
	int N;
	cin >> N;
	vector<int> input(N, 0), used(N, 0);
	for(int i=0; i<N; i++) {
		cin >> input[i];
		input[i] --;
		used[i] = 0;
	}
	UF uf(N);
	
	for(int i=0; i<N; i++) {
		uf.uni(i, input[i]);
	}
	vector<int> depth(N, -1);
	for(int i=0; i<N; i++) {
		int cur = i;
		bool flag = false;
		for(int j=0; j<2 * N; j++) {
			cur = input[cur];
			if(cur == i || flag) {
				flag = true;
//				cout <<" " << cur << endl;
				depth[cur] = 0;
			}
		}
	}
	
//	cout << "hoge" << endl;
	
	for(int i=0; i<N; i++) {
		if(depth[i] == -1) {
//			cout << i << endl;
			check(input, depth,  i);
			
		}
	}
	vector<vector<int> > parent(20, vector<int>(N, -1));
	for(int i=0; i<N; i++) parent[0][i] = input[i];
	
	for(int i=1; i<15; i++) {
		for(int j=0; j<N; j++)
			parent[i][j] = parent[i-1][parent[i-1][j]];
	}
	
//	cout << "piyo" << endl;
	
	vector<int> order(N, -1);
	vector<int> num_zero(N, -1);
	for(int i=0; i<N; i++) {
		if(depth[i] != 0) continue;
		if(order[i] != -1) continue;
		int num;
		{
			int cur = i;
			int j = 0;
			while( order[cur] == -1 ) {
				order[cur] = j;
				j++;
				cur = input[cur];
			}
			num = j;
		}
		int cur = i;
		while(num_zero[cur] == -1 ) {
			num_zero[cur] = num;
			cur = input[cur];
		}
	}
	/*+for(int i=0; i<N; i++) cout << depth[i] << " ";
	cout << endl;
	*/
	int ans = 0;
	for(int i=0; i<N;i++) 
		ans = max(ans, num_zero[i]);
	
	vector<int> father(N, -1);
	vector<int> bef(N,-1);
	for(int i=0; i<N; i++) {
		int cur = i;
		for(int j=0; j<depth[i]; j++) {
			if(j == depth[i]-1) bef[i] = cur;
			cur = input[cur];
			
		}
		father[i] = cur;
	}
	
//	cout << endl;
	vector<int> hoge(N, 0);
	for(int x=0; x<N; x++) {
		for(int y=x+1; y<N; y++) {
			if(uf.find(x) != uf.find(y)) continue;
//			cout << x << " " << y << " " << depth[x] << " "  << depth[y] << endl;
			
			int k = father[x];
			
			if(num_zero[k] != 2) continue;
//			cout << x << " " << y << " " << depth[x] << " "  << depth[y] << endl;
			if(depth[x] != 0 && depth[y] !=0) {
				if(father[x] == father[y]) continue;
			} 
			if( father[x] != father[y]){
				int ind = min(father[x], father[y]);
//				cout << father[x] << " " << father[y] << endl;
				hoge[ind] = max(hoge[ind], depth[x] + depth[y] + 2);
			}
//			cout << depth[x] << " " << depth[y] << endl;
			ans = max(ans, 2 + depth[x] + depth[y]);
			
		}
		
	}
/*	for(int i=0; i<N; i++)
		cout << hoge[i] << " ";
		cout << endl;
	*/
	int sss = 0;
	for(int i=0; i<hoge.size(); i++)
	 sss += hoge[i];
	ans = max(ans, sss);
	
	
	return ans;
	
}


int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		int ans = solve();
		cout << "Case #" << i+1 << ": " << ans <<  endl;
	}
	
	
	return 0;
}

