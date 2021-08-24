/*
    2009  Round 1A -
    Multi-base happiness
    by Dave Chang
*/
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std ;

    int T , base[10] , b_num ;
    char line[1000] , *p ;
    bool check[10000] , be_happy[11][10000] ;

bool check_base(int n,int b){
    memset(check,false,sizeof(check)) ;
    while(true){
        int nn = n ;
        n = 0 ;
        while(nn){
            int tmp = nn % b ;
            tmp *= tmp ;
            n += tmp ;
            nn /= b ;
        }
        if(n==1) return true ;
        if(check[n]) return false ;
        else check[n] = true ;
    }
}

bool check_all(int n){
    for(int i=0;i<b_num;++i){
        //if(!check_base(n,base[i])) return false ;
        int nn = n , tn = 0 ;
        while(nn){
            int tmp = nn % base[i] ;
            tmp *= tmp ;
            tn += tmp ;
            nn /= base[i] ;
        }
        if(!be_happy[base[i]][tn]) return false ;
    }
    return true ;
}

int main(){
    for(int i=2;i<=10;++i){
        be_happy[i][1] = true ;
        for(int j=2;j<10000;++j)
            if(check_base(j,i)) be_happy[i][j] = true ;
    }
    gets(line) ;
    sscanf(line,"%d",&T) ;
    for(int z=1;z<=T;++z){
        b_num = 0 ;
        gets(line) ;
        p = line ;
        while(*p && isspace(*p)) ++p ;
        while(*p){
            sscanf(p,"%d",&base[b_num++]) ;
            while(*p && isspace(*p)) ++p ;
            while(*p && !isspace(*p)) ++p ;
            while(*p && isspace(*p)) ++p ;
        }
        int ans ;
        for(ans=2;;++ans){
            //fprintf(stderr,"%d\n",ans) ;
            if(check_all(ans))
                break ;
        }
        fprintf(stderr,"%d\n",z) ;
        printf("Case #%d: %d\n",z,ans) ;
    }
	return 0 ;
}
