#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 10000000

bool x[11][N];
char file[10] = "2.txt";

int main(){
    freopen("A-small-attempt0.out","w",stdout);
    freopen(file,"r",stdin);
    int t;
    for (int i=1 ;i<10 ;++i){
        if (i == 2 || i == 4){
            memset(x[i],1,sizeof(x[i]));
            continue;
        }    
        else memset(x[i],0,sizeof(x[i]));
        file[0] = '0'+i;
        freopen(file,"r",stdin);
        int t;
        while (scanf("%d",&t) != EOF) {
            x[i][t] = 1;
        }
    }    
    freopen("A-small-attempt0.in","r",stdin);
    int T;
    scanf("%d",&T);
    string s;
    getline(cin,s);
    int index = 0;
    int p = -1;
    int v[10];
    while (T--){
        printf("Case #%d: ",++index);
        getline(cin,s);
        istringstream ssin(s);
        int tmp;
        p= -1;
        while (ssin>>tmp) {
            if (tmp == 10) tmp =1;
            v[++p] = tmp;
        }    
        int k = -1;
        for (int i =2 ;i<N ;++i){
            bool f = 1;
            for (int j=0 ;j<=p ;++j) f = f & x[v[j]][i];
            if (f) {
                printf("%d",i);
                break;
            }    
        }    
        puts("");
    }     
    return 0;
}    
