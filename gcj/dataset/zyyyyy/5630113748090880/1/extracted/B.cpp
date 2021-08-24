#include <iostream> 
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <functional>
#include "stdlib.h" 
#include "time.h"
#include <set>
#include <map>
#include <numeric>
using namespace std;

#define INF 800
#define LL long long

int main() {
	
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T,cas = 1;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		int N;
		cin >> N;
		map<int, int> m;
		for (int i = 0; i < 2 * N * N - N; i++)
		{
			int k;
			cin >> k;
			map<int, int>::iterator mit;;
			mit = m.find(k);
			if (mit == m.end())
				m[k] = 1;
			else
				m[k] += 1;
		}
		vector<int> v;
		map<int, int>::iterator it = m.begin();
		for (; it != m.end(); ++it) {
			if (it->second % 2 == 1) {
				v.push_back(it->first);
			}
		}
		sort(v.begin(), v.end());

		printf("Case #%d:",cas);
		for (int i = 0; i < v.size(); i++)
			printf(" %d",v[i]);
		puts("");
	}
	return 0;
}

