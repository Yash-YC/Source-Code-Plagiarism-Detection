#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
struct Time{
    clock_t c_lock=clock();
    ~Time(){
        fprintf(stderr,"\nrunning time: %lums\n",1000*(clock()-c_lock)/CLOCKS_PER_SEC);
    }
}Time;//return running time.

deque<char>dq;
char str[1111];
int cases;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d",&cases);
    for (int k=1; k<=cases; k++) {
        memset(str, 0, sizeof str);
        dq.clear();
        printf("Case #%d: ",k);
        scanf("%s",str);
        int len=(int)strlen(str);
        dq.push_back(str[0]);
        for (int i=1; i<len; i++) {
            if (str[i]>=dq.front()) {
                dq.push_front(str[i]);
            }else{dq.push_back(str[i]);}
        }
        for (int i=0; i<len; i++) {
            printf("%c",dq[i]);
        }
        puts("");
    }
}