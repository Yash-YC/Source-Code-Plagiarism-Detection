
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
int map[11][10000];

int sum(int i,int base){
    int x=0;
    while(i>0){
        x+=(i%base)*(i%base);
        i=i/base;
    }
    return x;
}
int test(int i, int base)
{
#if DEBUG
    printf("->(%d,%d)\n",i,base);
#endif
    if (i==0) {printf("ERROR i=0!\n"); return 1;}
    if (i<10000 && map[base][i]!=0)
        return map[base][i];
    if (i<10000) map[base][i]=-1;
    int x=sum(i,base);
    int m = test(x,base);
    if (i<10000) map[base][i]=m;
    return m;
}

int solve()
{
    char s[1000];
    gets(s);
    char *p;
    p = strtok(s," ");
    int n,i,j;
    int list[20];
    for (n=0;p!=NULL; p=strtok(NULL, " "), n++)
    {
        list[n] = atoi(p);
#if DEBUG
        printf("%d\n",list[n]);
#endif
    }
    for (i=2; i<100000; i++){
        for (j=0; j<n; j++)
            if (test(i,list[j])==-1){
                break;
            }
        if (j==n)
            return i;
    }
        
    if (i==100000)
        printf("ERROR\n ");
    
    return 0;
    
}

main() {
    
    int i,j;
    for (i=0; i<11; i++)
        map[i][1]=1;
    char s[100];
    gets(s);
    int c;
    sscanf(s, "%d", &c);
    for (i=0; i<c; i++)
    {
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}