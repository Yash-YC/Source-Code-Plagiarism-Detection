#include<cstdio>
#include<cstring>
#include<cctype>

using namespace std;

int T,test;
int i,j,k,l,n;
int g[1000000];
int f[10000000][11];
char s[10000];
int a[100];

bool ok(int n,int m){
    int k;
    ++l;
    while(n>1){
        k=0;
        while(n){
            k+=(n%m)*(n%m);
            n/=m;
        }
        n=k;
        if(g[n]==l) return false;
        g[n]=l;
    }
    return true;
}

int main(){
    memset(g,0,sizeof(g));
    l=0;
    scanf("%d",&T);
    gets(s);
    for(test=1;test<=T;++test){
        gets(s);
        k=strlen(s);
        n=0;
        for(i=0;i<k;++i){
            while(i<k && !isdigit(s[i])) ++i;
            if(i<k){
                a[n]=0;
                while(i<k && isdigit(s[i])) a[n]=a[n]*10+s[i++]-'0';
                ++n;
            }
        }
        for(i=2;;++i){
            k=1;
            for(j=0;k && j<n;++j)
                if(!ok(i,a[j])) k=0;
            if(k) break;
        }
        printf("Case #%d: %d\n",test,i);
    }        
}
