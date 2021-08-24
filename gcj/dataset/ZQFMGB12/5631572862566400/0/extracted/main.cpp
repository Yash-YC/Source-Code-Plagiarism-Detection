#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int T,N,ans;
int graph[1005];
vector<int> rev[1005];
bool flag[1005];
int dist[1005];
bool vis[1005];

int dfs(int nd,int par, int st){
    if (vis[nd]){
        if (nd == st || par == graph[nd]) return 0;
        return -10000;
    }
    vis[nd] = 1;
    return dfs(graph[nd],nd,st)+1;
}

int getDepth(int nd){
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    queue<int> q;
    q.push(nd);
    vis[nd] = 1;
    dist[nd] = 1;
    int cur = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for (int u : rev[cur]){
            if (!vis[u]){
                dist[u] = dist[cur]+1;
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    return dist[cur];
}

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf("%d",&N);
        ans = 0;
        for (int i = 0; i < 1005; i++)
            rev[i].clear();
        memset(graph,0,sizeof(graph));
        memset(flag,0,sizeof(flag));
        for (int i = 1; i <= N; i++){
            scanf("%d",&graph[i]);
            rev[graph[i]].push_back(i);
            if (i == graph[graph[i]]){
                flag[i] = 1;
            }
        }
        for (int i = 1; i <= N; i++){
            memset(vis,0,sizeof(vis));
            ans = max(ans,dfs(i,0,i));
        }
        for (int i = 1; i <= N; i++){
            if (flag[i]){
                int b1 = 0, b2 = 0;
                for (int u : rev[i]){
                    if (u != graph[i]){
                        int dep = getDepth(u);
                        if (dep > b1) b1 = dep;
                    }
                }
                for (int u : rev[graph[i]]){
                    if (u != i){
                        int dep = getDepth(u);
                        if (dep > b2) b2 = dep;
                    }
                }
                ans = max(ans,b1+b2+2);
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
