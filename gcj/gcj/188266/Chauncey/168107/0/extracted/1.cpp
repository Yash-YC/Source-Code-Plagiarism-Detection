#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <functional>

using namespace std;

#define Rep(i,n) for (int i(0); i<(n); ++i)
#define Vs vector<string>
#define Vsi vector<string>::iterator
#define Vi vector<int>
#define Vii vector<int>::iterator
#define Wilv(v,iter,iter_end) (iter)=(v).begin(),(iter_end)=(v).end();while( (iter)!=(iter_end) )

typedef map<string, string> PMap;

inline int sq(int n)
{
    return n*n;
}

inline int next(int num, int base)
{
    int ret=0;
    while(num>0) {
        ret += sq(num%base);
        num /= base;
    }
    return ret;
}

char happynum[11][2000]={0};

int main()
{
    int N;
    freopen("..\\in.txt", "r", stdin);
    freopen("..\\out.txt", "w", stdout);

    scanf("%d", &N);

    string str;
    getline(cin, str);
    for(int ncase=1; ncase<=N; ncase++) {
        getline(cin, str);
        stringstream sst(str);
        Vi bases;
        int num;
        while(sst>>num){
            bases.push_back(num);
        }
        int n=2;
        for(; ; n++) {
            int size=bases.size();
            int i=0;
            for(;i<size;i++) {
                int base = bases[i];
                bool is = false;
                char f[2000] = {0};
                int k = n;
                Vi path;
                while(true) {
                    k = next(k, base);
                    if(k==1 || happynum[base][k]==1){
                        is = true;
                        break;
                    } else if(happynum[base][k]==-1){
                        break;
                    } else {
                        path.push_back(k);
                    }
                    if(f[k]==1) break;
                    f[k] = 1;
                }
                if(is) {
                    int s = path.size();
                    Rep(j,s) {
                        happynum[base][path[j]] = 1;
                    }
                }
                else {
                    int s = path.size();
                    Rep(j,s) {
                        happynum[base][path[j]] = -1;
                    }
                    break;
                }
            }
            if(i==size) break;
        }

        printf("Case #%d: %d\n", ncase, n);
    }

    return 0;
}

