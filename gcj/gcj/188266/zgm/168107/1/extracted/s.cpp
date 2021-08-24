#include<iostream>
using namespace std;

bool vs[800][11], vis[800];

bool right( int s, int d ){
    memset( vis, 0, sizeof(bool)*800 );
    while( !vis[s] ){
        vis[s] = true;
        int t = 0;
        while( s>0 ){ t += (s%d)*(s%d); s /= d; }
        if( t == 1 ) return true;
        s = t;
    }
    return false;
}

bool ok( int s, int d ){
    int t = 0;
    while( s>0 ){ t += (s%d)*(s%d); s /= d; }
    return vs[t][d];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset( vs, 0, sizeof(bool)*800 );
    for(int i=1; i<800; i++){
        for(int j=2; j<=10; j++) vs[i][j] = right( i, j );
    }
    //for(int i=1; i<40; i++) printf("%d %d\n",i,vs[i]);
    
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
        for(int i=2, j; i<=100000000; i++){
            for(j=0; j<an; j++) if( !ok( i, a[j] ) ) break;
            if( j == an ){ printf("%d\n",i); break; }
            if( i== 100000000 ) printf("wrong!\n");
        }
    }
    return 0;
}
