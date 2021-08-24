#include <iostream>
using namespace std;
const int MAXN = 20000000
int base;
int x[20];
int p;
int n = 100;

int test(int n,int base){
    int res = 0;
    p = -1;
    while (n){
        res += (n % base) * (m % base);
        n /= base;
    }    
    return res;
}
    
int main(){
    char file[10] = "0.txt";
  for(int I = 2;I < 10;++I){  
    file[0] = '0' + I;
    freopen(file,"w",stdout);
    base = I;
    for (int i=2 ;i<=MAXN; ++i){
        int n(10),k(i);
        while(k != 1){
            k = test(k,base);
            //for (int j=p ;j>=0 ;--j) cout<<x[j];cout<<endl;
           // cout<<k<<endl;
           --n;
        }
        if (k == 1) printf("%d\n",i);
    }    
  }
    return 0;
}    
