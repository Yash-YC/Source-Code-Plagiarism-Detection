#include<iostream>
using namespace std;

bool vis[800];

bool ok( int s, int d ){
    //cout<<s<<" "<<d<<endl;
    memset( vis, 0, sizeof(bool)*800 );
    int t = 0;
    while( s>0 ){ t += (s%d)*(s%d); s /= d; }
    s = t;
    while( !vis[s] ){
        vis[s] = true;
        t = 0;
        while( s>0 ){ t += (s%d)*(s%d); s /= d; }
        if( t == 1 ) return true;
        //ut<<t<<endl;
        //( s > 800 ){ printf("wrong!\n"); break; }
        s = t;
    }
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cs = 0, t, an, a[10];
    scanf("%d",&t);
    getchar();
    while( t-- ){
        an = 0; char c; int tmp = 0;
        while( (c=getchar())!='\n' ){
            if( c==' ' && tmp!=0 ){ a[an++] = tmp; tmp = 0; }
            if( c>='0' && c<='9' ) tmp = 10*tmp+c-'0';
        }
        //cout<<tmp<<endl;
        a[an++] = tmp;
        //for(int i=0; i<an; i++) printf("%d ",a[i]); printf("\n");
        printf("Case #%d: ",++cs);
        for(int i=2, j; i<=10000000; i++){
            for(j=0; j<an; j++){
                if( !ok( i, a[j] ) ) break;
            }
            if( j == an ){ printf("%d\n",i); break; }
            if( i== 10000000 ) printf("wrong!\n");
        }
    }
    return 0;
}
