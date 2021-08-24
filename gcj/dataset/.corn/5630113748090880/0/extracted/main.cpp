#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
struct Time{
    clock_t c_lock=clock();
    ~Time(){
        fprintf(stderr,"\nrunning time: %lums\n",1000*(clock()-c_lock)/CLOCKS_PER_SEC);
    }
}Time;//return running time.
vector<vector<int> >mat,mat1,mat2;
int n,cases,t;
bool visited[55];
bool comp(const vector<int>&a,const vector<int>&b){
    return a[0]<b[0];
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d",&cases);
    for (int k=1; k<=cases; k++) {
        memset(visited, 0, sizeof visited);
        mat.clear();mat1.clear();mat2.clear();
        printf("Case #%d:",k);
        scanf("%d",&n);
        for (int i=0; i<2*n-1; i++) {
            vector<int>tmp;
            for (int j=0; j<n; j++) {
                scanf("%d",&t);
                tmp.push_back(t);
            }
            mat.push_back(tmp);
        }
        sort(mat.begin(), mat.end(),comp);
        for (int i=0;i<2*n-1;i+=2) {
            mat1.push_back(mat[i]);
        }
        for (int i=0; i<n; i++) {
            vector<int>tmp;
            for (int j=0; j<n; j++) {
                tmp.push_back(mat1[j][i]);
            }
            mat2.push_back(tmp);
        }
        for (int i=1,p=0; i<2*n-2; i+=2,p++) {
            visited[p]=1;
            if (mat2[p][0]==mat[i][0]) {
                for (int j=0; j<n; j++) {
                    if (mat2[p][j]!=mat[i][j]) {
                        mat2[p][j]=mat[i][j];
                        for (int s=0; s<n; s++) {
                            printf(" %d",mat2[s][j]);
                        }
                        break;
                    }
                }
            }
            else{
                for (int k=0; k<n; k++) {
                    printf(" %d",mat2[p][k]);
                }
                break;
            }
        }
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                for (int j=0; j<n; j++) {
                    printf(" %d",mat2[i][j]);
                }
            }
        }
        puts("");
    }
}