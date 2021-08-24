#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
struct node {
	int kid;
	int level;
};

int main()
{
	FILE *fin, *fout;
	fin = fopen("C-small-attempt0.in", "r");
	fout = fopen("C-small-attempt0.out", "w");
	int t;
	fscanf(fin, "%d", &t);
	//scanf("%d", &t);
	for (int r = 1; r <= t; ++r) {
		int n;
		fscanf(fin, "%d", &n);
		//scanf("%d", &n);
		vector<bool> used(n + 1, false);
		vector<int> like(n + 1);
		vector<unordered_set<int> > be_liked(n + 1);
		for (int i = 1; i <= n; ++i) {
			int m;
			fscanf(fin, "%d", &m);
			like[i] = m;
			be_liked[m].insert(i);
		}
		int maxL = 0;
		for (int i = 1; i < n; ++i) {
			int curL = 0;
			vector<bool> used(n + 1, false);
			int curKid = i;
			used[curKid] = true;
			while (!used[like[curKid]]) {
				curKid = like[curKid];
				used[curKid] = true;
			}
			int start = curKid;
			while (1) {
				int l1 = 0;
				queue<node> q;
				node temp;
				temp.kid = curKid;
				temp.level = 1;
				q.push(temp);
				while (!q.empty()) {
					node cur = q.front();
					q.pop();
					unordered_set<int> curBeLike = be_liked[cur.kid];
					l1 = cur.level;
					for (unordered_set<int>::iterator iter=curBeLike.begin();iter!=curBeLike.end();iter++) {
						if (!used[*iter]) {
							node temp;
							temp.kid = *iter;
							temp.level = cur.level + 1;
							q.push(temp);
						}
					}
				}
				curL += l1;
				curKid = like[curKid];
				if (curKid == start)
					break;
			}
			maxL = max(maxL, curL);
		}

		fprintf(fout, "Case #%d: %d\n", r, maxL);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}