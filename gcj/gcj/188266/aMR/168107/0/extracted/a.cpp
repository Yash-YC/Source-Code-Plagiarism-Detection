#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
set<int> vec[12];
bool mark[1100000][12];
bool luck[1100000][12];

bool check(int x, int b) {
    if(mark[x][b]) return luck[x][b];
    mark[x][b] = 1;
    int k = x;
    int sum = 0;
    while(k) {
        int t = k % b;
        sum += t * t;
        k /= b;
    }
    if(sum == 1) {
        return luck[x][b] = true;
    }
    return luck[x][b] = check(sum, b);
}

void init() {
    memset(mark, 0, sizeof(mark));
    memset(luck, 0, sizeof(luck));
    for(int i=0; i<=10; ++i)
        vec[i].clear();
    for(int i=2; i<=1000000; ++i) {
        for(int j=2; j<=10; ++j) {
            if(check(i, j)) {
                vec[j].insert(i);
            }
        }
    }
}

char ch[1010];
vector<int> tmp;

void work() {
    int u = tmp[0];
    for(set<int>::iterator it=vec[u].begin(); it!=vec[u].end(); ++it) {
        bool ok = true;
        for(int i=1; i<(int)tmp.size(); ++i) {
            int v = tmp[i];
            set<int>::iterator iter = vec[v].find(*it);
            if(iter == vec[v].end()) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        printf("%d\n", *it);
        return;
    }
}

int main() {
    init();
    freopen("a.txt", "w", stdout);
    int z, ca = 0;
    scanf("%d", &z);
    gets(ch);
    while(z--) {
        tmp.clear();
        gets(ch);
        int len = strlen(ch);
        int pos = 0, t;
        while(pos < len && sscanf(ch + pos, "%d", &t) == 1) {
            pos += 2;
            if(10 == t) ++pos;
            tmp.push_back(t);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        printf("Case #%d: ", ++ca);
        work();
    }
    return 0;
}
