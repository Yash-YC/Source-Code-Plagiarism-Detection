#include <bits/stdc++.h>
#define N 11111
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n,a[N],d[N],c_len,pos[N],fa[N][11],depth[N],done[N];
std::vector<int> point,son[N];
void clear(){
	memset(a, 0, sizeof a);
	memset(d, 0, sizeof d);
	memset(pos, 0, sizeof pos);
	memset(fa, 0, sizeof fa);
	memset(depth, 0, sizeof depth);
	memset(done, 0, sizeof done);
	point.clear();
	for (int i = 0; i < N; i ++ )
		son[i].clear();
}
void find_circle(int k){
	memset(d, 0, sizeof d);
	for (; !d[k]; d[k] = 1, k = a[k]);
	int k2 = a[k];//printf("|%d|\n", k);
	point.clear();
	point.push_back(k);
	for (; k2 != k; k2 = a[k2])
		point.push_back(k2);
	c_len = point.size();
	for (int i = 0; i < point.size(); i ++ )
		pos[fa[point[i]][0] = point[i]] = i + 1;
	for (int i = 0; i < point.size(); i ++ )
		for (auto j : son[point[i]]){
			if (pos[j]) continue;
			depth[j] = depth[point[i]] + 1;
			fa[j][0] = point[i];
			point.push_back(j);
		}
	for (auto i : point){
		done[i] = 1;
		//printf("%d ", i);
	}
	//printf("\n");
	for (int i = 0; i < 10; i ++ )
		for (auto j : point)
			fa[j][i + 1] = fa[fa[j][i]][i];
}
int lca(int x, int y){
	for (int i = 10; i >= 0; i -- )
		if (depth[fa[x][i]] >= depth[y]) x = fa[x][i];
	for (int i = 10; i >= 0; i -- )
		if (depth[fa[y][i]] >= depth[x]) y = fa[y][i];
	if (x == y) return x;
	for (int i = 10; i >= 0; i -- )
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}
int main(){
	Init;
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++ ){
		clear();
		printf("Case #%d: ", i);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) son[i].clear();
		for (int i = 1; i <= n; i ++ ){
			scanf("%d", &a[i]);
			son[a[i]].push_back(i);
		}
		int ans = 0, anss = 0;
		for (; ; ){
			bool flag = 0;
			for (int i = 1; i <= n; i ++ )
				if (!done[i]){
					flag = 1;
					find_circle(i);
					if (c_len > ans) ans = c_len;
					if (c_len == 2){
						int tans = 0;
						for (int i = 0; i < point.size(); i ++ )
							for (int j = i + 1; j < point.size(); j ++ ){
								int aa = 0;
								if (fa[point[i]][10] == fa[point[j]][10]){
									/*int LL = lca(point[i], point[j]);
									aa = depth[point[i]] + depth[point[j]] - depth[LL] * 2 + 1;
									if (aa > ans) ans = aa;*/
								}
								else{
									aa = depth[point[i]] + depth[point[j]] + 2;
									//int fi = fa[point[i]][10], fj = fa[point[j]][10];
									//if (std::abs(pos[fi] - pos[fj]) < c_len / 2) aa += c_len - std::abs(pos[fi] - pos[fj]);
									//else aa += std::abs(pos[fi] - pos[fj]);
									if (tans < aa) tans = aa;
								}
								//printf("%d %d %d\n", point[i], point[j], aa);
							}
						anss += tans;
					}
				}
			if (!flag) break;
		}
		printf("%d\n", ans > anss ? ans : anss);
	}
}
