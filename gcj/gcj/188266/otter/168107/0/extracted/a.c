#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000000
int stack[SIZE];
int sn;


inline int convert(int s, int base)
{
        int f;
        int ans;
        f = s;
        ans = 0;
        while( f > 0 ) {
                ans += (f % base) * ( f% base);
                f = f / base;
                
        }
        
        return ans;
}


int happy(int n, int base)
{
        int i;
        int s;
        int j;
        
        s = n;
        sn = 0;
        i = 0;
        /* printf("%d %d: ", n, base); */
        while(i < SIZE)
        {
                for(j = 0; j < sn; j ++){
                        if ( stack[j] == s ) break;
                }
                if ( j == sn) {
                        stack[sn] = s;
                        sn++;
                }
                else break;
                /* printf("%d %d\n",i, s); */
                
                s = convert(s, base);
                if (s == 1) break;
                
                i++;
                
        }
        if (s == 1 ) return 1;
        else return 0;
        
}


int main(void)
{
        int T;
        int i,j ;
        char input[100];
        char * p;
        
        int base[i];
        int bn;
        
        int n;
        
        int tmp;
        
        scanf("%d\n", &T);
        for(i = 1 ; i <= T; i ++) {
                gets(input);
                j = 0;
                bn = 0;
                p = input;
                tmp = 0;
                
                while(sscanf(p, "%d", &tmp) == 1) {
                        base[bn] = tmp;
                        bn ++;
                        p = p + 1;
                        if( tmp == 10 ) p = p + 1;
                        if (*p != '\0') p ++;
                };
                
                
                /* for(j = 0; j < bn; j++) printf("%d ", base[j]); */
                
                n = 2;
                while( n < SIZE){
                        for(j = 0; j < bn; j ++){
                                sn = 0;
                                if ( happy(n, base[j] )!= 1 ) break;
                                 /* printf("%d %d\n", n, base[j]);  */
                        }
                        if ( j == bn ) break;
                        n++;
                        
                }
                printf("Case #%d: %d\n", i, n);
                        
        }
        
        return 0;
        
}
