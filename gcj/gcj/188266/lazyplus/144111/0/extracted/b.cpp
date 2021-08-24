#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN  =   20+2;

int s[MAXN][MAXN];
int w[MAXN][MAXN];
int t[MAXN][MAXN];
int best[MAXN*2][MAXN*2];

int n, m;

void readin(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            scanf("%d%d%d", &s[i][j], &w[i][j], &t[i][j]);
            t[i][j] %= (s[i][j] + w[i][j]);
        }
}

struct state{
    int x, y;
    state(){};
    state(int a,int b):x(a), y(b){}
};

vector< state > que[3];

bool canpass(int x,int y,int t, int d){
    x >>= 1;
    y >>= 1;
    return d^((t+s[x][y]+w[x][y]-(::t[x][y])) % (s[x][y]+w[x][y]) < s[x][y]);
}

void solve(){
    int x,y;
    
    memset(best, -1, sizeof(best));
    que[0].clear();
    que[1].clear();
    que[2].clear();
    
    que[0].push_back( state(n*2-1, 0) );
    best[n*2-1][0] = 0;
    
    for(int t=0; ; ++t){
        vector< state > &q = que[t % 3];
        vector< state > &block = que[(t+2)%3];
        vector< state > &corner = que[(t+1)%3];
        //printf("time %d\n", t);
        for(unsigned int i=0; i<q.size(); ++i){
            x = q[i].x; y = q[i].y;
            
            //printf("expanding %d %d\n", x, y);
            
            if(x == 0 && y == 2*m -1){
                printf("%d\n", t);
                return;
            }
            //stay
            corner.push_back( state(x,y) );
            
            
            //down
            if(x < 2*n -1){
                if(x % 2){
                    if(best[x+1][y] == -1 || best[x+1][y] > t+2){
                        block.push_back( state(x+1, y) );
                        best[x+1][y] = t+2;
                    }
                }else{
                    if((best[x+1][y] == -1 || best[x+1][y] > t+1) && canpass(x,y,t,0)){
                        corner.push_back( state(x+1, y) );
                        best[x+1][y] = t+1;
                    }
                }
            }
            
            //up
            if(x > 0){
                if(x % 2){
                    if((best[x-1][y] == -1 || best[x-1][y] > t+1) && canpass(x,y,t,0)){
                        corner.push_back( state(x-1, y) );
                        best[x-1][y] = t+1;
                    }
                }else{
                    if(best[x-1][y] == -1 || best[x-1][y] > t+2){
                        block.push_back( state(x-1, y) );
                        best[x-1][y] = t+2;
                    }
                }
            }
            
            //right
            if(y < 2*m -1){
                if(y % 2){
                    if(best[x][y+1] == -1 || best[x][y+1] > t+2){
                        block.push_back( state(x, y+1) );
                        best[x][y+1] = t+2;
                    }
                }else{
                    if((best[x][y+1] == -1 || best[x][y+1] > t+1) && canpass(x,y,t,1)){
                        corner.push_back( state(x, y+1) );
                        best[x][y+1] = t+1;
                    }
                }
            }
            
            //left
            if(y > 0){
                if(y % 2){
                    if((best[x][y-1] == -1 || best[x][y-1] > t+1) && canpass(x,y,t,1)){
                        corner.push_back( state(x, y-1) );
                        best[x][y-1] = t+1;
                    }
                }else{
                    if(best[x][y-1] == -1 || best[x][y-1] > t+2){
                        block.push_back( state(x, y-1) );
                        best[x][y-1] = t+2;
                    }
                }
            }
        }
        q.clear();
    }
}

int main(){
    int c;
    scanf("%d", &c);
    for(int i=1; i<=c; ++i){
        readin();
        printf("Case #%d: ", i);
        solve();
    }
}
