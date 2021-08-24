#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <stdbool.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
const int INF = 0x3F3F3F3F;
const double EPS = 1e-10; 

using namespace std;


#define DELTA_LOOPS 10


/* This function returns the sum of squares of the digits */


int N,M,T;
string str;
string bases;
long long b[10];

long long f(long long  n , long long rdx)
{
	long long  k = 0,m;

	while(n){
		m = n % rdx;  /* m is least significant digit */ 
		n = n / rdx;
		k += m*m;
	}
	return k;
}

/* This function returns TRUE if the number n is happy in the given radix,
   FALSE if not */

long long  is_happy(long long  n, long long  rdx)
{
	long long  j,old_n,loops=10;	

	/* Recall that n is happy if and only if iterating the function f
           on n eventually produces a cycle of length one. We detect a
           cycle by periodically storing the current value of n and then
           comparing it with new values of n generated in the inner loop
           below. Each time through the outer loop the size of the inner
           loop is grown. When the size exceeds the length of the cycle
           the latter is sure to be detected. */

	while(true){
		old_n = n;
		for(j=loops;j>0;j--)
			if((n = f(n,rdx))== old_n)break;
		if(n==old_n)break;
		loops += DELTA_LOOPS;
	}
	return n == 1 ? true : false;
}
		


int main(){
	int i,j,k,qtde_bases,num,tam;
	bool fim;
	int Case=1,s;
	char c,ch;
	scanf("%d\n",&T);
	while(T--){
	    qtde_bases=0;
		while(ch!='\n'){
			while (((ch = getchar()) == ' ') || (ch == '\n'));
			if (ch == '-') { s = 1; ch = getchar(); }
			for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
					i = 10 * i + (ch - '0');
			b[qtde_bases++]=i;
		}
		
	   fim = false;
	   num=1;
		while(!fim){
			fim = true;
			num++;
			for(i=0;i<qtde_bases;i++){
				if(!is_happy(num,b[i])){
					fim=false;
					break;
				}
			}
		}
		
		printf("Case #%d: %d\n",Case++,num);
		ch = ' ';
	}
	return 0;
}




