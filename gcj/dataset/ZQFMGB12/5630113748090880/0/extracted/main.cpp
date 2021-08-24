#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Data{
    int v[105];
}H[105];
int T,N,h;
int ans[55][55];
bool taken[105];

bool cmp(const Data &d1, const Data &d2){
    for (int i = 0; i < N; i++){
        if (d1.v[i] == d2.v[i]) continue;
        return d1.v[i] < d2.v[i];
    }
    return 1;
}

bool eq(const vector<int> &v1, int ar[]){
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] != ar[i]) return 0;
    }
    return 1;
}

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf("%d",&N);
        for (int i = 0; i < 105; i++) memset(H[i].v,0,sizeof(H[i].v));
        memset(taken,0,sizeof(taken));
        for (int i = 0; i < 2*N-1; i++){
            for (int j = 0; j < N; j++){
                scanf("%d",&H[i].v[j]);
            }
        }
        sort(H,H+2*N-1,cmp);
        int row = 1, col = 1;
        //generate answer
        for (int i = 0; i < N; i++) ans[0][i] = H[0].v[i];
        for (int i = 0; i < N; i++) ans[i][0] = H[1].v[i];
        for (int i = 2; i < 2*N-1; i++){
            if (H[i].v[0] == ans[row][0]){
                for (int j = 0; j < N; j++) ans[row][j] = H[i].v[j];
                row++;
            }else{
                for (int j = 0; j < N; j++) ans[j][col] = H[i].v[j];
                col++;
            }
        }
        bool flag = 0;
        //check rows
        for (int i = 0; i < N; i++){
            vector<int> vect;
            for (int j = 0; j < N; j++)
                vect.push_back(ans[i][j]);
            bool ex = 0;
            for (int j = 0; j < 2*N-1; j++){
                if (!taken[j] && eq(vect,H[j].v)){
                    taken[j] = 1;
                    ex = 1;
                    break;
                }
            }
            if (!ex){
                printf("Case #%d:",z);
                for (int i = 0; i < vect.size(); i++){
                    printf(" %d",vect[i]);
                }
                printf("\n");
                flag = 1;
                break;
            }
        }
        //check cols
        if (!flag){
            for (int i = 0; i < N; i++){
                vector<int> vect;
                for (int j = 0; j < N; j++){
                    vect.push_back(ans[j][i]);
                }
                bool ex = 0;
                for (int j = 0; j < 2*N-1; j++){
                    if (!taken[j] && eq(vect,H[j].v)){
                        taken[j] = 1;
                        ex = 1;
                        break;
                    }
                }
                if (!ex){
                    printf("Case #%d:",z);
                    for (int i = 0; i < vect.size(); i++){
                        printf(" %d",vect[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
