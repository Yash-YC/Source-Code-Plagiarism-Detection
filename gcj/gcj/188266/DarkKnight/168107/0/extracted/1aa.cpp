#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
char tmp[9999];
int go(int a,int b)
{
    int i,j;
    set<int> H;
    H.insert(a);
    while(1){
        for(i=a,a=0;i>0;i/=b)
            a+=(i%b)*(i%b);
        if(H.count(a))break;
        H.insert(a);
    }
    return a==1;
}
main()
{
    int i,j,n,T,C=1,s[99];
    scanf("%d%*c",&T);
    while(T--){
        gets(tmp);
        char *p=strtok(tmp," ");
        for(n=0;p;n++){
            sscanf(p,"%d",s+n);
            p=strtok(NULL," ");
        }
        for(i=2,j=0;j<n;i++)
            for(j=0;j<n && go(i,s[j]);j++);
        printf("Case #%d: %d\n",C++,i-1);
    }
}
