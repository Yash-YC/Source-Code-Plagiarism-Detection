#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int base(int x,int b){
    int res(0);
    while(x){
        res += (x % b) * (x % b);
        x /= b;
    }
    return res;
}
bool vi[1000000];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int N;
    int a[20];
    string s;
    cin >> N;
    getline(cin,s);
    for(int I = 1;I <= N;++I){
        getline(cin,s);
        istringstream tout(s);
        int n(0);
        while(tout >> a[n++]);
        --n;
        bool flag;
        for(int i = 2;;++i){
            flag = 1;
            for(int j = 0;j < n && flag;++j){
                memset(vi,0,sizeof(vi));
                vi[i] = 1;
                int s(base(i,a[j]));
                while(!vi[s]){
                    vi[s] = 1;
                    s = base(s,a[j]);
                }
                if(s != 1){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                printf("Case #%d: %d\n",I,i);
                break;
            }
        }
    }
}
