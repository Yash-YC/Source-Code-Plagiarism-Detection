#include<cstdio>
#include<cstring>
#include<cctype>

using namespace std;

const int ans[11]={0,0,11814485,11814485,11814485,4817803,346719,28099,711725,2688153,569669};

int T,test;
int i,j,k,l,n;
int g[1000000];
int f[10000000][11];
char s[10000];
bool b[100];
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
        if(n==9){
            printf("Case #%d: 11814485\n",test);
            continue;
        }
        if(n==8){
            memset(b,1,sizeof(b));
            for(i=0;i<n;++i) b[a[i]]=false;
            for(i=2;i<=10;++i)
                if(b[i]) break;
            printf("Case #%d: %d\n",test,ans[i]);    
            continue;            
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
