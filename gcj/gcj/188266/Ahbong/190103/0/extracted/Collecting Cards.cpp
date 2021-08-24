/*
    2009  Round 1A -
    Collecting Cards
    by Dave Chang
*/
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std ;

    int T , N , C ;
    long long Com[41][41] ;
    double DP[41] ;
    double ans ;

int main(){
    Com[0][0] = 1 ;
    for(int i=1;i<=40;++i){
        Com[i][0] = 1 ;
        for(int j=1;j<=i;++j){
            Com[i][j] = Com[i-1][j] + Com[i-1][j-1] ;
            //printf("%I64d ",Com[i][j]) ;
        }
        //puts("") ;
    }
    scanf("%d",&T) ;
    for(int z=1;z<=T;++z){
        scanf("%d %d",&N,&C) ;
        for(int i=0;i<=N;++i)
            DP[i] = 0.0 ;
        DP[C] = 1.0 ;
        for(int i=C+1;i<=N;++i){
            // 0 card new
            //DP[i] += (double) Com[N][N-i] / Com[N][C] ;
            //printf("%lf ",DP[i]) ;
            for(int j=C;j>=0;--j){
                //from i-j
                //j cards repeat
                //C-j cards new
                if(i-j<C) continue ;
                if(C-j>N-i+j) continue ;
                //printf("%I64d %I64d %I64d %lf\n",Com[N-i+j][C-j],Com[N][C],Com[i-j][C-j],DP[i-j]) ;
                double tmp = (double)Com[N-i+j][C-j]/Com[N][C]*Com[i-j][C-j] ;
                                // new               all        repeat
                //printf("%lf %I64d %I64d\n",(double)Com[i-j][C]/Com[N][C],Com[i-j][C],Com[N][C]) ;
                //printf("%lf\n",(1.0-double(Com[i-j][C])/Com[N][C])) ;
                tmp *= 1.0 / (1.0-double(Com[i-j][C])/Com[N][C]) ;
                double tans = tmp / (1.0-double(Com[i-j][C])/double(Com[N][C])) ;
                //printf("%lf %lf %lf\n",tmp,tans,DP[i-j]) ;
                DP[i] += tans + DP[i-j] ;
                //printf("%d %d\n",i,j) ;
            }
            //printf("%lf ",DP[i]) ;
        }
        ans = DP[N] ;
        fprintf(stderr,"%d\n",z) ;
        printf("Case #%d: %.6lf\n",z,ans) ;
    }
	return 0 ;
}
