#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

const int MAXN = 1000;

char str[1000], cs[1000];
int num[1000], len;
int mark[MAXN], tot;
int c[1000];

void convert(int x, int b, int num[], int &len) {
    len = 0;
    while (x) {
        num[len] = x % b;
        len ++;
        x /= b;
    }
}
    
int check(int x, int b) {
    memset(mark, 0, sizeof(mark));
    while (x != 1) {
        if (x < MAXN) mark[x] = 1;
       	convert(x, b, num, len);
       	x = 0;
       	for (int i=0;i<len;i++) x += num[i] * num[i];
       	if (x < MAXN && mark[x]) break;
   }
   return x == 1;
}

void init() {
	stringstream ss(str);
	tot = 0;
	while (ss>>cs)
	    if (strlen(cs) == 1) c[tot++] = cs[0] - '0'; else c[tot++] = 10;
//    for (int i=0;i<tot;i++) printf("%d\n", c[i]);
}
     
void work() {
    int x = 1, ok;
    do {
        x ++;
        ok = 1;
        for (int i=0;i<tot;i++)
        	if (!check(x, c[i])) { ok = 0; break; }
    } while (!ok);
    printf("%d\n", x);
}
    
int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    init();
    int T;
    scanf("%d", &T);
    gets(str);
    for (int ti=1;ti<=T;ti++) {
        printf("Case #%d: ", ti);
        gets(str);
//        printf("%s\n", str);
    	init();
    	work();
   	}   	
    return 0;
}
