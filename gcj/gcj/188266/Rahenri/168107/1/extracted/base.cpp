#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int table[11][12000000];

int transforma(int n, int b) {
    int ret = 0;
    while(n>0) {
        int d = n%b;
        ret += d*d;
        n/=b;
    }
    return ret;
}

bool is_happy(int n, int b) {
    int x;
    for(x = n; table[b][x] == 0; x=transforma(x, b)) table[b][x] = 1;
    if(table[b][x] == 2) {
        for(x = n; table[b][x] != 2; x=transforma(x, b)) table[b][x] = 2;
        return true;
    } else {
        return false;
    }
}

int bases[10];

int main(void) {

    for(int i=2;i<=10;++i) table[i][1]=2;

    int T, K;
    scanf("%d ", &T);
    for(int t=0;t<T;++t) {
        char linha[256];
        gets(linha);
        K = 0;
        int p = 0, x;
        while(sscanf(linha+p, "%d%n", &bases[K], &x) != EOF) {
            p += x;
            K++;
        }
        int ret;
        for(int i=2;;++i) {
            //if(i%100000 == 0)
            //    fprintf(stderr, "%d\n", i);
            bool fail = false;
            for(int j=0;j<K;++j) {
                if(not is_happy(i, bases[j])) {
                    fail = true;
                    break;
                }
            }
            if(not fail) {
                ret = i;
                break;
            }
        }
        printf("Case #%d: %d\n", t+1, ret);


    }

    return 0;
}
